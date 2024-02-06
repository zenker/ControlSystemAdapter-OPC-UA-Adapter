# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'generatorUI.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1147, 856)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.rootFolder = QtWidgets.QLineEdit(self.centralwidget)
        self.rootFolder.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.rootFolder.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.rootFolder.setObjectName("rootFolder")
        self.horizontalLayout.addWidget(self.rootFolder)
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setObjectName("label_2")
        self.horizontalLayout.addWidget(self.label_2)
        self.applicationName = QtWidgets.QLineEdit(self.centralwidget)
        self.applicationName.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.applicationName.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.applicationName.setObjectName("applicationName")
        self.horizontalLayout.addWidget(self.applicationName)
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setObjectName("label_3")
        self.horizontalLayout.addWidget(self.label_3)
        self.port = QtWidgets.QSpinBox(self.centralwidget)
        self.port.setMinimum(0)
        self.port.setMaximum(99999)
        self.port.setProperty("value", 16664)
        self.port.setObjectName("port")
        self.horizontalLayout.addWidget(self.port)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setObjectName("label_6")
        self.horizontalLayout_3.addWidget(self.label_6)
        self.applicationDescription = QtWidgets.QLineEdit(self.centralwidget)
        self.applicationDescription.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.applicationDescription.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.applicationDescription.setObjectName("applicationDescription")
        self.horizontalLayout_3.addWidget(self.applicationDescription)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.addHistorySettingButton = QtWidgets.QPushButton(self.centralwidget)
        self.addHistorySettingButton.setObjectName("addHistorySettingButton")
        self.horizontalLayout_2.addWidget(self.addHistorySettingButton)
        self.histories = QtWidgets.QComboBox(self.centralwidget)
        self.histories.setMinimumSize(QtCore.QSize(0, 0))
        self.histories.setEditable(False)
        self.histories.setObjectName("histories")
        self.horizontalLayout_2.addWidget(self.histories)
        self.editHistorySettingButton = QtWidgets.QPushButton(self.centralwidget)
        self.editHistorySettingButton.setEnabled(False)
        self.editHistorySettingButton.setObjectName("editHistorySettingButton")
        self.horizontalLayout_2.addWidget(self.editHistorySettingButton)
        self.setHistoryForInputsButton = QtWidgets.QRadioButton(self.centralwidget)
        self.setHistoryForInputsButton.setEnabled(False)
        self.setHistoryForInputsButton.setObjectName("setHistoryForInputsButton")
        self.horizontalLayout_2.addWidget(self.setHistoryForInputsButton)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem)
        self.enableLoginSwitch = QtWidgets.QCheckBox(self.centralwidget)
        self.enableLoginSwitch.setObjectName("enableLoginSwitch")
        self.horizontalLayout_2.addWidget(self.enableLoginSwitch)
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout_2.addWidget(self.label_4)
        self.userName = QtWidgets.QLineEdit(self.centralwidget)
        self.userName.setEnabled(False)
        self.userName.setMaximumSize(QtCore.QSize(100, 16777215))
        self.userName.setText("")
        self.userName.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.userName.setObjectName("userName")
        self.horizontalLayout_2.addWidget(self.userName)
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setObjectName("label_5")
        self.horizontalLayout_2.addWidget(self.label_5)
        self.password = QtWidgets.QLineEdit(self.centralwidget)
        self.password.setEnabled(False)
        self.password.setMaximumSize(QtCore.QSize(100, 16777215))
        self.password.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.password.setObjectName("password")
        self.horizontalLayout_2.addWidget(self.password)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.horizontalFrame = QtWidgets.QFrame(self.centralwidget)
        self.horizontalFrame.setFrameShape(QtWidgets.QFrame.Box)
        self.horizontalFrame.setObjectName("horizontalFrame")
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout(self.horizontalFrame)
        self.horizontalLayout_5.setSizeConstraint(QtWidgets.QLayout.SetDefaultConstraint)
        self.horizontalLayout_5.setContentsMargins(1, -1, -1, -1)
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.label_9 = QtWidgets.QLabel(self.horizontalFrame)
        self.label_9.setObjectName("label_9")
        self.horizontalLayout_5.addWidget(self.label_9)
        self.label_7 = QtWidgets.QLabel(self.horizontalFrame)
        self.label_7.setAutoFillBackground(False)
        self.label_7.setStyleSheet("background-color: rgb(254, 232, 200);")
        self.label_7.setObjectName("label_7")
        self.horizontalLayout_5.addWidget(self.label_7)
        self.label_8 = QtWidgets.QLabel(self.horizontalFrame)
        self.label_8.setAutoFillBackground(False)
        self.label_8.setStyleSheet("background-color: rgb(229, 245, 224);")
        self.label_8.setObjectName("label_8")
        self.horizontalLayout_5.addWidget(self.label_8)
        self.horizontalLayout_4.addWidget(self.horizontalFrame)
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_4.addItem(spacerItem1)
        self.enableEncryptionButton = QtWidgets.QCheckBox(self.centralwidget)
        self.enableEncryptionButton.setObjectName("enableEncryptionButton")
        self.horizontalLayout_4.addWidget(self.enableEncryptionButton)
        self.addUnsecureEndpoint = QtWidgets.QCheckBox(self.centralwidget)
        self.addUnsecureEndpoint.setEnabled(False)
        self.addUnsecureEndpoint.setObjectName("addUnsecureEndpoint")
        self.horizontalLayout_4.addWidget(self.addUnsecureEndpoint)
        self.configureEncryptionButton = QtWidgets.QPushButton(self.centralwidget)
        self.configureEncryptionButton.setEnabled(False)
        self.configureEncryptionButton.setObjectName("configureEncryptionButton")
        self.horizontalLayout_4.addWidget(self.configureEncryptionButton)
        self.verticalLayout.addLayout(self.horizontalLayout_4)
        self.treeWidget = QtWidgets.QTreeWidget(self.centralwidget)
        self.treeWidget.setAcceptDrops(True)
        self.treeWidget.setDragEnabled(True)
        self.treeWidget.setIndentation(20)
        self.treeWidget.setObjectName("treeWidget")
        self.treeWidget.headerItem().setText(0, "Name")
        self.treeWidget.header().setVisible(True)
        self.treeWidget.header().setDefaultSectionSize(100)
        self.verticalLayout.addWidget(self.treeWidget)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1147, 22))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setToolTipsVisible(False)
        self.menuFile.setObjectName("menuFile")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionOpen_File = QtWidgets.QAction(MainWindow)
        self.actionOpen_File.setObjectName("actionOpen_File")
        self.actionQuit = QtWidgets.QAction(MainWindow)
        self.actionQuit.setShortcut("")
        self.actionQuit.setObjectName("actionQuit")
        self.actionSave_as = QtWidgets.QAction(MainWindow)
        self.actionSave_as.setObjectName("actionSave_as")
        self.actionSave = QtWidgets.QAction(MainWindow)
        self.actionSave.setEnabled(False)
        self.actionSave.setObjectName("actionSave")
        self.actionLoad_mapping_file = QtWidgets.QAction(MainWindow)
        self.actionLoad_mapping_file.setObjectName("actionLoad_mapping_file")
        self.menuFile.addAction(self.actionOpen_File)
        self.menuFile.addAction(self.actionSave_as)
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionLoad_mapping_file)
        self.menuFile.addAction(self.actionQuit)
        self.menubar.addAction(self.menuFile.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "Root folder name:"))
        self.label_2.setText(_translate("MainWindow", "Application name:"))
        self.label_3.setText(_translate("MainWindow", "Port:"))
        self.label_6.setText(_translate("MainWindow", "Application description:"))
        self.addHistorySettingButton.setText(_translate("MainWindow", "Add history setting"))
        self.editHistorySettingButton.setText(_translate("MainWindow", "Edit history setting"))
        self.setHistoryForInputsButton.setToolTip(_translate("MainWindow", "<html><head/><body><p>Use the selected history for all input process variables.</p></body></html>"))
        self.setHistoryForInputsButton.setText(_translate("MainWindow", "Use selected history for inputs"))
        self.enableLoginSwitch.setText(_translate("MainWindow", "Enable login"))
        self.label_4.setText(_translate("MainWindow", "Username:"))
        self.label_5.setText(_translate("MainWindow", "Password:"))
        self.label_9.setText(_translate("MainWindow", "Color legend:"))
        self.label_7.setText(_translate("MainWindow", "Controlsystem to Application"))
        self.label_8.setText(_translate("MainWindow", "Application to Controlsystem"))
        self.enableEncryptionButton.setText(_translate("MainWindow", "Enable encryption"))
        self.addUnsecureEndpoint.setText(_translate("MainWindow", "Add non-encrypted Endpoint"))
        self.configureEncryptionButton.setText(_translate("MainWindow", "Configure..."))
        self.treeWidget.headerItem().setText(1, _translate("MainWindow", "Map"))
        self.treeWidget.headerItem().setText(2, _translate("MainWindow", "History"))
        self.treeWidget.headerItem().setText(3, _translate("MainWindow", "Unit"))
        self.treeWidget.headerItem().setText(4, _translate("MainWindow", "Description"))
        self.treeWidget.headerItem().setText(5, _translate("MainWindow", "Additional Location"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.actionOpen_File.setText(_translate("MainWindow", "Open File..."))
        self.actionQuit.setText(_translate("MainWindow", "Quit"))
        self.actionSave_as.setText(_translate("MainWindow", "Save as..."))
        self.actionSave.setText(_translate("MainWindow", "Save"))
        self.actionLoad_mapping_file.setText(_translate("MainWindow", "Load mapping file..."))
