#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_maintest.h"

class maintest : public QMainWindow
{
	Q_OBJECT

public:
	maintest(QWidget *parent = Q_NULLPTR);
protected:
	void paintEvent(QPaintEvent* event);
private:
	Ui::maintestClass ui;
};
