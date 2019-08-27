#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_maintest.h"
#include "..\\DriverTool\\Driver.h"
#include"FileFilterThread.h"
class maintest : public QMainWindow
{
	Q_OBJECT

public:
	maintest(QWidget *parent = Q_NULLPTR);
protected:
	void paintEvent(QPaintEvent* event);
    //��갴��
    void mousePressEvent(QMouseEvent* e);
    //����ƶ�
    void mouseMoveEvent(QMouseEvent* e);
    //����ͷ�
    void mouseReleaseEvent(QMouseEvent* e);
private:
	Ui::maintestClass ui;

private  slots:
	void StartFileFilterButtonClick();
	void StopFileFilterButtonClick();
	void AddFileFilterPathButtonClick();
    void RemoveFileFilterPathButtonClick();
	void StartNetFilterButtonClick();
	void StopNetFilterButtonClick();
	void AddDeterAppcationButtonClick();
	void RemoveDeterAppcationButtonClick();
private:
	Driver m_cDrvTool;
	Driver m_cDrvTool1;
	QThread* filterThread;
	FileFilterThread* obj;
    QPoint last;
	HANDLE PortToNet;
};
