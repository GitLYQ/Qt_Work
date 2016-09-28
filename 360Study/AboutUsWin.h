#ifndef ABOUTUSWIN_H
#define ABOUTUSWIN_H

#include "DropShadowWin.h"
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include "MyPushButton.h"

class AboutUsWin : public DropShadowWin
{
    Q_OBJECT
public:
    explicit AboutUsWin(QWidget *parent = 0);
    void initUi();
    void translateLanguage();

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:

private:
    QLabel      *m_titleLab; //标题
    QLabel      *m_titleIconLab; //标题图标
    QLabel      *m_contentSafeLab; //360安全卫士
    QLabel      *m_contentInfoLab; //杀木马、防盗号、电脑加速
    QLabel      *m_versionLab; //主程序版本
    QLabel      *m_mummyLab; //备用木马库
    QLabel      *m_copyrightLab; //版本信息
    QLabel      *m_iconLab; //图标
    MyPushButton *m_closeBtn; //关闭按钮
    QPushButton *m_okBtn; //确定按钮

};

#endif // ABOUTUSWIN_H
