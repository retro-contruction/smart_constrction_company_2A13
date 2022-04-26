QT       += core gui sql charts serialport bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

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
<<<<<<< HEAD:old/tache2.pro
    ajouter.cpp \
    connection.cpp \
    employe.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    projet2th.cpp \
    task.cpp

HEADERS += \
    ajouter.h \
    connection.h \
    employe.h \
    mail.h \
    mainwindow.h \
    projet2th.h \
    task.h

FORMS += \
    ajouter.ui \
    mainwindow.ui
=======
    arduino.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    material.cpp \
    secdialog.cpp

HEADERS += \
    arduino.h \
    dialog.h \
    mainwindow.h \
    material.h \
    secdialog.h

FORMS += \
    dialog.ui \
    interfacelogin.ui \
    secdialog.ui
>>>>>>> main:materials/ss.pro

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
