/********************************************************************************
** Form generated from reading UI file 'RegisterWin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIN_H
#define UI_REGISTERWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWin
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_close;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_icon;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_register;
    QLabel *label_privilege;
    QWidget *widget2;
    QGridLayout *gridLayout;
    QLabel *label_confirm;
    QLineEdit *lineEdit_emali;
    QLabel *label_email;
    QLabel *label_password;
    QLabel *label_tip_email;
    QLabel *label_tip_password;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_confirm;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_remember;
    QCheckBox *checkBox_auto_login;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_accout;
    QPushButton *pushButton_login;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_reginster;

    void setupUi(QWidget *RegisterWin)
    {
        if (RegisterWin->objectName().isEmpty())
            RegisterWin->setObjectName(QString::fromUtf8("RegisterWin"));
        RegisterWin->resize(373, 285);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegisterWin->sizePolicy().hasHeightForWidth());
        RegisterWin->setSizePolicy(sizePolicy);
        widget = new QWidget(RegisterWin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 3, 361, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 5, 0);
        label_title = new QLabel(widget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        sizePolicy.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_close = new QPushButton(widget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image: url(:/sysButton/close);\n"
"border-width: 0px;\n"
"border-color: none;\n"
"border-style: none;\n"
"padding: 0px;\n"
"padding-left: 0px;\n"
"padding-right: 0px;\n"
"}\n"
"QPushButton:hover{\n"
"background-image: url(:/sysButton/close_hover);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-image: url(:/sysButton/close_pressed);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sysButton/close"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon);
        pushButton_close->setIconSize(QSize(27, 22));

        horizontalLayout->addWidget(pushButton_close);

        widget1 = new QWidget(RegisterWin);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(11, 40, 361, 72));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(30, 0, 20, 0);
        label_icon = new QLabel(widget1);
        label_icon->setObjectName(QString::fromUtf8("label_icon"));
        sizePolicy.setHeightForWidth(label_icon->sizePolicy().hasHeightForWidth());
        label_icon->setSizePolicy(sizePolicy);
        label_icon->setMinimumSize(QSize(70, 70));
        label_icon->setMaximumSize(QSize(70, 70));
        label_icon->setPixmap(QPixmap(QString::fromUtf8(":/img/360safe")));
        label_icon->setScaledContents(true);

        horizontalLayout_2->addWidget(label_icon);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_register = new QLabel(widget1);
        label_register->setObjectName(QString::fromUtf8("label_register"));
        QFont font;
        font.setPointSize(14);
        label_register->setFont(font);
        label_register->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout->addWidget(label_register);

        label_privilege = new QLabel(widget1);
        label_privilege->setObjectName(QString::fromUtf8("label_privilege"));
        label_privilege->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        verticalLayout->addWidget(label_privilege);


        horizontalLayout_2->addLayout(verticalLayout);

        widget2 = new QWidget(RegisterWin);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(11, 110, 361, 141));
        gridLayout = new QGridLayout(widget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 10, 10, 10);
        label_confirm = new QLabel(widget2);
        label_confirm->setObjectName(QString::fromUtf8("label_confirm"));
        label_confirm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_confirm, 2, 0, 1, 1);

        lineEdit_emali = new QLineEdit(widget2);
        lineEdit_emali->setObjectName(QString::fromUtf8("lineEdit_emali"));
        lineEdit_emali->setMinimumSize(QSize(25, 0));
        lineEdit_emali->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(lineEdit_emali, 0, 1, 1, 1);

        label_email = new QLabel(widget2);
        label_email->setObjectName(QString::fromUtf8("label_email"));
        label_email->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_email, 0, 0, 1, 1);

        label_password = new QLabel(widget2);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_password, 1, 0, 1, 1);

        label_tip_email = new QLabel(widget2);
        label_tip_email->setObjectName(QString::fromUtf8("label_tip_email"));

        gridLayout->addWidget(label_tip_email, 0, 2, 1, 1);

        label_tip_password = new QLabel(widget2);
        label_tip_password->setObjectName(QString::fromUtf8("label_tip_password"));

        gridLayout->addWidget(label_tip_password, 1, 2, 1, 1);

        lineEdit_password = new QLineEdit(widget2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setMinimumSize(QSize(25, 0));
        lineEdit_password->setMaximumSize(QSize(16777215, 25));
        lineEdit_password->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(lineEdit_password, 1, 1, 1, 1);

        lineEdit_confirm = new QLineEdit(widget2);
        lineEdit_confirm->setObjectName(QString::fromUtf8("lineEdit_confirm"));
        lineEdit_confirm->setMinimumSize(QSize(25, 0));
        lineEdit_confirm->setMaximumSize(QSize(16777215, 25));
        lineEdit_confirm->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(lineEdit_confirm, 2, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox_remember = new QCheckBox(widget2);
        checkBox_remember->setObjectName(QString::fromUtf8("checkBox_remember"));

        horizontalLayout_4->addWidget(checkBox_remember);

        checkBox_auto_login = new QCheckBox(widget2);
        checkBox_auto_login->setObjectName(QString::fromUtf8("checkBox_auto_login"));

        horizontalLayout_4->addWidget(checkBox_auto_login);


        gridLayout->addLayout(horizontalLayout_4, 3, 1, 1, 1);

        widget3 = new QWidget(RegisterWin);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(11, 250, 361, 27));
        horizontalLayout_3 = new QHBoxLayout(widget3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, 0, 10, 0);
        label_accout = new QLabel(widget3);
        label_accout->setObjectName(QString::fromUtf8("label_accout"));

        horizontalLayout_3->addWidget(label_accout);

        pushButton_login = new QPushButton(widget3);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout_3->addWidget(pushButton_login);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_reginster = new QPushButton(widget3);
        pushButton_reginster->setObjectName(QString::fromUtf8("pushButton_reginster"));
        pushButton_reginster->setMinimumSize(QSize(60, 25));
        pushButton_reginster->setMaximumSize(QSize(60, 25));

        horizontalLayout_3->addWidget(pushButton_reginster);


        retranslateUi(RegisterWin);

        QMetaObject::connectSlotsByName(RegisterWin);
    } // setupUi

    void retranslateUi(QWidget *RegisterWin)
    {
        RegisterWin->setWindowTitle(QApplication::translate("RegisterWin", "Form", 0, QApplication::UnicodeUTF8));
        label_title->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QString());
        label_icon->setText(QString());
        label_register->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_privilege->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_confirm->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_email->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_password->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_tip_email->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_tip_password->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        checkBox_remember->setText(QApplication::translate("RegisterWin", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_auto_login->setText(QApplication::translate("RegisterWin", "CheckBox", 0, QApplication::UnicodeUTF8));
        label_accout->setText(QApplication::translate("RegisterWin", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_login->setText(QApplication::translate("RegisterWin", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_reginster->setText(QApplication::translate("RegisterWin", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegisterWin: public Ui_RegisterWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIN_H
