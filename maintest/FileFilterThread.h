#pragma once
#include <QObject>
typedef struct _SCANNER_THREAD_CONTEXT {

	HANDLE Port;
	HANDLE Completion;

} SCANNER_THREAD_CONTEXT, * PSCANNER_THREAD_CONTEXT;
class FileFilterThread :
	public QObject
{
	Q_OBJECT
public slots:

	void StartFilter();
public:
	HANDLE RetPort();

private:
	SCANNER_THREAD_CONTEXT context;

};

