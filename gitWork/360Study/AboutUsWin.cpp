#include "AboutUsWin.h"

#include <QLayout>
#include <QPainter>
#include "Common.h"
#include "Util.h"

AboutUsWin::AboutUsWin(QWidget *parent) :
    DropShadowWin(parent)
{
    this->resize(520, 290);
    initUi();
    translateLanguage();
}

void AboutUsWin::paintEvent(QPaintEvent *event)
{
    DropShadowWin::paintEvent(event);

    QString skin_name = Util::getSkinName();
    int height = 35;
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawPixmap(QRect(2*SHADOW_WIDTH, 2*SHADOW_WIDTH, this->width()-4*SHADOW_WIDTH, this->height()-4*SHADOW_WIDTH), QPixmap(skin_name));
    painter.drawRect(QRect(2*SHADOW_WIDTH, height, this->width()-4*SHADOW_WIDTH, this->height()-height-2*SHADOW_WIDTH));

}


void AboutUsWin::initUi()
{
    m_titleLab      = new QLabel; //标题
    m_titleIconLab  = new QLabel; //标题图标
    m_contentSafeLab= new QLabel; //360安全卫士
    m_contentInfoLab= new QLabel; //杀木马、防盗号、电脑加速
    m_versionLab    = new QLabel; //主程序版本
    m_mummyLab      = new QLabel; //备用木马库
    m_copyrightLab  = new QLabel; //版本信息
    m_iconLab       = new QLabel; //图标
    m_closeBtn      = new MyPushButton; //关闭按钮
    m_okBtn         = new QPushButton; //确定按钮

    m_titleLab->setObjectName("whiteLabel");
    m_titleLab->setFixedHeight(30);


    QPixmap pixmapTitle(":/img/safe");
    m_titleIconLab->setPixmap(pixmapTitle);
    m_titleIconLab->setFixedSize(16,16);
    m_titleIconLab->setScaledContents(true);

    m_closeBtn->setPicName(QString(":/sysButton/close"));

    QHBoxLayout *titleHlay = new QHBoxLayout;
    titleHlay->addWidget(m_titleIconLab,0,Qt::AlignVCenter);
    titleHlay->addWidget(m_titleLab,0,Qt::AlignVCenter);
    titleHlay->addStretch();
    titleHlay->addWidget(m_closeBtn,0,Qt::AlignTop);
    titleHlay->setSpacing(2);
    titleHlay->setContentsMargins(10, 0, 5, 0);


    QPixmap pixmapContent(":/img/360safe");
    m_iconLab->setPixmap(pixmapContent);
    m_iconLab->setFixedSize(pixmapContent.size());

    m_contentSafeLab->setObjectName("infoLabel");
    QFont title_info_font("微软雅黑", 14, QFont::Bold, false);
    m_contentSafeLab->setFont(title_info_font);
    m_copyrightLab->setObjectName("grayLabel");

    m_contentInfoLab->setObjectName("infoLabel");
    QFont info_font = m_contentInfoLab->font();
    info_font.setBold(true);
    m_contentInfoLab->setFont(info_font);


    QVBoxLayout *centerVLay = new QVBoxLayout;
    centerVLay->addWidget(m_contentSafeLab);
    centerVLay->addWidget(m_contentInfoLab);
    centerVLay->addWidget(m_versionLab);
    centerVLay->addWidget(m_mummyLab);
    centerVLay->addWidget(m_copyrightLab);
    centerVLay->addStretch();
    centerVLay->setSpacing(5);
    centerVLay->setContentsMargins(0, 15, 0, 0);
    m_contentInfoLab->setContentsMargins(0, 0, 0, 40);

    QHBoxLayout *h_layout = new QHBoxLayout;
    h_layout->addLayout(centerVLay);
    h_layout->addWidget(m_iconLab);
    h_layout->setSpacing(0);
    h_layout->setContentsMargins(40, 0, 20, 10);

    m_okBtn->setObjectName("okButton");
    m_okBtn->setFixedSize(75, 25);
    QHBoxLayout *bottom_layout = new QHBoxLayout;
    bottom_layout->addStretch();
    bottom_layout->addWidget(m_okBtn);
    bottom_layout->setSpacing(0);
    bottom_layout->setContentsMargins(0, 0, 30, 20);


    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(titleHlay);
    main_layout->addStretch();
    main_layout->addLayout(h_layout);
    main_layout->addLayout(bottom_layout);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(2*SHADOW_WIDTH, 2*SHADOW_WIDTH, 2*SHADOW_WIDTH, 2*SHADOW_WIDTH);

    this->setLayout(main_layout);

    connect(m_closeBtn,SIGNAL(clicked()),this,SLOT(hide()));
    connect(m_okBtn,SIGNAL(clicked()),this,SLOT(hide()));
}

void AboutUsWin::translateLanguage()
{
    m_titleLab->setText(tr("title"));
    m_contentSafeLab->setText(tr("360 safe"));
    m_contentInfoLab->setText(tr("info"));
    m_versionLab->setText(tr("version") + QString("9.2.0.2001"));
    m_mummyLab->setText(tr("mummy") + QString("2013-10-14"));
    m_copyrightLab->setText(tr("copyright"));
    m_closeBtn->setToolTip(tr("close"));
    m_okBtn->setText(tr("ok"));
}


