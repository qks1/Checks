/****************************************************************************
** Meta object code from reading C++ file 'doctable.h'
**
** Created: Sun 12. Aug 04:26:55 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../doctable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doctable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DocTable[] = {

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
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,    9,    9,    9, 0x08,
      38,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DocTable[] = {
    "DocTable\0\0close_signal()\0close_slot()\0"
    "fill_slot(int)\0"
};

void DocTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DocTable *_t = static_cast<DocTable *>(_o);
        switch (_id) {
        case 0: _t->close_signal(); break;
        case 1: _t->close_slot(); break;
        case 2: _t->fill_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DocTable::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DocTable::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DocTable,
      qt_meta_data_DocTable, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DocTable::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DocTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DocTable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DocTable))
        return static_cast<void*>(const_cast< DocTable*>(this));
    return QWidget::qt_metacast(_clname);
}

int DocTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DocTable::close_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
