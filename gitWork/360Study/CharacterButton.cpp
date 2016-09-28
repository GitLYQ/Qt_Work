#include "CharacterButton.h"
#include <QLayout>
#include <QPen>
#include <QPainter>
#include <QLinearGradient>

CharacterButton::CharacterButton(QWidget *parent) :
    QWidget(parent)
{
    initUI();
}

void CharacterButton::initUI()
{
    this->setStyleSheet("QWidget {background:transparent;border:0px;color:white;font-weight:bold;font-size:16px;}");

    m_iconLab = new QLabel;
    m_textLab = new QLabel;

    QHBoxLayout *hlay = new QHBoxLayout;
    hlay->addWidget(m_iconLab);
    hlay->addWidget(m_textLab);
    hlay->addStretch();
    hlay->setSpacing(10);
    hlay->setContentsMargins(5,0,5,0);
    this->setLayout(hlay);

    setMouseEnterFlag(false);
    setMousePressFlag(false);
}


void CharacterButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if ( getMousePressFlag() )
    {
        paintWiget(80,&painter);
    }
    else if ( getMouseEnterFlag() )
    {
        paintWiget(50,&painter);
    }
}

void CharacterButton::leaveEvent(QEvent *)
{
    setMouseEnterFlag(false);
}

void CharacterButton::enterEvent(QEvent *)
{
    if ( !getMousePressFlag())
    {
        setMouseEnterFlag(true);
    }
    this->setCursor(Qt::PointingHandCursor);
}

void CharacterButton::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
    {
        setMousePressFlag(true);
        emit sigPressed(this);
    }
}


void CharacterButton::paintWiget(int nAlpha,QPainter *painter)
{

    QPen pen(Qt::NoBrush,1);
    painter->setPen(pen);
    QLinearGradient linearG(this->rect().topLeft(),this->rect().bottomLeft());
    linearG.setColorAt(0,QColor(255,255,255,nAlpha));

    QBrush brush(linearG);
    painter->setBrush(brush);
    painter->drawRoundedRect(this->rect(),2,2);
}


void CharacterButton::setIconPixmap(const QPixmap &pix)
{
    m_iconLab->setPixmap(pix.scaled(QSize(30,30),Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

void CharacterButton::setTextLabText(const QString &str)
{
    m_textLab->setText(str);
}
