/****************************************************************************
** Meta object code from reading C++ file 'customtab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../openCV-demo/customtab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customtab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CustomTab_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomTab_t qt_meta_stringdata_CustomTab = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CustomTab"
QT_MOC_LITERAL(1, 10, 16), // "onTabNameChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "newOperationEvent"
QT_MOC_LITERAL(4, 46, 14), // "onComboClicked"
QT_MOC_LITERAL(5, 61, 4), // "text"
QT_MOC_LITERAL(6, 66, 13), // "onDataChanged"
QT_MOC_LITERAL(7, 80, 14), // "onNewOperation"
QT_MOC_LITERAL(8, 95, 7), // "cv::Mat"
QT_MOC_LITERAL(9, 103, 5) // "image"

    },
    "CustomTab\0onTabNameChanged\0\0"
    "newOperationEvent\0onComboClicked\0text\0"
    "onDataChanged\0onNewOperation\0cv::Mat\0"
    "image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   41,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void CustomTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomTab *_t = static_cast<CustomTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTabNameChanged(); break;
        case 1: _t->newOperationEvent(); break;
        case 2: _t->onComboClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onDataChanged(); break;
        case 4: _t->onNewOperation((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CustomTab::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomTab::onTabNameChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CustomTab::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomTab::newOperationEvent)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CustomTab::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_CustomTab.data,
      qt_meta_data_CustomTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CustomTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CustomTab.stringdata0))
        return static_cast<void*>(const_cast< CustomTab*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int CustomTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CustomTab::onTabNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CustomTab::newOperationEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
