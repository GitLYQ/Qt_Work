#ifndef CHARACTERBOTTON_H
#define CHARACTERBOTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QLabel>

class CharacterButton : public QWidget
{
    Q_OBJECT
public:
    explicit CharacterButton(QWidget *parent = 0);

    void initUI();
    void setIconPixmap(const QPixmap &pix);
    void setTextLabText(const QString &str);

    void setMouseEnterFlag(bool bIsEnter) {  m_bIsMouseEnter = bIsEnter; this->update(); }
    void setMousePressFlag(bool bIsPress) {  m_bIsMousePress = bIsPress; this->update(); }
    bool getMouseEnterFlag() const { return m_bIsMouseEnter; }
    bool getMousePressFlag() const { return m_bIsMousePress; }

protected:
    void paintEvent(QPaintEvent *);
    void leaveEvent(QEvent *);
    void enterEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);

private:

    void paintWiget(int nAlpha,QPainter *);



signals:
    void sigPressed(CharacterButton *);

public slots:

private:
    QLabel  *m_iconLab;
    QLabel  *m_textLab;

    bool     m_bIsMousePress;
    bool     m_bIsMouseEnter;

};

#endif // CHARACTERBOTTON_H
