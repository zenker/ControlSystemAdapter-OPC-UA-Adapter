from PyQt5.QtWidgets import QFileDialog, QDialog, QMainWindow, QTreeWidget, QTreeWidgetItem, QCheckBox, QMessageBox
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QBrush, QColor
import lxml.etree as ET
import os
from generator_tools.generatorUI import Ui_MainWindow
from generator_tools.encryptionUI import Ui_EncryptionDialog
from generator_tools.generatorClass import MapGenerator, XMLDirectory, XMLVar, EncryptionSettings
import logging
from typing import Optional


class EncryptionDialog(QDialog, Ui_EncryptionDialog):
  def _getFileDialog(self):
    dlg = QFileDialog(self)
    dlg.setFileMode(QFileDialog.ExistingFile)
    dlg.setViewMode( QFileDialog.Detail )
    dlg.setNameFilters( [self.tr('Certificate file (*.der)'), self.tr('All Files (*)')] )
    dlg.setDefaultSuffix('der')
    return dlg

  def openUserCert(self):
    dlg = self._getFileDialog()
    dlg.setWindowTitle('Set application certificate file')
    # show dialog, save only if user did not cancel
    if dlg.exec_() :
        self.settings.certificate = str(dlg.selectedFiles()[0])
        self.userCert.setText(self.settings.certificate)

  def openPrivateKey(self):
    dlg = self._getFileDialog()
    dlg.setWindowTitle('Set appliction private key file')
    # show dialog, save only if user did not cancel
    if dlg.exec_() :
        self.settings.key = str(dlg.selectedFiles()[0])
        self.privateKey.setText(self.settings.key)
        
  def _openDirectory(self) -> Optional[str]:
    dlg = QFileDialog(self)
    dlg.setFileMode(QFileDialog.Directory)
    dlg.setOption(QFileDialog.ShowDirsOnly)
    if dlg.exec() :
      return str(dlg.selectedFiles()[0])
    else:
      return None
    
  def openTrustList(self):
    dir = self._openDirectory()
    if dir:
      self.settings.trustList = dir
      self.trustList.setText(dir)
      
  def openBlockList(self):
    dir = self._openDirectory()
    if dir:
      self.settings.blockList = dir
      self.blockList.setText(dir)

  def openIssuerList(self):
    dir = self._openDirectory()
    if dir:
      self.settings.issuerList = dir
      self.issuerList.setText(dir)
    
  
  def __init__(self, data:EncryptionSettings, parent=None):
    super(EncryptionDialog, self).__init__(parent)
    self.setupUi(self)
    
    self.settings = data
    
    self.setUserCert.clicked.connect(self.openUserCert)
    self.setPrivateKey.clicked.connect(self.openPrivateKey)
    self.setBlockList.clicked.connect(self.openBlockList)
    self.setTrustList.clicked.connect(self.openTrustList)
    self.setIssuerList.clicked.connect(self.openIssuerList)

class MapGeneratorForm(QMainWindow, Ui_MainWindow):
  def openFile(self):
    '''
    Read all information from the given XML file.
    Data is stored in the MapGenerator object.
    '''
    name = QFileDialog.getOpenFileName(self, caption='Set input file', filter="XML files (*.xml)", options=QFileDialog.DontResolveSymlinks)
    if name[0]:
      try:    
        self.MapGenerator = MapGenerator(name[0])
        self.statusbar.showMessage(name[0])
        self.fillTree()
      except:
        QMessageBox.critical(self, "Map file generator", 
                             "Could not parse xml file. Is that a file generated by the XML generator of your application?" )
        self.treeWidget.clear()
        self.MapGenerator = None
  
  def fillTree(self):
    '''
    Fill the tree by passing the root node read from the XML file.
    Filling is done recursively.
    '''
    self.treeWidget.clear()
    # block widget while filling in order to avoid calling _updateItem
    self.treeWidget.blockSignals(True)
    self._createDirectoryNode(self.treeWidget, self.MapGenerator.dir, True)
    self.treeWidget.blockSignals(False)
    self.applicationName.setText(self.MapGenerator.applicationName)
    
  def _getCheckBox(self, item:XMLDirectory | XMLVar, text:str, node:QTreeWidgetItem, index:int):
    '''
    Create a checkbox.
    
    @param item: The XML items that corresponds to the checkbox.
    @param text: The check box label.
    @param node: The widget item where the checkbox will be added. It is assumed it is a QTreeWidgetItem with multiple columns.
    @param index: The column index of the checkbox.
    '''
    checkbox = QCheckBox(parent=self.treeWidget, text=text)
    if isinstance(item, XMLDirectory) == True:
      checkbox.stateChanged.connect(lambda state: self._mapDirectory(state,item, node, index))
    else:
      checkbox.stateChanged.connect(lambda state: self._mapItem(state,item, node, index))
    return checkbox
  
  def _updateItem(self, item:QTreeWidgetItem, index:int):
    self.treeWidget.blockSignals(True)
    data = item.data(0, Qt.UserRole)
    if index == 0:
      # Name
      data.newName = item.text(index)
      item.setText(index, item.text(index) + " (Orig.: " + data.name + ")")
      item.setForeground(index,QBrush(QColor("#FF0000")))
    elif index == 3:
      # Unit
      if isinstance(data,XMLVar):
        data.newUnit = item.text(index)
        item.setText(index, item.text(index) + " (Orig.: " + str(data.unit or '') + ")")
        item.setForeground(index,QBrush(QColor("#FF0000")))
      else:
        item.setText(index, '')
        msg = "Adding unit to a directory does not make sense!"
        QMessageBox.warning(self, "Map file generator", msg )
    elif index == 4:
      # Description
      data.newDescription = item.text(index)
      item.setText(index, item.text(index) + " (Added descr.)")
      item.setForeground(index,QBrush(QColor("#FF0000")))
    self.treeWidget.blockSignals(False)
    
  def _setupRow(self, item:QTreeWidgetItem, data:XMLDirectory | XMLVar):
    item.setData(0, Qt.UserRole, data)
    self.treeWidget.setItemWidget(item, 1, self._getCheckBox(data, "exclude", item, 1))
    self.treeWidget.setItemWidget(item, 2, self._getCheckBox(data, "enable", item, 2))
    if isinstance(data, XMLDirectory):
      item.setFlags(Qt.ItemIsEditable | Qt.ItemIsEnabled | Qt.ItemIsDragEnabled | Qt.ItemIsSelectable | Qt.ItemIsDropEnabled)
    else:
      item.setFlags(Qt.ItemIsEditable | Qt.ItemIsEnabled | Qt.ItemIsDragEnabled | Qt.ItemIsSelectable)
  
  def _setState(self, state:int, index:int, item:XMLDirectory | XMLVar):
    '''
    Set data in XMLDirectory or XMLVar.
    This could be to enable mapping or enable history.
    '''
    if index == 1:
      if state == Qt.Checked:
        item.exclude = True
        logging.debug("Excluding item {}.".format(item.name))
      else:
        item.exclude = False
        logging.debug("Including item {}.".format(item.name))
    elif index == 2:
      if state == Qt.Checked:
        item.history = True
        logging.debug("Enabling history for item {}.".format(item.name))
      else:
        item.history = False
        logging.debug("Disabling history for item {}.".format(item.name))

  def _createVariableNode(self, parent:QTreeWidgetItem, v:XMLVar) -> QTreeWidgetItem:
    '''
    Create variable entry in the tree.
    Reads description and unit. 
    Add CheckBox to enable/disable mapping of that variable.
    '''
    node = QTreeWidgetItem(parent, [v.name]+[""]*2 + [v.unit] + [v.description]+[""])
    self._setupRow(node, v)
    return node
  
  def _createDirectoryNode(self, parent:QTreeWidgetItem, dir:XMLDirectory, isRootNode:bool = False) -> QTreeWidgetItem:
    '''
    Create a directory entry in the Tree.
    This will recursively add sub directories and variables in the directories.
    ''' 
    mainNode = QTreeWidgetItem(parent, [dir.name] + [""]*5)
    self._setupRow(mainNode, dir)
    if isRootNode == True:
      mainNode.setExpanded(True)
    for d in dir.dirs:
      lastNode = self._createDirectoryNode(mainNode, d)
    for v in dir.vars:
      node = self._createVariableNode(mainNode, v)
    return mainNode
  
  def _mapItem(self, state:int, var:XMLVar, node:QTreeWidgetItem, index:int):
    '''
    Called when a variable is to be mapped. 
    The corresponding check box is edited.
    '''
    self._setState(state, index, var)
    logging.debug("Childs: {}".format(node.childCount()))
    
  def _mapDirectory(self, state:int, dir:XMLDirectory, node:QTreeWidgetItem, index:int):
    '''
    Called when a directory is to be mapped. 
    The corresponding check box is edited.
    This will change the map status of all variables in the directory.
    '''
    logging.debug("Mapping directory.")
    for chId in range(node.childCount()):
      ch = node.child(chId)
      self.treeWidget.itemWidget(ch, index).setCheckState(state)
      self._setState(state, index, ch.data(0,Qt.UserRole))
      
  def closeEvent(self, event):
    msg = "Are you sure you want to close the editor?"
    reply = QMessageBox.question(self, 'ChimeraTK Logical Name Mapping editor', msg, QMessageBox.Yes, QMessageBox.No)
    if reply != QMessageBox.Yes:
      event.ignore()
    else:
      event.accept()
      
  def saveFile(self):
    '''
    Save file. If file not yet set open dialog with saveFileAs()
    '''
    try:
      if self.MapGenerator.outputFile == None:
        self.saveFileAs()
      else:
        self.MapGenerator.save()
    except RuntimeError as error:
      msg = "The following error was reported: " + str(error)
      QMessageBox.critical(self, "Map file generator", msg )
      
  def saveFileAs(self):
    # create file-save dialog
    dlg = QFileDialog(self, directory=self.MapGenerator.applicationName + "_mapping.xml")
    dlg.setAcceptMode(QFileDialog.AcceptSave)
    dlg.setWindowTitle('Save XML mapping file')
    dlg.setViewMode( QFileDialog.Detail )
    dlg.setNameFilters( [self.tr('XML Mapping Files (*.xml)'), self.tr('All Files (*)')] )
    dlg.setDefaultSuffix('xml')
    if self.MapGenerator.outputFile != None:
        dlg.setDirectory( os.path.dirname(self.MapGenerator.outputFile) )
    
    # show dialog, save only if user did not cancel
    if dlg.exec_() :
        # file name must be converted into standard python string
        self.MapGenerator.outputFile = str(dlg.selectedFiles()[0])
        # save the file
        self.saveFile()
    self.actionSave.setEnabled(True)

  def enableLogin(self, state):
    if state == Qt.Checked:
      self.userName.setEnabled(True)
      self.password.setEnabled(True)
      self.MapGenerator.enableLogin = True
    else: 
      self.userName.setEnabled(False)
      self.password.setEnabled(False)
      self.MapGenerator.enableLogin = False
      
  def updateConfig(self):
    self.MapGenerator.username = self.userName.text()
    self.MapGenerator.password = self.password.text()
    self.MapGenerator.applicationName = self.applicationName.text()
    self.MapGenerator.rootFolder = self.rootFolder.text()
    self.MapGenerator.applicationDescription = self.applicationDescription.text()
    self.MapGenerator.port = self.port.value()
    
    
  def dropEvent(self, event):
    # get item where to drop
    item = self.treeWidget.itemAt(event.pos())
    if isinstance(item.data(0,Qt.UserRole), XMLVar):
      msg = "Variables or directories can only be moved to other directories."
      QMessageBox.critical(self, "Map file generator", msg )
      return
    # get item that is dropped
    current = self.treeWidget.currentItem()
    # get data that is dropped
    currentData = current.data(0,Qt.UserRole)
    currentData.newDestination = item.data(0,Qt.UserRole).path
    current.setText(5,currentData.newDestination)
    current.setForeground(5,QBrush(QColor("#FF0000")))
    # create new item in the dropped place
    # self._createVariableNode(item, currentData)
    # remove original item -> leave original PV/directory
    # parent = current.parent()
    # parent.removeChild(current)
  
  def dragEnterEvent(self, e)->None:
    e.accept()
    
  def configureEncryption(self):
    dlg = EncryptionDialog(parent=self, data=MapGenerator)
    dlg.exec()
    
  def updateEncryptionConfiguration(self, state):
    states = [self.enableEncryptionButton.isChecked(),
              self.addUnsecureEndpoint.isChecked()]
    self.addUnsecureEndpoint.setEnabled(states[0])
    self.configureEncryptionButton.setEnabled(states[0])
    self.MapGenerator.encryptionEnabled = states[0]
    self.MapGenerator.addUnsecureEndpoint = states[1]
  
  def __init__(self, args, parent=None):
    super(MapGeneratorForm, self).__init__(parent)
    self.setupUi(self)
    

    self.MapGenerator = None
    if args.input:
      self.MapGenerator = MapGenerator(args.input)
      self.statusbar.showMessage(args.input)
      self.fillTree()
    else:
      self.openFile()
      # dlg = QFileDialog(self)
      # dlg.setFileMode(QFileDialog.ExistingFile)
      # dlg.setViewMode( QFileDialog.Detail )
      # dlg.setNameFilters( [self.tr('ChimeraTK XML file (*.xml)'), self.tr('All Files (*)')] )
      # dlg.setDefaultSuffix('xml')
      # if dlg.exec():
      #   self.MapGenerator = MapGenerator(str(dlg.selectedFiles()[0]))

   
    self.treeWidget.itemChanged.connect(self._updateItem)
    
    self.actionOpen_File.triggered.connect(self.openFile)
    self.actionSave_as.triggered.connect(self.saveFileAs)
    self.actionSave.triggered.connect(self.saveFile)
    self.enableLoginSwitch.stateChanged.connect(self.enableLogin)
    self.password.textChanged.connect(self.updateConfig)
    self.userName.textChanged.connect(self.updateConfig)
    self.applicationName.textChanged.connect(self.updateConfig)
    self.rootFolder.textChanged.connect(self.updateConfig)
    self.applicationDescription.textChanged.connect(self.updateConfig)
    self.actionQuit.triggered.connect(self.close)
    self.enableEncryptionButton.stateChanged.connect(self.updateEncryptionConfiguration)
    self.addUnsecureEndpoint.stateChanged.connect(self.updateEncryptionConfiguration)
    self.configureEncryptionButton.clicked.connect(self.configureEncryption)

    
    # Allow to move items 
    self.treeWidget.dropEvent = self.dropEvent
    self.treeWidget.dragEnterEvent = self.dragEnterEvent