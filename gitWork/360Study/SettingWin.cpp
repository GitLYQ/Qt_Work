#include "SettingWin.h"


#include "Util.h"

#include <QPainter>

SettingWin::SettingWin(QWidget *parent) :
    DropShadowWin(parent)
{
    this->resize(560, 400);

    initTitle();
    initCenter();
    initBottom();

    QVBoxLayout *mainVLay = new QVBoxLayout;
    mainVLay->addLayout(m_titleLay);
    mainVLay->addWidget(m_tabWidget);
    mainVLay->addLayout(m_bottomLay);
    mainVLay->addStretch();
    mainVLay->setSpacing(0);
    mainVLay->setContentsMargins(SHADOW_WIDTH,SHADOW_WIDTH,SHADOW_WIDTH,SHADOW_WIDTH);


    this->setLayout(mainVLay);

    translateLanguage();
}

void SettingWin::paintEvent(QPaintEvent *event)
{
    DropShadowWin::paintEvent(event);

    int nHeight = 65;
    QString strSkin = Util::getSkinName();

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);

    painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH),QPixmap(strSkin));
    painter.drawRect(QRect(SHADOW_WIDTH, nHeight, this->width()-2*SHADOW_WIDTH, this->height()-nHeight-SHADOW_WIDTH));
}


void SettingWin::translateLanguage()
{
    QString space_str = QString("    ");
    m_titleContentLab->setText(tr("360 safe setting"));
    m_closeBtn->setToolTip(tr("close"));

    m_tabWidget->addTab(m_tab1, tr("rise style"));
    m_tabWidget->addTab(m_tab2, tr("advanced setting"));
    m_tabWidget->addTab(m_tab3, tr("physical setting"));
    m_tabWidget->addTab(m_tab4, tr("user setting"));
    m_tabWidget->addTab(m_tab5, tr("improve program"));
    m_tabWidget->addTab(m_tab6, tr("cloud secure program"));

    tab1_group_box->setTitle(tr("rise style title"));
    auto_rise_button->setText(tr("auto rise"));
    not_auto_rise_button->setText(tr("not auto rise"));
    rise_mummy_check_box->setText(tr("rise mummy"));
    game_check_box->setText(tr("game"));
    g3_check_box->setText(tr("3g"));
    p2p_check_box->setText(tr("p2p"));
    mummy_check_box->setText(tr("mummy"));

    tab2_group_box1->setTitle(tr("mummy fireproof"));
    tab2_group_box2->setTitle(tr("context menu"));
    tab2_group_box3->setTitle(tr("software manager"));
    auto_start_check_box->setText(tr("auto start"));
    remove_own_check_box->setText(tr("remove own"));
    strong_remove_check_box->setText(tr("strong remove"));
    mummy_kill_check_box->setText(tr("mummy kill"));
    display_count_check_box->setText(tr("display count"));

    tab3_group_box1->setTitle(tr("frequency setting"));
    tab3_group_box2->setTitle(tr("quit style setting"));
    auto_check_button->setText(tr("auto check"));
    first_check_button->setText(tr("first check"));
    hand_check_button->setText(tr("hand check"));
    select_quit_button->setText(tr("select quit"));
    backstage_mode_button->setText(tr("backstage mode"));
    immediacy_close_button->setText(tr("immediacy close"));

    tab4_group_box->setTitle(tr("rate task setting"));
    diaplay_experience_check_box->setText(tr("diaplay experience"));
    diaplay_login_check_box->setText(tr("diaplay login"));
    tray_quit_check_box->setText(tr("tray quit"));
    new_character_check_box->setText(tr("new character"));
    rise_remind_check_box->setText(tr("rise remind"));
    language_label->setText(tr("language"));
    language_combo_box->setItemText(0, tr("chinese"));
    language_combo_box->setItemText(1, tr("english"));

    tab5_group_box->setTitle(tr("improve plan"));
    improve_plan_check_box->setText(tr("join improve plan"));
    understand_detail_button->setText(tr("understand detail"));

    tab6_group_box1->setTitle(tr("file safe plan"));
    tab6_group_box2->setTitle(tr("internet safe plan"));
    file_safe_label->setText(space_str + tr("file safe info"));
    internet_safe_label->setText(space_str + tr("internet safe info"));
    file_safe_check_box->setText(tr("file safe"));
    internet_safe_check_box->setText(tr("internet safe"));
    look_privacy_button->setText(tr("look privacy"));


    m_okBtn->setText(tr("ok"));
    m_cancleBtn->setText(tr("cancel"));
}


void SettingWin::initTitle()
{
    m_closeBtn = new MyPushButton;
    m_closeBtn->setPicName(QString(":/sysButton/close"));

    m_titleIconLab = new QLabel;
    m_titleContentLab = new QLabel;

    m_titleIconLab->setPixmap(QPixmap(":/img/safe"));
    m_titleIconLab->setFixedSize(16,16);
    m_titleIconLab->setScaledContents(true);

    m_titleContentLab->setObjectName("whiteLabel");

    m_titleLay = new QHBoxLayout;
    m_titleLay->addWidget(m_titleIconLab,0,Qt::AlignVCenter);
    m_titleLay->addWidget(m_titleContentLab,0,Qt::AlignVCenter);
    m_titleLay->addStretch();
    m_titleLay->addWidget(m_closeBtn,0,Qt::AlignTop);
    m_titleLay->setSpacing(5);
    m_titleLay->setContentsMargins(10,0,5,10);

    connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(hide()));
}

void SettingWin::initCenter()
{
    m_tabWidget = new QTabWidget;
    m_tabWidget->setFixedSize(this->width(),320);

    m_tab1 = new QWidget;
    m_tab2 = new QWidget;
    m_tab3 = new QWidget;
    m_tab4 = new QWidget;
    m_tab5 = new QWidget;
    m_tab6 = new QWidget;

    initTab1();
    initTab2();
    initTab3();
    initTab4();
    initTab5();
    initTab6();

}

void SettingWin::initBottom()
{
    m_okBtn     = new QPushButton();
    m_cancleBtn = new QPushButton();
    m_bottomLay = new QHBoxLayout;

    m_okBtn->setFixedSize(75,25);
    m_cancleBtn->setFixedSize(75,25);
    m_okBtn->setObjectName("okButton");
    m_cancleBtn->setObjectName("okButton");

    m_bottomLay->addStretch();
    m_bottomLay->addWidget(m_okBtn);
    m_bottomLay->addWidget(m_cancleBtn);
    m_bottomLay->setSpacing(20);
    m_bottomLay->setContentsMargins(0, 10, 20, 20);

    connect(m_okBtn, SIGNAL(clicked()), this, SLOT(slotUpdateConfig()));
    connect(m_cancleBtn, SIGNAL(clicked()), this, SLOT(hide()));
}

void SettingWin::slotUpdateConfig()
{
    int index = language_combo_box->currentIndex();
    LANGUAGE ui_language = (LANGUAGE)language_combo_box->itemData(index).toInt();
    emit sigChangeLanguage(ui_language);

    this->hide();
}



void SettingWin::initTab1()
{
    tab1_group_box   = new QGroupBox();
    auto_rise_button = new QRadioButton();
    not_auto_rise_button = new QRadioButton();
    rise_mummy_check_box = new QCheckBox();
    game_check_box = new QCheckBox();
    g3_check_box = new QCheckBox();
    p2p_check_box = new QCheckBox();
    mummy_check_box = new QCheckBox();

    QFont group_box_font = tab1_group_box->font();
    group_box_font.setBold(true);
    tab1_group_box->setFont(group_box_font);
    tab1_group_box->setFixedSize(480, 250);

    QHBoxLayout *rise_mummy_layout = new QHBoxLayout();
    rise_mummy_layout->addWidget(rise_mummy_check_box);
    rise_mummy_layout->setSpacing(0);
    rise_mummy_layout->setContentsMargins(20, 0, 0, 0);

    QVBoxLayout *group_layout = new QVBoxLayout();
    group_layout->addWidget(auto_rise_button);
    group_layout->addWidget(not_auto_rise_button);
    group_layout->addLayout(rise_mummy_layout);
    group_layout->addWidget(game_check_box);
    group_layout->addWidget(g3_check_box);
    group_layout->addWidget(p2p_check_box);
    group_layout->addWidget(mummy_check_box);
    group_layout->setSpacing(0);
    group_layout->setContentsMargins(30, 0, 0, 0);
    tab1_group_box->setLayout(group_layout);

    QHBoxLayout *tab1_layout = new QHBoxLayout();
    tab1_layout->addWidget(tab1_group_box);
    tab1_layout->setSpacing(0);
    tab1_layout->setContentsMargins(0, 0, 0, 0);
    m_tab1->setLayout(tab1_layout);
}

void SettingWin::initTab2()
{
    tab2_group_box1 = new QGroupBox();
    tab2_group_box2 = new QGroupBox();
    tab2_group_box3 = new QGroupBox();
    auto_start_check_box = new QCheckBox();
    remove_own_check_box = new QCheckBox();
    strong_remove_check_box = new QCheckBox();
    mummy_kill_check_box = new QCheckBox();
    display_count_check_box = new QCheckBox();

    QFont group_box_font = tab2_group_box1->font();
    group_box_font.setBold(true);
    tab2_group_box1->setFont(group_box_font);
    tab2_group_box2->setFont(group_box_font);
    tab2_group_box3->setFont(group_box_font);

    QHBoxLayout *group_box1_layout = new QHBoxLayout();
    group_box1_layout->addWidget(auto_start_check_box);
    group_box1_layout->setSpacing(0);
    group_box1_layout->setContentsMargins(30, 0, 0, 0);
    tab2_group_box1->setLayout(group_box1_layout);

    QVBoxLayout *group_box2_layout = new QVBoxLayout();
    group_box2_layout->addWidget(remove_own_check_box);
    group_box2_layout->addWidget(strong_remove_check_box);
    group_box2_layout->addWidget(mummy_kill_check_box);
    group_box2_layout->setSpacing(0);
    group_box2_layout->setContentsMargins(30, 0, 0, 0);
    tab2_group_box2->setLayout(group_box2_layout);

    QHBoxLayout *group_box3_layout = new QHBoxLayout();
    group_box3_layout->addWidget(display_count_check_box);
    group_box3_layout->setSpacing(0);
    group_box3_layout->setContentsMargins(30, 0, 0, 0);
    tab2_group_box3->setLayout(group_box3_layout);

    tab2_group_box1->setFixedSize(480, 60);
    tab2_group_box2->setFixedSize(480, 110);
    tab2_group_box3->setFixedSize(480, 60);

    QVBoxLayout *group_layout = new QVBoxLayout();
    group_layout->addWidget(tab2_group_box1, 0, Qt::AlignCenter);
    group_layout->addWidget(tab2_group_box2, 0, Qt::AlignCenter);
    group_layout->addWidget(tab2_group_box3, 0, Qt::AlignCenter);
    group_layout->addStretch();
    group_layout->setSpacing(10);
    group_layout->setContentsMargins(0, 20, 0, 0);
    m_tab2->setLayout(group_layout);
}

void SettingWin::initTab3()
{
    tab3_group_box1 = new QGroupBox();
    tab3_group_box2 = new QGroupBox();
    auto_check_button = new QRadioButton();
    first_check_button = new QRadioButton();
    hand_check_button = new QRadioButton();
    select_quit_button = new QRadioButton();
    backstage_mode_button = new QRadioButton();
    immediacy_close_button = new QRadioButton();

    QFont group_box_font = tab3_group_box1->font();
    group_box_font.setBold(true);
    tab3_group_box1->setFont(group_box_font);
    tab3_group_box2->setFont(group_box_font);

    QVBoxLayout *group_box1_layout = new QVBoxLayout();
    group_box1_layout->addWidget(auto_check_button);
    group_box1_layout->addWidget(first_check_button);
    group_box1_layout->addWidget(hand_check_button);
    group_box1_layout->setSpacing(0);
    group_box1_layout->setContentsMargins(30, 0, 0, 0);
    tab3_group_box1->setLayout(group_box1_layout);

    QVBoxLayout *group_box2_layout = new QVBoxLayout();
    group_box2_layout->addWidget(select_quit_button);
    group_box2_layout->addWidget(backstage_mode_button);
    group_box2_layout->addWidget(immediacy_close_button);
    group_box2_layout->setSpacing(0);
    group_box2_layout->setContentsMargins(30, 0, 0, 0);
    tab3_group_box2->setLayout(group_box2_layout);

    tab3_group_box1->setFixedSize(480, 120);
    tab3_group_box2->setFixedSize(480, 120);

    QVBoxLayout *group_layout = new QVBoxLayout();
    group_layout->addWidget(tab3_group_box1, 0, Qt::AlignCenter);
    group_layout->addWidget(tab3_group_box2, 0, Qt::AlignCenter);
    group_layout->addStretch();
    group_layout->setSpacing(10);
    group_layout->setContentsMargins(0, 20, 0, 0);
    m_tab3->setLayout(group_layout);
}

void SettingWin::initTab4()
{
    tab4_group_box = new QGroupBox();
    diaplay_experience_check_box = new QCheckBox();
    diaplay_login_check_box = new QCheckBox();
    tray_quit_check_box = new QCheckBox();
    new_character_check_box = new QCheckBox();
    rise_remind_check_box = new QCheckBox();
    language_label = new QLabel();
    language_combo_box = new QComboBox();

    language_combo_box->addItem("chinese", UI_ZH);
    language_combo_box->addItem("english", UI_EN);
    language_label->setBuddy(language_combo_box);
    language_combo_box->setFixedWidth(70);

    QHBoxLayout *language_layout = new QHBoxLayout();
    language_layout->addWidget(language_label);
    language_layout->addWidget(language_combo_box);
    language_layout->addStretch();

    QFont group_box_font = tab4_group_box->font();
    group_box_font.setBold(true);
    tab4_group_box->setFont(group_box_font);
    tab4_group_box->setFixedSize(480, 240);

    QVBoxLayout *group_layout = new QVBoxLayout();
    group_layout->addWidget(diaplay_experience_check_box);
    group_layout->addWidget(diaplay_login_check_box);
    group_layout->addWidget(tray_quit_check_box);
    group_layout->addWidget(new_character_check_box);
    group_layout->addWidget(rise_remind_check_box);
    group_layout->addLayout(language_layout);
    group_layout->setSpacing(0);
    group_layout->setContentsMargins(30, 0, 0, 0);
    tab4_group_box->setLayout(group_layout);

    QVBoxLayout *tab4_layout = new QVBoxLayout();
    tab4_layout->addWidget(tab4_group_box, 0 , Qt::AlignCenter);
    tab4_layout->addStretch();
    tab4_layout->setSpacing(0);
    tab4_layout->setContentsMargins(0, 20, 0, 0);
    m_tab4->setLayout(tab4_layout);
}

void SettingWin::initTab5()
{
    tab5_group_box = new QGroupBox();
    improve_plan_check_box = new QCheckBox();
    understand_detail_button = new QPushButton();

    QFont group_box_font = tab5_group_box->font();
    group_box_font.setBold(true);
    tab5_group_box->setFont(group_box_font);

    tab5_group_box->setFixedSize(480, 60);
    understand_detail_button->setFixedSize(80, 25);
    understand_detail_button->setCursor(Qt::PointingHandCursor);
    understand_detail_button->setObjectName("blueButton");

    QHBoxLayout *group_layout = new QHBoxLayout();
    group_layout->addWidget(improve_plan_check_box);
    group_layout->addStretch();
    group_layout->addWidget(understand_detail_button);
    group_layout->setSpacing(0);
    group_layout->setContentsMargins(30, 0, 30, 0);
    tab5_group_box->setLayout(group_layout);

    QVBoxLayout *tab5_layout = new QVBoxLayout();
    tab5_layout->addWidget(tab5_group_box, 0 , Qt::AlignCenter);
    tab5_layout->addStretch();
    tab5_layout->setSpacing(0);
    tab5_layout->setContentsMargins(0, 20, 0, 0);
    m_tab5->setLayout(tab5_layout);
}

void SettingWin::initTab6()
{
    tab6_group_box1 = new QGroupBox();
    tab6_group_box2 = new QGroupBox();
    file_safe_label = new QLabel();
    internet_safe_label = new QLabel();
    file_safe_check_box = new QCheckBox();
    internet_safe_check_box = new QCheckBox();
    look_privacy_button = new QPushButton();

    QFont group_box_font = tab6_group_box1->font();
    group_box_font.setBold(true);
    tab6_group_box1->setFont(group_box_font);
    tab6_group_box2->setFont(group_box_font);
    look_privacy_button->setCursor(Qt::PointingHandCursor);

    look_privacy_button->setObjectName("blueButton");
    file_safe_label->setObjectName("grayLabel");
    internet_safe_label->setObjectName("grayLabel");
    file_safe_label->setFixedWidth(420);
    file_safe_label->resize(420, 25*3);
    file_safe_label->setWordWrap(true);
    internet_safe_label->setFixedWidth(420);
    internet_safe_label->resize(420, 25*3);
    internet_safe_label->setWordWrap(true);

    QHBoxLayout *group_box1_h_layout = new QHBoxLayout();
    group_box1_h_layout->addWidget(file_safe_check_box);
    group_box1_h_layout->addStretch();
    group_box1_h_layout->addWidget(look_privacy_button);
    group_box1_h_layout->setSpacing(0);
    group_box1_h_layout->setContentsMargins(0, 0, 30, 0);

    QVBoxLayout *group_box1_layout = new QVBoxLayout();
    group_box1_layout->addWidget(file_safe_label);
    group_box1_layout->addLayout(group_box1_h_layout);
    group_box1_layout->setSpacing(0);
    group_box1_layout->setContentsMargins(30, 0, 0, 10);
    tab6_group_box1->setLayout(group_box1_layout);

    QVBoxLayout *group_box2_layout = new QVBoxLayout();
    group_box2_layout->addWidget(internet_safe_label);
    group_box2_layout->addWidget(internet_safe_check_box);
    group_box2_layout->setSpacing(0);
    group_box2_layout->setContentsMargins(30, 0, 0, 10);
    tab6_group_box2->setLayout(group_box2_layout);

    tab6_group_box1->setFixedSize(480, 120);
    tab6_group_box2->setFixedSize(480, 120);

    QVBoxLayout *group_layout = new QVBoxLayout();
    group_layout->addWidget(tab6_group_box1, 0, Qt::AlignCenter);
    group_layout->addWidget(tab6_group_box2, 0, Qt::AlignCenter);
    group_layout->addStretch();
    group_layout->setSpacing(10);
    group_layout->setContentsMargins(0, 20, 0, 0);
    m_tab6->setLayout(group_layout);

}
