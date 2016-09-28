#ifndef USERIDITEM_H
#define USERIDITEM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class UserIdItem : public QWidget
{
    Q_OBJECT
public:
    explicit UserIdItem(QWidget *parent = 0);

    void setUserIdLabText(const QString strUserId);
    QString getUserIdLabText() const;

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);


signals:

    void sigShowUserId(QString strUserId);
    void sigRemoveUserId(QString strUserId);

private slots:

    void slotRemovUserId();


private:
    QPushButton *m_deleteBtn;
    QLabel      *m_userIdLab;
    bool         m_bIsMousePress;
};

#endif // USERIDITEM_H
