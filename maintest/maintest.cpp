#include "stdafx.h"
#include "maintest.h"
#include <fltuser.h>
#include "Header.h"

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
	connect(ui.m_btnAddFolderPath, &QPushButton::clicked, this, &maintest::AddFileFilterPathButtonClick);
    connect(ui.m_btnRemoveFolderPath, &QPushButton::clicked, this, &maintest::RemoveFileFilterPathButtonClick);
	
    //工具栏的事件绑定
    connect(ui.m_btnClose, &QPushButton::clicked, this, [=]() {
        this->close();
        });
    connect(ui.m_btnMin, &QPushButton::clicked, this, [=]
        {
		  this->showMinimized();		
        });
    connect(ui.m_btnMenu, &QPushButton::clicked, this, [=] {\
        QMessageBox::about(NULL, QString::fromLocal8Bit("菜单点击"), QString::fromLocal8Bit("尽情期待哦！"));
        });


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
			filterThread = new QThread();
			obj=new FileFilterThread();
			obj->moveToThread(filterThread);
			connect(filterThread, &QThread::started, obj, &FileFilterThread::StartFilter);
			filterThread->start();
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

void maintest::AddFileFilterPathButtonClick()
{
	DWORD bytesReturned = 0;
	DWORD hResult = 0;
	SCANNER_RECV message = {};
	QString file_path = QFileDialog::getExistingDirectory(this, "请选择文件路径...", "./");
	if (!file_path.isEmpty())
	{
       
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(file_path);                     //设置列表项的文本
        ui.MyFilterPathList->addItem(item);          //加载列表项到列表框          
		file_path.replace("/", "\\");
		message.option = 1;
		wchar_t m[260];
		QueryDosDevice((LPCWSTR)(file_path.left(2).utf16()), m, 260);
		file_path.replace(0, 2, QString::fromWCharArray(m));
		file_path += "\\*.*";
		wchar_t* Path = (wchar_t*)(file_path.utf16());
		wcscpy_s(message.path, 260, Path);
		message.ul_PathLength = file_path.length();
		hResult = FilterSendMessage(obj->RetPort(), &message, sizeof(message), NULL, NULL, &bytesReturned);

	}
	return;
}

void maintest::RemoveFileFilterPathButtonClick()
{
    DWORD bytesReturned = 0;
    DWORD hResult = 0;
    //定义消息结构
    SCANNER_RECV message = {0};
    //表明是进行移除列表的操作
    message.option = 2;    
    //开始构造字符串

    QListWidgetItem* item = ui.MyFilterPathList->takeItem(ui.MyFilterPathList->currentRow());
    if (item==nullptr)
    {
        return;
    }
    QString temp= item->text();
    temp.replace("/", "\\");
    wchar_t m[260];
    QueryDosDevice((LPCWSTR)(temp.left(2).utf16()), m, 260);
    temp.replace(0, 2, QString::fromWCharArray(m));
    temp += "\\*.*";
    wchar_t* Path = (wchar_t*)(temp.utf16());
    wcscpy_s(message.path, 260, Path);
    message.ul_PathLength = temp.length();
    hResult = FilterSendMessage(obj->RetPort(), &message, sizeof(message), NULL, NULL, &bytesReturned);

    delete item;        //释放指针所指向的列表项
}

void maintest::mousePressEvent(QMouseEvent* e)
{
    if (e->pos().rx() > 1000 || e->pos().ry() > 500)
        return;
    last = e->globalPos();
}

//鼠标移动
void maintest::mouseMoveEvent(QMouseEvent* e)
{
    if (e->pos().rx() > 1000 || e->pos().ry() > 500)
        return;
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x() + dx, y() + dy);
}

//鼠标释放
void maintest::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->pos().rx() > 1000 || e->pos().ry() > 500)
        return;
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x() + dx, y() + dy);
}