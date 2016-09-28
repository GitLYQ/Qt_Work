#include "MsgBoxWin.h"
#include <QLayout>
#include <QPainter>

#include "Common.h"
#include "Util.h"

MsgBoxWin::MsgBoxWin(QWidget *parent) :
    DropShadowWin(parent)
{
    initUI();


    translateLanguage();
}


void MsgBoxWin::initUI()
{
    this->resize(280,160);
    m_titleInfolab      = new QLabel;
    m_titleImageLab     = new QLabel;
    m_contentInfoLab    = new QLabel;
    m_contentImageLab   = new QLabel;
    m_closeBtn          = new MyPushButton;
    m_okBtn             = new QPushButton;
    m_cancleBtn         = new QPushButton;

    QPixmap pix(":/img/safe");
    m_titleImageLab->setPixmap(pix);
    m_titleImageLab->setFixedSize(16,16);
    m_titleImageLab->setScaledContents(true);

    m_titleInfolab->setFixedHeight(30);
    m_titleInfolab->setStyleSheet("color:white;");

    m_closeBtn->setPicName(":/sysButton/close");

    QHBoxLayout *hLay1 = new QHBoxLayout;
    hLay1->addWidget(m_titleImageLab);
    hLay1->addWidget(m_titleInfolab);
    hLay1->addStretch();
    hLay1->addWidget(m_closeBtn,0,Qt::AlignTop);
    hLay1->setSpacing(5);
    hLay1->setContentsMargins(10, 0, 5, 20);

    m_contentImageLab->setFixedSize(45,45);
    m_contentImageLab->setScaledContents(true);
    m_contentInfoLab->setWordWrap(true);

    QHBoxLayout *hLay2 = new QHBoxLayout;
    hLay2->addWidget(m_contentImageLab);
    hLay2->addWidget(m_contentInfoLab);
    hLay2->setSpacing(10);
    hLay2->setContentsMargins(15, 0, 15, 0);

    m_okBtn->setFixedSize(60,25);
    m_okBtn->setObjectName("loginGreenButton");
    m_cancleBtn->setFixedSize(60,25);
    m_cancleBtn->setObjectName("loginGreenButton");

    QHBoxLayout *hLay3 = new QHBoxLayout;
    hLay3->addStretch();
    hLay3->addWidget(m_okBtn);
    hLay3->addWidget(m_cancleBtn);
    hLay3->setSpacing(10);
    hLay3->setContentsMargins(0, 0, 10, 10);


    QVBoxLayout *vMainLay= new QVBoxLayout;
    vMainLay->addLayout(hLay1);
    vMainLay->addStretch();
    vMainLay->addLayout(hLay2);
    vMainLay->addStretch();
    vMainLay->addLayout(hLay3);
    vMainLay->setSpacing(0);
    vMainLay->setContentsMargins(SHADOW_WIDTH,SHADOW_WIDTH,SHADOW_WIDTH,SHADOW_WIDTH);

    this->setLayout(vMainLay);

    connect(m_okBtn,SIGNAL(clicked()),this,SLOT(slotOkBtnclicked()));
    connect(m_cancleBtn,SIGNAL(clicked()),this,SLOT(slotCancleBtnclicked()));
    connect(m_closeBtn,SIGNAL(clicked()),this,SLOT(slotCancleBtnclicked()));

}

void MsgBoxWin::paintEvent(QPaintEvent *event)
{
    DropShadowWin::paintEvent(event);

    int nheight = 35;
    QString strSkinName = Util::getSkinName();
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);

    painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH),QPixmap(strSkinName));
    painter.drawRect(QRect(SHADOW_WIDTH,nheight,this->width()-2*SHADOW_WIDTH,this->height()-nheight-SHADOW_WIDTH));

}




void MsgBoxWin::setInfo(QString titleInfo, QString strInfo, QPixmap pixmap, bool bIsOkBtnHidden)
{
    m_titleInfolab->setText(titleInfo);
    m_contentInfoLab->setText(strInfo);
    m_contentImageLab->setPixmap(pixmap);

    //是否隐藏确定按钮
    m_okBtn->setHidden(bIsOkBtnHidden);
    if(bIsOkBtnHidden)
    {
        m_cancleBtn->setText(m_strOk);
    }
    else
    {
        m_okBtn->setText(m_strOk);
        m_cancleBtn->setText(m_strCancle);
    }
}


void MsgBoxWin::translateLanguage()
{
    m_closeBtn->setToolTip(tr("close"));
    m_strOk = tr("ok");
    m_strCancle = tr("cancle");
}


void MsgBoxWin::slotOkBtnclicked()
{
    this->accept();
}

void MsgBoxWin::slotCancleBtnclicked()
{
    this->reject();
}
