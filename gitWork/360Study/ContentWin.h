#ifndef CONTENTWIN_H
#define CONTENTWIN_H

#include <QWidget>
#include <QSplitter>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>

class ContentWin : public QWidget
{
    Q_OBJECT
public:
    explicit ContentWin(QWidget *parent = 0);

    void initLeftWidget();
    void initRightTop();
    void initRightCenter();
    void initRightCenterFunction();
    void initRightBottom();

    void translateLanguage();

protected:
    bool eventFilter(QObject *, QEvent *);
signals:
    void sigLoginBtnClicked();
    void sigRegisterBtnClicked();

public slots:

private:
    QSplitter *m_mainSplitter;
    QSplitter *m_rightSplitter;


    QWidget     *m_leftWidget;
    QLabel      *m_leftWidget_imageLab;
    QLabel      *m_leftWidget_suggestLab;
    QLabel      *m_leftWidget_systemSafeLab;
    QPushButton *m_leftWidget_powerButton;      //立即体检按钮

    QWidget     *m_rightTopWidget;
    QPushButton *m_rightTopWidget_loginBtn;     //登录我的360帐号
    QLabel      *m_rightTopWidget_privLab;      //皇砖图标
    QLabel      *m_rightTopWidget_infoLab;      //开启炫动卫视图标
    QLabel      *m_rightTopWidget_privilegeLab; //转享特权
    QPushButton *m_rightTopWidget_registerBtn;  //10秒免费注册
    QPushButton *m_rightTopWidget_safeBtn;      //特权领360炫动logo
    QPushButton *m_rightTopWidget_tabBtn;       //领取炫动导航功能图标
    QPushButton *m_rightTopWidget_petBtn;       //宠物安仔精灵
    QPushButton *m_rightTopWidget_lotteryBtn;   //按在抱枕大派送
    QPushButton *m_rightTopWidget_cloudFiveBtn; //5G云盘
    QPushButton *m_rightTopWidget_caipiaoBtn;   //彩票


    QWidget     *m_rightCenterWidget;
    QToolButton *m_rightCenterWidget_fireproofBtn;  //360防火墙
    QToolButton *m_rightCenterWidget_triggermanBtn; //360保镖
    QToolButton *m_rightCenterWidget_netShopBtn;   //网购先赔
    QLabel      *m_rightCenterWidget_lineLab1;      //虚线
    QLabel      *m_rightCenterWidget_lineLab2;      //虚线

    QWidget     *m_rightCenterFuncWidget;
    QLabel      *m_rightCenterFuncWidget_functionLab;        //功能大全
    QPushButton *m_rightCenterFuncWidget_moreBtn;           //更多
    QList<QToolButton *> m_rightCenterFuncWidget_btnList;   //按钮容器

    QWidget     *m_rightBottomWidget;
    QLabel      *m_rightBottomWidget_iconLab;    //云图标
    QLabel      *m_rightBottomWidget_connectLab; //成功连接云安全
    QLabel      *m_rightBottomWidget_versionLab; //版本号
    QPushButton *m_rightBottomWidget_versionBtn; //版本升级


};

#endif // CONTENTWIN_H
