/*++

Copyright (c) 1999-2002  Microsoft Corporation

Module Name:

    scanuk.h

Abstract:

    Header file which contains the structures, type definitions,
    constants, global variables and function prototypes that are
    shared between kernel and user mode.

Environment:

    Kernel & user mode

--*/
#pragma once

#ifndef __SCANUK_H__
#define __SCANUK_H__

//
//  Name of port used to communicate
//

const wchar_t* ScannerPortName = L"\\ScannerPort";


#define SCANNER_READ_BUFFER_SIZE   1024
#define MAX_PATH 260


typedef struct _SCANNER_NOTIFICATION {

    ULONG BytesToScan;
 //   ULONG Reserved;             // for quad-word alignement of the Contents structure
    UCHAR Contents[SCANNER_READ_BUFFER_SIZE];
	ULONG  Option;
	WCHAR  ProcessPath[MAX_PATH];
	WCHAR  FilePath[MAX_PATH];
	WCHAR  RenamePath[MAX_PATH];
    
} SCANNER_NOTIFICATION, *PSCANNER_NOTIFICATION;

// typedef struct _SCANNER_SENDMESSAGE {
// 	
// 	ULONG  Option;
// 	WCHAR  ProcessPath[MAX_PATH];
// 	WCHAR  FilePath[MAX_PATH];
// 	WCHAR  RenamePath[MAX_PATH];
// 	
// }SCANNER_SENDMESSAGE,*PSCANNER_SENDMESSAGE;
// 


typedef struct _SCANNER_REPLY {

    BOOLEAN SafeToOpen;
    
} SCANNER_REPLY, *PSCANNER_REPLY;

#endif //  __SCANUK_H__


