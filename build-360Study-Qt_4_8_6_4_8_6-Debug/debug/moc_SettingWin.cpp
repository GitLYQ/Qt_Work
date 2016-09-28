/****************************************************************************
** Meta object code from reading C++ file 'SettingWin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../360Study/SettingWin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingWin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SettingWin[] = {
    "SettingWin\0\0sigChangeLanguage(LANGUAGE)\0"
    "slotUpdateConfig()\0"
};

void SettingWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SettingWin *_t = static_cast<SettingWin *>(_o);
        switch (_id) {
        case 0: _t->sigChangeLanguage((*reinterpret_cast< LANGUAGE(*)>(_a[1]))); break;
        case 1: _t->slotUpdateConfig(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SettingWin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SettingWin::staticMetaObject = {
    { &DropShadowWin::staticMetaObject, qt_meta_stringdata_SettingWin,
      qt_meta_data_SettingWin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingWin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingWin))
        return static_cast<void*>(const_cast< SettingWin*>(this));
    return DropShadowWin::qt_metacast(_clname);
}

int SettingWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DropShadowWin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SettingWin::sigChangeLanguage(LANGUAGE _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
