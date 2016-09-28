#include "MyPushButton.h"

#include <QPainter>

MyPushButton::MyPushButton(QWidget *parent) :
    QPushButton(parent)
{
    m_enButtonStatus = NORMAL;
    m_bIsMousePress  = false;
}


void MyPushButton::setPicName(QString strPicName)
{
    m_strPicName = strPicName;
    setFixedSize(QPixmap(m_strPicName).size());
}


void MyPushButton::enterEvent(QEvent *)
{
    m_enButtonStatus = ENTER;
    update();
}

void MyPushButton::leaveEvent(QEvent *)
{
    m_enButtonStatus = NORMAL;
    update();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if ( Qt::LeftButton ==  e->button() )
    {
        m_enButtonStatus = PRESS;
        m_bIsMousePress = true;
        update();
        emit clicked();
    }
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if ( ( this->rect().contains(e->pos()) ) && ( true == m_bIsMousePress ) )
    {
        m_enButtonStatus = NORMAL;
        m_bIsMousePress = false;
        update();
    }
}


void MyPushButton::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPixmap  pix;

    switch (m_enButtonStatus)
    {

        case NORMAL:
        {
            pix.load(m_strPicName);
            break;
        }
        case ENTER:
        {
            pix.load(m_strPicName + QString("_hover"));
            break;
        }
        case PRESS:
        {
            pix.load(m_strPicName + QString("_pressed"));
            break;
        }
        case NOSTATUS:
        {
            pix.load(m_strPicName);
            break;
        }
        default:
            pix.load(m_strPicName);
            break;
    }

    p.drawPixmap(this->rect(),pix);
}
