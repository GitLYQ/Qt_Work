#ifndef MYTOOLBUTTON_H
#define MYTOOLBUTTON_H

#include <QToolButton>

class MyToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit MyToolButton(QString strPicName,QWidget *parent = 0);

    void setPicName(QString strPicName);

    void setMousePress(bool mouse_press);
protected:

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void painterInfo(int top_color, int middle_color, int bottom_color);

signals:

public slots:

private:

    QString m_strPicName;

    bool m_bIsMouseHover;
    bool m_bIsMousePress;
};

#endif // MYTOOLBUTTON_H
