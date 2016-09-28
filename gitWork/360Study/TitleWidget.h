#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QList>

#include "MyToolButton.h"
#include "MyPushButton.h"


class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget *parent = 0);

    void initFirstRow();
    void initSecondRow();

    void translateLanguage();

signals:
    void sigTurnPage(int);
    void sigShowSkin();
    void sigShowMin();
    void sigShowMainMenu();
    void sigCloseWidget();



public slots:
    void slotTurnPage(QString);
    void slotCloseBtnClicked();
private:

    QLabel       *m_versionTitle;       //标题
    MyPushButton *m_dedalBtn;           //勋章墙
    MyPushButton *m_skinBtn;            //换肤
    MyPushButton *m_mainMenuBtn;        //主菜单
    MyPushButton *m_feedBackBtn;        //反馈意见
    MyPushButton *m_minBtn;             //最小化
    MyPushButton *m_closeBtn;           //关闭



    QLabel       *m_360Lab;
    QLabel       *m_safeLab;
    QLabel       *m_logoLab;
    QList<MyToolButton *>  m_listToolBtn;

    QHBoxLayout  *m_firstRowHLay;
    QHBoxLayout  *m_secondRowHLay;
    QVBoxLayout  *m_mainVLay;
};

#endif // TITLEWIDGET_H
