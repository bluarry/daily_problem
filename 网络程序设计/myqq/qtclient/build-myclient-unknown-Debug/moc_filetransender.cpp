/****************************************************************************
** Meta object code from reading C++ file 'filetransender.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myclient/filetransender.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filetransender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_filetransender[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      44,   15,   15,   15, 0x08,
      55,   15,   15,   15, 0x08,
      84,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_filetransender[] = {
    "filetransender\0\0on_filetransstart_clicked()\0"
    "sendfile()\0on_filetranscancle_clicked()\0"
    "recivesig()\0"
};

void filetransender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        filetransender *_t = static_cast<filetransender *>(_o);
        switch (_id) {
        case 0: _t->on_filetransstart_clicked(); break;
        case 1: _t->sendfile(); break;
        case 2: _t->on_filetranscancle_clicked(); break;
        case 3: _t->recivesig(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData filetransender::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject filetransender::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_filetransender,
      qt_meta_data_filetransender, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &filetransender::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *filetransender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *filetransender::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_filetransender))
        return static_cast<void*>(const_cast< filetransender*>(this));
    return QDialog::qt_metacast(_clname);
}

int filetransender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
