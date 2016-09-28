#ifndef KILLMUMMYWIN_H
#define KILLMUMMYWIN_H

#include <QWidget>

namespace Ui {
class KillMummyWin;
}

class KillMummyWin : public QWidget
{
    Q_OBJECT

public:
    explicit KillMummyWin(QWidget *parent = 0);
    ~KillMummyWin();

    void translateLanguage();


private:
    Ui::KillMummyWin *ui;
};

#endif // KILLMUMMYWIN_H
