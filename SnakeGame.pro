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
    loading.cpp \
    menu.cpp \
    gameStage.cpp \
    leaderBoard.cpp \
    selectStage.cpp \
    SnakeObject.cpp \
    AppleObject.cpp \
    GameWidget.cpp

HEADERS  += \
    Game.h \
    SnakeObject.h \
    AppleObject.h \
    State.h \
    Menu.h \
    GameStage.h \
    Gameobject.h \
    Gamewidget.h \
    LeaderBoard.h \
    Loading.h \
    SelectStage.h

RESOURCES += \
    gameresources.qrc

OTHER_FILES +=
