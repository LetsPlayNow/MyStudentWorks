/****************************************************************************
** Meta object code from reading C++ file 'diary.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../diary.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Diary_t {
    QByteArrayData data[9];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Diary_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Diary_t qt_meta_stringdata_Diary = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Diary"
QT_MOC_LITERAL(1, 6, 7), // "addNote"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 10), // "updateNote"
QT_MOC_LITERAL(4, 26, 17), // "deleteCurrentNote"
QT_MOC_LITERAL(5, 44, 8), // "fillData"
QT_MOC_LITERAL(6, 53, 13), // "checkedButton"
QT_MOC_LITERAL(7, 67, 8), // "newValue"
QT_MOC_LITERAL(8, 76, 28) // "showNoteWhichClikedInBrowser"

    },
    "Diary\0addNote\0\0updateNote\0deleteCurrentNote\0"
    "fillData\0checkedButton\0newValue\0"
    "showNoteWhichClikedInBrowser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Diary[] = {

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
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,

       0        // eod
};

void Diary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Diary *_t = static_cast<Diary *>(_o);
        switch (_id) {
        case 0: _t->addNote(); break;
        case 1: _t->updateNote(); break;
        case 2: _t->deleteCurrentNote(); break;
        case 3: _t->fillData(); break;
        case 4: _t->checkedButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->showNoteWhichClikedInBrowser(); break;
        default: ;
        }
    }
}

const QMetaObject Diary::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Diary.data,
      qt_meta_data_Diary,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Diary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Diary::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Diary.stringdata))
        return static_cast<void*>(const_cast< Diary*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Diary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
