#pragma once
#include <QObject>
#include "sendStruct.h"
class FileFilterThread :
	public QObject
{
	Q_OBJECT
public slots:

	void StartFilter();

	void SendRule(SCANNER_RECV obj);
};

