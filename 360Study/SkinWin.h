#ifndef SKINWIN_H
#define SKINWIN_H

#include "DropShadowWin.h"
#include "MyPushButton.h"
#include "SkinItemWin.h"
#include "Common.h"

#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QList>


class SkinWin : public DropShadowWin
{
    Q_OBJECT
public:
    explicit SkinWin(QWidget *parent = 0);

    void initTitle();
    void initCenter();
    void initBottom();

    void translateLanguage();

protected:

    void paintEvent(QPaintEvent *event);

signals:
    void sigChangeSkin(QString strSkinName);

public slots:
    void slotChangeSkin();
    void slotShowSkin(QString);
private:
    int     m_totalPageCount;           //总页数
    int     m_lastPageCount;            //最后一页的显示个数
    int     m_currentPage;              //当前为第几页
    bool    m_bIsSkinChange;            //是否改变背景
    QString m_skinName;                 //背景图片

    QLabel          *m_titleContentLab; //标题
    QLabel          *m_titleIconLab;    //标题图标
    MyPushButton    *m_closeBtn;        //关闭按钮
    QHBoxLayout     *m_titleLay;

    QStringList     m_skinPathList;     //图片路径列表
    QGridLayout     *m_centerLay;       //
    QList<SkinItemWin *> m_skinItemList;//缩略图列表
    QStringList     m_skinNameTipList; //缩略图命名列表

    QHBoxLayout     *m_bottomLay;
    QPushButton     *m_firstPageBtn;    //首页
    QPushButton     *m_previousPageBtn; //上一页
    QPushButton     *m_nextPageBtn;     //下一页
    QPushButton     *m_lastPageBtn;     //末页
    QList<QPushButton *> m_pageBtnList; //数字页按钮列表
};

#endif // SKINWIN_H
