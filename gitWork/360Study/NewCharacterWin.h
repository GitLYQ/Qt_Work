#ifndef NEWCHARACTERWIN_H
#define NEWCHARACTERWIN_H

#include <QWidget>
#include <QLabel>

#include "CharacterButton.h"
#include "MyPushButton.h"
#include "Common.h"

class NewCharacterWin : public QWidget
{
    Q_OBJECT
public:
    explicit NewCharacterWin(QWidget *parent = 0);

    void initUI();
    void translateLanguage();


protected:

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    void changeCurrentButton();
    void setLabelMove(bool);
    void moveCurrentPage(bool);

signals:

public slots:
    void slotCharaBtnPressed(CharacterButton *);
    //void changeCurrentPage(CLabel *);



private:
    CharacterButton *m_charaBtnArry[4];    //按钮数组
    QLabel          *m_backImageLab;       //默认背景图片
    QLabel          *m_totalImageLab;      //4合1大图片
    MyPushButton    *m_closeBtn;           //关闭按钮


    int              m_nCurrentImageIndex; //当前显示图片下标

    bool             m_bIsTotalLabMove;
    bool             m_bIsWinMove;
    bool             m_bIsMousePress;
    QPoint           m_mouseSrcPos;
    QPoint           m_mouseDstPos;
    int              m_currentPos_x;
};

#endif // NEWCHARACTERWIN_H
