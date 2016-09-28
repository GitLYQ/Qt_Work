#ifndef DROPSHADOWWIN_H
#define DROPSHADOWWIN_H

#include <QDialog>


class DropShadowWin : public QDialog
{
    Q_OBJECT
public:
    explicit DropShadowWin(QWidget *parent = 0);

protected:

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);


signals:

public slots:



private:
    QPoint m_movePoint; //移动的距离
    bool m_bIsLeftMousePress; //按下鼠标左键

};

#endif // DROPSHADOWWIN_H
