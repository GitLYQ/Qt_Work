#include "TitleWidget.h"

#include <QVBoxLayout>
#include <QSignalMapper>
#include <QDebug>

TitleWidget::TitleWidget(QWidget *parent) :
    QWidget(parent)
{

    initFirstRow();
    initSecondRow();

    m_mainVLay = new QVBoxLayout();
    m_mainVLay->addLayout(m_firstRowHLay);
    m_mainVLay->addLayout(m_secondRowHLay);
    m_mainVLay->setSpacing(0);
    m_mainVLay->setContentsMargins(0, 0, 0, 0);
    setLayout(m_mainVLay);

    translateLanguage();

    setFixedHeight(120);
}


void TitleWidget::initFirstRow()
{
    m_versionTitle = new QLabel();
    m_versionTitle->setObjectName("whiteLabel");

    m_dedalBtn      = new MyPushButton();
    m_skinBtn       = new MyPushButton();        //换肤
    m_mainMenuBtn   = new MyPushButton();        //主菜单
    m_feedBackBtn   = new MyPushButton();        //反馈意见
    m_minBtn        = new MyPushButton();        //最小化
    m_closeBtn      = new MyPushButton();        //关闭

    m_dedalBtn->setPicName(QString(":/sysButton/medal"));
    m_skinBtn->setPicName(QString(":/sysButton/skin"));
    m_mainMenuBtn->setPicName(QString(":/sysButton/menu"));
    m_feedBackBtn->setPicName(QString(":/sysButton/feedback"));
    m_minBtn->setPicName(QString(":/sysButton/min"));
    m_closeBtn->setPicName(QString(":/sysButton/close"));

    m_firstRowHLay = new QHBoxLayout();

    m_firstRowHLay->addWidget(m_versionTitle,0,Qt::AlignVCenter);
    m_firstRowHLay->addStretch();
    m_firstRowHLay->addWidget(m_dedalBtn,0,Qt::AlignTop);
    m_firstRowHLay->addWidget(m_skinBtn,0,Qt::AlignTop);
    m_firstRowHLay->addWidget(m_mainMenuBtn,0,Qt::AlignTop);
    m_firstRowHLay->addWidget(m_feedBackBtn,0,Qt::AlignTop);
    m_firstRowHLay->addWidget(m_minBtn,0,Qt::AlignTop);
    m_firstRowHLay->addWidget(m_closeBtn,0,Qt::AlignTop);
    m_firstRowHLay->setSpacing(0);
    m_firstRowHLay->setContentsMargins(0,0,5,0);

    connect(m_skinBtn,SIGNAL(clicked()),this,SIGNAL(sigShowSkin()));
    connect(m_mainMenuBtn,SIGNAL(clicked()),this,SIGNAL(sigShowMainMenu()));
    connect(m_minBtn,SIGNAL(clicked()),this,SIGNAL(sigShowMin()));
    connect(m_closeBtn,SIGNAL(clicked()),this,SLOT(slotCloseBtnClicked()));
}


void TitleWidget::initSecondRow()
{
    m_360Lab = new QLabel();
    m_safeLab = new QLabel();
    m_360Lab->setObjectName("whiteLabel");
    m_safeLab->setObjectName("whiteLabel");
    m_360Lab->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    m_safeLab->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QFont font360Lab = m_360Lab->font();
    font360Lab.setBold(true);
    font360Lab.setPointSize(18);
    m_360Lab->setFont(font360Lab);
    QFont fontSafeLab = m_safeLab->font();
    fontSafeLab.setBold(true);
    fontSafeLab.setPointSize(14);
    m_safeLab->setFont(fontSafeLab);

    QVBoxLayout *safe360VLay =  new QVBoxLayout();
    safe360VLay->addWidget(m_360Lab);
    safe360VLay->addWidget(m_safeLab);
    safe360VLay->setSpacing(5);
    safe360VLay->setContentsMargins(0,0,0,0);

    m_logoLab = new QLabel();
    QPixmap pix(":/img/safe");
    m_logoLab->setPixmap(pix);
    m_logoLab->setFixedSize(pix.size());

    m_secondRowHLay = new QHBoxLayout();
    QStringList string_list;
    string_list <<":/toolWidget/tiJian"
                <<":/toolWidget/muMa"
                <<":/toolWidget/repair"
                <<":/toolWidget/qingLi"
                <<":/toolWidget/jiaSu"
                <<":/toolWidget/expert"
                <<":/toolWidget/menZhen"
                <<":/toolWidget/gongNeng";

    QSignalMapper *signalMapper = new QSignalMapper(this);
    for (int i=0; i < string_list.size(); i++)
    {
        MyToolButton *newToolBtn = new MyToolButton(string_list.at(i));
        m_listToolBtn.append(newToolBtn);
        m_secondRowHLay->addWidget(newToolBtn);

        connect(newToolBtn,SIGNAL(clicked()),signalMapper,SLOT(map()));
        signalMapper->setMapping(newToolBtn,QString::number(i,10));
    }
    connect(signalMapper,SIGNAL(mapped(QString)),this,SLOT(slotTurnPage(QString)));

    m_secondRowHLay->addStretch();
    m_secondRowHLay->addLayout(safe360VLay);
    m_secondRowHLay->addWidget(m_logoLab);
    m_secondRowHLay->setSpacing(8);
    m_secondRowHLay->setContentsMargins(15, 0, 15, 0);
}


void TitleWidget::translateLanguage()
{
    m_versionTitle->setText(tr("title") + QString("9.2"));
    m_skinBtn->setToolTip(tr("change skin"));
    m_mainMenuBtn->setToolTip(tr("main menu"));
    m_minBtn->setToolTip(tr("minimize"));
    m_feedBackBtn->setToolTip(tr("feedback"));
    m_closeBtn->setToolTip(tr("close"));

    m_listToolBtn.at(0)->setText(tr("power"));
    m_listToolBtn.at(1)->setText(tr("mummy"));
    m_listToolBtn.at(2)->setText(tr("repair"));
    m_listToolBtn.at(3)->setText(tr("clear"));
    m_listToolBtn.at(4)->setText(tr("optimize"));
    m_listToolBtn.at(5)->setText(tr("expert"));
    m_listToolBtn.at(6)->setText(tr("hole"));
    m_listToolBtn.at(7)->setText(tr("software"));

    m_360Lab->setText(tr("360"));
    m_safeLab->setText(tr("safe"));
}

void TitleWidget::slotTurnPage(QString currentPage )
{
    bool ok;
    int nCurrentIndex = currentPage.toInt(&ok,10);

    for(int i = 0; i < m_listToolBtn.size(); i++)
    {
        MyToolButton *toolBtn = m_listToolBtn.at(i);
        if ( i == nCurrentIndex )
        {
            toolBtn->setMousePress(true);
        }
        else
        {
            toolBtn->setMousePress(false);
        }
    }

    emit sigTurnPage(nCurrentIndex);
}


void TitleWidget::slotCloseBtnClicked()
{
    //qDebug() << "slotCloseBtnClicked";
    emit sigCloseWidget();
}
