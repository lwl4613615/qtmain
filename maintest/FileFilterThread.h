#pragma once
#include <QObject>
class FileFilterThread :
	public QObject
{
	Q_OBJECT
public slots:

	void StartFilter();


};

