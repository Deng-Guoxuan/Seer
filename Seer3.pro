#-------------------------------------------------
#
# Project created by QtCreator 2020-06-13T10:53:21
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Seer3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    bullet.cpp \
    point.cpp \
    spirits.cpp \
    pirates.cpp \
    blackbullet.cpp \
    bluebullet.cpp \
    capsule.cpp \
    greenbullet.cpp \
    mengbubuzhongzi.cpp \
    menghuohou.cpp \
    mengyiyou.cpp \
    redbullet.cpp \
    selectionbox.cpp \
    subbutton.cpp \
    world1.cpp \
    interface.cpp \
    pirate1.cpp \
    pirate2.cpp \
    pirate3.cpp \
    brownbullet.cpp \
    leiyi.cpp \
    lightingbullet.cpp \
    yingkaluosi.cpp \
    knifebullet.cpp \
    puni.cpp \
    shiningbullet.cpp

HEADERS += \
        mainwindow.h \
    bullet.h \
    point.h \
    spirits.h \
    pirates.h \
    blackbullet.h \
    bluebullet.h \
    capsule.h \
    greenbullet.h \
    mengbubuzhongzi.h \
    menghuohou.h \
    mengyiyou.h \
    redbullet.h \
    selectionbox.h \
    subbutton.h \
    world1.h \
    interface.h \
    pirate1.h \
    pirate2.h \
    pirate3.h \
    brownbullet.h \
    leiyi.h \
    lightingbullet.h \
    yingkaluosi.h \
    knifebullet.h \
    puni.h \
    shiningbullet.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    pics.qrc \
    snds.qrc

