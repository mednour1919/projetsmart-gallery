/****************************************************************************
** Meta object code from reading C++ file 'pagetransaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../integ/pagetransaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pagetransaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pagetransaction_t {
    QByteArrayData data[11];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pagetransaction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pagetransaction_t qt_meta_stringdata_pagetransaction = {
    {
QT_MOC_LITERAL(0, 0, 15), // "pagetransaction"
QT_MOC_LITERAL(1, 16, 23), // "on_pb_supprimer_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 22), // "on_pb_modifier_clicked"
QT_MOC_LITERAL(4, 64, 21), // "on_pb_ajouter_clicked"
QT_MOC_LITERAL(5, 86, 22), // "handleMessageBoxResult"
QT_MOC_LITERAL(6, 109, 6), // "result"
QT_MOC_LITERAL(7, 116, 28), // "on_tableViewSelectionChanged"
QT_MOC_LITERAL(8, 145, 7), // "current"
QT_MOC_LITERAL(9, 153, 8), // "previous"
QT_MOC_LITERAL(10, 162, 31) // "on_commandLinkButton_24_clicked"

    },
    "pagetransaction\0on_pb_supprimer_clicked\0"
    "\0on_pb_modifier_clicked\0on_pb_ajouter_clicked\0"
    "handleMessageBoxResult\0result\0"
    "on_tableViewSelectionChanged\0current\0"
    "previous\0on_commandLinkButton_24_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pagetransaction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    2,   50,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    8,    9,
    QMetaType::Void,

       0        // eod
};

void pagetransaction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pagetransaction *_t = static_cast<pagetransaction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pb_supprimer_clicked(); break;
        case 1: _t->on_pb_modifier_clicked(); break;
        case 2: _t->on_pb_ajouter_clicked(); break;
        case 3: _t->handleMessageBoxResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_tableViewSelectionChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 5: _t->on_commandLinkButton_24_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject pagetransaction::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_pagetransaction.data,
      qt_meta_data_pagetransaction,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pagetransaction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pagetransaction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pagetransaction.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int pagetransaction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
