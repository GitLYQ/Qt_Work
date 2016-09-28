#include "MainWidget.h"
#include <QApplication>
#include <QFile>
#include <QTranslator>
#include <QSharedMemory>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    QTranslator translator;
    translator.load(QString(":/qm/qt_zh_CN"));
    app.installTranslator(&translator);

    QTranslator translator_zh;
    translator_zh.load(QString(":/qm/360safe_zh"));
    app.installTranslator(&translator_zh);


    //加载QSS样式表
    QFile qss(":/qss/360safe");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    QSharedMemory singleApp;    //同一时间只允许运行一个程序
    singleApp.setKey("360safe");

    if ( singleApp.attach() )
    {
        QMessageBox::warning(0,QObject::tr("warning"),QObject::tr("a app has running!"));
        return -1;
    }

    if ( singleApp.create(1) )
    {
        MainWidget w;
        w.setTranslator(&translator_zh);
        w.slotShowWidget();
        return app.exec();
    }


}
