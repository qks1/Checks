/****************************************************************************
** Meta object code from reading C++ file 'mtable.h'
**
** Created: Sun 12. Aug 04:26:58 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mtable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mtable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MTable[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,    7,    7,    7, 0x08,
      49,    7,    7,    7, 0x08,
      73,    7,    7,    7, 0x08,
      89,    7,    7,    7, 0x08,
     112,    7,    7,    7, 0x08,
     122,    7,    7,    7, 0x08,
     148,    7,    7,    7, 0x08,
     167,    7,    7,    7, 0x08,
     194,    7,    7,    7, 0x08,
     211,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MTable[] = {
    "MTable\0\0show_doc_signal(int)\0"
    "date_changed(QDate)\0disactivate_dates(bool)\0"
    "switch_hidden()\0combobox_used(QString)\0"
    "refresh()\0double_click(QModelIndex)\0"
    "click(QModelIndex)\0text_changed_slot(QString)\0"
    "clear_textline()\0reset_textfilter()\0"
};

void MTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MTable *_t = static_cast<MTable *>(_o);
        switch (_id) {
        case 0: _t->show_doc_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->date_changed((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: _t->disactivate_dates((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->switch_hidden(); break;
        case 4: _t->combobox_used((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->refresh(); break;
        case 6: _t->double_click((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->click((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 8: _t->text_changed_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->clear_textline(); break;
        case 10: _t->reset_textfilter(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MTable::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MTable::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MTable,
      qt_meta_data_MTable, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MTable::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MTable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MTable))
        return static_cast<void*>(const_cast< MTable*>(this));
    return QWidget::qt_metacast(_clname);
}

int MTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MTable::show_doc_signal(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
