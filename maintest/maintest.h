#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_maintest.h"
#include "..\\DriverTool\\Driver.h"
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
private:
	Driver m_cDrvTool;
    QPoint last;
};
