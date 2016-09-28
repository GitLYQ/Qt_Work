#include "MainWidget.h"

#include <QIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QPalette>
#include <QDebug>

#include "Common.h"
#include "Util.h"

MainWidget::MainWidget(QWidget *parent)
    : DropShadowWin(parent)
{
    this->setMinimumSize(900,600);
    setWindowIcon(QIcon(":/img/safe"));
    m_enLanguage = UI_ZH;

    m_titleWidget       = new TitleWidget();
    m_contentWin        = new ContentWin();
    m_killMummyWin      = new KillMummyWin();
    //m_killMummyWin    = new KillMummyWidget();

    m_systemTray        = new MySystemTray(this);
    m_aboutUsWin        = new AboutUsWin(this);
    m_mainMenu          = new MainMenu(this);
    m_registerWin       = new RegisterWin(this);
    m_loginWin          = new LoginWin(this);
    m_newCharacterWin   = new NewCharacterWin();
    m_settingWin        = new SettingWin(this);
    m_skinWin           = new SkinWin(this);

    m_stackedWin  = new QStackedWidget();
    m_stackedWin->addWidget(m_contentWin);
    m_stackedWin->addWidget(m_killMummyWin);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(Qt::white));
    m_stackedWin->setPalette(palette);
    m_stackedWin->setAutoFillBackground(true);

    QVBoxLayout *centerVlay = new QVBoxLayout;
    centerVlay->addWidget(m_stackedWin);
    centerVlay->setSpacing(0);
    centerVlay->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *mainHLay = new QVBoxLayout;
    mainHLay->addWidget(m_titleWidget);
    mainHLay->addLayout(centerVlay);
    mainHLay->setSpacing(0);
    mainHLay->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

    setLayout(mainHLay);

    //标题栏
    connect(m_titleWidget,SIGNAL(sigTurnPage(int)),this,SLOT(slotTurnPage(int)));
    connect(m_titleWidget,SIGNAL(sigShowMin()),this,SLOT(slotHideMainWin()));
    connect(m_titleWidget,SIGNAL(sigCloseWidget()),this,SLOT(slotCloseMainWin()));
    connect(m_titleWidget,SIGNAL(sigShowMainMenu()),this,SLOT(slotShowMainMenu()));
    connect(m_titleWidget,SIGNAL(sigShowSkin()),this,SLOT(slotShowSkinWin()));

    //标题栏-设置菜单栏
    connect(m_mainMenu,SIGNAL(sigShowAboutUs()),this,SLOT(slotShowAboutUs()));
    connect(m_mainMenu,SIGNAL(sigShowNewCharacter()),this,SLOT(slotShowNewCharacter()));
    connect(m_mainMenu,SIGNAL(sigShowSettingDialog()),this,SLOT(slotShowSettingDialog()));

    //系统托盘图标
    connect(m_systemTray,SIGNAL(sigShowWidget()),this,SLOT(slotShowWidget()));
    connect(m_systemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(slotSysemTrayIconIsActived(QSystemTrayIcon::ActivationReason)));
    m_systemTray->show();

    //标题栏-设置菜单栏-设置
    connect(m_settingWin, SIGNAL(sigChangeLanguage(LANGUAGE)), this, SLOT(slotChangeLanguage(LANGUAGE)));

     //标题栏-皮肤中心
    connect(m_skinWin,SIGNAL(sigChangeSkin(QString)),this,SLOT(slotChangeSkin(QString)));

    //电脑体检界面
    connect(m_contentWin,SIGNAL(sigLoginBtnClicked()),this,SLOT(slotShowLoginWin()));
    connect(m_contentWin,SIGNAL(sigRegisterBtnClicked()),this,SLOT(slotShowRegisterWin()));


    slotTurnPage(0);
    m_strBackPicName = Util::getSkinName();
    if (m_strBackPicName.isEmpty() )
    {
        m_strBackPicName = DEFAULT_SKIN;
    }
}

MainWidget::~MainWidget()
{

}


void MainWidget::paintEvent(QPaintEvent *event)
{
    DropShadowWin::paintEvent(event);

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(m_strBackPicName));

    QWidget::paintEvent(event);
}




void MainWidget::slotTurnPage(int nCurrentIndex)
{
    if ( 0 == nCurrentIndex )
    {
        m_stackedWin->setCurrentWidget(m_contentWin);
    }
    else if ( 1 == nCurrentIndex )
    {
        m_stackedWin->setCurrentWidget(m_killMummyWin);
    }

}

void MainWidget::slotCloseMainWin()
{
    //qDebug( ) << "slotCloseMainWin";
    this->close();
}

void MainWidget::slotHideMainWin()
{
    //qDebug( ) << "slotHideMainWin";
    this->hide();
}

void MainWidget::slotShowMainMenu()
{
    QPoint point = this->rect().topRight();
    point.setX( point.x() - 120);
    point.setY( point.y() + 25);
    m_mainMenu->exec(this->mapToGlobal(point));
}

void MainWidget::slotShowSkinWin()
{
    m_skinWin->exec();
}

void MainWidget::slotShowSettingDialog()
{
    m_settingWin->exec();
}

void MainWidget::slotShowAboutUs()
{
    qDebug() << "slotShowAboutUs";
    m_aboutUsWin->exec();
}

void MainWidget::slotShowNewCharacter()
{
    m_newCharacterWin->show();
}


void MainWidget::slotShowWidget()
{
    this->showNormal();
    this->raise();
    this->activateWindow();
}

void MainWidget::slotSysemTrayIconIsActived(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        //点击托盘图标之后松开
    case QSystemTrayIcon::Trigger:
        {
            slotShowWidget();
            break;
        }
        //双击托盘图标
    case QSystemTrayIcon::DoubleClick:
        {
            slotShowWidget();
            break;
        }
    default:
        break;
    }
}


void MainWidget::slotShowLoginWin()
{
    m_loginWin->exec();
}

void MainWidget::slotShowRegisterWin()
{
    m_registerWin->show();
}

void MainWidget::setTranslator(QTranslator* translator)
{
    m_translator = translator;
}


void MainWidget::slotChangeLanguage(LANGUAGE language)
{
    if(m_enLanguage == language)
    {
        return;
    }
    m_enLanguage = language;

    switch(language)
    {
    case UI_EN:
        m_translator->load(QString(":/qm/360safe_en"));
        break;

    case UI_ZH:
        m_translator->load(QString(":/qm/360safe_zh"));
        break;

    default:
        m_translator->load(QString(":/qm/360safe_zh"));
    }

    m_titleWidget->translateLanguage();
    m_contentWin->translateLanguage();
    m_killMummyWin->translateLanguage();
    m_mainMenu->translateActions();
    m_newCharacterWin->translateLanguage();
    m_loginWin->translateLanguage();
    m_registerWin->translateLanguage();
    m_aboutUsWin->translateLanguage();
    m_settingWin->translateLanguage();
    m_skinWin->translateLanguage();
    m_systemTray->translateLanguage();
}

void MainWidget::slotChangeSkin(QString skin_name)
{
    Util::writeInit(QString("./user.ini"), QString("skin"), skin_name);
    this->m_strBackPicName = skin_name;
    update();
}
