#include "LoginWin.h"
#include "UserIdItem.h"
#include "Util.h"

#include <QPainter>
#include <QDebug>

LoginWin::LoginWin(QWidget *parent) :
    DropShadowWin(parent)
{

    this->resize(360,275);
    m_enLogin       = SAFE;
    m_enSinaLogin   = SINA;
    m_msgBox        = new MsgBoxWin();
    m_loadingWin    = new LoadingWin();

    initTitle();
    initLoginCenter();
    initBottom();
    initSafeWidget();
    initRenRenWidget();
    initSinaWidget();

    m_loginStackLay = new QStackedLayout;
    m_loginStackLay->addWidget(m_safeRenrenCenterWidget);
    m_loginStackLay->addWidget(m_loadingWin);
    m_loginStackLay->setCurrentWidget(m_safeRenrenCenterWidget);

    m_stackLay = new QStackedLayout;
    m_stackLay->addWidget(m_safeWidget);
    m_stackLay->addWidget(m_renrenWidget);
    m_stackLay->setCurrentWidget(m_safeWidget);

    qDebug() << "m_safeWidget="   << m_safeWidget;
    qDebug() << "m_renrenWidget=" << m_renrenWidget;

    initSafeRenRenWidget();

    m_mainStackLay = new QStackedLayout;    //切换 m_safeRenrenWidget 和 m_sinaWidget
    m_mainStackLay->addWidget(m_safeRenrenWidget);
    m_mainStackLay->setCurrentWidget(m_safeRenrenWidget);

    QHBoxLayout *loginHlay = new QHBoxLayout();
    loginHlay->addStretch();
    loginHlay->addWidget(m_loginBtn);
    loginHlay->setSpacing(0);
    loginHlay->setContentsMargins(0, 0, 20, 10);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addLayout(m_titleHLay);
    main_layout->addLayout(m_mainStackLay);
    main_layout->addLayout(loginHlay);
    main_layout->addLayout(m_bottomHLay);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

    connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(hide()));
    connect(m_renrenBtn, SIGNAL(clicked()), this, SLOT(slotTurnRenRen()));
    connect(m_sinaBtn, SIGNAL(clicked()), this, SLOT(slotTurnSina()));
    connect(m_loginBtn, SIGNAL(clicked()), this, SLOT(slotVerify()));


    this->setLayout(main_layout);
    translateLanguage();
}

void LoginWin::paintEvent(QPaintEvent *event)
{
    DropShadowWin::paintEvent(event);
    bool bIsSina = false;
    int width = this->width();
    int height = this->height();
    switch(m_enLogin)
    {
    case SINA:
        bIsSina = true;
        break;
    default:
        break;
    }

    int draw_height = 95;
    if(bIsSina)
    {
        draw_height = 35;
    }

    QString skin_name = Util::getSkinName();

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(skin_name));

    int sina_line = 0;
    if(bIsSina)
    {
        sina_line = 3;
        QLinearGradient linear(rect().topLeft(), rect().bottomRight());
        linear.setColorAt(0, QColor(240, 30, 50));
        linear.setColorAt(0.2, QColor(240, 40, 50));
        linear.setColorAt(0.4, QColor(255, 50, 60));
        linear.setColorAt(0.6, QColor(255, 150, 10));
        linear.setColorAt(0.8, QColor(255, 180, 60));
        linear.setColorAt(1, QColor(255, 200, 120));

        QPainter painter2(this);
        painter2.setBrush(QBrush(linear));
        painter2.setPen(Qt::NoPen);
        painter2.drawRect(QRect(SHADOW_WIDTH, draw_height, width-2*SHADOW_WIDTH, sina_line));
    }

    QPainter painter3(this);
    painter3.setPen(Qt::NoPen);
    painter3.setBrush(Qt::white);
    painter3.drawRect(QRect(SHADOW_WIDTH, draw_height+sina_line, width-2*SHADOW_WIDTH, height-draw_height-sina_line-SHADOW_WIDTH));

}


void LoginWin::initSafeWidget()
{
    m_safeWidget = new QWidget(this);
    m_safeWidget_iconLab = new QLabel;
    m_safeWidget_safeLab = new QLabel;
    m_safeWidget_protectLab = new QLabel;

    m_safeWidget_safeLab->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    m_safeWidget_protectLab->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    QFont font = m_safeWidget_safeLab->font();
    font.setPointSize(14);
    font.setBold(true);
    m_safeWidget_safeLab->setFont(font);

    m_safeWidget_safeLab->setObjectName("whiteLabel");
    m_safeWidget_protectLab->setObjectName("whiteLabel");

    QPixmap pix(":/img/360safe");
    m_safeWidget_iconLab->setPixmap(pix);
    m_safeWidget_iconLab->setFixedSize(70,70);
    m_safeWidget_iconLab->setScaledContents(true);

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addWidget(m_safeWidget_safeLab);
    vLay->addWidget(m_safeWidget_protectLab);
    vLay->addStretch();
    vLay->setSpacing(5);
    vLay->setContentsMargins(0,0,0,0);

    QHBoxLayout *hLay = new QHBoxLayout;
    hLay->addWidget(m_safeWidget_iconLab);
    hLay->addStretch();
    hLay->addLayout(vLay);
    hLay->setSpacing(0);
    hLay->setContentsMargins(30,0,20,0);

    m_safeWidget->setLayout(hLay);
}

void LoginWin::initRenRenWidget()
{
    m_renrenWidget = new QWidget(this);
    m_renrenWidget_iconLab  = new QLabel();
    m_renrenWidget_infoLab  = new QLabel();
    m_renrenWidget_netLab   = new QLabel();
    m_renrenWidget_loginLab = new QLabel();

    QFont renren_info_font = m_renrenWidget_infoLab->font();
    renren_info_font.setPointSize(14);
    m_renrenWidget_infoLab->setFont(renren_info_font);

    QFont renren_login_font = m_renrenWidget_loginLab->font();
    renren_login_font.setPointSize(14);
    m_renrenWidget_loginLab->setFont(renren_login_font);

    m_renrenWidget_infoLab->setStyleSheet("color:rgb(0, 90, 170);");
    m_renrenWidget_netLab->setStyleSheet("color:rgb(0, 90, 170);");
    m_renrenWidget_loginLab->setStyleSheet("color:white;");

    QPixmap icon_pixmap(":/loginDialog/ren");
    m_renrenWidget_iconLab->setPixmap(icon_pixmap);
    m_renrenWidget_iconLab->setFixedSize(icon_pixmap.size());
    m_renrenWidget_iconLab->setScaledContents(true);

    QVBoxLayout *info_layout = new QVBoxLayout();
    info_layout->addStretch();
    info_layout->addWidget(m_renrenWidget_infoLab);
    info_layout->addWidget(m_renrenWidget_netLab);
    info_layout->addStretch();
    info_layout->setSpacing(0);
    info_layout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(m_renrenWidget_iconLab);
    main_layout->addLayout(info_layout);
    main_layout->addStretch();
    main_layout->addWidget(m_renrenWidget_loginLab);
    main_layout->setSpacing(5);
    main_layout->setContentsMargins(30, 0, 20, 0);

    m_renrenWidget->setLayout(main_layout);
}

void LoginWin::initSinaWidget()
{
    m_sinaWidget = new QWidget();


    m_sinaWidget_iconLab = new QLabel();
    m_sinaWidget_netLab  = new QLabel();
    m_sinaWidget_infoLab = new QLabel();
    m_sinaWidget_registerBtn    = new QPushButton();
    m_sinaWidget_userIDLedit    = new QLineEdit();
    m_sinaWidget_passwordLedit  = new QLineEdit();
    m_sinaWidget_examineAuthorizeBtn = new QPushButton();
    m_sinaWidget_authorizeBtn = new QPushButton();
    m_sinaWidget_loginCbox = new QCheckBox();
    m_sinaWidget_attentionSafeCbox = new QCheckBox();

    m_sinaWidget_netLab->setAlignment(Qt::AlignTop);
    m_sinaWidget_netLab->setCursor(Qt::PointingHandCursor);

    QPixmap icon_pixmap(":/loginDialog/sina");
    m_sinaWidget_iconLab->setPixmap(icon_pixmap);
    m_sinaWidget_iconLab->setFixedSize(icon_pixmap.size());
    m_sinaWidget_iconLab->setScaledContents(true);

    QFont sina_info_font = m_sinaWidget_infoLab->font();
    sina_info_font.setPointSize(14);
    sina_info_font.setItalic(true);
    m_sinaWidget_infoLab->setFont(sina_info_font);

    QFont sina_net_font = m_sinaWidget_netLab->font();
    sina_net_font.setItalic(true);
    m_sinaWidget_netLab->setFont(sina_net_font);

    m_sinaWidget_registerBtn->setObjectName("blueButton");

    m_sinaWidget_userIDLedit->setFixedHeight(30);
    m_sinaWidget_passwordLedit->setFixedHeight(30);
    m_sinaWidget_passwordLedit->setEchoMode(QLineEdit::Password);
    m_sinaWidget_passwordLedit->setAlignment(Qt::AlignBottom);
    m_sinaWidget_examineAuthorizeBtn->setCursor(Qt::PointingHandCursor);
    m_sinaWidget_examineAuthorizeBtn->setObjectName("examineAuthorizeButton");

    m_sinaWidget_authorizeBtn->setFixedSize(90, 30);
    QFont authorize_font = m_sinaWidget_authorizeBtn->font();
    authorize_font.setPointSize(14);
    m_sinaWidget_authorizeBtn->setFont(authorize_font);
    m_sinaWidget_authorizeBtn->setObjectName("redButton");

    QVBoxLayout *info_layout = new QVBoxLayout();
    info_layout->addWidget(m_sinaWidget_infoLab);
    info_layout->addWidget(m_sinaWidget_netLab);
    info_layout->setSpacing(0);
    info_layout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *sina_layout = new QHBoxLayout();
    sina_layout->addWidget(m_sinaWidget_iconLab);
    sina_layout->addLayout(info_layout);
    sina_layout->addStretch();
    sina_layout->setSpacing(5);
    sina_layout->setContentsMargins(0, 0, 0, 0);

    QGridLayout *grid_layout = new QGridLayout();
    grid_layout->addLayout(sina_layout, 0, 0);
    grid_layout->addWidget(m_sinaWidget_registerBtn, 0, 2);
    grid_layout->addWidget(m_sinaWidget_userIDLedit, 1, 0, 1, 3);
    grid_layout->addWidget(m_sinaWidget_passwordLedit, 2, 0, 1, 3);
    grid_layout->addWidget(m_sinaWidget_examineAuthorizeBtn, 3, 0);
    grid_layout->addWidget(m_sinaWidget_authorizeBtn, 3, 2, Qt::AlignRight);
    grid_layout->setHorizontalSpacing(5);
    grid_layout->setVerticalSpacing(10);
    grid_layout->setContentsMargins(50, 0, 50, 0);

    QHBoxLayout *h_layout = new QHBoxLayout();
    h_layout->addStretch();
    h_layout->addWidget(m_sinaWidget_loginCbox);
    h_layout->addWidget(m_sinaWidget_attentionSafeCbox);
    h_layout->setSpacing(20);
    h_layout->setContentsMargins(0, 0, 20, 0);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addLayout(grid_layout);
    main_layout->addLayout(h_layout);
    main_layout->setSpacing(20);
    main_layout->setContentsMargins(0, 0, 0, 0);

    m_sinaWidget->setLayout(main_layout);
}

void LoginWin::initTitle()
{
    m_titleLab = new QLabel;
    m_closeBtn = new MyPushButton;

    m_titleLab->setObjectName("whiteLabel");
    m_titleLab->setAlignment(Qt::AlignBottom);
    m_closeBtn->setPicName(QString(":/sysButton/close"));

    m_titleHLay = new QHBoxLayout;
    m_titleHLay->addWidget(m_titleLab);
    m_titleHLay->addStretch();
    m_titleHLay->addWidget(m_closeBtn);
    m_titleHLay->setSpacing(0);
    m_titleHLay->setContentsMargins(10, 0, 5, 10);
}

void LoginWin::initLoginCenter()
{
    m_userIdLab     = new QLabel;
    m_passwordLab   = new QLabel;
    m_passwordLedit = new QLineEdit;
    m_registerBtn   = new QPushButton;
    m_forgotBtn     = new QPushButton;
    m_userIdCbox    = new QComboBox;
    m_rememberCbox  = new QCheckBox;
    m_autoLoginCbox = new QCheckBox;
    m_loginBtn      = new QPushButton;

    m_userIdLab->setScaledContents(true);
    m_passwordLab->setScaledContents(true);
    m_userIdLab->setAlignment(Qt::AlignRight);
    m_passwordLab->setAlignment(Qt::AlignRight);
    m_userIdCbox->setFixedHeight(25);
    m_passwordLedit->setFixedHeight(25);
    m_passwordLedit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    //inituserId
    m_listWidget = new QListWidget();
    m_userIdCbox->setModel(m_listWidget->model());
    m_userIdCbox->setView(m_listWidget);
    m_userIdCbox->setEditable(true);
    for ( int i = 0; i < 3; i++)
    {
        UserIdItem *userIdItem = new  UserIdItem;
        userIdItem->setUserIdLabText(QString("safe_") + QString::number(i, 10) + QString("@qq.com"));
        connect(userIdItem,SIGNAL(sigRemoveUserId(QString)),this,SLOT(slotRemoveUserId(QString)));
        connect(userIdItem,SIGNAL(sigShowUserId(QString)),this,SLOT(slotShowUserId(QString)));
        QListWidgetItem *listItem = new QListWidgetItem(m_listWidget);
        m_listWidget->setItemWidget(listItem,userIdItem);
    }

    m_registerBtn->setFixedSize(70, 25);
    m_forgotBtn->setFixedSize(70, 25);
    m_loginBtn->setFixedSize(60, 25);
    m_registerBtn->setObjectName("blueButton");
    m_forgotBtn->setObjectName("blueButton");
    m_loginBtn->setObjectName("loginGreenButton");

    QHBoxLayout *hLay = new QHBoxLayout;
    hLay->addWidget(m_rememberCbox);
    hLay->addWidget(m_autoLoginCbox);
    //hLay->addStretch();
    hLay->setSpacing(40);
    hLay->setContentsMargins(0,0,0,0);

    QGridLayout *gLay = new QGridLayout;
    gLay->addWidget(m_userIdLab,0,0);
    gLay->addWidget(m_userIdCbox,0,1);
    gLay->addWidget(m_registerBtn,0,2);
    gLay->addWidget(m_passwordLab,1,0);
    gLay->addWidget(m_passwordLedit,1,1);
    gLay->addWidget(m_forgotBtn,1,2);
    gLay->addLayout(hLay,2,1);
    gLay->setHorizontalSpacing(5);
    gLay->setVerticalSpacing(10);
    gLay->setContentsMargins(20, 0, 20, 0);

    m_safeRenrenCenterWidget = new QWidget(this);
    m_safeRenrenCenterWidget->setLayout(gLay);
}

void LoginWin::initBottom()
{
    m_otherUserIdLab = new QLabel;
    m_sinaBtn = new QPushButton;
    m_renrenBtn = new QPushButton;

    QPixmap sina_pixmap(":/loginDialog/sina");
    m_sinaBtn->setIcon(sina_pixmap);
    m_sinaBtn->setIconSize(QSize(20, 20));
    m_sinaBtn->setFixedSize(25, 22);

    QPixmap renren_pixmap(":/loginDialog/renren");
    m_renrenBtn->setIcon(renren_pixmap);
    m_renrenBtn->setIconSize(QSize(20, 20));
    m_renrenBtn->setFixedSize(25, 22);

    m_sinaBtn->setObjectName("skinButton");
    m_renrenBtn->setObjectName("skinButton");

    m_bottomHLay = new QHBoxLayout;

    m_bottomHLay->addWidget(m_otherUserIdLab);
    m_bottomHLay->addWidget(m_sinaBtn);
    m_bottomHLay->addWidget(m_renrenBtn);
    m_bottomHLay->addStretch();
    m_bottomHLay->setSpacing(5);
    m_bottomHLay->setContentsMargins(20, 0, 0, 5);
}

void LoginWin::initSafeRenRenWidget()
{
    m_safeRenrenWidget = new QWidget(this);

    QVBoxLayout *safe_renren_layout = new QVBoxLayout();
    safe_renren_layout->addLayout(m_stackLay);
    safe_renren_layout->addStretch();
    safe_renren_layout->addLayout(m_loginStackLay);
    safe_renren_layout->setSpacing(0);
    safe_renren_layout->setContentsMargins(0, 0, 0, 0);

    m_safeRenrenWidget->setLayout(safe_renren_layout);
}

void LoginWin::translateLanguage()
{
    m_msgBox->translateLanguage();
    this->changeTitle();
    m_closeBtn->setToolTip(tr("close"));

    m_safeWidget_safeLab->setText(tr("360 safe"));
    m_safeWidget_protectLab->setText(tr("protect every day"));

    m_renrenWidget_infoLab->setText(tr("renren"));
    m_renrenWidget_netLab->setText(tr("renren.com"));
    m_renrenWidget_loginLab->setText(tr("login by renren"));

    m_sinaWidget_infoLab->setText(tr("sina info"));
    m_sinaWidget_netLab->setText(tr("sina net"));
    m_sinaWidget_registerBtn->setText(tr("sina register"));
    m_sinaWidget_loginCbox->setText(tr("sina login"));
    m_sinaWidget_userIDLedit->setPlaceholderText(tr("sina account"));
    m_sinaWidget_attentionSafeCbox->setText(tr("safe attention"));
    m_sinaWidget_examineAuthorizeBtn->setText(tr("examine authorize"));
    m_sinaWidget_authorizeBtn->setText(tr("authorize"));

    m_userIdLab->setText(tr("account"));
    m_passwordLab->setText(tr("password"));
    m_otherUserIdLab->setText(tr("other account"));
    m_registerBtn->setText(tr("register"));
    m_forgotBtn->setText(tr("forgot"));
    m_loginBtn->setText(tr("login"));
    m_rememberCbox->setText(tr("remember"));
    m_autoLoginCbox->setText(tr("auto login"));


}

void LoginWin::changeTitle()
{
    switch(m_enLogin)
    {
    case SAFE:
        m_titleLab->setText(tr("360 safe login"));
        break;
    case SINA:
        m_titleLab->setText(tr("login by sina"));
        break;
    case RENREN:
        m_titleLab->setText(tr("login by renren"));
        break;

    default:
        m_titleLab->setText(tr("360 safe login"));
    }
}

void LoginWin::slotRemoveUserId(QString strUserId)
{
    m_msgBox->setInfo(tr("remove account"), tr("are you sure to remove account?"), QPixmap(":/loginDialog/attention"), false);
    if ( m_msgBox->exec() == QDialog::Accepted )
    {
        for( int i= 0; i < m_listWidget->count(); i++)
        {
            QListWidgetItem *listItem = m_listWidget->item(i);
            UserIdItem *userIdItem = (UserIdItem *)m_listWidget->itemWidget(listItem);
            if ( 0 == strUserId.compare(userIdItem->getUserIdLabText()))
            {
                m_listWidget->takeItem(i);
                delete listItem;
                break;
            }
        }
    }

    m_userIdCbox->hidePopup();
}


void LoginWin::slotShowUserId(QString strUserId)
{
    m_userIdCbox->setEditText(strUserId);
    m_userIdCbox->hidePopup();
}

void LoginWin::slotTurnSina()
{
    switch(m_enLogin)
    {
    case SAFE:
        {
            if(m_enSinaLogin == SINA)
            {
                m_enLogin = SINA;
            }
            else
            {
                m_enLogin = RENREN;
            }
            this->changeTitle();
            this->turnWidget();
            m_enSinaLogin = SAFE;
            m_sinaBtn->setIcon(QIcon(":/img/safe"));
        }
        break;
    case RENREN:
        {
            if(m_enSinaLogin == SINA)
            {
                m_enLogin = SINA;
            }
            else
            {
                m_enLogin = SAFE;
            }
            this->changeTitle();
            this->turnWidget();
            m_enSinaLogin = RENREN;
            m_sinaBtn->setIcon(QIcon(":/loginDialog/renren"));
        }
        break;
    case SINA:
        {
            if(m_enSinaLogin == SAFE)
            {
                m_enLogin = SAFE;
                update();
            }
            else
            {
                m_enLogin = RENREN;
            }
            this->changeTitle();
            this->turnWidget();
            m_enSinaLogin = SINA;
            m_sinaBtn->setIcon(QIcon(":/loginDialog/sina"));
        }
        break;
    default:
        break;
    }

}

void LoginWin::slotTurnRenRen()
{
    switch(m_enLogin)
    {
    case SAFE:
        {
            if(m_enSinaLogin == SINA)
            {
                m_enLogin = RENREN;
            }
            else
            {
                m_enLogin = SINA;
            }
            this->changeTitle();
            this->turnWidget();
            m_renrenBtn->setIcon(QIcon(":/img/safe"));
        }
        break;
    case RENREN:
        {
            if(m_enSinaLogin == SINA)
            {
                m_enLogin = SAFE;
            }
            else
            {
                m_enLogin = SINA;
            }
            this->changeTitle();
            this->turnWidget();
            m_renrenBtn->setIcon(QIcon(":/loginDialog/renren"));
        }
        break;
    case SINA:
        {
            if(m_enSinaLogin == SAFE)
            {
                m_enLogin = RENREN;
            }
            else
            {
                m_enLogin = SAFE;
            }
            this->changeTitle();
            this->turnWidget();
            m_renrenBtn->setIcon(QIcon(":/loginDialog/sina"));
        }
        break;

    default:
        break;
    }
}

void LoginWin::turnWidget()
{
    switch(m_enLogin)
    {
    case SAFE:
        {
            m_mainStackLay->removeWidget(m_sinaWidget);
            this->resize(370, 275);
            QWidget *current_widget = m_mainStackLay->currentWidget();
            if(current_widget != m_safeRenrenWidget)
            {
                m_mainStackLay->setCurrentWidget(m_safeRenrenWidget);
            }
            QWidget *stack_current_widget = m_stackLay->currentWidget();
            if(stack_current_widget != m_safeWidget)
            {
                m_stackLay->setCurrentWidget(m_safeWidget);
                m_registerBtn->show();
                m_forgotBtn->show();
                m_autoLoginCbox->show();
            }
            m_loginBtn->show();
        }
        break;
    case SINA:
        {
            this->resize(400, 310);
            m_mainStackLay->addWidget(m_sinaWidget);
            QWidget *current_widget = m_mainStackLay->currentWidget();
            if(current_widget == m_safeRenrenWidget)
            {
                m_mainStackLay->setCurrentWidget(m_sinaWidget);
                m_loginBtn->hide();
            }
        }
        break;
    case RENREN:
        {
            m_mainStackLay->removeWidget(m_sinaWidget);
            this->resize(370, 275);
            QWidget *current_widget = m_mainStackLay->currentWidget();
            if(current_widget != m_safeRenrenWidget)
            {
                m_mainStackLay->setCurrentWidget(m_safeRenrenWidget);
            }
            QWidget *stack_current_widget = m_stackLay->currentWidget();
            if(stack_current_widget != m_renrenWidget)
            {
                m_stackLay->setCurrentWidget(m_renrenWidget);
                m_registerBtn->show();
                m_forgotBtn->show();
                m_autoLoginCbox->show();
            }
            m_loginBtn->show();

        }
        break;

    default:
        break;
    }
}


void LoginWin::slotVerify()
{
    bool is_hidden = false;
    bool is_login_hidden = false;
    m_enLogin = SAFE;
    QWidget *current_widget = m_loginStackLay->currentWidget();
    if(current_widget != m_loadingWin )
    {
        m_loginBtn->setText(tr("cancel"));
        is_hidden = true;
        m_loginStackLay->setCurrentWidget(m_loadingWin);
        m_loadingWin->setUserId(m_userIdCbox->currentText());
        m_loadingWin->start(true);
    }
    else
    {
        m_loginBtn->setText(tr("login"));
        m_loadingWin->start(false);
        m_loginStackLay->setCurrentWidget(m_safeRenrenCenterWidget);
        is_login_hidden = m_autoLoginCbox->isHidden();
    }

    if(is_login_hidden)
    {
        m_enLogin = RENREN;
        m_stackLay->setCurrentWidget(m_renrenWidget);
    }
    else
    {
        m_stackLay->setCurrentWidget(m_safeWidget);
    }
    changeTitle();
    m_otherUserIdLab->setHidden(is_hidden);
    m_sinaBtn->setHidden(is_hidden);
    m_renrenBtn->setHidden(is_hidden);
}
