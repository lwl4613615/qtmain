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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
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
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *page_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *maintestClass)
    {
        if (maintestClass->objectName().isEmpty())
            maintestClass->setObjectName(QString::fromUtf8("maintestClass"));
        maintestClass->resize(703, 543);
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

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget);

        maintestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(maintestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        maintestClass->setStatusBar(statusBar);

        retranslateUi(maintestClass);

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
    } // retranslateUi

};

namespace Ui {
    class maintestClass: public Ui_maintestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTEST_H
