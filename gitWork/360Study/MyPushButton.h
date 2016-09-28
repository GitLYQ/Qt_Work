#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);


    void setPicName(QString strPicName);

protected:

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void paintEvent(QPaintEvent *);

signals:

public slots:


private:
    QString m_strPicName;

    enum ButtonStatus {NORMAL,ENTER,PRESS,NOSTATUS};
    ButtonStatus m_enButtonStatus;
    bool m_bIsMousePress;
};

#endif // MYPUSHBUTTON_H
