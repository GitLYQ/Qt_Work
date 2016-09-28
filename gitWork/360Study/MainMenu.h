#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMenu>

class MainMenu : public QMenu
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = 0);
    void translateActions();

signals:

    void sigShowSettingDialog();
    void sigShowNewCharacter();
    void sigShowAboutUs();

private slots:

    void slotShowUrlPage();

private:

    void createActions();


private:
    QAction *m_actionSetting;       //设置
    QAction *m_actionNewCharacter;  //新版特性
    QAction *m_actionCheckUpdate;   //检查更新
    QAction *m_actionChangeCompany; //切换为企业版
    QAction *m_actionHelpOnline;    //在线帮助
    QAction *m_actionPlatformHelp;  //论坛求助
    QAction *m_actionLoginHome;     //360网站
    QAction *m_actionProtect;       //隐私保护
    QAction *m_actionAboutUs;       //关于我们

};

#endif // MAINMENU_H
