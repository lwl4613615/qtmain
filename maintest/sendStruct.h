#pragma once
typedef struct _SCANNER_RECV {

	ULONG option;
	ULONG ul_PathLength;
	wchar_t path[260];

}SCANNER_RECV, * PSCANNER_RECV;