/****************************************************************************
** Meta object code from reading C++ file 'TitleWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../360Study/TitleWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TitleWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TitleWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      30,   12,   12,   12, 0x05,
      44,   12,   12,   12, 0x05,
      57,   12,   12,   12, 0x05,
      75,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,   12,   12,   12, 0x0a,
     114,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TitleWidget[] = {
    "TitleWidget\0\0sigTurnPage(int)\0"
    "sigShowSkin()\0sigShowMin()\0sigShowMainMenu()\0"
    "sigCloseWidget()\0slotTurnPage(QString)\0"
    "slotCloseBtnClicked()\0"
};

void TitleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TitleWidget *_t = static_cast<TitleWidget *>(_o);
        switch (_id) {
        case 0: _t->sigTurnPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigShowSkin(); break;
        case 2: _t->sigShowMin(); break;
        case 3: _t->sigShowMainMenu(); break;
        case 4: _t->sigCloseWidget(); break;
        case 5: _t->slotTurnPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slotCloseBtnClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TitleWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TitleWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TitleWidget,
      qt_meta_data_TitleWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TitleWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TitleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TitleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TitleWidget))
        return static_cast<void*>(const_cast< TitleWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TitleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TitleWidget::sigTurnPage(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TitleWidget::sigShowSkin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TitleWidget::sigShowMin()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TitleWidget::sigShowMainMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void TitleWidget::sigCloseWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
