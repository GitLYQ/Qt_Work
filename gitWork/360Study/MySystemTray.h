#ifndef MYSYSTEMTRAY_H
#define MYSYSTEMTRAY_H

#include <QSystemTrayIcon>
#include <QMenu>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QWidgetAction>

class MySystemTray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit MySystemTray(QWidget *parent = 0);

    void initTopWidgetAction();
    void initMiddleAction();
    void initBottomWidgetAction();

    void initMenu();

    void translateLanguage();

protected:

    bool eventFilter(QObject *, QEvent *);

signals:

    void sigShowWidget();

public slots:



private:
    QMenu           *m_mainMenu;                 //托盘菜单

    QWidget         *m_topWidget;                //顶部菜单项
    QPushButton     *m_topWidget_openBtn;        //木马防火墙已经开启
    QPushButton     *m_topWidget_enterBtn;       //进入
    QLabel          *m_topWidget_infoLab;        //360已保护电脑...天
    QWidgetAction   *m_topWidgetAction;

    QAction *m_actionOpen;          //打开360安全卫士
    QAction *m_actionHelpCenter;    //求助中心
    QAction *m_actionKillMummy;     //查杀木马
    QAction *m_actionClear;         //清理垃圾
    QAction *m_actionOptimize;      //一键优化
    QAction *m_actionFireproof;     //检查更新
    QAction *m_actionShowSpeed;     //显示加速球
    QAction *m_actionSoftManage;    //软件管家
    QAction *m_actionSafeNotice;    //安全通知
    QAction *m_actionRise;          //升级
    QAction *m_action_login;        //360用户登录
    QAction *m_action_separate;     //隔离沙箱
    QAction *m_action_logout;       //退出


    QWidget         *m_bottomWidget;             //底部菜单项
    QPushButton     *m_bottomWidget_gameBtn;     //进入游戏模式
    QPushButton     *m_bottomWidget_buyBtn;    //进入网购模式
    QWidgetAction   *m_bottomWidgetAction;

};

#endif // MYSYSTEMTRAY_H
