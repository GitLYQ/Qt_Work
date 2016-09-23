#-------------------------------------------------
#
# Project created by QtCreator 2016-09-12T10:03:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 360Study
TEMPLATE = app
DEPENDPATH = . Resources

SOURCES += main.cpp\
        MainWidget.cpp \
    TitleWidget.cpp \
    MyToolButton.cpp \
    MyPushButton.cpp \
    ContentWin.cpp \
    kill_mummy_widget.cpp \
    DropShadowWin.cpp \
    MySystemTray.cpp \
    KillMummyWin.cpp \
    RegisterWin.cpp \
    MsgBoxWin.cpp \
    Util.cpp \
    LoadingWin.cpp \
    LoginWin.cpp \
    UserIdItem.cpp

HEADERS  += \
    TitleWidget.h \
    MyToolButton.h \
    MyPushButton.h \
    ContentWin.h \
    Common.h \
    kill_mummy_widget.h \
    DropShadowWin.h \
    MySystemTray.h \
    KillMummyWin.h \
    MainWidget.h \
    RegisterWin.h \
    MsgBoxWin.h \
    Util.h \
    LoadingWin.h \
    LoginWin.h \
    UserIdItem.h



RESOURCES += ./Resources/360safe.qrc

FORMS += \
    KillMummyWin.ui \
    RegisterWin.ui
