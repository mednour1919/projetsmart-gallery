QT       += core gui sql multimedia multimediawidgets printsupport charts network
QT +=svg
QT +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    arduino.cpp \
    artiste.cpp \
    cameramanager.cpp \
    client.cpp \
    connection.cpp \
    event.cpp \
    main.cpp \
    mainwindow.cpp \
    oeuvre.cpp \
    pageartiste.cpp \
    pageclient.cpp \
    pageevenement.cpp \
    pageoeuvre.cpp \
    pagepersonnel.cpp \
    pagetransaction.cpp \
    pers.cpp \
    qrcode.cpp \
    qrcodegeneratordemo.cpp \
    qrcodegeneratorworker.cpp \
    qrwidget.cpp \
    recorder.cpp \
    smtp.cpp \
    transaction.cpp

HEADERS += \
    arduino.h \
    artiste.h \
    cameramanager.h \
    client.h \
    connection.h \
    event.h \
    mainwindow.h \
    oeuvre.h \
    pageartiste.h \
    pageclient.h \
    pageevenement.h \
    pageoeuvre.h \
    pagepersonnel.h \
    pagetransaction.h \
    pers.h \
    qrcode.h \
    qrwidget.h \
    recorder.h \
    smtp.h \
    transaction.h

FORMS += \
    mainwindow.ui \
    pageartiste.ui \
    pageclient.ui \
    pageevenement.ui \
    pageoeuvre.ui \
    pagepersonnel.ui \
    pagetransaction.ui \
    recorder.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
