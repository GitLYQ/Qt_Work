#ifndef LOADINGWIN_H
#define LOADINGWIN_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class LoadingWin : public QWidget
{
    Q_OBJECT
public:
    explicit LoadingWin(QWidget *parent = 0);

    void initUI();


    void translateLanguage();
    void start(bool is_start);
    void setUserId(QString strUserId);

signals:

public slots:
    void slotUpdatePixmap();

private:
    QLabel *m_imageLab;
    QLabel *m_userIdLab;
    QLabel *m_waitInfoLab;
    QTimer *m_timer;

    int     m_nIndex;
    QString m_strUserID;

};

#endif // LOADINGWIN_H
