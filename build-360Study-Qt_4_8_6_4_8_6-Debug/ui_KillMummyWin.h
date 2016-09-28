/********************************************************************************
** Form generated from reading UI file 'KillMummyWin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KILLMUMMYWIN_H
#define UI_KILLMUMMYWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KillMummyWin
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_main;
    QHBoxLayout *horizontalLayout_lab;
    QLabel *label_icon;
    QVBoxLayout *verticalLayout;
    QLabel *lab_info;
    QLabel *lab_suggest;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_btn;
    QToolButton *toolButton_fastScan;
    QToolButton *toolButton_fullScan;
    QToolButton *toolButton_customScan;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *KillMummyWin)
    {
        if (KillMummyWin->objectName().isEmpty())
            KillMummyWin->setObjectName(QString::fromUtf8("KillMummyWin"));
        KillMummyWin->resize(668, 457);
        widget = new QWidget(KillMummyWin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 70, 601, 371));
        verticalLayout_main = new QVBoxLayout(widget);
        verticalLayout_main->setSpacing(0);
        verticalLayout_main->setObjectName(QString::fromUtf8("verticalLayout_main"));
        verticalLayout_main->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_lab = new QHBoxLayout();
        horizontalLayout_lab->setSpacing(10);
        horizontalLayout_lab->setObjectName(QString::fromUtf8("horizontalLayout_lab"));
        horizontalLayout_lab->setContentsMargins(20, 20, -1, -1);
        label_icon = new QLabel(widget);
        label_icon->setObjectName(QString::fromUtf8("label_icon"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_icon->sizePolicy().hasHeightForWidth());
        label_icon->setSizePolicy(sizePolicy);
        label_icon->setMinimumSize(QSize(44, 45));
        label_icon->setMaximumSize(QSize(44, 45));
        label_icon->setPixmap(QPixmap(QString::fromUtf8(":/killMummyWidget/tip")));
        label_icon->setScaledContents(true);

        horizontalLayout_lab->addWidget(label_icon);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lab_info = new QLabel(widget);
        lab_info->setObjectName(QString::fromUtf8("lab_info"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lab_info->setFont(font);

        verticalLayout->addWidget(lab_info);

        lab_suggest = new QLabel(widget);
        lab_suggest->setObjectName(QString::fromUtf8("lab_suggest"));

        verticalLayout->addWidget(lab_suggest);


        horizontalLayout_lab->addLayout(verticalLayout);


        verticalLayout_main->addLayout(horizontalLayout_lab);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_main->addItem(verticalSpacer);

        horizontalLayout_btn = new QHBoxLayout();
        horizontalLayout_btn->setSpacing(0);
        horizontalLayout_btn->setObjectName(QString::fromUtf8("horizontalLayout_btn"));
        toolButton_fastScan = new QToolButton(widget);
        toolButton_fastScan->setObjectName(QString::fromUtf8("toolButton_fastScan"));
        sizePolicy.setHeightForWidth(toolButton_fastScan->sizePolicy().hasHeightForWidth());
        toolButton_fastScan->setSizePolicy(sizePolicy);
        toolButton_fastScan->setMinimumSize(QSize(148, 140));
        toolButton_fastScan->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/killMummyWidget/fast_scan"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_fastScan->setIcon(icon);
        toolButton_fastScan->setIconSize(QSize(123, 115));
        toolButton_fastScan->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_btn->addWidget(toolButton_fastScan);

        toolButton_fullScan = new QToolButton(widget);
        toolButton_fullScan->setObjectName(QString::fromUtf8("toolButton_fullScan"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(148);
        sizePolicy1.setVerticalStretch(140);
        sizePolicy1.setHeightForWidth(toolButton_fullScan->sizePolicy().hasHeightForWidth());
        toolButton_fullScan->setSizePolicy(sizePolicy1);
        toolButton_fullScan->setMinimumSize(QSize(148, 140));
        toolButton_fullScan->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/killMummyWidget/full_scan"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_fullScan->setIcon(icon1);
        toolButton_fullScan->setIconSize(QSize(101, 91));
        toolButton_fullScan->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_btn->addWidget(toolButton_fullScan);

        toolButton_customScan = new QToolButton(widget);
        toolButton_customScan->setObjectName(QString::fromUtf8("toolButton_customScan"));
        toolButton_customScan->setMinimumSize(QSize(148, 140));
        toolButton_customScan->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/killMummyWidget/custom_scan"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_customScan->setIcon(icon2);
        toolButton_customScan->setIconSize(QSize(101, 96));
        toolButton_customScan->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_btn->addWidget(toolButton_customScan);


        verticalLayout_main->addLayout(horizontalLayout_btn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_main->addItem(verticalSpacer_2);


        retranslateUi(KillMummyWin);

        QMetaObject::connectSlotsByName(KillMummyWin);
    } // setupUi

    void retranslateUi(QWidget *KillMummyWin)
    {
        KillMummyWin->setWindowTitle(QApplication::translate("KillMummyWin", "Form", 0, QApplication::UnicodeUTF8));
        label_icon->setText(QString());
        lab_info->setText(QApplication::translate("KillMummyWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        lab_suggest->setText(QApplication::translate("KillMummyWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        toolButton_fastScan->setText(QApplication::translate("KillMummyWin", "...", 0, QApplication::UnicodeUTF8));
        toolButton_fullScan->setText(QApplication::translate("KillMummyWin", "...", 0, QApplication::UnicodeUTF8));
        toolButton_customScan->setText(QApplication::translate("KillMummyWin", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KillMummyWin: public Ui_KillMummyWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KILLMUMMYWIN_H
