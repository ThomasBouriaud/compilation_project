/****************************************************************************
** Meta object code from reading C++ file 'jardinRendering.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "jardinRendering.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jardinRendering.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JardinRendering_t {
    QByteArrayData data[9];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JardinRendering_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JardinRendering_t qt_meta_stringdata_JardinRendering = {
    {
QT_MOC_LITERAL(0, 0, 15), // "JardinRendering"
QT_MOC_LITERAL(1, 16, 5), // "parse"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "newTortue"
QT_MOC_LITERAL(4, 33, 1), // "x"
QT_MOC_LITERAL(5, 35, 1), // "y"
QT_MOC_LITERAL(6, 37, 11), // "sizeFenetre"
QT_MOC_LITERAL(7, 49, 1), // "w"
QT_MOC_LITERAL(8, 51, 1) // "h"

    },
    "JardinRendering\0parse\0\0newTortue\0x\0y\0"
    "sizeFenetre\0w\0h"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JardinRendering[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    2,   30,    2, 0x06 /* Public */,
       6,    2,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

       0        // eod
};

void JardinRendering::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JardinRendering *_t = static_cast<JardinRendering *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parse(); break;
        case 1: _t->newTortue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sizeFenetre((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (JardinRendering::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JardinRendering::parse)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (JardinRendering::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JardinRendering::newTortue)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (JardinRendering::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JardinRendering::sizeFenetre)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject JardinRendering::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_JardinRendering.data,
      qt_meta_data_JardinRendering,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *JardinRendering::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JardinRendering::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JardinRendering.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int JardinRendering::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void JardinRendering::parse()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void JardinRendering::newTortue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JardinRendering::sizeFenetre(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
