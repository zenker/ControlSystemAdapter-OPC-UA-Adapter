/* WARNING: This is a generated file.
 * Any manual changes will be overwritten.

 */
#include "mtca_namespaceinit_generated.h"
UA_INLINE void mtca_namespaceinit_generated(UA_Server *server) {
UA_Server_addNamespace(server, "http://yourorganisation.org/templatemodel/");

do {
// Referencing node found and declared as parent: i=58/BaseObjectType using i=45/HasSubtype
// Node: opcua_node_objectType_t(ns=2;i=1002), 1:mtcaModule
UA_ObjectTypeAttributes attr;
UA_ObjectTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "mtcaModule");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 1002);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 58);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "mtcaModule");
UA_Server_addObjectTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: i=58/BaseObjectType using i=45/HasSubtype
// Node: opcua_node_objectType_t(ns=2;i=1001), 1:mtcaProcessVariable
UA_ObjectTypeAttributes attr;
UA_ObjectTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "mtcaProcessVariable");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 1001);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 58);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "mtcaProcessVariable");
UA_Server_addObjectTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: i=58/BaseObjectType using i=45/HasSubtype
// Node: opcua_node_objectType_t(ns=2;i=1004), 1:mtcaTimeStamp
UA_ObjectTypeAttributes attr;
UA_ObjectTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "mtcaTimeStamp");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 1004);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 58);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "mtcaTimeStamp");
UA_Server_addObjectTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: i=11487/OptionSetType using i=46/HasProperty
// Node: opcua_node_variable_t(ns=2;i=6017), 1:seconds
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "seconds");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6017);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 68);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, 11487);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "seconds");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6017), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6017), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1002/1:mtcaModule using i=47/HasComponent
// Node: opcua_node_object_t(ns=2;i=5002), 1:Constants
UA_ObjectAttributes attr;
UA_ObjectAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Constants");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 5002);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 61);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Constants");
UA_Server_addObjectNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 58), true); //remove HasTypeDefinition refs generated by addObjectNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 5002), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 61), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1002/1:mtcaModule using i=47/HasComponent
// Node: opcua_node_object_t(ns=2;i=5001), 1:Variables
UA_ObjectAttributes attr;
UA_ObjectAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Variables");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 5001);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 61);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Variables");
UA_Server_addObjectNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 58), true); //remove HasTypeDefinition refs generated by addObjectNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 5001), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 61), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1001/1:mtcaProcessVariable using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6006), 1:EngineeringUnit
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnit");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6006);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "EngineeringUnit");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6006), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6006), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1001/1:mtcaProcessVariable using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6004), 1:Name
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Name");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_String *opcua_node_variable_t_ns_2_i_6004_variant_DataContents =  UA_String_new();
*opcua_node_variable_t_ns_2_i_6004_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar( &attr.value, opcua_node_variable_t_ns_2_i_6004_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6004);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Name");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6004), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6004), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1001/1:mtcaProcessVariable using i=47/HasComponent
// Node: opcua_node_object_t(ns=2;i=5005), 1:timeStamp
UA_ObjectAttributes attr;
UA_ObjectAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "timeStamp");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 5005);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(2, 1004);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "timeStamp");
UA_Server_addObjectNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 58), true); //remove HasTypeDefinition refs generated by addObjectNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 5005), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 5005), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(2, 1004), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=5005/1:timeStamp using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6001), 1:index0
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "index0");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6001);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 5005);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "index0");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6001), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6001), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=5005/1:timeStamp using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6002), 1:index1
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "index1");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6002);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 5005);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "index1");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6002), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6002), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=5005/1:timeStamp using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6003), 1:nanoseconds
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "nanoseconds");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6003);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 5005);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "nanoseconds");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6003), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6003), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=5005/1:timeStamp using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6005), 1:seconds
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "seconds");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6005);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 5005);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "seconds");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6005), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6005), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1001/1:mtcaProcessVariable using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6012), 1:Type
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Type");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_String *opcua_node_variable_t_ns_2_i_6012_variant_DataContents =  UA_String_new();
*opcua_node_variable_t_ns_2_i_6012_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar( &attr.value, opcua_node_variable_t_ns_2_i_6012_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6012);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Type");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6012), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6012), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1001/1:mtcaProcessVariable using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6010), 1:Value
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Value");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -2;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6010);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "Value");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6010), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6010), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1004/1:mtcaTimeStamp using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6020), 1:index0
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "index0");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6020);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "index0");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6020), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6020), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1004/1:mtcaTimeStamp using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6021), 1:index1
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "index1");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6021);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "index1");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6021), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6021), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1004/1:mtcaTimeStamp using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6016), 1:nanoseconds
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "nanoseconds");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6016);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "nanoseconds");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6016), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6016), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1004/1:mtcaTimeStamp using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6013), 1:seconds
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "seconds");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.userAccessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(2, 6013);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(2, 1004);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(1, "seconds");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6013), UA_NODEID_NUMERIC(0, 40), UA_EXPANDEDNODEID_NUMERIC(0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(2, 6013), UA_NODEID_NUMERIC(0, 37), UA_EXPANDEDNODEID_NUMERIC(0, 78), true);
} while(0);
}
