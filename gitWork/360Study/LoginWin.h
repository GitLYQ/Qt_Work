#ifndef LOGINWIN_H
#define LOGINWIN_H

#include "DropShadowWin.h"
#include "MyPushButton.h"
#include "Common.h"
#include "MsgBoxWin.h"
#include "LoadingWin.h"

#include <QStackedLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QListWidget>
#include <QLayout>

class LoginWin : public DropShadowWin
{
    Q_OBJECT
public:
    explicit LoginWin(QWidget *parent = 0);
    void translateLanguage();

protected:

    void paintEvent(QPaintEvent *event);

private:

    void initTitle();
    void initBottom();
    void initSafeWidget();
    void initRenRenWidget();
    void initSinaWidget();
    void initLoginCenter();

    void initSafeRenRenWidget();

    void changeTitle();
    void turnWidget();

signals:

public slots:
    void slotRemoveUserId(QString);
    void slotShowUserId(QString);

    void slotTurnSina();
    void slotTurnRenRen();
    void slotVerify();
private:
    QStackedLayout *m_mainStackLay;     //新浪、360、人人网界面
    QStackedLayout *m_stackLay;         //360、人人网界面
    QStackedLayout *m_loginStackLay;    //360、登录验证界面


    QWidget *m_safeRenrenCenterWidget;
    QWidget *m_safeRenrenWidget;

    QWidget *m_safeWidget;//安全卫士界面
    QLabel  *m_safeWidget_iconLab;
    QLabel  *m_safeWidget_safeLab;
    QLabel  *m_safeWidget_protectLab;

    QWidget *m_renrenWidget; //人人界面
    QLabel  *m_renrenWidget_iconLab;
    QLabel  *m_renrenWidget_infoLab;
    QLabel  *m_renrenWidget_netLab;
    QLabel  *m_renrenWidget_loginLab;

    QWidget     *m_sinaWidget;                  //新浪界面
    QLabel      *m_sinaWidget_iconLab;          //新浪图标
    QLabel      *m_sinaWidget_infoLab;          //新浪微博
    QLabel      *m_sinaWidget_netLab;           //sina.com
    QPushButton *m_sinaWidget_registerBtn;      //新浪注册按钮
    QLineEdit   *m_sinaWidget_userIDLedit;      //新浪帐号
    QLineEdit   *m_sinaWidget_passwordLedit;    //新浪密码
    QPushButton *m_sinaWidget_examineAuthorizeBtn;  //查看授权信息
    QPushButton *m_sinaWidget_authorizeBtn;         //授权按钮
    QCheckBox   *m_sinaWidget_loginCbox;            //自动登录
    QCheckBox   *m_sinaWidget_attentionSafeCbox;    //关注360安全卫士

    QLabel      *m_titleLab;
    QLabel      *m_userIdLab;
    QLabel      *m_passwordLab;
    QComboBox   *m_userIdCbox;
    QLabel      *m_otherUserIdLab;
    MyPushButton *m_closeBtn;
    QPushButton *m_sinaBtn;
    QPushButton *m_renrenBtn;
    QLineEdit   *m_passwordLedit;
    QPushButton *m_registerBtn;
    QPushButton *m_forgotBtn;
    QPushButton *m_loginBtn;
    QCheckBox   *m_rememberCbox;
    QCheckBox   *m_autoLoginCbox;
    QListWidget *m_listWidget;
    QHBoxLayout *m_titleHLay;
    QHBoxLayout *m_bottomHLay;

    LOGIN m_enLogin;            //登录显示的界面
    LOGIN m_enSinaLogin;        //新浪按钮表示的界面

    MsgBoxWin   *m_msgBox;      //删除用户提示界面
    LoadingWin  *m_loadingWin;  //等待界面，正在登录


};

#endif // LOGINWIN_H
