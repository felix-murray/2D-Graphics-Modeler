QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RenderArea.cpp \
    contact_us.cpp \
    customertest.cpp \
    ellipse.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    polygon.cpp \
    polyline.cpp \
    rectangle.cpp \
    shape.cpp \
    signin.cpp \
    text.cpp

HEADERS += \
    RenderArea.h \
    contact_us.h \
    customertest.h \
    ellipse.h \
    line.h \
    mainwindow.h \
    parser.h \
    polygon.h \
    polyline.h \
    rectangle.h \
    shape.h \
    shape_Vector.h \
    signin.h \
    text.h

FORMS += \
    contact_us.ui \
    customertest.ui \
    mainwindow.ui \
    signin.ui

TRANSLATIONS += \
    2d-Graphics-Modler_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../shape.txt

RESOURCES += \
    icons.qrc \
    shapes.qrc
