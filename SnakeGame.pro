#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T03:05:26
#
#-------------------------------------------------
CONFIG += c++14

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app


SOURCES +=\
    SnakeObject.cpp \
    AppleObject.cpp \
    GameWidget.cpp \
    GameStage.cpp \
    LeaderBoard.cpp \
    Loading.cpp \
    main.cpp \
    SelectStage.cpp \
    applefactory.cpp \
    SnakeFactory.cpp \
    MenuStage.cpp

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
    SelectStage.h \
    factory.h \
    AppleFactory.h \
    SnakeFactory.h

RESOURCES += \
    gameresources.qrc

OTHER_FILES +=
