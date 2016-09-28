/****************************************************************************
** Meta object code from reading C++ file 'MainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../360Study/MainWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      29,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      80,   66,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     142,  135,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     246,   11,   11,   11, 0x08,
     278,  269,   11,   11, 0x08,
     307,   11,   11,   11, 0x08,
     326,   11,   11,   11, 0x08,
     348,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWidget[] = {
    "MainWidget\0\0slotShowWidget()\0"
    "slotCloseMainWin()\0slotHideMainWin()\0"
    "nCurrentIndex\0slotTurnPage(int)\0"
    "slotShowMainMenu()\0slotShowSkinWin()\0"
    "reason\0"
    "slotSysemTrayIconIsActived(QSystemTrayIcon::ActivationReason)\0"
    "slotShowSettingDialog()\0slotShowAboutUs()\0"
    "slotShowNewCharacter()\0language\0"
    "slotChangeLanguage(LANGUAGE)\0"
    "slotShowLoginWin()\0slotShowRegisterWin()\0"
    "slotChangeSkin(QString)\0"
};

void MainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWidget *_t = static_cast<MainWidget *>(_o);
        switch (_id) {
        case 0: _t->slotShowWidget(); break;
        case 1: _t->slotCloseMainWin(); break;
        case 2: _t->slotHideMainWin(); break;
        case 3: _t->slotTurnPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotShowMainMenu(); break;
        case 5: _t->slotShowSkinWin(); break;
        case 6: _t->slotSysemTrayIconIsActived((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 7: _t->slotShowSettingDialog(); break;
        case 8: _t->slotShowAboutUs(); break;
        case 9: _t->slotShowNewCharacter(); break;
        case 10: _t->slotChangeLanguage((*reinterpret_cast< LANGUAGE(*)>(_a[1]))); break;
        case 11: _t->slotShowLoginWin(); break;
        case 12: _t->slotShowRegisterWin(); break;
        case 13: _t->slotChangeSkin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWidget::staticMetaObject = {
    { &DropShadowWin::staticMetaObject, qt_meta_stringdata_MainWidget,
      qt_meta_data_MainWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget))
        return static_cast<void*>(const_cast< MainWidget*>(this));
    return DropShadowWin::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DropShadowWin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
