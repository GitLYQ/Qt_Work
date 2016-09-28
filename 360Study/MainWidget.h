#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QTranslator>

#include "DropShadowWin.h"
#include "TitleWidget.h"
#include "ContentWin.h"
#include "KillMummyWin.h"
#include "kill_mummy_widget.h"
#include "KillMummyWin.h"
#include "MySystemTray.h"

#include "RegisterWin.h"
#include "LoginWin.h"

#include "MainMenu.h"
#include "AboutUsWin.h"
#include "NewCharacterWin.h"
#include "SettingWin.h"
#include "SkinWin.h"


class MainWidget : public DropShadowWin
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void setTranslator(QTranslator* translator);

protected:

    virtual void paintEvent(QPaintEvent *event);

public slots:

    void slotShowWidget();

private slots:

    void slotCloseMainWin();
    void slotHideMainWin() ;
    void slotTurnPage(int nCurrentIndex);
    void slotShowMainMenu();
    void slotShowSkinWin();

    //系统托盘
    void slotSysemTrayIconIsActived(QSystemTrayIcon::ActivationReason reason);

    //标题栏-设置主菜单
    void slotShowSettingDialog();
    void slotShowAboutUs();
    void slotShowNewCharacter();
    void slotChangeLanguage(LANGUAGE language);

    //注册及登录界面
    void slotShowLoginWin();
    void slotShowRegisterWin();

    //标题栏-皮肤中心
    void slotChangeSkin(QString);

private:

    TitleWidget     *m_titleWidget;     //标题栏
    ContentWin      *m_contentWin;      //主界面内容
   // KillMummyWidget *m_killMummyWin;
    KillMummyWin    *m_killMummyWin;
    MySystemTray    *m_systemTray;      //托盘项
    QStackedWidget  *m_stackedWin;

    RegisterWin     *m_registerWin;     //注册账户界面
    LoginWin        *m_loginWin;        //登录界面

    MainMenu        *m_mainMenu;        //顶部主菜单
    AboutUsWin      *m_aboutUsWin;      //关于我们
    NewCharacterWin *m_newCharacterWin; //设置-新特性
    SettingWin      *m_settingWin;      //设置-相关设置
    SkinWin         *m_skinWin;         //皮肤界面

    QString          m_strBackPicName;  //主窗口背景图片的名称
    QTranslator     *m_translator;      //翻译器
    LANGUAGE         m_enLanguage;      //系统语言
};

#endif // MAINWIDGET_H
