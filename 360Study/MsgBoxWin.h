#ifndef MSGBOXWIN_H
#define MSGBOXWIN_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

#include "DropShadowWin.h"
#include "MyPushButton.h"

class MsgBoxWin : public DropShadowWin
{
    Q_OBJECT
public:
    explicit MsgBoxWin(QWidget *parent = 0);

    void initUI();
    void translateLanguage();
    void setInfo(QString title_info, QString info, QPixmap pixmap, bool is_ok_hidden);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void slotOkBtnclicked();
    void slotCancleBtnclicked();

private:
    QLabel      *m_titleInfolab;
    QLabel      *m_titleImageLab;
    QLabel      *m_contentImageLab; //提示图片
    QLabel      *m_contentInfoLab;  //提示信息

    MyPushButton *m_closeBtn;    //提示框上的关闭按钮
    QPushButton *m_okBtn;       //下载按钮
    QPushButton *m_cancleBtn;   //取消按钮

    QString      m_strOk;
    QString      m_strCancle;


};

#endif // MSGBOXWIN_H
