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
}

void maintest::paintEvent(QPaintEvent* event)
{

	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(0, 0, width(), height(), QPixmap(":/Background/main"));  // 设置主窗体的背景图片
}
