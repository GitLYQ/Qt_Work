#ifndef SETTINGWIN_H
#define SETTINGWIN_H

#include "DropShadowWin.h"
#include "MyPushButton.h"
#include "Common.h"

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QTabWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QComboBox>


class SettingWin : public DropShadowWin
{
    Q_OBJECT
public:
    explicit SettingWin(QWidget *parent = 0);

    void initTitle();
    void initCenter();
    void initBottom();

    void initTab1();
    void initTab2();
    void initTab3();
    void initTab4();
    void initTab5();
    void initTab6();

    void translateLanguage();


protected:
    void paintEvent(QPaintEvent *event);

signals:
    void sigChangeLanguage(LANGUAGE);
public slots:
    void slotUpdateConfig();

private:
    MyPushButton    *m_closeBtn;
    QLabel          *m_titleIconLab;
    QLabel          *m_titleContentLab;
    QHBoxLayout     *m_titleLay;

    QPushButton     *m_okBtn;
    QPushButton     *m_cancleBtn;
    QHBoxLayout     *m_bottomLay;

    QTabWidget      *m_tabWidget;
    QWidget         *m_tab1; //升级方式
    QWidget         *m_tab2; //高级设置
    QWidget         *m_tab3; //体验设置
    QWidget         *m_tab4; //用户设置
    QWidget         *m_tab5; //改善计划
    QWidget         *m_tab6; //云安全计划

    //tab1
    QGroupBox       *tab1_group_box;
    QRadioButton    *auto_rise_button;      //自动升级
    QRadioButton    *not_auto_rise_button;  //不自动升级
    QCheckBox       *rise_mummy_check_box;  //不升级但备用木马库
    QCheckBox       *game_check_box;        //游戏时不升级
    QCheckBox       *g3_check_box;          //3G上网时不升级
    QCheckBox       *p2p_check_box;         //使用p2p/p2s技术为升级程序加速
    QCheckBox       *mummy_check_box;       //备用木马库升级完成后右下角提示

    //tab2
    QGroupBox       *tab2_group_box1;
    QGroupBox       *tab2_group_box2;
    QGroupBox       *tab2_group_box3;
    QCheckBox       *auto_start_check_box;  //开机自启动
    QCheckBox       *remove_own_check_box;  //解除占有
    QCheckBox       *strong_remove_check_box; //强力删除
    QCheckBox       *mummy_kill_check_box;  //木马云查杀
    QCheckBox       *display_count_check_box; //显示软件升级数

    //tab3
    QGroupBox       *tab3_group_box1;
    QGroupBox       *tab3_group_box2;
    QRadioButton    *auto_check_button;     //每次启动自动体检
    QRadioButton    *first_check_button;    //首次开启体检
    QRadioButton    *hand_check_button;     //手动进行体检
    QRadioButton    *select_quit_button;    //选择退出方式
    QRadioButton    *backstage_mode_button; //后台模式
    QRadioButton    *immediacy_close_button; //直接关闭

    //tab4
    QGroupBox       *tab4_group_box;
    QCheckBox       *diaplay_experience_check_box;  //完成任务显示获取经验值的动态提醒
    QCheckBox       *diaplay_login_check_box;       //自动登录后显示登录提示窗口
    QCheckBox       *tray_quit_check_box;           //托盘退出登录后显示提示窗口
    QCheckBox       *new_character_check_box;       //有新特权时显示通知窗口
    QCheckBox       *rise_remind_check_box;         //升级提醒通知窗口
    QLabel          *language_label;                //语言标签
    QComboBox       *language_combo_box;            //语言下拉框

    //ta5
    QGroupBox       *tab5_group_box;
    QCheckBox       *improve_plan_check_box;        //参加“360用户体检改善计划”
    QPushButton     *understand_detail_button;      //了解详情

    //tab6
    QGroupBox       *tab6_group_box1;
    QGroupBox       *tab6_group_box2;
    QLabel          *file_safe_label;               //文件安全承诺
    QLabel          *internet_safe_label;           //网址安全承诺
    QCheckBox       *file_safe_check_box;           //加入360“文件云安全计划”
    QCheckBox       *internet_safe_check_box;       //加入360“网址云安全计划”
    QPushButton     *look_privacy_button;           //查看360用户隐私保护承诺



};

#endif // SETTINGWIN_H
