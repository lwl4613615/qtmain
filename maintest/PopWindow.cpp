#include "stdafx.h"
#include "PopWindow.h"

PopWindow::PopWindow(int option, wchar_t* ProcessPath, wchar_t* FilePath, wchar_t* RenamePath /*= nullptr */, QWidget* parent /*= Q_NULLPTR*/):QDialog(parent)
{
	ui.setupUi(this);
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(showTimelimit()));
	connect(ui.btn_ok, &QPushButton::clicked, this, &PopWindow::ButtonClick);
	timer->start(1000);
	ui.time->setText("30");
	this->setWindowTitle(QString::fromLocal8Bit("发现违法行为!"));
	//
	switch (option)
	{
		//创建文件的时候
	case 1:
		ui.action->setText(QString::fromLocal8Bit("创建文件操作"));
		ui.process->setText(QString::fromWCharArray(ProcessPath));
		ui.file->setText(QString::fromWCharArray(FilePath));
		ui.textBrowser->setText("Create File");
		break;
		//重命名文件的时候
	case 2:
		ui.action->setText(QString::fromLocal8Bit("重命名文件操作"));
		ui.process->setText(QString::fromWCharArray(ProcessPath));
		ui.file->setText(QString::fromWCharArray(FilePath));
		
		break;
		//删除文件的时候
	case 3:
		ui.action->setText(QString::fromLocal8Bit("删除文件操作"));
		ui.process->setText(QString::fromWCharArray(ProcessPath));
		ui.file->setText(QString::fromWCharArray(FilePath));
		ui.textBrowser->setText("Delete File");
		break;
	default:
		break;
	}
}

bool PopWindow::getResult()
{
	return refuse;
}

void PopWindow::showTimelimit()
{
	if (timesecond != 1)
	{
		timesecond = timesecond - 1; //注意字符类型
		QString num = QString::number(timesecond);
		ui.time->setText(num);
	}
	else
	{
		this->close();
	}
}

void PopWindow::ButtonClick()
{
	if(ui.radio_allow->isChecked())
{
		
		refuse = false;
		this->close();
	}
	else
	{
		refuse = true;
		this->close();
	}
}
