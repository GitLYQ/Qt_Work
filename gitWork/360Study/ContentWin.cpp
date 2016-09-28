#include "ContentWin.h"

#include <QLayout>
#include <QEvent>
#include <QPainter>

ContentWin::ContentWin(QWidget *parent) :
    QWidget(parent)
{
    QSplitter *m_mainSplitter = new QSplitter();
    m_mainSplitter->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_mainSplitter->setOrientation(Qt::Horizontal);
    m_mainSplitter->setHandleWidth(1);

    QSplitter *m_rightSplitter = new QSplitter();;
    m_rightSplitter->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_rightSplitter->setOrientation(Qt::Vertical);
    m_rightSplitter->setHandleWidth(1);

    initLeftWidget();
    initRightTop();
    initRightCenter();
    initRightCenterFunction();
    initRightBottom();

    m_rightSplitter->addWidget(m_rightTopWidget);
    m_rightSplitter->addWidget(m_rightCenterWidget);
    m_rightSplitter->addWidget(m_rightCenterFuncWidget);
    m_rightSplitter->addWidget(m_rightBottomWidget);

    m_mainSplitter->addWidget(m_leftWidget);
    m_mainSplitter->addWidget(m_rightSplitter);

    for ( int i= 0; i < m_rightSplitter->count(); i++)
    {
        QSplitterHandle *handle = m_rightSplitter->handle(i);
        handle->setEnabled(false);
    }
    for ( int i= 0; i < m_mainSplitter->count(); i++)
    {
        QSplitterHandle *handle = m_mainSplitter->handle(i);
        handle->setEnabled(false);
    }

    QHBoxLayout *mainHLay = new QHBoxLayout;
    mainHLay->addWidget(m_mainSplitter);
    mainHLay->setSpacing(0);
    mainHLay->setContentsMargins(0,0,0,0);

    this->setLayout(mainHLay);

    connect(m_rightTopWidget_loginBtn,SIGNAL(clicked()),this,SIGNAL(sigLoginBtnClicked()));
    connect(m_rightTopWidget_registerBtn,SIGNAL(clicked()),this,SIGNAL(sigRegisterBtnClicked()));
    translateLanguage();
}

void ContentWin::initLeftWidget()
{
    m_leftWidget = new QWidget();
    m_leftWidget_imageLab = new QLabel();
    m_leftWidget_suggestLab = new QLabel();
    m_leftWidget_systemSafeLab = new QLabel();
    m_leftWidget_powerButton = new QPushButton();


    m_leftWidget->resize(650,500);

    QPixmap label_pixmap(":/contentWidget/computer");
    m_leftWidget_imageLab->setPixmap(label_pixmap);
    m_leftWidget_imageLab->setFixedSize(label_pixmap.size());

    QFont suggestLabFont = m_leftWidget_suggestLab->font();
    suggestLabFont.setPointSize(12);
    suggestLabFont.setBold(true);
    m_leftWidget_suggestLab->setFont(suggestLabFont);
    m_leftWidget_suggestLab->setObjectName("grayLabel");

    QFont systemSafeLabFont = m_leftWidget_systemSafeLab->font();
    systemSafeLabFont.setBold(true);
    m_leftWidget_systemSafeLab->setFont(systemSafeLabFont);
    m_leftWidget_systemSafeLab->setObjectName("grayLabel");

    QPixmap pixmap(":/contentWidget/power");
    m_leftWidget_powerButton->setIcon(pixmap);
    m_leftWidget_powerButton->setIconSize(pixmap.size());
    m_leftWidget_powerButton->setFixedSize(180, 70);
    m_leftWidget_powerButton->setObjectName("greenButton");

    QFont powerButtonFont = m_leftWidget_powerButton->font();
    powerButtonFont.setPointSize(16);
    powerButtonFont.setBold(true);
    m_leftWidget_powerButton->setFont(powerButtonFont);

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addStretch();
    vLay->addWidget(m_leftWidget_suggestLab);
    vLay->addWidget(m_leftWidget_systemSafeLab);
    vLay->addStretch();
    vLay->addSpacing(30);
    vLay->setContentsMargins(0,20,0,0);

    QHBoxLayout *hLay = new QHBoxLayout;
    hLay->addWidget(m_leftWidget_imageLab);
    hLay->addLayout(vLay);
    hLay->addStretch();
    hLay->addSpacing(20);
    hLay->setContentsMargins(30,20,0,0);

    QVBoxLayout *mainVLay = new QVBoxLayout;
    mainVLay->addLayout(hLay);
    mainVLay->addWidget(m_leftWidget_powerButton,0,Qt::AlignCenter);
    mainVLay->addStretch();
    mainVLay->addSpacing(0);
    mainVLay->setContentsMargins(0,0,0,0);

    m_leftWidget->setLayout(mainVLay);

}


void ContentWin::initRightTop()
{
    m_rightTopWidget = new QWidget();
    m_rightTopWidget_loginBtn = new QPushButton();     //登录我的360帐号
    m_rightTopWidget_privLab = new  QLabel();      //皇砖图标
    m_rightTopWidget_infoLab = new  QLabel();      //开启炫动卫视图标
    m_rightTopWidget_privilegeLab = new  QLabel(); //转享特权
    m_rightTopWidget_registerBtn = new QPushButton();;  //10秒免费注册
    m_rightTopWidget_safeBtn = new QPushButton();;      //特权领360炫动logo
    m_rightTopWidget_tabBtn = new QPushButton();;       //领取炫动导航功能图标
    m_rightTopWidget_petBtn = new QPushButton();;       //宠物安仔精灵
    m_rightTopWidget_lotteryBtn = new QPushButton();;   //按在抱枕大派送
    m_rightTopWidget_cloudFiveBtn = new QPushButton();; //5G云盘
    m_rightTopWidget_caipiaoBtn = new QPushButton();;   //彩票

    m_rightTopWidget_loginBtn->setObjectName("loginButton");
    m_rightTopWidget_loginBtn->setFixedSize(240,60);
    QFont loginBtnFont = m_rightTopWidget_loginBtn->font();
    loginBtnFont.setPointSize(12);
    loginBtnFont.setBold(true);
    m_rightTopWidget_loginBtn->setFont(loginBtnFont);

    m_rightTopWidget_privLab->setPixmap(QPixmap(":/contentWidget/priv"));
    QPixmap safe_pixmap(":/contentWidget/360");
    m_rightTopWidget_safeBtn->setIcon(safe_pixmap);
    m_rightTopWidget_safeBtn->setFixedSize(safe_pixmap.size());
    QPixmap tab_pixmap(":/contentWidget/tab");
    m_rightTopWidget_tabBtn->setIcon(tab_pixmap);
    m_rightTopWidget_tabBtn->setFixedSize(tab_pixmap.size());
    QPixmap pet_pixmap(":/contentWidget/pet");
    m_rightTopWidget_petBtn->setIcon(pet_pixmap);
    m_rightTopWidget_petBtn->setFixedSize(tab_pixmap.size());
    QPixmap lottery_pixmap(":/contentWidget/lottery");
    m_rightTopWidget_lotteryBtn->setIcon(lottery_pixmap);
    m_rightTopWidget_lotteryBtn->setFixedSize(lottery_pixmap.size());
    QPixmap cloud_five_pixmap(":/contentWidget/cloud_five");
    m_rightTopWidget_cloudFiveBtn->setIcon(cloud_five_pixmap);
    m_rightTopWidget_cloudFiveBtn->setFixedSize(cloud_five_pixmap.size());
    QPixmap caipiao_pixmap(":/contentWidget/caipiao");
    m_rightTopWidget_caipiaoBtn->setIcon(caipiao_pixmap);
    m_rightTopWidget_caipiaoBtn->setFixedSize(caipiao_pixmap.size());


    m_rightTopWidget_safeBtn->setCursor(Qt::PointingHandCursor);
    m_rightTopWidget_tabBtn->setCursor(Qt::PointingHandCursor);
    m_rightTopWidget_petBtn->setCursor(Qt::PointingHandCursor);
    m_rightTopWidget_lotteryBtn->setCursor(Qt::PointingHandCursor);
    m_rightTopWidget_cloudFiveBtn->setCursor(Qt::PointingHandCursor);
    m_rightTopWidget_caipiaoBtn->setCursor(Qt::PointingHandCursor);

    m_rightTopWidget_registerBtn->setObjectName("blueButton");
    m_rightTopWidget_safeBtn->setObjectName("transparentButton");
    m_rightTopWidget_tabBtn->setObjectName("transparentButton");
    m_rightTopWidget_petBtn->setObjectName("transparentButton");
    m_rightTopWidget_lotteryBtn->setObjectName("transparentButton");
    m_rightTopWidget_cloudFiveBtn->setObjectName("transparentButton");
    m_rightTopWidget_caipiaoBtn->setObjectName("transparentButton");

    QHBoxLayout *login_layout = new QHBoxLayout();
    login_layout->addWidget(m_rightTopWidget_loginBtn);
    login_layout->addStretch();
    login_layout->setContentsMargins(15, 0, 0, 0);

    QHBoxLayout *register_layout = new QHBoxLayout();
    register_layout->addStretch();
    register_layout->addWidget(m_rightTopWidget_privLab);
    register_layout->addWidget(m_rightTopWidget_infoLab);
    register_layout->addWidget(m_rightTopWidget_registerBtn);
    register_layout->addStretch();
    register_layout->setSpacing(5);
    register_layout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *privilege_layout = new QHBoxLayout();
    privilege_layout->addStretch();
    privilege_layout->addWidget(m_rightTopWidget_privilegeLab);
    privilege_layout->addWidget(m_rightTopWidget_safeBtn);
    privilege_layout->addWidget(m_rightTopWidget_tabBtn);
    privilege_layout->addWidget(m_rightTopWidget_petBtn);
    privilege_layout->addWidget(m_rightTopWidget_lotteryBtn);
    privilege_layout->addWidget(m_rightTopWidget_cloudFiveBtn);
    privilege_layout->addWidget(m_rightTopWidget_caipiaoBtn);
    privilege_layout->addStretch();
    privilege_layout->setSpacing(8);
    privilege_layout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addStretch();
    main_layout->addLayout(login_layout);
    main_layout->addLayout(register_layout);
    main_layout->addLayout(privilege_layout);
    main_layout->addStretch();
    main_layout->setSpacing(5);
    main_layout->setContentsMargins(10, 10, 10, 10);

    m_rightTopWidget->setLayout(main_layout);
}

void ContentWin::initRightCenter()
{
    m_rightCenterWidget = new QWidget();
    m_rightCenterWidget_fireproofBtn = new QToolButton();  //360防火墙
    m_rightCenterWidget_triggermanBtn = new QToolButton(); //360保镖
    m_rightCenterWidget_netShopBtn = new QToolButton();   //网购先赔
    m_rightCenterWidget_lineLab1 = new QLabel();      //虚线
    m_rightCenterWidget_lineLab2 = new QLabel();      //虚线

    m_rightCenterWidget_fireproofBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_rightCenterWidget_triggermanBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_rightCenterWidget_netShopBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QPixmap fireproof_pixmap(":/contentWidget/fireproof");
    m_rightCenterWidget_fireproofBtn->setIcon(fireproof_pixmap);
    m_rightCenterWidget_fireproofBtn->setIconSize(fireproof_pixmap.size());
    m_rightCenterWidget_fireproofBtn->setFixedSize(fireproof_pixmap.width() + 25, fireproof_pixmap.height() + 25);

    QPixmap triggerman_pixmap(":/contentWidget/triggerman");
    m_rightCenterWidget_triggermanBtn->setIcon(triggerman_pixmap);
    m_rightCenterWidget_triggermanBtn->setIconSize(triggerman_pixmap.size());
    m_rightCenterWidget_triggermanBtn->setFixedSize(triggerman_pixmap.width() + 25, triggerman_pixmap.height() + 25);

    QPixmap net_shop_pixmap(":/contentWidget/net_shop");
    m_rightCenterWidget_netShopBtn->setIcon(net_shop_pixmap);
    m_rightCenterWidget_netShopBtn->setIconSize(net_shop_pixmap.size());
    m_rightCenterWidget_netShopBtn->setFixedSize(net_shop_pixmap.width() + 25, net_shop_pixmap.height() + 25);

    m_rightCenterWidget_fireproofBtn->setObjectName("transparentToolButton");
    m_rightCenterWidget_triggermanBtn->setObjectName("transparentToolButton");
    m_rightCenterWidget_netShopBtn->setObjectName("transparentToolButton");


    m_rightCenterWidget_lineLab1->setFixedWidth(10);
    m_rightCenterWidget_lineLab2->setFixedWidth(10);
    m_rightCenterWidget_lineLab1->installEventFilter(this);
    m_rightCenterWidget_lineLab2->installEventFilter(this);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(m_rightCenterWidget_fireproofBtn);
    hLayout->addWidget(m_rightCenterWidget_lineLab1);
    hLayout->addWidget(m_rightCenterWidget_triggermanBtn);
    hLayout->addWidget(m_rightCenterWidget_lineLab2);
    hLayout->addWidget(m_rightCenterWidget_netShopBtn);
    hLayout->setSpacing(0);
    hLayout->setContentsMargins(0, 0, 0, 0);

    m_rightCenterWidget->setLayout(hLayout);

}

void ContentWin::initRightCenterFunction()
{
    m_rightCenterFuncWidget = new QWidget();
    m_rightCenterFuncWidget_functionLab = new QLabel;        //功能大全
    m_rightCenterFuncWidget_moreBtn = new QPushButton();           //更多

    QFont function_font = m_rightCenterFuncWidget_functionLab->font();
    function_font.setBold(true);
    m_rightCenterFuncWidget_functionLab->setFont(function_font);
    m_rightCenterFuncWidget_functionLab->setObjectName("infoLabel");
    m_rightCenterFuncWidget_moreBtn->setFixedSize(50, 25);
    m_rightCenterFuncWidget_moreBtn->setObjectName("blueButton");
    m_rightCenterFuncWidget_moreBtn->setCursor(Qt::PointingHandCursor);

    QHBoxLayout *h_layout = new QHBoxLayout();
    h_layout->addWidget(m_rightCenterFuncWidget_functionLab);
    h_layout->addStretch();
    h_layout->addWidget(m_rightCenterFuncWidget_moreBtn);
    h_layout->setSpacing(0);
    h_layout->setContentsMargins(10, 5, 0, 0);


    QStringList string_list;
    string_list     <<":/contentWidget/recovery"
                    <<":/contentWidget/mobile"
                    <<":/contentWidget/game_box"
                    <<":/contentWidget/desktop"
                    <<":/contentWidget/net_repair"
                    <<":/contentWidget/auto_run"
                    <<":/contentWidget/net_speed"
                    <<":/contentWidget/net_pretext"
                    <<":/contentWidget/first_add";
    QGridLayout *gridLay = new QGridLayout;
    for ( int i =0; i < string_list.size(); i++ )
    {
        QToolButton *newToolBtn = new QToolButton();
        newToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        QPixmap button_pixmap(string_list.at(i));
        newToolBtn->setIcon(button_pixmap);
        newToolBtn->setIconSize(button_pixmap.size());
        newToolBtn->setFixedSize(button_pixmap.width()+50, button_pixmap.height()+35);
        newToolBtn->setObjectName("functionButton");

        gridLay->addWidget(newToolBtn, i/3, i%3 );
        m_rightCenterFuncWidget_btnList.append(newToolBtn);
    }
    gridLay->setSpacing(0);
    gridLay->setContentsMargins(5, 0, 5, 5);

    QVBoxLayout *mainVlayout = new QVBoxLayout();
    mainVlayout->addLayout(h_layout);
    mainVlayout->addLayout(gridLay);
    mainVlayout->addStretch();
    mainVlayout->setSpacing(10);
    mainVlayout->setContentsMargins(0, 0, 0, 0);

    m_rightCenterFuncWidget->setLayout(mainVlayout);
}

void ContentWin::initRightBottom()
{
    m_rightBottomWidget = new QWidget();
    m_rightBottomWidget_iconLab = new QLabel();
    m_rightBottomWidget_connectLab = new QLabel();
    m_rightBottomWidget_versionLab = new QLabel();
    m_rightBottomWidget_versionBtn = new QPushButton();

    QPixmap label_pixmap(":/contentWidget/cloud");
    m_rightBottomWidget_iconLab->setPixmap(label_pixmap);
    m_rightBottomWidget_iconLab->setFixedSize(label_pixmap.size());

    QPixmap pixmap(":/contentWidget/version");
    m_rightBottomWidget_versionBtn->setIcon(pixmap);
    m_rightBottomWidget_versionBtn->setIconSize(pixmap.size());
    m_rightBottomWidget_versionBtn->setFixedSize(20, 20);
    m_rightBottomWidget_versionBtn->setObjectName("transparentButton");

    QHBoxLayout *bottom_layout = new QHBoxLayout();
    bottom_layout->addWidget(m_rightBottomWidget_iconLab);
    bottom_layout->addWidget(m_rightBottomWidget_connectLab);
    bottom_layout->addStretch();
    bottom_layout->addWidget(m_rightBottomWidget_versionLab);
    bottom_layout->addWidget(m_rightBottomWidget_versionBtn);
    bottom_layout->setSpacing(5);
    bottom_layout->setContentsMargins(10, 0, 10, 0);

    m_rightBottomWidget->setLayout(bottom_layout);
}

void ContentWin::translateLanguage()
{
    m_leftWidget_suggestLab->setText(tr("suggest"));
    m_leftWidget_systemSafeLab->setText(tr("system safe"));
    m_leftWidget_powerButton->setText(tr("power"));

    m_rightTopWidget_loginBtn->setText(tr("login home"));
    m_rightTopWidget_infoLab->setText(tr("show beautifull icon"));
    m_rightTopWidget_registerBtn->setText(tr("register"));
    m_rightTopWidget_privilegeLab->setText(tr("privilege power"));

    m_rightCenterWidget_fireproofBtn->setText(tr("fireproof"));
    m_rightCenterWidget_triggermanBtn->setText(tr("triggerman"));
    m_rightCenterWidget_netShopBtn->setText(tr("net shop"));

    m_rightCenterFuncWidget_functionLab->setText(tr("function"));
    m_rightCenterFuncWidget_moreBtn->setText(tr("more"));
    m_rightCenterFuncWidget_btnList.at(0)->setText(tr("recovery"));
    m_rightCenterFuncWidget_btnList.at(1)->setText(tr("mobile"));
    m_rightCenterFuncWidget_btnList.at(2)->setText(tr("game box"));
    m_rightCenterFuncWidget_btnList.at(3)->setText(tr("desktop"));
    m_rightCenterFuncWidget_btnList.at(4)->setText(tr("net repair"));
    m_rightCenterFuncWidget_btnList.at(5)->setText(tr("auto run"));
    m_rightCenterFuncWidget_btnList.at(6)->setText(tr("net speed"));
    m_rightCenterFuncWidget_btnList.at(7)->setText(tr("net pretext"));
    m_rightCenterFuncWidget_btnList.at(8)->setText(tr("first add"));

    m_rightBottomWidget_connectLab->setText(tr("connect success"));
    m_rightBottomWidget_versionLab->setText(tr("version"));
}



bool ContentWin::eventFilter(QObject *obj, QEvent *event)
{
    if ( ( obj == m_rightCenterWidget_lineLab1) || ( obj == m_rightCenterWidget_lineLab2))
    {
        if ( event->type() == QEvent::Paint )
        {
            QPainter painter1(m_rightCenterWidget_lineLab1);
            QPen pen(QColor(220, 220, 220), 1, Qt::DashLine);
            painter1.setPen(pen);
            painter1.drawLine(m_rightCenterWidget_lineLab1->width()/2,0,m_rightCenterWidget_lineLab1->width()/2,m_rightCenterWidget_lineLab1->height());

            QPainter painter2(m_rightCenterWidget_lineLab2);
            painter2.setPen(pen);
            painter2.drawLine(m_rightCenterWidget_lineLab2->width()/2,0,
                              m_rightCenterWidget_lineLab2->width()/2,
                              m_rightCenterWidget_lineLab2->height());
        }
    }

    return QWidget::eventFilter(obj,event);
}

































