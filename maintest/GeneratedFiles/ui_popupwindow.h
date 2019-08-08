/********************************************************************************
** Form generated from reading UI file 'popupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPWINDOW_H
#define UI_POPUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mypop
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QLabel *action;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label2;
    QLabel *process;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label3;
    QLabel *file;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label4;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radio_allow;
    QRadioButton *radio_refuse;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label5;
    QLabel *time;
    QPushButton *btn_ok;

    void setupUi(QWidget *mypop)
    {
        if (mypop->objectName().isEmpty())
            mypop->setObjectName(QString::fromUtf8("mypop"));
        mypop->resize(398, 342);
        verticalLayout = new QVBoxLayout(mypop);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label1 = new QLabel(mypop);
        label1->setObjectName(QString::fromUtf8("label1"));

        horizontalLayout->addWidget(label1);

        action = new QLabel(mypop);
        action->setObjectName(QString::fromUtf8("action"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(action->sizePolicy().hasHeightForWidth());
        action->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(action);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label2 = new QLabel(mypop);
        label2->setObjectName(QString::fromUtf8("label2"));

        horizontalLayout_2->addWidget(label2);

        process = new QLabel(mypop);
        process->setObjectName(QString::fromUtf8("process"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(process->sizePolicy().hasHeightForWidth());
        process->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(process);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label3 = new QLabel(mypop);
        label3->setObjectName(QString::fromUtf8("label3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label3->sizePolicy().hasHeightForWidth());
        label3->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label3);

        file = new QLabel(mypop);
        file->setObjectName(QString::fromUtf8("file"));
        sizePolicy1.setHeightForWidth(file->sizePolicy().hasHeightForWidth());
        file->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(file);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label4 = new QLabel(mypop);
        label4->setObjectName(QString::fromUtf8("label4"));

        horizontalLayout_4->addWidget(label4);

        textBrowser = new QTextBrowser(mypop);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setAcceptDrops(false);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setReadOnly(true);

        horizontalLayout_4->addWidget(textBrowser);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        radio_allow = new QRadioButton(mypop);
        radio_allow->setObjectName(QString::fromUtf8("radio_allow"));
        radio_allow->setChecked(true);

        horizontalLayout_5->addWidget(radio_allow);

        radio_refuse = new QRadioButton(mypop);
        radio_refuse->setObjectName(QString::fromUtf8("radio_refuse"));

        horizontalLayout_5->addWidget(radio_refuse);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label5 = new QLabel(mypop);
        label5->setObjectName(QString::fromUtf8("label5"));

        horizontalLayout_6->addWidget(label5);

        time = new QLabel(mypop);
        time->setObjectName(QString::fromUtf8("time"));

        horizontalLayout_6->addWidget(time);

        btn_ok = new QPushButton(mypop);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));

        horizontalLayout_6->addWidget(btn_ok);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(mypop);

        QMetaObject::connectSlotsByName(mypop);
    } // setupUi

    void retranslateUi(QWidget *mypop)
    {
        mypop->setWindowTitle(QCoreApplication::translate("mypop", "0", nullptr));
        label1->setText(QCoreApplication::translate("mypop", "\345\212\250\344\275\234:", nullptr));
        action->setText(QCoreApplication::translate("mypop", "TextLabel", nullptr));
        label2->setText(QCoreApplication::translate("mypop", "\350\277\233\347\250\213:", nullptr));
        process->setText(QCoreApplication::translate("mypop", "TextLabel", nullptr));
        label3->setText(QCoreApplication::translate("mypop", "\346\226\207\344\273\266:", nullptr));
        file->setText(QCoreApplication::translate("mypop", "TextLabel", nullptr));
        label4->setText(QCoreApplication::translate("mypop", "\350\257\246\347\273\206:", nullptr));
        radio_allow->setText(QCoreApplication::translate("mypop", "\345\205\201\350\256\270", nullptr));
        radio_refuse->setText(QCoreApplication::translate("mypop", "\346\213\222\347\273\235", nullptr));
        label5->setText(QCoreApplication::translate("mypop", "\346\227\266\351\227\264:", nullptr));
        time->setText(QCoreApplication::translate("mypop", "TextLabel", nullptr));
        btn_ok->setText(QCoreApplication::translate("mypop", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mypop: public Ui_mypop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPWINDOW_H
