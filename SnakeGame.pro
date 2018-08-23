#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T03:05:26
#
#-------------------------------------------------
CONFIG += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app


SOURCES += main.cpp\
        gamewidget.cpp \
    loading.cpp \
    menu.cpp \
    gameStage.cpp \
    leaderBoard.cpp \
    selectStage.cpp \
    SnakeObject.cpp \
    AppleObject.cpp

HEADERS  += gamewidget.h \
    Game.h \
    state.h \
    loading.h \
    menu.h \
    selectStage.h \
    leaderBoard.h \
    gameStage.h \
    debuglog.h \
    SnakeObject.h \
    gameobject.h \
    AppleObject.h

RESOURCES += \
    GameRes.qrc

OTHER_FILES +=
