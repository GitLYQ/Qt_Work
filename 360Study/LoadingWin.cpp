#include "LoadingWin.h"
#include <QLayout>
#include "Util.h"

LoadingWin::LoadingWin(QWidget *parent) :
    QWidget(parent)
{
    initUI();

    m_timer = new QTimer(this);
    m_timer->setInterval(100);
    //connect(timer, &QTimer::timeout, this, &LoadingWidget::updatePixmap);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotUpdatePixmap()));

    translateLanguage();
}



void LoadingWin::initUI()
{
    m_nIndex = 1;
    m_imageLab      = new QLabel;
    m_userIdLab     = new QLabel;
    m_waitInfoLab   = new QLabel;

    QPixmap pixmap(QString(":/loginDialog/") + QString::number(m_nIndex, 10));
    m_imageLab->setPixmap(pixmap);
    m_imageLab->setFixedSize(pixmap.size());
    m_imageLab->setScaledContents(true);

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addWidget(m_userIdLab);
    vLay->addWidget(m_waitInfoLab);
    vLay->setSpacing(15);
    vLay->setContentsMargins(0, 0, 0, 0);


    QHBoxLayout *hMainLay = new QHBoxLayout;
    hMainLay->addStretch();
    hMainLay->addWidget(m_imageLab);
    hMainLay->addLayout(vLay);
    hMainLay->addStretch();
    hMainLay->setSpacing(20);
    hMainLay->setContentsMargins(0, 0, 0, 30);

    this->setLayout(hMainLay);
}

void LoadingWin::translateLanguage()
{
    m_waitInfoLab->setText(tr("waiting"));
}

void LoadingWin::start(bool is_start)
{
    if ( true == is_start )
    {
        //进行账号的转化，防止过长显示不全，过长用...代替
        QString elided_text;
        bool is_elided = Util::updateText(m_strUserID, 200, elided_text);
        if(!is_elided)
        {
            elided_text = m_strUserID;
        }

        m_userIdLab->setText(tr("hi") + QString("   ") + elided_text);
        m_timer->start();
    }
    else
    {
        m_timer->stop();
        m_nIndex = 1;
        QPixmap pixmap(QString(":/loginDialog/") + QString::number(m_nIndex, 10));
        m_imageLab->setPixmap(pixmap);
    }
}

void LoadingWin::setUserId(QString strUserId)
{
    m_strUserID = strUserId;
}



void LoadingWin::slotUpdatePixmap()
{
    m_nIndex++;
    if ( m_nIndex > 8 )
    {
        m_nIndex = 1;
    }

    QPixmap pixmap(QString(":/loginDialog/") + QString::number(m_nIndex, 10));
    m_imageLab->setPixmap(pixmap);
}

