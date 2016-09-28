#include "KillMummyWin.h"
#include "ui_KillMummyWin.h"

KillMummyWin::KillMummyWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KillMummyWin)
{
    ui->setupUi(this);


    ui->lab_info->setObjectName("grayLabel");
    ui->lab_suggest->setObjectName("grayLabel");
    ui->toolButton_fastScan->setObjectName("grayToolButton");
    ui->toolButton_fullScan->setObjectName("grayToolButton");
    ui->toolButton_customScan->setObjectName("grayToolButton");


    this->setLayout(ui->verticalLayout_main);

    translateLanguage();
}

KillMummyWin::~KillMummyWin()
{
    delete ui;
}

void KillMummyWin::translateLanguage()
{
    ui->lab_info->setText(tr("the last scanning") + QString::number(3, 10) + tr("no threat found"));
    ui->lab_suggest->setText(tr("regular scanning"));
    ui->toolButton_fastScan->setText(tr("fast scan"));
    ui->toolButton_fullScan->setText(tr("full scan"));
    ui->toolButton_customScan->setText(tr("custom scan"));
}
