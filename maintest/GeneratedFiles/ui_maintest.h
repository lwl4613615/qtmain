/********************************************************************************
** Form generated from reading UI file 'maintest.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTEST_H
#define UI_MAINTEST_H

#include <CustomPushButton.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_maintestClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *m_nWindowsTitle;
    CustomPushButton *m_btnMenu;
    CustomPushButton *m_btnMin;
    CustomPushButton *m_btnClose;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *m_btnhips;
    QToolButton *m_btntest1;
    QToolButton *m_btntest2;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *MainStackWidget;
    QWidget *FilterWidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *m_btnFileFilter;
    QPushButton *m_btnNetFilter;
    QStackedWidget *HipsStackWindow;
    QWidget *FileFilter;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_btnStartFileFilter;
    QPushButton *m_AddFolderPath;
    QPushButton *m_btnRemoveFolderPath;
    QPushButton *m_btnStopFileFilter;
    QListView *m_FolderTable;
    QWidget *NetFilter;
    QWidget *test1;
    QLabel *label_2;
    QWidget *test2;
    QLabel *label_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *maintestClass)
    {
        if (maintestClass->objectName().isEmpty())
            maintestClass->setObjectName(QString::fromUtf8("maintestClass"));
        maintestClass->resize(711, 543);
        centralWidget = new QWidget(maintestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        m_nWindowsTitle = new QLabel(frame);
        m_nWindowsTitle->setObjectName(QString::fromUtf8("m_nWindowsTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        m_nWindowsTitle->setFont(font);
        m_nWindowsTitle->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 127)"));

        horizontalLayout->addWidget(m_nWindowsTitle);

        m_btnMenu = new CustomPushButton(frame);
        m_btnMenu->setObjectName(QString::fromUtf8("m_btnMenu"));
        m_btnMenu->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(m_btnMenu);

        m_btnMin = new CustomPushButton(frame);
        m_btnMin->setObjectName(QString::fromUtf8("m_btnMin"));

        horizontalLayout->addWidget(m_btnMin);

        m_btnClose = new CustomPushButton(frame);
        m_btnClose->setObjectName(QString::fromUtf8("m_btnClose"));

        horizontalLayout->addWidget(m_btnClose);


        verticalLayout->addWidget(frame);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        m_btnhips = new QToolButton(widget);
        m_btnhips->setObjectName(QString::fromUtf8("m_btnhips"));
        m_btnhips->setFocusPolicy(Qt::StrongFocus);
        m_btnhips->setContextMenuPolicy(Qt::DefaultContextMenu);
        m_btnhips->setStyleSheet(QString::fromUtf8("color: rgb(48, 255, 34);\n"
"background: transparent;"));
        m_btnhips->setPopupMode(QToolButton::DelayedPopup);
        m_btnhips->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_btnhips->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(m_btnhips);

        m_btntest1 = new QToolButton(widget);
        m_btntest1->setObjectName(QString::fromUtf8("m_btntest1"));
        m_btntest1->setStyleSheet(QString::fromUtf8("color: rgb(48, 255, 34);\n"
"background: transparent;"));
        m_btntest1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(m_btntest1);

        m_btntest2 = new QToolButton(widget);
        m_btntest2->setObjectName(QString::fromUtf8("m_btntest2"));
        m_btntest2->setStyleSheet(QString::fromUtf8("color: rgb(48, 255, 34);\n"
"background: transparent;"));
        m_btntest2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(m_btntest2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        MainStackWidget = new QStackedWidget(centralWidget);
        MainStackWidget->setObjectName(QString::fromUtf8("MainStackWidget"));
        FilterWidget = new QWidget();
        FilterWidget->setObjectName(QString::fromUtf8("FilterWidget"));
        horizontalLayout_3 = new QHBoxLayout(FilterWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(FilterWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("color:rgb(248, 220, 255)"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_btnFileFilter = new QPushButton(groupBox);
        m_btnFileFilter->setObjectName(QString::fromUtf8("m_btnFileFilter"));
        m_btnFileFilter->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(m_btnFileFilter);

        m_btnNetFilter = new QPushButton(groupBox);
        m_btnNetFilter->setObjectName(QString::fromUtf8("m_btnNetFilter"));
        m_btnNetFilter->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(m_btnNetFilter);


        horizontalLayout_3->addWidget(groupBox);

        HipsStackWindow = new QStackedWidget(FilterWidget);
        HipsStackWindow->setObjectName(QString::fromUtf8("HipsStackWindow"));
        FileFilter = new QWidget();
        FileFilter->setObjectName(QString::fromUtf8("FileFilter"));
        verticalLayout_3 = new QVBoxLayout(FileFilter);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_2 = new QWidget(FileFilter);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_btnStartFileFilter = new QPushButton(widget_2);
        m_btnStartFileFilter->setObjectName(QString::fromUtf8("m_btnStartFileFilter"));

        horizontalLayout_4->addWidget(m_btnStartFileFilter);

        m_AddFolderPath = new QPushButton(widget_2);
        m_AddFolderPath->setObjectName(QString::fromUtf8("m_AddFolderPath"));

        horizontalLayout_4->addWidget(m_AddFolderPath);

        m_btnRemoveFolderPath = new QPushButton(widget_2);
        m_btnRemoveFolderPath->setObjectName(QString::fromUtf8("m_btnRemoveFolderPath"));

        horizontalLayout_4->addWidget(m_btnRemoveFolderPath);

        m_btnStopFileFilter = new QPushButton(widget_2);
        m_btnStopFileFilter->setObjectName(QString::fromUtf8("m_btnStopFileFilter"));

        horizontalLayout_4->addWidget(m_btnStopFileFilter);


        verticalLayout_3->addWidget(widget_2);

        m_FolderTable = new QListView(FileFilter);
        m_FolderTable->setObjectName(QString::fromUtf8("m_FolderTable"));

        verticalLayout_3->addWidget(m_FolderTable);

        HipsStackWindow->addWidget(FileFilter);
        NetFilter = new QWidget();
        NetFilter->setObjectName(QString::fromUtf8("NetFilter"));
        HipsStackWindow->addWidget(NetFilter);

        horizontalLayout_3->addWidget(HipsStackWindow);

        MainStackWidget->addWidget(FilterWidget);
        test1 = new QWidget();
        test1->setObjectName(QString::fromUtf8("test1"));
        label_2 = new QLabel(test1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 220, 72, 15));
        MainStackWidget->addWidget(test1);
        test2 = new QWidget();
        test2->setObjectName(QString::fromUtf8("test2"));
        label_3 = new QLabel(test2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 270, 72, 15));
        MainStackWidget->addWidget(test2);

        verticalLayout->addWidget(MainStackWidget);

        maintestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(maintestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("color:rgb(240, 255, 250)"));
        maintestClass->setStatusBar(statusBar);

        retranslateUi(maintestClass);

        HipsStackWindow->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(maintestClass);
    } // setupUi

    void retranslateUi(QMainWindow *maintestClass)
    {
        maintestClass->setWindowTitle(QCoreApplication::translate("maintestClass", "maintest", nullptr));
        m_nWindowsTitle->setText(QCoreApplication::translate("maintestClass", "LWL's Hips Demo 1.0", nullptr));
        m_btnMenu->setText(QString());
        m_btnMin->setText(QString());
        m_btnClose->setText(QString());
        m_btnhips->setText(QCoreApplication::translate("maintestClass", "\344\270\273\345\212\250\351\230\262\345\276\241", nullptr));
        m_btntest1->setText(QCoreApplication::translate("maintestClass", "\346\265\213\350\257\2251", nullptr));
        m_btntest2->setText(QCoreApplication::translate("maintestClass", "\346\265\213\350\257\2252", nullptr));
        groupBox->setTitle(QCoreApplication::translate("maintestClass", "\345\212\237\350\203\275\345\214\272", nullptr));
        m_btnFileFilter->setText(QCoreApplication::translate("maintestClass", "FileFilter", nullptr));
        m_btnNetFilter->setText(QCoreApplication::translate("maintestClass", "NetFilter", nullptr));
        m_btnStartFileFilter->setText(QCoreApplication::translate("maintestClass", "StartFileFilter", nullptr));
        m_AddFolderPath->setText(QCoreApplication::translate("maintestClass", "AddFolderPath", nullptr));
        m_btnRemoveFolderPath->setText(QCoreApplication::translate("maintestClass", "RemoveFolderPath", nullptr));
        m_btnStopFileFilter->setText(QCoreApplication::translate("maintestClass", "StopFileFilter", nullptr));
        label_2->setText(QCoreApplication::translate("maintestClass", "\351\241\265\351\235\2422", nullptr));
        label_3->setText(QCoreApplication::translate("maintestClass", "\351\241\265\351\235\2423 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class maintestClass: public Ui_maintestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTEST_H
