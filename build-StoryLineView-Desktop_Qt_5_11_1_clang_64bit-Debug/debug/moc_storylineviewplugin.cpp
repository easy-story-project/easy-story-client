/****************************************************************************
** Meta object code from reading C++ file 'storylineviewplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StoryLineView/storylineviewplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'storylineviewplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StoryLineViewPlugin_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StoryLineViewPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StoryLineViewPlugin_t qt_meta_stringdata_StoryLineViewPlugin = {
    {
QT_MOC_LITERAL(0, 0, 19) // "StoryLineViewPlugin"

    },
    "StoryLineViewPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StoryLineViewPlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void StoryLineViewPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject StoryLineViewPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StoryLineViewPlugin.data,
      qt_meta_data_StoryLineViewPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StoryLineViewPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StoryLineViewPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StoryLineViewPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(this);
    if (!strcmp(_clname, "org.qt-project.QDesignerCustomWidgetInterface"))
        return static_cast< QDesignerCustomWidgetInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int StoryLineViewPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x04, 0x01, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xf0, 0x00, 0x00, 0x00, 0x13, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '0',  0x00, 0x00, 0x00, 'o',  0x00, 'r',  0x00,
    'g',  0x00, '.',  0x00, 'q',  0x00, 't',  0x00,
    '-',  0x00, 'p',  0x00, 'r',  0x00, 'o',  0x00,
    'j',  0x00, 'e',  0x00, 'c',  0x00, 't',  0x00,
    '.',  0x00, 'Q',  0x00, 't',  0x00, '.',  0x00,
    'Q',  0x00, 'D',  0x00, 'e',  0x00, 's',  0x00,
    'i',  0x00, 'g',  0x00, 'n',  0x00, 'e',  0x00,
    'r',  0x00, 'C',  0x00, 'u',  0x00, 's',  0x00,
    't',  0x00, 'o',  0x00, 'm',  0x00, 'W',  0x00,
    'i',  0x00, 'd',  0x00, 'g',  0x00, 'e',  0x00,
    't',  0x00, 'I',  0x00, 'n',  0x00, 't',  0x00,
    'e',  0x00, 'r',  0x00, 'f',  0x00, 'a',  0x00,
    'c',  0x00, 'e',  0x00, 0x93, 0x11, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x13, 0x00, 0x00, 0x00,
    'S',  0x00, 't',  0x00, 'o',  0x00, 'r',  0x00,
    'y',  0x00, 'L',  0x00, 'i',  0x00, 'n',  0x00,
    'e',  0x00, 'V',  0x00, 'i',  0x00, 'e',  0x00,
    'w',  0x00, 'P',  0x00, 'l',  0x00, 'u',  0x00,
    'g',  0x00, 'i',  0x00, 'n',  0x00, 0x00, 0x00,
    ':',  '`',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x1c, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00,
    '|',  0x00, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00,
    0xb8, 0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x04, 0x01, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xf0, 0x00, 0x00, 0x00, 0x13, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '0',  0x00, 0x00, 0x00, 'o',  0x00, 'r',  0x00,
    'g',  0x00, '.',  0x00, 'q',  0x00, 't',  0x00,
    '-',  0x00, 'p',  0x00, 'r',  0x00, 'o',  0x00,
    'j',  0x00, 'e',  0x00, 'c',  0x00, 't',  0x00,
    '.',  0x00, 'Q',  0x00, 't',  0x00, '.',  0x00,
    'Q',  0x00, 'D',  0x00, 'e',  0x00, 's',  0x00,
    'i',  0x00, 'g',  0x00, 'n',  0x00, 'e',  0x00,
    'r',  0x00, 'C',  0x00, 'u',  0x00, 's',  0x00,
    't',  0x00, 'o',  0x00, 'm',  0x00, 'W',  0x00,
    'i',  0x00, 'd',  0x00, 'g',  0x00, 'e',  0x00,
    't',  0x00, 'I',  0x00, 'n',  0x00, 't',  0x00,
    'e',  0x00, 'r',  0x00, 'f',  0x00, 'a',  0x00,
    'c',  0x00, 'e',  0x00, 0x95, 0x11, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x13, 0x15, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x13, 0x00, 0x00, 0x00, 'S',  0x00, 't',  0x00,
    'o',  0x00, 'r',  0x00, 'y',  0x00, 'L',  0x00,
    'i',  0x00, 'n',  0x00, 'e',  0x00, 'V',  0x00,
    'i',  0x00, 'e',  0x00, 'w',  0x00, 'P',  0x00,
    'l',  0x00, 'u',  0x00, 'g',  0x00, 'i',  0x00,
    'n',  0x00, 0x00, 0x00, '1',  0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    ':',  '`',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, '|',  0x00, 0x00, 0x00,
    0x98, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(StoryLineViewPlugin, StoryLineViewPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
