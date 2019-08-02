#include "stdafx.h"
#include "FileFilterThread.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <winioctl.h>
#include <string.h>
#include <crtdbg.h>
#include <assert.h>
#include <fltuser.h>
#include "..\\inc\\scanuk.h"
#include "scanuser.h"
#include <dontuse.h>
#include <conio.h>
#include <fltuser.h>
#pragma comment(lib,"fltLib.lib")
#define SCANNER_DEFAULT_REQUEST_COUNT       5
#define SCANNER_DEFAULT_THREAD_COUNT        2
#define SCANNER_MAX_THREAD_COUNT            64
CRITICAL_SECTION cr;
UCHAR FoulString[] = "foul";

//
//  Context passed to worker threads
//

typedef struct _SCANNER_THREAD_CONTEXT {

	HANDLE Port;
	HANDLE Completion;

} SCANNER_THREAD_CONTEXT, * PSCANNER_THREAD_CONTEXT;

SCANNER_THREAD_CONTEXT context;
VOID
Usage(
	VOID
)
/*++

Routine Description

	Prints usage

Arguments

	None

Return Value

	None

--*/
{

	printf("Connects to the scanner filter and scans buffers \n");
	printf("Usage: scanuser [requests per thread] [number of threads(1-64)]\n");
}

BOOL
ScanBuffer(
	__in_bcount(BufferSize) PUCHAR Buffer,
	__in ULONG BufferSize
)
/*++

Routine Description

	Scans the supplied buffer for an instance of FoulString.

	Note: Pattern matching algorithm used here is just for illustration purposes,
	there are many better algorithms available for real world filters

Arguments

	Buffer      -   Pointer to buffer
	BufferSize  -   Size of passed in buffer

Return Value

	TRUE        -    Found an occurrence of the appropriate FoulString
	FALSE       -    Buffer is ok

--*/
{
	PUCHAR p;
	ULONG searchStringLength = sizeof(FoulString) - sizeof(UCHAR);

	for (p = Buffer;
		p <= (Buffer + BufferSize - searchStringLength);
		p++) {

		if (RtlEqualMemory(p, FoulString, searchStringLength)) {

			printf("Found a string\n");

			//
			//  Once we find our search string, we're not interested in seeing
			//  whether it appears again.
			//

			return TRUE;
		}
	}

	return FALSE;
}


DWORD
ScannerWorker(
	__in PSCANNER_THREAD_CONTEXT Context
)
/*++

Routine Description

	This is a worker thread that


Arguments

	Context  - This thread context has a pointer to the port handle we use to send/receive messages,
				and a completion port handle that was already associated with the comm. port by the caller

Return Value

	HRESULT indicating the status of thread exit.

--*/
{
	PSCANNER_NOTIFICATION notification;
	SCANNER_REPLY_MESSAGE replyMessage;
	PSCANNER_MESSAGE message;
	LPOVERLAPPED pOvlp;
	BOOL result;
	DWORD outSize;
	HRESULT hr;
	ULONG_PTR key;
	char tmp[256];
#pragma warning(push)
#pragma warning(disable:4127) // conditional expression is constant
	EnterCriticalSection(&cr);
	while (TRUE) {

#pragma warning(pop)

		//
		//  Poll for messages from the filter component to scan.
		//

		result = GetQueuedCompletionStatus(Context->Completion, &outSize, &key, &pOvlp, INFINITE);

		//
		//  Obtain the message: note that the message we sent down via FltGetMessage() may NOT be
		//  the one dequeued off the completion queue: this is solely because there are multiple
		//  threads per single port handle. Any of the FilterGetMessage() issued messages can be
		//  completed in random order - and we will just dequeue a random one.
		//

		message = CONTAINING_RECORD(pOvlp, SCANNER_MESSAGE, Ovlp);

		if (!result) {

			//
			//  An error occured.
			//

			hr = HRESULT_FROM_WIN32(GetLastError());
			break;
		}
		sprintf_s(tmp, 256,"Received message, size %d\n", pOvlp->InternalHigh);
		OutputDebugStringA(tmp);

		notification = &message->Notification;

		sprintf_s(tmp, 256, "option: % d\n", notification->Option);
		OutputDebugStringA(tmp);
	
		switch (notification->Option)
		{
		case 0:
			//扫描文件
		{
			result = ScanBuffer(notification->Contents, notification->BytesToScan);
			break;
		}
		case 1:
			//创建文件的时候
		{
			sprintf_s(tmp, 256, "r3 CreateProcessPath:%ws \n ", notification->ProcessPath);
			OutputDebugStringA(tmp);
			sprintf_s(tmp, 256, "r3 CreateFilePath:%ws \n", notification->FilePath);
			OutputDebugStringA(tmp);
			result = false;
			break;
		}
		case 2:
			//重命名文件的时候
		{
			sprintf_s(tmp, 256, "r3 RenameProcessPath:%ws \n ", notification->ProcessPath);
			OutputDebugStringA(tmp);
			sprintf_s(tmp, 256, "r3 RenameoldFilePath:%ws \n", notification->FilePath);
			OutputDebugStringA(tmp);
			sprintf_s(tmp, 256, "r3 RenamenewFilePath:%ws \n", notification->RenamePath);
			OutputDebugStringA(tmp);
		
			result = false;
			break;
		}
		case 3:
			//创建文件的时候
		{
			sprintf_s(tmp, 256, "r3 deleteProcessPath:%ws \n ", notification->ProcessPath);
			OutputDebugStringA(tmp);
			sprintf_s(tmp, 256, "r3 deleteFilePath:%ws \n", notification->FilePath);
			OutputDebugStringA(tmp);		
			result = false;
			break;
		}
		default:
			break;
		}

		replyMessage.ReplyHeader.Status = 0;
		replyMessage.ReplyHeader.MessageId = message->MessageHeader.MessageId;

		//
		//  Need to invert the boolean -- result is true if found
		//  foul language, in which case SafeToOpen should be set to false.
		//

		replyMessage.Reply.SafeToOpen = !result;

		printf("Replying message, SafeToOpen: %d\n", replyMessage.Reply.SafeToOpen);

		hr = FilterReplyMessage(Context->Port,
			(PFILTER_REPLY_HEADER)& replyMessage,
			sizeof(FILTER_REPLY_HEADER) + sizeof(SCANNER_REPLY));
		//这个时候，执行完上面函数后，驱动中FltSendMessage()返回

		if (SUCCEEDED(hr)) {

		
			OutputDebugStringA("Replied message");
		}
		else {
			sprintf_s(tmp, 256, "Scanner: Error replying message. Error = 0x%X\n", hr);
			OutputDebugStringA(tmp);
			break;
		}

		memset(&message->Ovlp, 0, sizeof(OVERLAPPED));

		hr = FilterGetMessage(Context->Port,
			&message->MessageHeader,
			FIELD_OFFSET(SCANNER_MESSAGE, Ovlp),
			&message->Ovlp);

		if (hr != HRESULT_FROM_WIN32(ERROR_IO_PENDING)) {

			break;
		}
	}

	if (!SUCCEEDED(hr)) {

		if (hr == HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE)) {

			//
			//  Scanner port disconncted.
			//
		
			OutputDebugStringA("Scanner: Port is disconnected, probably due to scanner filter unloading.\n");
			

		}
		else {
			OutputDebugStringA("Scanner: Unknown error occured. Error = 0x%X\n");

			
		}
	}

	free(message);
	LeaveCriticalSection(&cr);
	return hr;
}
void FileFilterThread::StartFilter()
{
	DWORD requestCount = SCANNER_DEFAULT_REQUEST_COUNT;
	DWORD threadCount = SCANNER_DEFAULT_THREAD_COUNT;
	HANDLE threads[SCANNER_MAX_THREAD_COUNT];
	
	HANDLE port, completion;
	PSCANNER_MESSAGE msg;
	DWORD threadId;
	HRESULT hr;
	DWORD i, j;

	//
	//  Open a commuication channel to the filter
	//
	qDebug() << "Scanner: Connecting to the filter ...";
	hr = FilterConnectCommunicationPort(ScannerPortName,
		0,
		NULL,
		0,
		NULL,
		&port);

	if (IS_ERROR(hr)) {

		QString tmp = "ERROR: Connecting to filter port : 0x" + hr;
		qDebug() << tmp;
		return;
	}

	//
	//  Create a completion port to associate with this handle.
	//

	completion = CreateIoCompletionPort(port,
		NULL,
		0,
		threadCount);

	if (completion == NULL) {
		QString tmp = "ERROR: Creating completion port: 0x" + GetLastError();
		qDebug() << tmp;
		CloseHandle(port);
		return;
	}

	printf("Scanner: Port = 0x%p Completion = 0x%p\n", port, completion);

	context.Port = port;
	context.Completion = completion;

	//
	//  Create specified number of threads.
	//

	for (i = 0; i < threadCount; i++) {

		threads[i] = CreateThread(NULL,
			0,
			(LPTHREAD_START_ROUTINE)ScannerWorker,
			&context,
			0,
			&threadId);

		if (threads[i] == NULL) {

			//
			//  Couldn't create thread.
			//

			QString tmp = "ERROR: Couldn't create thread: " + GetLastError();
			qDebug() << tmp;			
			goto main_cleanup;
		}

		for (j = 0; j < requestCount; j++) {

			//
			//  Allocate the message.
			//

#pragma prefast(suppress:__WARNING_MEMORY_LEAK, "msg will not be leaked because it is freed in ScannerWorker")
			msg = (SCANNER_MESSAGE*)malloc(sizeof(SCANNER_MESSAGE));

			if (msg == NULL) {
				hr = ERROR_NOT_ENOUGH_MEMORY;
				goto main_cleanup;
			}

			memset(&msg->Ovlp, 0, sizeof(OVERLAPPED));

			//
			//  Request messages from the filter driver.
			//

			hr = FilterGetMessage(port,
				&msg->MessageHeader,
				FIELD_OFFSET(SCANNER_MESSAGE, Ovlp),
				&msg->Ovlp);

			if (hr != HRESULT_FROM_WIN32(ERROR_IO_PENDING)) {

				free(msg);
				goto main_cleanup;
			}
		}
	}

	hr = S_OK;

	WaitForMultipleObjectsEx(i, threads, TRUE, INFINITE, FALSE);

main_cleanup:	
	QString tmp = "Scanner:  All done. Result = 0x%08x " +hr;
	qDebug() << tmp;
	CloseHandle(port);
	CloseHandle(completion);


}

void FileFilterThread::SendRule(SCANNER_RECV obj)
{
	DWORD bytesReturned = 0;
	HRESULT hResult = NULL;
	hResult = FilterSendMessage(context.Port, &obj, sizeof(SCANNER_RECV), NULL, NULL, &bytesReturned);

	if (hResult != S_OK)
	{
		qDebug() << "Send failed";
	}
}
