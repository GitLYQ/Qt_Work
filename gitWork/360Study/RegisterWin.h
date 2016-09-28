#ifndef REGISTERWIN_H
#define REGISTERWIN_H

#include <QWidget>
#include "DropShadowWin.h"

namespace Ui {
class RegisterWin;
}

class RegisterWin : public DropShadowWin
{
    Q_OBJECT

public:
    explicit RegisterWin(QWidget *parent = 0);
    ~RegisterWin();
    void translateLanguage();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::RegisterWin *ui;
};

#endif // REGISTERWIN_H
