#include "SkinItemWin.h"

#include <QLayout>
#include <QPainter>

SkinItemWin::SkinItemWin(QWidget *parent) :
    QWidget(parent)
{
    m_bIsMouseEnter = false;
    m_bIsMousePress = false;

    initUI();
}

void SkinItemWin::initUI()
{
    m_imageLab = new QLabel();
    m_nameLab = new QLabel();
    m_downloadNumLab = new QLabel();
    m_useBtn = new QPushButton;

    this->setCursor(Qt::PointingHandCursor);

    m_useBtn->setObjectName("skinButton");
    m_imageLab->setScaledContents(true);
    m_imageLab->setFixedSize(100, 65);
    m_useBtn->setFixedSize(85, 25);

    QVBoxLayout *background_layout = new QVBoxLayout();
    background_layout->addWidget(m_imageLab, 0, Qt::AlignCenter);
    background_layout->addWidget(m_nameLab, 0, Qt::AlignCenter);
    background_layout->addWidget(m_downloadNumLab, 0, Qt::AlignCenter);
    background_layout->addWidget(m_useBtn, 0, Qt::AlignCenter);
    background_layout->setSpacing(5);
    background_layout->setContentsMargins(0, 10, 0, 10);

    connect(m_useBtn, SIGNAL(clicked()), this,SLOT(slotUseSkin()));

    this->setLayout(background_layout);
    translateLanguage();
}

void SkinItemWin::translateLanguage()
{
    m_useBtn->setText(tr("use skin"));
}


QString SkinItemWin::getPixmapName()
{
    return m_pixmapName;
}

void SkinItemWin::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton )
    {
        m_bIsMousePress = true;
    }
}

void SkinItemWin::mouseReleaseEvent(QMouseEvent *event)
{
    if ( m_bIsMousePress && this->rect().contains(event->pos()) )
    {
        emit sigChangeSkin();
    }
    m_bIsMousePress = false;
}

void SkinItemWin::leaveEvent(QEvent *)
{
    m_bIsMouseEnter = false;
    update();
}

void SkinItemWin::enterEvent(QEvent *)
{
    m_bIsMouseEnter = true;
    update();
}

void SkinItemWin::paintEvent(QPaintEvent *)
{
    if ( m_bIsMouseEnter )
    {
        QPainter painter(this);
        painter.setPen(QPen(QColor(210, 225, 230)));
        painter.drawRoundRect(QRect(0,0,this->width()-1,this->height()-1),5,5);
    }
}

void SkinItemWin::slotChangeSkin(QString pixmap_name, QString skin_name, QString download_count)
{
    QString background_name = pixmap_name + "_big";
    this->m_pixmapName = background_name;

    //更改皮肤背景
    QPixmap pixmap(background_name);
    m_imageLab->setPixmap(pixmap);

    //更改皮肤名称
    m_nameLab->setText(skin_name);

    //更改下载次数
    m_downloadNumLab->setText(tr("download count:") + download_count);
}


void SkinItemWin::slotUseSkin()
{
    emit sigChangeSkin();
}
