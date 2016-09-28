#include "MySystemTray.h"

#include <QLayout>
#include <QApplication>
#include <QPainter>

MySystemTray::MySystemTray(QWidget *parent) :
    QSystemTrayIcon(parent)
{
    m_mainMenu = new QMenu();

    initTopWidgetAction();
    initMiddleAction();
    initBottomWidgetAction();
    initMenu();

    translateLanguage();
}

void MySystemTray::translateLanguage()
{
    //放在托盘图标上时候显示
    this->setToolTip(tr("360 safe"));

    m_topWidget_infoLab->setText(tr("protect") + QString::number(3, 10) + tr("day"));
    m_topWidget_openBtn->setText(tr("firewall start"));
    m_topWidget_enterBtn->setText(tr("enter"));

    m_bottomWidget_gameBtn->setText(tr("game mode"));
    m_bottomWidget_buyBtn->setText(tr("online mode"));

    m_actionOpen->setText(tr("open"));
    m_actionHelpCenter->setText(tr("help center"));
    m_actionKillMummy->setText(tr("kill mummy"));
    m_actionClear->setText(tr("clear"));
    m_actionOptimize->setText(tr("optimize"));
    m_actionFireproof->setText(tr("fireproof"));
    m_actionShowSpeed->setText(tr("show speed"));
    m_actionSoftManage->setText(tr("soft manage"));
    m_actionSafeNotice->setText(tr("safe notice"));
    m_actionRise->setText(tr("rise"));
    m_action_login->setText(tr("login"));
    m_action_separate->setText(tr("separate"));
    m_action_logout->setText(tr("logout"));
}


void MySystemTray::initTopWidgetAction()
{
    m_topWidget = new QWidget();
    m_topWidget_openBtn = new QPushButton();
    m_topWidget_enterBtn = new QPushButton();
    m_topWidget_infoLab = new QLabel();
    m_topWidgetAction = new QWidgetAction(m_mainMenu);

    m_topWidget_openBtn->setObjectName("trayButton");
    m_topWidget_enterBtn->setObjectName("trayButton");
    m_topWidget_openBtn->setCursor(Qt::PointingHandCursor);
    m_topWidget_enterBtn->setCursor(Qt::PointingHandCursor);

    m_topWidget_infoLab->setObjectName("whiteLabel");

    QHBoxLayout *hLay = new QHBoxLayout;
    hLay->addWidget(m_topWidget_openBtn);
    hLay->addStretch();
    hLay->addWidget(m_topWidget_enterBtn);
    hLay->setSpacing(0);
    hLay->setContentsMargins(0,0,0,0);

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addWidget(m_topWidget_infoLab);
    vLay->addLayout(hLay);
    vLay->setSpacing(10);
    vLay->setContentsMargins(10, 5, 10, 5);

    m_topWidget->setLayout(vLay);

    m_topWidgetAction->setDefaultWidget(m_topWidget);

    m_topWidget->installEventFilter(this);
}

void MySystemTray::initMiddleAction()
{
    m_actionOpen = new QAction(this);          //打开360安全卫士
    m_actionHelpCenter = new QAction(this);    //求助中心
    m_actionKillMummy = new QAction(this);     //查杀木马
    m_actionClear = new QAction(this);         //清理垃圾
    m_actionOptimize = new QAction(this);      //一键优化
    m_actionFireproof = new QAction(this);     //检查更新
    m_actionShowSpeed = new QAction(this);     //显示加速球
    m_actionSoftManage = new QAction(this);    //软件管家
    m_actionSafeNotice = new QAction(this);    //安全通知
    m_actionRise = new QAction(this);          //升级
    m_action_login = new QAction(this);        //360用户登录
    m_action_separate = new QAction(this);     //隔离沙箱
    m_action_logout = new QAction(this);       //退出


}

void MySystemTray::initBottomWidgetAction()
{
    m_bottomWidget = new QWidget();
    m_bottomWidget_gameBtn = new QPushButton();
    m_bottomWidget_buyBtn = new QPushButton();
    m_bottomWidgetAction = new QWidgetAction(m_mainMenu);

    m_bottomWidget_gameBtn->setObjectName("trayButton");
    m_bottomWidget_buyBtn->setObjectName("trayButton");
    m_bottomWidget_gameBtn->setCursor(Qt::PointingHandCursor);
    m_bottomWidget_buyBtn->setCursor(Qt::PointingHandCursor);

    QHBoxLayout *hLay = new QHBoxLayout;
    hLay->addWidget(m_bottomWidget_gameBtn);
    hLay->addStretch();
    hLay->addWidget(m_bottomWidget_buyBtn);
    hLay->setSpacing(0);
    hLay->setContentsMargins(10, 5, 10, 5);

    m_bottomWidget->setLayout(hLay);

    m_bottomWidgetAction->setDefaultWidget(m_bottomWidget);

    m_bottomWidget->installEventFilter(this);
}

void MySystemTray::initMenu()
{

    m_mainMenu->addAction(m_topWidgetAction);
    m_mainMenu->addAction(m_actionOpen);
    m_mainMenu->addAction(m_actionHelpCenter);
    m_mainMenu->addSeparator();
    m_mainMenu->addAction(m_actionKillMummy);
    m_mainMenu->addAction(m_actionClear);
    m_mainMenu->addSeparator();
    m_mainMenu->addAction(m_actionOptimize);
    m_mainMenu->addAction(m_actionFireproof);
    m_mainMenu->addAction(m_actionShowSpeed);
    m_mainMenu->addAction(m_actionSoftManage);
    m_mainMenu->addSeparator();
    m_mainMenu->addAction(m_actionSafeNotice);
    m_mainMenu->addAction(m_actionRise);
    m_mainMenu->addAction(m_action_separate);
    m_mainMenu->addSeparator();
    m_mainMenu->addAction(m_action_login);
    m_mainMenu->addAction(m_action_logout);
    m_mainMenu->addAction(m_bottomWidgetAction);


    connect(m_actionOpen,SIGNAL(triggered()),this,SIGNAL(sigShowWidget()));
    connect(m_action_logout,SIGNAL(triggered()),qApp,SLOT(quit()));

    m_mainMenu->setFixedWidth(250);
    this->setIcon(QIcon(":/img/safe"));
    this->setContextMenu(m_mainMenu);
}

bool MySystemTray::eventFilter(QObject *obj, QEvent *event)
{
    if ( (obj == m_topWidget) || ( obj == m_bottomWidget ) )
    {
        if ( event->type() == QEvent::Paint )
        {
            QPainter painter1(m_topWidget);
            painter1.setPen(Qt::NoPen);
            painter1.setBrush(QColor(70, 180, 20));
            painter1.drawRect(m_topWidget->rect());

            QPainter painter2(m_bottomWidget);
            painter2.setPen(Qt::NoPen);
            painter2.setBrush(QColor(70, 180, 20));
            painter2.drawRect(m_bottomWidget->rect());

        }
    }
}
