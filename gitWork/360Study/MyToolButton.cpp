#include "MyToolButton.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

MyToolButton::MyToolButton(QString strPicName,QWidget *parent) :
    m_strPicName(strPicName),QToolButton(parent)
{
    //设置文本颜色
    QPalette textPalette = this->palette();
    textPalette.setColor(QPalette::ButtonText,QColor(230, 230, 230));
    this->setPalette(textPalette);

    //设置文本粗体
    QFont textFont = this->font();
    textFont.setBold(true);
    this->setFont(textFont);

    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //qDebug() << "m_strPicName=" << m_strPicName;
    QPixmap pix(m_strPicName);
    this->setIcon(QIcon(pix));
    this->setIconSize(pix.size());

    setFixedSize(pix.width()+ 25,pix.height()+25);
    setAutoRaise(true);
    setObjectName("transparentToolButton");

    m_bIsMouseHover = false;
    m_bIsMousePress = false;

}



void MyToolButton::enterEvent(QEvent *)
{
    m_bIsMouseHover = true;
}

void MyToolButton::leaveEvent(QEvent *)
{
    m_bIsMouseHover = false;
}


void MyToolButton::mousePressEvent(QMouseEvent *event)
{
    if ( Qt::LeftButton == event->button() )
    {
        emit clicked();
    }
}

void MyToolButton::paintEvent(QPaintEvent *event)
{
    if ( m_bIsMouseHover )
    {
        painterInfo(0,100,150);
    }
    else
    {
        if ( m_bIsMousePress )
            painterInfo(0,100,150);
    }

    QToolButton::paintEvent(event);
}

void MyToolButton::painterInfo(int top_color, int middle_color, int bottom_color)
{
    QPainter painter(this);
    QPen pen(Qt::NoBrush,1);
    painter.setPen(pen);

    QLinearGradient linear(this->rect().topLeft(),this->rect().bottomLeft());
    linear.setColorAt(0,  QColor(230, 230, 230, top_color));
    linear.setColorAt(0.5,QColor(230, 230, 230, middle_color));
    linear.setColorAt(1,  QColor(230, 230, 230, bottom_color));

    painter.setBrush(linear);
    painter.drawRect(this->rect());

    //qDebug() << "m_strPicName=" << m_strPicName;
}


void MyToolButton::setPicName(QString strPicName)
{
    m_strPicName = strPicName;
    setFixedSize(QPixmap(m_strPicName).size());
}


void MyToolButton::setMousePress(bool mouse_press)
{
    m_bIsMousePress = mouse_press;
    update();
}
