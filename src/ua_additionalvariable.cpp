/* 
 * This file is part of ChimeraTKs ControlSystem-OPC-UA-Adapter.
 *
 * ChimeraTKs ControlSystem-OPC-UA-Adapter is free software: you can 
 * redistribute it and/or modify it under the terms of the Lesser GNU 
 * General Public License as published by the Free Software Foundation, 
 * either version 3 of the License, or (at your option) any later version.
 *
 * ChimeraTKs ControlSystem-OPC-UA-Adapter is distributed in the hope 
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty ofMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 * See the Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see https://www.gnu.org/licenses/lgpl.html
 * 
 * Copyright (c) 2016 Chris Iatrou   <Chris_Paul.Iatrou@tu-dresden.de>
 * Copyright (c) 2016 Julian Rahm    <Julian.Rahm@tu-dresden.de>
 * Copyright (c) 2019 Andreas Ebner <Andreas.Ebner@iosb-extern.fraunhofer.de>
 */

#include "ua_additionalvariable.h"
#include "csa_config.h"

extern "C" {
#include "csa_namespaceinit_generated.h"
}

#include "ua_proxies.h"
#include "ua_proxies_callback.h"

#include <iostream>

using namespace std;

ua_additionalvariable::ua_additionalvariable(UA_Server* server, UA_NodeId basenodeid, string name, string value, string description) : ua_mapped_class(server, basenodeid) {
	
	this->name = name;
  	this->value = value;
	this->description = description;

	this->mapSelfToNamespace();
}

ua_additionalvariable::~ua_additionalvariable()
{
  // Our ua_mapped_class destructor will take care of deleting our opcua footprint as long as all variables are mapped in this->ownedNodes
}

//
UA_RDPROXY_STRING(ua_additionalvariable, getValue)
string ua_additionalvariable::getValue() {
	return this->value;
}

UA_StatusCode ua_additionalvariable::mapSelfToNamespace() {
 
  	UA_StatusCode retval = UA_STATUSCODE_GOOD;
    UA_NodeId createdNodeId = UA_NODEID_NULL;
		
    if (UA_NodeId_equal(&this->baseNodeId, &createdNodeId) == UA_TRUE) 
        return UA_STATUSCODE_BADINVALIDARGUMENT; // Something went UA_WRING (initializer should have set this!)

	//Generate additional variable node id
	UA_String baseNodeIdString = baseNodeId.identifier.string;
	string baseNodeIdStringCPP;
	UASTRING_TO_CPPSTRING(baseNodeIdString, baseNodeIdStringCPP);

    UA_String *opcua_node_variable_t_ns_2_variant_DataContents =  UA_String_new();
    *opcua_node_variable_t_ns_2_variant_DataContents = UA_STRING_ALLOC(this->value.c_str());
    UA_VariableAttributes vAttr;
    UA_VariableAttributes_init(&vAttr);
    vAttr.displayName = UA_LOCALIZEDTEXT_ALLOC((char*) "en_US", (char*)this->name.c_str());
    vAttr.description = UA_LOCALIZEDTEXT_ALLOC((char*) "en_US", (char*)this->description.c_str());
    vAttr.dataType = UA_NODEID_NUMERIC(0, UA_NS0ID_STRING);
    UA_Variant_setScalar(&vAttr.value, opcua_node_variable_t_ns_2_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);

    UA_INSTATIATIONCALLBACK(icb);

	retval |= UA_Server_addVariableNode(this->mappedServer, UA_NODEID_STRING(1, (char *) (baseNodeIdStringCPP+"/"+name+"AdditionalVariable").c_str()), this->baseNodeId,
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT), UA_QUALIFIEDNAME_ALLOC(1, this->name.c_str()),
                              UA_NODEID_NUMERIC(CSA_NSID, UA_NS2ID_CTKADDITIONALVARIABLE), vAttr ,&icb, &createdNodeId);
	this->ownNodeId = createdNodeId;

    UA_VariableAttributes_init(&vAttr);
    vAttr.displayName = UA_LOCALIZEDTEXT_ALLOC((char*) "en_US", (char*) "description");
    vAttr.description = UA_LOCALIZEDTEXT_ALLOC((char*) "en_US", (char*)this->description.c_str());
    vAttr.dataType = UA_NODEID_NUMERIC(0, UA_NS0ID_STRING);
    UA_String addVarDescription = UA_STRING_ALLOC(description.c_str());
    UA_Variant_setScalar(&vAttr.value, &addVarDescription, &UA_TYPES[UA_TYPES_STRING]);

    retval |= UA_Server_addVariableNode(this->mappedServer, UA_NODEID_STRING(1, (char *) (baseNodeIdStringCPP+"/"+name+"/description").c_str()),
            this->ownNodeId, UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
            UA_QUALIFIEDNAME_ALLOC(1, this->description.c_str()),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), vAttr, NULL, &createdNodeId);
		
	/* Use a datasource map to map any local getter/setter functions to opcua variables nodes */
	UA_DataSource_Map mapDs;
	mapDs.push_back((UA_DataSource_Map_Element) { .typeTemplateId = UA_NODEID_NUMERIC(CSA_NSID, CSA_NSID_ADDITIONAL_VARIABLE_VALUE), vAttr.description, .read=UA_RDPROXY_NAME(ua_additionalvariable, getValue), .write=NULL});
	
	this->ua_mapDataSources((void *) this, &mapDs);
	
	return retval;
}
	

UA_DateTime ua_additionalvariable::getSourceTimeStamp() {
	return UA_DateTime_now();
}
