/****************************************************************************
** Meta object code from reading C++ file 'UserIdItem.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../360Study/UserIdItem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserIdItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserIdItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   12,   11,   11, 0x05,
      45,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UserIdItem[] = {
    "UserIdItem\0\0strUserId\0sigShowUserId(QString)\0"
    "sigRemoveUserId(QString)\0slotRemovUserId()\0"
};

void UserIdItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserIdItem *_t = static_cast<UserIdItem *>(_o);
        switch (_id) {
        case 0: _t->sigShowUserId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigRemoveUserId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotRemovUserId(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UserIdItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UserIdItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserIdItem,
      qt_meta_data_UserIdItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserIdItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserIdItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserIdItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserIdItem))
        return static_cast<void*>(const_cast< UserIdItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserIdItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void UserIdItem::sigShowUserId(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserIdItem::sigRemoveUserId(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
