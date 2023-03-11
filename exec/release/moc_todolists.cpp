/****************************************************************************
** Meta object code from reading C++ file 'todolists.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../todolists_5/todolists.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'todolists.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToDoLists_t {
    QByteArrayData data[15];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToDoLists_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToDoLists_t qt_meta_stringdata_ToDoLists = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ToDoLists"
QT_MOC_LITERAL(1, 10, 13), // "onEditEntered"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "onRefreshClicked"
QT_MOC_LITERAL(4, 42, 23), // "onPushButtonMenuClicked"
QT_MOC_LITERAL(5, 66, 18), // "onChildItemClicked"
QT_MOC_LITERAL(6, 85, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 102, 4), // "item"
QT_MOC_LITERAL(8, 107, 24), // "onPushButtonCloseClicked"
QT_MOC_LITERAL(9, 132, 21), // "onPushButtonOkClicked"
QT_MOC_LITERAL(10, 154, 25), // "onPushButtonCancelClicked"
QT_MOC_LITERAL(11, 180, 13), // "updateWidget1"
QT_MOC_LITERAL(12, 194, 12), // "QTreeWidget*"
QT_MOC_LITERAL(13, 207, 6), // "widget"
QT_MOC_LITERAL(14, 214, 13) // "updateWidget2"

    },
    "ToDoLists\0onEditEntered\0\0onRefreshClicked\0"
    "onPushButtonMenuClicked\0onChildItemClicked\0"
    "QTreeWidgetItem*\0item\0onPushButtonCloseClicked\0"
    "onPushButtonOkClicked\0onPushButtonCancelClicked\0"
    "updateWidget1\0QTreeWidget*\0widget\0"
    "updateWidget2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToDoLists[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    1,   68,    2, 0x08 /* Private */,
      14,    1,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void ToDoLists::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToDoLists *_t = static_cast<ToDoLists *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onEditEntered(); break;
        case 1: _t->onRefreshClicked(); break;
        case 2: _t->onPushButtonMenuClicked(); break;
        case 3: _t->onChildItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->onPushButtonCloseClicked(); break;
        case 5: _t->onPushButtonOkClicked(); break;
        case 6: _t->onPushButtonCancelClicked(); break;
        case 7: _t->updateWidget1((*reinterpret_cast< QTreeWidget*(*)>(_a[1]))); break;
        case 8: _t->updateWidget2((*reinterpret_cast< QTreeWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTreeWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject ToDoLists::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ToDoLists.data,
      qt_meta_data_ToDoLists,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ToDoLists::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToDoLists::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToDoLists.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ToDoLists::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
