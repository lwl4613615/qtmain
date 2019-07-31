#include "stdafx.h"
#include "maintest.h"

maintest::maintest(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	setFixedSize(1024, 768);
	setWindowFlags(Qt::FramelessWindowHint);
	ui.m_btnMenu->setBtnBackground(QStringLiteral(":/SysButtons/menu"));   // 设置按钮的背景图片，下同
	ui.m_btnMenu->setToolTip(QStringLiteral("Settings"));                  // 设置文本提示，下同
	ui.m_btnMin->setBtnBackground(QStringLiteral(":/SysButtons/min"));
	ui.m_btnMin->setToolTip(QStringLiteral("Minimize"));
	ui.m_btnClose->setBtnBackground(QStringLiteral(":/SysButtons/close"));
	ui.m_btnClose->setToolTip(QStringLiteral("Close"));	
	ui.m_btnhips->setIcon(QPixmap(":/ToolButtons/hips"));
	ui.m_btnhips->setIconSize(QPixmap(":/ToolButtons/hips").size());
	ui.m_btntest1->setIcon(QPixmap(":/ToolButtons/test1"));
	ui.m_btntest1->setIconSize(QPixmap(":/ToolButtons/test1").size());
	ui.m_btntest2->setIcon(QPixmap(":/ToolButtons/test2"));
	ui.m_btntest2->setIconSize(QPixmap(":/ToolButtons/test2").size());
	QLabel* statustext = new QLabel("lwl's gift", this);
	statusBar()->addPermanentWidget(statustext);

	//绑定消息和槽
    //切换页面
    connect(ui.m_btnhips, &QToolButton::clicked, this, [=] {
        ui.MainStackWidget->setCurrentIndex(0);
    });
    connect(ui.m_btntest1, &QToolButton::clicked, this, [=] {
        ui.MainStackWidget->setCurrentIndex(1);
    });
    connect(ui.m_btntest2, &QToolButton::clicked, this, [=] {
        ui.MainStackWidget->setCurrentIndex(2);
    });
    connect(ui.m_btnFileFilter, &QPushButton::clicked, this, [=]
    {
        ui.HipsStackWindow->setCurrentIndex(0);
    });
    connect(ui.m_btnNetFilter, &QPushButton::clicked, this, [=]
    {
        ui.HipsStackWindow->setCurrentIndex(1);
    });
	//开启文件过滤和关闭文件过滤
	connect(ui.m_btnStartFileFilter, &QPushButton::clicked, this, &maintest::StartFileFilterButtonClick);
	connect(ui.m_btnStopFileFilter, &QPushButton::clicked, this, &maintest::StopFileFilterButtonClick);
}

void maintest::paintEvent(QPaintEvent* event)
{

	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(0, 0, width(), height(), QPixmap(":/Background/main"));  // 设置主窗体的背景图片
}

void maintest::StartFileFilterButtonClick()
{
	qDebug() << "Click FileFilterButton!";
	QString SysFilePath = QFileDialog::getOpenFileName(NULL,
		tr("Open Sys File"),
		QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),//"C:\\",指定路径为当前桌面路径
		tr("Driver File(*.sys)"));
	QFileInfo fileinfo(SysFilePath);

	std::string strFilePath = SysFilePath.toStdString();
	std::string strDrvName = fileinfo.baseName().toStdString();
	m_cDrvTool.DeleteDriver(strDrvName.c_str());
	if (m_cDrvTool.InstallDriver(strDrvName.c_str(), strFilePath.c_str(),"370020"))
	{
		if (m_cDrvTool.StartDriver(strDrvName.c_str()))
		{
			QMessageBox::about(NULL, QString::fromLocal8Bit("开启"), QString::fromLocal8Bit("驱动加载成功"));
		}
	}
	return;
}

void maintest::StopFileFilterButtonClick()
{
	m_cDrvTool.StopDriver(m_cDrvTool.GetDriverName());

	if (m_cDrvTool.DeleteDriver(m_cDrvTool.GetDriverName()))
	{
		QMessageBox::about(NULL, QString::fromLocal8Bit("关闭"), QString::fromLocal8Bit("驱动关闭成功"));;
	}
}
