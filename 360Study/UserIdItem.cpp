#include "UserIdItem.h"
#include <QMouseEvent>
#include <QLayout>

UserIdItem::UserIdItem(QWidget *parent) :
    QWidget(parent)
{

    m_deleteBtn = new QPushButton;
    QPixmap pixmap(":/loginDialog/delete");
    m_deleteBtn->setIcon(pixmap);
    m_deleteBtn->setIconSize(pixmap.size());
    m_deleteBtn->setStyleSheet("background:transparent;");

    m_userIdLab = new QLabel;

    QHBoxLayout  *mainHLay = new QHBoxLayout;
    mainHLay->addWidget(m_userIdLab);
    mainHLay->addStretch();
    mainHLay->addWidget(m_deleteBtn);
    mainHLay->setSpacing(5);
    mainHLay->setContentsMargins(5,5,5,5);

    this->setLayout(mainHLay);

    m_bIsMousePress = false;
    connect(m_deleteBtn,SIGNAL(clicked()),this,SLOT(slotRemovUserId()));
}


void UserIdItem::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
        m_bIsMousePress = true;
}

void UserIdItem::mouseReleaseEvent(QMouseEvent *event)
{
     if ( m_bIsMousePress && ( this->rect().contains(event->pos() )))
     {
         emit sigShowUserId(m_userIdLab->text());
     }
     m_bIsMousePress = false;
}

void UserIdItem::setUserIdLabText(const QString strUserId)
{
    m_userIdLab->setText(strUserId);
}

QString UserIdItem::getUserIdLabText() const
{
    return m_userIdLab->text();
}


void UserIdItem::slotRemovUserId()
{
    emit sigRemoveUserId(m_userIdLab->text());
}
