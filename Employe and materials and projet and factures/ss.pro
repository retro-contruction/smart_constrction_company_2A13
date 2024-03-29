QT       += core gui sql charts serialport bluetooth
QT       += core gui sql network
QT       += core gui sql charts printsupport
QT       += core gui sql printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport multimedia
TARGET = smtp
TEMPLATE = app
CONFIG += c++11 console

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
    Form.cpp \
    arduino.cpp \
    dialog.cpp \
    employes.cpp \
    facture.cpp \
    main.cpp \
    mainwindow.cpp \
    material.cpp \
    projet.cpp \
    reset.cpp \
    secdialog.cpp \
    smtp.cpp \
    smtpreset.cpp \
    task.cpp

HEADERS += \
    Form.h \
    arduino.h \
    dialog.h \
    employes.h \
    facture.h \
    mainwindow.h \
    material.h \
    projet.h \
    reset.h \
    secdialog.h \
    smtp.h \
    smtpreset.h \
    task.h

FORMS += \
    dialog.ui \
    interfacelogin.ui \
    mainwindow.ui \
    reset.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
