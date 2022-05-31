/****************************************************************************
** Meta object code from reading C++ file 'cabin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lab_04/cabin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cabin_t {
    QByteArrayData data[15];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cabin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cabin_t qt_meta_stringdata_cabin = {
    {
QT_MOC_LITERAL(0, 0, 5), // "cabin"
QT_MOC_LITERAL(1, 6, 17), // "open_doors_signal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "floor_passed"
QT_MOC_LITERAL(4, 38, 7), // "ssize_t"
QT_MOC_LITERAL(5, 46, 5), // "floor"
QT_MOC_LITERAL(6, 52, 9), // "direction"
QT_MOC_LITERAL(7, 62, 3), // "dir"
QT_MOC_LITERAL(8, 66, 13), // "moving_signal"
QT_MOC_LITERAL(9, 80, 14), // "stopped_signal"
QT_MOC_LITERAL(10, 95, 12), // "cabin_moving"
QT_MOC_LITERAL(11, 108, 17), // "cabin_take_target"
QT_MOC_LITERAL(12, 126, 13), // "cabin_stopped"
QT_MOC_LITERAL(13, 140, 7), // "is_last"
QT_MOC_LITERAL(14, 148, 9) // "new_floor"

    },
    "cabin\0open_doors_signal\0\0floor_passed\0"
    "ssize_t\0floor\0direction\0dir\0moving_signal\0"
    "stopped_signal\0cabin_moving\0"
    "cabin_take_target\0cabin_stopped\0is_last\0"
    "new_floor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cabin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    2,   65,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    2,   71,    2, 0x06 /* Public */,
       9,    1,   76,    2, 0x26 /* Public | MethodCloned */,
       9,    0,   79,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   80,    2, 0x0a /* Public */,
      11,    1,   81,    2, 0x0a /* Public */,
      12,    2,   84,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,   13,   14,
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void cabin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cabin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open_doors_signal(); break;
        case 1: _t->floor_passed((*reinterpret_cast< ssize_t(*)>(_a[1])),(*reinterpret_cast< direction(*)>(_a[2]))); break;
        case 2: _t->moving_signal(); break;
        case 3: _t->stopped_signal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< ssize_t(*)>(_a[2]))); break;
        case 4: _t->stopped_signal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->stopped_signal(); break;
        case 6: _t->cabin_moving(); break;
        case 7: _t->cabin_take_target((*reinterpret_cast< ssize_t(*)>(_a[1]))); break;
        case 8: _t->cabin_stopped((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< ssize_t(*)>(_a[2]))); break;
        case 9: _t->cabin_stopped((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cabin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cabin::open_doors_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (cabin::*)(ssize_t , direction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cabin::floor_passed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (cabin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cabin::moving_signal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (cabin::*)(bool , ssize_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cabin::stopped_signal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cabin::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_cabin.data,
    qt_meta_data_cabin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cabin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cabin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cabin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cabin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void cabin::open_doors_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cabin::floor_passed(ssize_t _t1, direction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void cabin::moving_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void cabin::stopped_signal(bool _t1, ssize_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
