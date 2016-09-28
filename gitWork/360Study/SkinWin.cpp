#include "SkinWin.h"

#include "Util.h"

#include <QPainter>
#include <QSignalMapper>
#include <QPushButton>

SkinWin::SkinWin(QWidget *parent) :
    DropShadowWin(parent)
{
    this->resize(620, 445);

    m_skinName      = QString("");
    m_bIsSkinChange = false;
    m_currentPage   = 1;

    initTitle();
    initCenter();
    initBottom();

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addLayout(m_titleLay);
    main_layout->addLayout(m_centerLay);
    main_layout->addLayout(m_bottomLay);
    main_layout->addStretch();
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

    setLayout(main_layout);

    translateLanguage();

    this->slotShowSkin("first");

}

void SkinWin::paintEvent(QPaintEvent *event)
{
    DropShadowWin::paintEvent(event);

    if ( m_skinName.isEmpty() )
    {
        m_skinName = Util::getSkinName();
    }
    int height = 35;
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(m_skinName));
    painter.drawRect(QRect(SHADOW_WIDTH, height, this->width()-2*SHADOW_WIDTH, this->height()-height-SHADOW_WIDTH));
}


void SkinWin::translateLanguage()
{
    m_titleContentLab->setText(tr("title"));
    m_closeBtn->setToolTip(tr("close"));

    m_firstPageBtn->setText(tr("first page"));
    m_previousPageBtn->setText(tr("previous page"));
    m_nextPageBtn->setText(tr("next page"));
    m_lastPageBtn->setText(tr("last page"));

    m_skinNameTipList<<tr("profound life")<<tr("blue sea")<<tr("red heart")<<tr("lovely baby")<<tr("transparent water")<<
        tr("flower")<<tr("great sunshine")<<tr("shadow amazement")<<tr("life in blossom")<<tr("360 pet")<<
        tr("beautiful stone")<<tr("yellow energy")<<tr("magic world")<<tr("intense emotion")<<tr("dream sky")<<
        tr("angry bird")<<tr("graceful jazz")<<tr("card")<<tr("summer cool")<<tr("blue world")<<
        tr("woodwind")<<tr("pink mood")<<tr("across time")<<tr("six year");
}

void SkinWin::initTitle()
{
    m_titleContentLab = new QLabel();
    m_titleIconLab = new QLabel();
    m_closeBtn = new MyPushButton();

    QPixmap title_pixmap(":/img/safe");
    m_titleIconLab->setPixmap(title_pixmap);
    m_titleIconLab->setFixedSize(16, 16);
    m_titleIconLab->setScaledContents(true);

    m_closeBtn->setPicName(":/sysButton/close");
    m_titleContentLab->setFixedHeight(30);

    m_titleLay = new QHBoxLayout();
    m_titleLay->addWidget(m_titleIconLab, 0, Qt::AlignVCenter);
    m_titleLay->addWidget(m_titleContentLab, 0, Qt::AlignVCenter);
    m_titleLay->addStretch();
    m_titleLay->addWidget(m_closeBtn, 0, Qt::AlignTop);
    m_titleLay->setSpacing(5);
    m_titleLay->setContentsMargins(10, 0, 5, 0);

    m_titleContentLab->setObjectName("whiteLabel");
    connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(hide()));
}

void SkinWin::initCenter()
{
    m_centerLay = new QGridLayout;
    m_centerLay->setSpacing(5);
    m_centerLay->setContentsMargins(5, 35, 5, 0);

    m_skinPathList <<":/skin/0"<<":/skin/1"<<":/skin/2"<<":/skin/3"<<":/skin/4"
                   <<":/skin/5"<<":/skin/6"<<":/skin/7"<<":/skin/8"<<":/skin/9"
                   <<":/skin/10"<<":/skin/11"<<":/skin/12"<<":/skin/13"<<":/skin/14"
                   <<":/skin/15"<<":/skin/16"<<":/skin/17"<<":/skin/18"<<":/skin/19"
                   <<":/skin/20"<<":/skin/21"<<":/skin/22"<<":/skin/23";

    for( int i=0; i < 8; i++)
    {
        SkinItemWin *skinItem = new SkinItemWin();
        connect(skinItem,SIGNAL(sigChangeSkin()),this,SLOT(slotChangeSkin()));
        m_centerLay->addWidget(skinItem,i/4,i%4);
        m_skinItemList.append(skinItem);

    }

    int skin_list_count = m_skinPathList.size();
    m_totalPageCount = skin_list_count / 8;
    m_lastPageCount  = skin_list_count % 8;
    if(m_lastPageCount > 0)
    {
        m_totalPageCount = m_totalPageCount + 1;
    }

}

void SkinWin::initBottom()
{

    m_firstPageBtn      = new QPushButton();
    m_previousPageBtn   = new QPushButton();
    m_nextPageBtn       = new QPushButton();
    m_lastPageBtn       = new QPushButton();
    m_firstPageBtn->setFixedWidth(50);
    m_previousPageBtn->setFixedWidth(50);
    m_nextPageBtn->setFixedWidth(50);
    m_lastPageBtn->setFixedWidth(50);
    m_firstPageBtn->setCursor(Qt::PointingHandCursor);
    m_previousPageBtn->setCursor(Qt::PointingHandCursor);
    m_nextPageBtn->setCursor(Qt::PointingHandCursor);
    m_lastPageBtn->setCursor(Qt::PointingHandCursor);
    m_firstPageBtn->setObjectName("blueButton");
    m_previousPageBtn->setObjectName("blueButton");
    m_nextPageBtn->setObjectName("blueButton");
    m_lastPageBtn->setObjectName("blueButton");

    QSignalMapper *signal_mapper = new QSignalMapper(this);

    connect(m_firstPageBtn, SIGNAL(clicked()), signal_mapper, SLOT(map()));
    connect(m_previousPageBtn, SIGNAL(clicked()), signal_mapper, SLOT(map()));
    connect(m_nextPageBtn, SIGNAL(clicked()), signal_mapper, SLOT(map()));
    connect(m_lastPageBtn, SIGNAL(clicked()), signal_mapper, SLOT(map()));
    signal_mapper->setMapping(m_firstPageBtn, "first");
    signal_mapper->setMapping(m_previousPageBtn, "previous");
    signal_mapper->setMapping(m_nextPageBtn, "next");
    signal_mapper->setMapping(m_lastPageBtn, "last");
    connect(signal_mapper, SIGNAL(mapped(QString)), this, SLOT(slotShowSkin(QString)));

    for( int i = 0; i < m_totalPageCount; i++)
    {
        QPushButton * pageTmpBtn = new QPushButton();
        pageTmpBtn->setFixedWidth(20);
        pageTmpBtn->setText(QString::number(i+1, 10));
        pageTmpBtn->setObjectName("blueButton");
        pageTmpBtn->setCursor(Qt::PointingHandCursor);
        connect(pageTmpBtn, SIGNAL(clicked()), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(pageTmpBtn, QString::number(i+1, 10));
        m_pageBtnList.push_back(pageTmpBtn);
    }

    m_bottomLay = new QHBoxLayout;
    m_bottomLay->addStretch();
    m_bottomLay->addWidget(m_firstPageBtn);
    m_bottomLay->addWidget(m_previousPageBtn);
    for( int i = 0; i < m_pageBtnList.count(); i++)
    {
        QPushButton * pageTmpBtn = m_pageBtnList.at(i);
        m_bottomLay->addWidget(pageTmpBtn);
    }
    m_bottomLay->addWidget(m_nextPageBtn);
    m_bottomLay->addWidget(m_lastPageBtn);
    m_bottomLay->addStretch();
    m_bottomLay->setSpacing(2);
    m_bottomLay->setContentsMargins(0, 10, 0, 0);

}

void SkinWin::slotChangeSkin()
{
    QObject *object = QObject::sender();
    SkinItemWin *skinItem = qobject_cast<SkinItemWin *>(object);
    QString skin_name = skinItem->getPixmapName();

    m_skinName = skin_name;
    m_bIsSkinChange = true;
    update();
    emit sigChangeSkin(m_skinName);

}

void SkinWin::slotShowSkin(QString strPageBtnText)
{
    if ( strPageBtnText == "first" )
    {
        m_currentPage = 1;
    }
    else if ( strPageBtnText == "previous" )
    {
        if ( m_currentPage > 1 )
        {
            m_currentPage--;
        }
    }
    else if ( strPageBtnText == "next" )
    {
        if ( m_currentPage < m_totalPageCount )
        {
            m_currentPage++;
        }
    }
    else if(strPageBtnText == "last")
    {
        m_currentPage = m_totalPageCount;
    }
    else
    {
        bool ok;
        m_currentPage = strPageBtnText.toInt(&ok, 10);
    }

    if ( m_currentPage == 1 )
    {
        m_firstPageBtn->hide();
        m_previousPageBtn->hide();
        m_nextPageBtn->show();
        m_lastPageBtn->show();
    }
    else if ( m_currentPage == m_totalPageCount )
    {
        m_firstPageBtn->show();
        m_previousPageBtn->show();
        m_nextPageBtn->hide();
        m_lastPageBtn->hide();
    }
    else
    {
        m_firstPageBtn->hide();
        m_previousPageBtn->show();
        m_nextPageBtn->show();
        m_lastPageBtn->hide();
    }

    //第一页为0-7 显示至previous_total_page个
    int previous_total_page = (m_currentPage - 1)*8;
    int tip_index = previous_total_page;

    for(int i=0; i<m_skinItemList.count(); i++)
    {
        m_skinItemList.at(i)->slotChangeSkin(":/skin/"+ QString::number(previous_total_page++, 10), m_skinNameTipList.at(tip_index++), "11");
    }


}
