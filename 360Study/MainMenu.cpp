#include "MainMenu.h"

#include "Common.h"
#include <QUrl>
#include <QDesktopServices>


MainMenu::MainMenu(QWidget *parent) :
    QMenu(parent)
{
    createActions();
    translateActions();


    this->setObjectName("menu");
}



void MainMenu::createActions()
{

    m_actionAboutUs         = new QAction(this);
    m_actionChangeCompany   = new QAction(this);
    m_actionCheckUpdate     = new QAction(this);
    m_actionHelpOnline      = new QAction(this);
    m_actionLoginHome       = new QAction(this);
    m_actionNewCharacter    = new QAction(this);
    m_actionPlatformHelp    = new QAction(this);
    m_actionProtect         = new QAction(this);
    m_actionSetting         = new QAction(this);

    //添加菜单项
    this->addAction(m_actionSetting);
    this->addAction(m_actionNewCharacter);
    this->addAction(m_actionCheckUpdate);
    this->addAction(m_actionChangeCompany);
    this->addSeparator();
    this->addAction(m_actionHelpOnline);
    this->addAction(m_actionPlatformHelp);
    this->addAction(m_actionLoginHome);
    this->addAction(m_actionProtect);
    this->addAction(m_actionAboutUs);

    m_actionHelpOnline->setObjectName(QString::number(HELP_ONLINE, 10));
    m_actionPlatformHelp->setObjectName(QString::number(PLATFORM_HELP, 10));
    m_actionLoginHome->setObjectName(QString::number(LOGIN_HOME, 10));
    m_actionProtect->setObjectName(QString::number(PROTECT, 10));

    //设置信号连接
    connect(m_actionSetting, SIGNAL(triggered()), this, SIGNAL(sigShowSettingDialog()));
    connect(m_actionNewCharacter, SIGNAL(triggered()), this, SIGNAL(sigShowNewCharacter()));
    connect(m_actionAboutUs, SIGNAL(triggered()), this, SIGNAL(sigShowAboutUs()));
    connect(m_actionHelpOnline, SIGNAL(triggered()), this, SLOT(slotShowUrlPage()));
    connect(m_actionPlatformHelp, SIGNAL(triggered()), this, SLOT(slotShowUrlPage()));
    connect(m_actionLoginHome, SIGNAL(triggered()), this, SLOT(slotShowUrlPage()));
    connect(m_actionProtect, SIGNAL(triggered()), this, SLOT(slotShowUrlPage()));
}

void MainMenu::translateActions()
{
    m_actionSetting->setText(tr("setting"));
    m_actionNewCharacter->setText(tr("new character"));
    m_actionCheckUpdate->setText(tr("check update"));
    m_actionChangeCompany->setText(tr("change company"));
    m_actionHelpOnline->setText(tr("help online"));
    m_actionPlatformHelp->setText(tr("platform help"));
    m_actionLoginHome->setText(tr("login home"));
    m_actionProtect->setText(tr("protect"));
    m_actionAboutUs->setText(tr("about us"));
}


void MainMenu::slotShowUrlPage()
{
    QObject *obj = QObject::sender();
    QAction *action = qobject_cast<QAction *>(obj);
    QString strObjectName = action->objectName();
    int nIndex = strObjectName.toInt();
    QString strUrl;
    switch (nIndex)
    {
    case HELP_ONLINE:
        strUrl = QString("http://bbs.360.cn/cms/guide.html");
        break;
    case PLATFORM_HELP:
        strUrl = QString("http://bbs.360safe.com/forum.php?mod=forumdisplay&fid=100");
        break;
    case LOGIN_HOME:
        strUrl = QString("http://www.360.cn/");
        break;
    case PROTECT:
        strUrl = QString("http://www.360.cn/privacy/v2/index.html");
        break;
    default:
        break;
    }

    QUrl url(strUrl);
    QDesktopServices::openUrl(url);

}
