#ifndef HAVE_CONFIG_H_
#define HAVE_CONFIG_H_

/* Example parameter expansion:
 * #define ENABLE_BUILDMODEL "ON"
 */
 
// Namespace ID for UA Information Model
#define CSA_NSID 2

// SubIDs in types ...
// ... of Module
#define CSA_NSID_CONSTANTS 5002
#define CSA_NSID_VARIABLES 5001

// ... of ProcessVariable
#define CSA_NSID_VARIABLE_NAME  6004
#define CSA_NSID_VARIABLE_TYPE  6012
#define CSA_NSID_VARIABLE_VALUE 6010
#define CSA_NSID_VARIABLE_TIMESTAMP_INDEX0 6020
#define CSA_NSID_VARIABLE_TIMESTAMP_INDEX1 6021
#define CSA_NSID_VARIABLE_TIMESTAMP_NANOSECONDS 6016
#define CSA_NSID_VARIABLE_TIMESTAMP_SECONDS 6013

#endif
