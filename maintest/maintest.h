#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_maintest.h"
#include "..\\DriverTool\\Driver.h"
#include "sendStruct.h"

class maintest : public QMainWindow
{
	Q_OBJECT

public:
	maintest(QWidget *parent = Q_NULLPTR);
protected:
	void paintEvent(QPaintEvent* event);
private:
	Ui::maintestClass ui;
signals:
	void sendfilter(SCANNER_RECV obj);
private  slots:
	void StartFileFilterButtonClick();
	void StopFileFilterButtonClick();
	void AddFilterButtuonClick();
private:
	Driver m_cDrvTool;
};
