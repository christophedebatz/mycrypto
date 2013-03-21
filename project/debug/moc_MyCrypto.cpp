/****************************************************************************
** Meta object code from reading C++ file 'MyCrypto.h'
**
** Created: Fri 7. Jan 19:07:52 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MyCrypto.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyCrypto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyCrypto[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      32,    9,    9,    9, 0x08,
      48,    9,    9,    9, 0x08,
      66,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyCrypto[] = {
    "MyCrypto\0\0generationInterface()\0"
    "AppelCryptage()\0AppelDecryptage()\0"
    "AppelCryptanalyse()\0"
};

const QMetaObject MyCrypto::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyCrypto,
      qt_meta_data_MyCrypto, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyCrypto::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyCrypto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyCrypto::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyCrypto))
        return static_cast<void*>(const_cast< MyCrypto*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyCrypto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: generationInterface(); break;
        case 1: AppelCryptage(); break;
        case 2: AppelDecryptage(); break;
        case 3: AppelCryptanalyse(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
