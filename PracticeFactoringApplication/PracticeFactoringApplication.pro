QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += verbose
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    factoringmodel.cpp \
    main.cpp \
    factoringapplicationwindow.cpp

HEADERS += \
    factoringapplicationwindow.h \
    factoringmodel.h

FORMS += \
    factoringapplicationwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# include JKQTPlotter library
DEPENDPATH += \
              ../JKQtPlotter/lib \
              ../JKQtPlotter/qmake/staticlib/jkqtmathtextlib
INCLUDEPATH += ../JKQtPlotter/lib
CONFIG (debug, release) {
    DEPENDPATH += ../../JKQtPlotter/qmake/staticlib/jkqtmathtextlib/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug
    LIBS += -L../../JKQtPlotter/qmake/staticlib/jkqtmathtextlib/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug -ljkqtmathtextlib_debug
} else {
    DEPENDPATH += ../../JKQtPlotter/qmake/staticlib/jkqtmathtextlib/build/Desktop_Qt_6_8_0_MinGW_64_bit-Release/release
    LIBS += -L./Test -ljkqtmathtextlib
}

unix|win32: LIBS += -L$$PWD/Test/ -ljkqtmathtextlib

INCLUDEPATH += $$PWD/../JKQtPlotter/qmake/staticlib/jkqtmathtextlib/build/Desktop_Qt_6_8_0_MinGW_64_bit-Release/release
DEPENDPATH += $$PWD/../JKQtPlotter/qmake/staticlib/jkqtmathtextlib/build/Desktop_Qt_6_8_0_MinGW_64_bit-Release/release

INCLUDEPATH += $$PWD/../JKQtPlotter/qmake/staticlib/jkqtmathtextlib/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug
DEPENDPATH += $$PWD/../JKQtPlotter/qmake/staticlib/jkqtmathtextlib/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/Test/jkqtmathtextlib.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/Test/libjkqtmathtextlib.a
