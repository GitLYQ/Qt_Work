#include "DropShadowWin.h"

#include <QMouseEvent>
#include <QPainter>
#include <qmath.h>
#include <QDebug>

DropShadowWin::DropShadowWin(QWidget *parent) :
    QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);

    m_bIsLeftMousePress = false;
}


void DropShadowWin::paintEvent(QPaintEvent *)
{
    QPainterPath painterPath;
    painterPath.setFillRule(Qt::WindingFill);
    painterPath.addRect(10,10,this->width()-20,this->height()-20);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(painterPath,QBrush(Qt::white));

    QColor color(0,0,0,50);
    for( int i = 0 ; i < 10; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
        color.setAlpha(150 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
    //qDebug() << "DropShadowWin::paintEvent";
}

void DropShadowWin::mousePressEvent(QMouseEvent *event)
{
    if ( Qt::LeftButton == event->button() )
    {
        m_bIsLeftMousePress = true;
    }

    m_movePoint = event->globalPos() - pos();
}

void DropShadowWin::mouseReleaseEvent(QMouseEvent *)
{
    m_bIsLeftMousePress = false;
}

void DropShadowWin::mouseMoveEvent(QMouseEvent *event)
{
    if ( m_bIsLeftMousePress )
    {
        move( event->globalPos() - m_movePoint );
    }
}
