/****************************************************************************
** Meta object code from reading C++ file 'SkinWin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../360Study/SkinWin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SkinWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SkinWin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,    8,    8,    8, 0x0a,
      61,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SkinWin[] = {
    "SkinWin\0\0strSkinName\0sigChangeSkin(QString)\0"
    "slotChangeSkin()\0slotShowSkin(QString)\0"
};

void SkinWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SkinWin *_t = static_cast<SkinWin *>(_o);
        switch (_id) {
        case 0: _t->sigChangeSkin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotChangeSkin(); break;
        case 2: _t->slotShowSkin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SkinWin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SkinWin::staticMetaObject = {
    { &DropShadowWin::staticMetaObject, qt_meta_stringdata_SkinWin,
      qt_meta_data_SkinWin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SkinWin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SkinWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SkinWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SkinWin))
        return static_cast<void*>(const_cast< SkinWin*>(this));
    return DropShadowWin::qt_metacast(_clname);
}

int SkinWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DropShadowWin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SkinWin::sigChangeSkin(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
