#include "NewCharacterWin.h"
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QApplication>

#include <unistd.h>


NewCharacterWin::NewCharacterWin(QWidget *parent) :
    QWidget(parent)
{
    this->resize(WINDOW_WIDTH,WINDOW_HEIGHT);
    this->setWindowFlags(Qt::FramelessWindowHint);

    m_bIsTotalLabMove    = true;
    m_nCurrentImageIndex = 0;
    m_bIsMousePress      = false;
    m_bIsWinMove         = false;


    initUI();
    translateLanguage();
}


void NewCharacterWin::initUI()
{
    m_backImageLab = new QLabel(this);
    m_backImageLab->setPixmap(QPixmap(":/newCharacter/bg_bottom"));
    m_backImageLab->setGeometry(0,0,this->width(),this->height());


    QPixmap pixTotal(this->width()*WINDOW_PAGE_COUNT,this->height());
    QPainter painter(&pixTotal);
    for(int i =0; i < WINDOW_PAGE_COUNT; i++ )
    {
        painter.drawImage(QRect(this->width()*i,0,WINDOW_WIDTH,WINDOW_HEIGHT),\
                          QImage(QString(":/newCharacter/desktop_%1").arg(i)));
    }

    m_totalImageLab = new QLabel(this);
    m_totalImageLab->resize(pixTotal.size());
    m_totalImageLab->setPixmap(pixTotal);
    m_totalImageLab->move(WINDOW_START_X,WINDOW_START_Y);

    m_closeBtn = new MyPushButton(this);
    m_closeBtn->setPicName(":/sysButton/close");
    m_closeBtn->move(this->width() - m_closeBtn->width() - 5, 0);
    connect(m_closeBtn,SIGNAL(clicked()),this,SLOT(hide()));

    for(int i =0; i < WINDOW_PAGE_COUNT; i++ )
    {
        CharacterButton *charaBtn = new CharacterButton(this);
        charaBtn->setIconPixmap(QPixmap(QString(":/newCharacter/btn_%1").arg(i)));
        charaBtn->resize(QSize(155, 45));
        charaBtn->move(8+i*170, 319);
        connect(charaBtn,SIGNAL(sigPressed(CharacterButton*)),this,SLOT(slotCharaBtnPressed(CharacterButton *)));
        m_charaBtnArry[i] = charaBtn;
    }
    m_charaBtnArry[0]->setMousePressFlag(true);

}


void NewCharacterWin::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton)
    {
        qDebug()<< "NewCharacterWin::mousePressEvent--LeftButton ";
        qDebug()<< "NewCharacterWin::mousePressEvent--event->pos()= "<<event->pos();
        m_mouseSrcPos = event->pos();
        if ( m_mouseSrcPos.y() < 40 )
        {
            m_bIsWinMove = true;
        }
        else
        {
            m_currentPos_x = m_totalImageLab->x();
            m_bIsMousePress = true;
        }

    }
    else if ( event->button() == Qt::RightButton )
    {
        qDebug()<< "NewCharacterWin::mousePressEvent--RightButton ";
        if ( m_bIsTotalLabMove )
        {
            if ( m_nCurrentImageIndex > 0 )
            {
                m_nCurrentImageIndex--;
                moveCurrentPage(false);
            }
        }
    }

    QWidget::mousePressEvent(event);

}


void NewCharacterWin::mouseReleaseEvent(QMouseEvent *event)
{
    int nOffset = 0;
    if ( true == m_bIsMousePress )
    {
        if ( true == m_bIsTotalLabMove )
        {
            m_mouseDstPos = event->pos();
            nOffset = m_mouseDstPos.x() - m_mouseSrcPos.x();
            qDebug() << "m_mouseDstPos="<<m_mouseDstPos;
            qDebug() << "m_mouseSrcPos="<<m_mouseSrcPos;

            if ( nOffset > 0 )  //鼠标从左往右移动
            {
                if ( nOffset >= WINDOW_ONEBUTTON_WIDTH)  //移动距离超过WINDOW_ONEBUTTON_WIDTH
                {
                    if ( m_nCurrentImageIndex > 0 )  //m_totalImageLab的x坐标往右移动,显示 m_nCurrentImageIndex-1 对应的图片
                    {
                        m_nCurrentImageIndex--;
                        moveCurrentPage(false);
                    }
                    else  //m_totalImageLab的x坐标往左移动，恢复原图
                    {
                        moveCurrentPage(true);
                    }
                }
                else //m_totalImageLab的x坐标往左移动，恢复原图
                {
                    moveCurrentPage(true);
                }
            }
            else
            {
                if( nOffset <= -WINDOW_ONEBUTTON_WIDTH)
                {
                    if(m_nCurrentImageIndex < WINDOW_PAGE_COUNT-1)
                    {
                        m_nCurrentImageIndex++;
                        moveCurrentPage(true); //左移
                    }
                    else
                    {
                        moveCurrentPage(false); //右移
                    }
                }
                else
                {
                    moveCurrentPage(false); //右移
                }
            }

            m_bIsMousePress = false;
        }
    }
    else if ( m_bIsWinMove)  //窗体移动
    {
        m_bIsWinMove = false;
    }
}


void NewCharacterWin::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug()<< "NewCharacterWin::mousePressEvent--m_bIsMousePress |  m_bIsWinMove "<< m_bIsMousePress << m_bIsMousePress;
    int nOffset = 0;
    if ( m_bIsMousePress )
    {
        if( m_bIsTotalLabMove)
        {
            m_mouseDstPos = event->pos();
            nOffset = m_mouseDstPos.x() - m_mouseSrcPos.x();

            setLabelMove(false);
            m_totalImageLab->move(m_currentPos_x + nOffset, WINDOW_START_Y);
            setLabelMove(true);
        }
    }
    else if ( m_bIsWinMove )
    {
        m_mouseDstPos = event->pos();
        this->move(this->pos() + m_mouseDstPos - m_mouseSrcPos );
    }


}


void NewCharacterWin::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< "event->key()="<<event->key();
    if ( m_bIsTotalLabMove )
    {
        switch (event->key())
        {

        case Qt::Key_A:
        case Qt::Key_W:
        {
            if ( m_nCurrentImageIndex > 0 )
            {
                m_nCurrentImageIndex--;
                moveCurrentPage(false);
            }
            break;
        }
        case Qt::Key_S:
        case Qt::Key_D:
        {
            if( m_nCurrentImageIndex < WINDOW_PAGE_COUNT-1 )
            {
                m_nCurrentImageIndex++;
                moveCurrentPage(true);
            }
            break;
        }
        default:
            break;
        }
    }

}


void NewCharacterWin::translateLanguage()
{
    m_charaBtnArry[0]->setTextLabText(tr("function"));
    m_charaBtnArry[1]->setTextLabText(tr("clear cookie"));
    m_charaBtnArry[2]->setTextLabText(tr("triggerman"));
    m_charaBtnArry[3]->setTextLabText(tr("booster"));

    m_closeBtn->setToolTip(tr("close"));
}


void NewCharacterWin::slotCharaBtnPressed(CharacterButton *btn)
{
    int nCharaBtnIndex = 0;
    for ( int i =0; i < WINDOW_BUTTON_COUNT; i++) //获取目标图索引
    {
        if ( m_charaBtnArry[i] == btn )
        {
            nCharaBtnIndex = i;
            break;
        }
    }

    //qDebug() << "nCharaBtnIndex="<<nCharaBtnIndex;
    //qDebug() << "m_nCurrentImageIndex="<<m_nCurrentImageIndex;
    if( m_nCurrentImageIndex < nCharaBtnIndex )
    {
        while (m_nCurrentImageIndex != nCharaBtnIndex)  //解决跨图切换问题，如从图一切换到图三
        {
            m_nCurrentImageIndex++;
            moveCurrentPage(true);
        }
    }
    else
    {
        while (m_nCurrentImageIndex != nCharaBtnIndex)
        {
            m_nCurrentImageIndex--;
            moveCurrentPage(false);
        }
    }
    //qDebug() << "m_nCurrentImageIndex="<<m_nCurrentImageIndex;
}

void NewCharacterWin::changeCurrentButton()
{
    for(int i=0; i<WINDOW_BUTTON_COUNT; i++)
    {
        if(i != m_nCurrentImageIndex )
        {
            m_charaBtnArry[i]->setMousePressFlag(false);
        }
        else
        {
            m_charaBtnArry[i]->setMousePressFlag(true);
        }
    }
}

void NewCharacterWin::setLabelMove(bool bIsTotalMove)
{
    m_bIsTotalLabMove = bIsTotalMove;
}

void NewCharacterWin::moveCurrentPage(bool bDirection)
{
    changeCurrentButton();


    //图片的几个分割点
    //0-680, 680-1360, 1360-2040, 2040-2720
    //x坐标：  真-向左移;  假-向右移

    //左移的几种可能性,对于x坐标
    //index=0, 将label移动到-680*0
    //index=1, 将label移动到-680*1
    //index=2, 将label移动到-680*2
    //index=3, 将label移动到-680*3
    setLabelMove(false);
    int current_pos_x = m_totalImageLab->x(); //当前label坐标
    int dest_pos_x = -WINDOW_WIDTH * m_nCurrentImageIndex; //目标X坐标
    //qDebug()<< "current_pos_x=" << current_pos_x;
    //qDebug()<< "dest_pos_x=" << dest_pos_x;
    if(bDirection)
    {
        while(current_pos_x > dest_pos_x)
        {
            //qDebug()<< "x move to left " << current_pos_x-WINDOW_PAGE_MOVE;
            m_totalImageLab->move(current_pos_x-WINDOW_PAGE_MOVE, WINDOW_START_Y);//每次移动20px
            current_pos_x = m_totalImageLab->x();
            usleep(1000*10);  //每0.01s移动一次
            qApp->processEvents(QEventLoop::AllEvents);
        }
    }
    else
    {
        while(current_pos_x < dest_pos_x)
        {
            //qDebug()<< "x move to right " << current_pos_x+WINDOW_PAGE_MOVE;
            m_totalImageLab->move(current_pos_x+WINDOW_PAGE_MOVE, WINDOW_START_Y);
            current_pos_x = m_totalImageLab->x();
            qApp->processEvents(QEventLoop::AllEvents);
        }
    }

    m_totalImageLab->move(dest_pos_x, WINDOW_START_Y);
    setLabelMove(true);

}
