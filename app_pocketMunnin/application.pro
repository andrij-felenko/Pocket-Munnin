include($$PWD/../qt_base_template.pri)

QT += gui
QT += qml
QT += quick

TARGET  = Pocket_munnin

SOURCES += \
    main.cpp \
    src/LibraryHandler.cpp \
    src/LibrarySingle.cpp \
    src/PluginHandler.cpp \
    src/PluginSingle.cpp

RESOURCES += resource/resource.qrc

HEADERS += \
    src/LibraryHandler.h \
    src/LibrarySingle.h \
    src/PluginHandler.h \
    src/PluginSingle.h
