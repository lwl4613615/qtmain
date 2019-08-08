#pragma once
#include "ui_popupwindow.h"
#include <QDialog>
class PopWindow :
	public QDialog
{
	Q_OBJECT
public:
	PopWindow(int option, wchar_t* ProcessPath, wchar_t* FilePath, wchar_t* RenamePath = nullptr , QWidget* parent = Q_NULLPTR);
public:
	bool getResult();
private slots:
	void showTimelimit();
	void ButtonClick();
private:
	Ui::mypop ui;
	int timesecond = 30;
	bool refuse = false;
};

