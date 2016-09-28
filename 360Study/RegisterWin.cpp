#include "RegisterWin.h"
#include "ui_RegisterWin.h"

#include <QPainter>
#include <QLayout>
#include "DropShadowWin.h"
#include "Common.h"
#include "Util.h"

RegisterWin::RegisterWin(QWidget *parent) :
    DropShadowWin(parent),
    ui(new Ui::RegisterWin)
{
    ui->setupUi(this);

    ui->label_title->setObjectName("whiteLabel");
    ui->label_register->setObjectName("whiteLabel");
    ui->label_privilege->setObjectName("whiteLabel");

    ui->label_tip_email->setObjectName("grayLabel");
    ui->label_tip_password->setObjectName("grayLabel");

    ui->pushButton_login->setObjectName("examineAuthorizeButton");
    ui->pushButton_reginster->setObjectName("loginGreenButton");


//    QVBoxLayout *vMain = new QVBoxLayout;
//    vMain->addLayout(ui->horizontalLayout);
//    vMain->addLayout(ui->horizontalLayout_2);
//    vMain->addLayout(ui->gridLayout);
//    vMain->addLayout(ui->horizontalLayout_3);
//    vMain->setContentsMargins(5,5,5,5);

//    this->setLayout(vMain);
    this->setModal(true);

    translateLanguage();

    connect(ui->pushButton_close,SIGNAL(clicked()),this,SLOT(hide()));
}

RegisterWin::~RegisterWin()
{
    delete ui;
}

void RegisterWin::translateLanguage()
{
    ui->label_title->setText(tr("360 register"));
    ui->pushButton_close->setToolTip(tr("close"));
    ui->label_register->setText(tr("register 360 safe account"));
    ui->label_privilege->setText(tr("privilege"));
    ui->label_email->setText(tr("email"));
    ui->label_password->setText(tr("password"));
    ui->label_confirm->setText(tr("confirm password"));
    ui->label_tip_email->setText(tr("forgot password"));
    ui->label_tip_password->setText(tr("6-20 bytes"));
    ui->checkBox_remember->setText(tr("remember password"));
    ui->checkBox_auto_login->setText(tr("auto login"));
    ui->label_accout->setText(tr("account"));
    ui->pushButton_login->setText(tr("login"));
    ui->pushButton_reginster->setText(tr("register"));
}



void RegisterWin::paintEvent(QPaintEvent *event)
{
    DropShadowWin::paintEvent(event);
    QString skin_name = Util::getSkinName();
    int height = 95;
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(skin_name));
    painter.drawRect(QRect(SHADOW_WIDTH, height, this->width()-2*SHADOW_WIDTH, this->height()-height-SHADOW_WIDTH));
}
