#include "stdafx.h"
#include "maintest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	maintest w;
	w.show();
	return a.exec();
}
