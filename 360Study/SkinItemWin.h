#ifndef SKINITEMWIN_H
#define SKINITEMWIN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>


class SkinItemWin : public QWidget
{
    Q_OBJECT
public:
    explicit SkinItemWin(QWidget *parent = 0);

    void initUI();
    void translateLanguage();
    QString getPixmapName();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void leaveEvent(QEvent *);
    void enterEvent(QEvent *);
    void paintEvent(QPaintEvent *);

signals:
    void sigChangeSkin();

public slots:

    void slotChangeSkin(QString pixmap_name, QString skin_name, QString download_count);

private slots:

    void slotUseSkin();

private:

    QLabel      *m_imageLab;
    QLabel      *m_nameLab;
    QLabel      *m_downloadNumLab;
    QPushButton *m_useBtn;

    QString      m_pixmapName;
    bool         m_bIsMousePress;
    bool         m_bIsMouseEnter;
};

#endif // SKINITEMWIN_H
