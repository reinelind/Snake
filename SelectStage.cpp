#include "SelectStage.h"
#include "MenuStage.h"
#include "GameStage.h"

SelectStage::SelectStage()
    : menuItem (SELECT_ITEM::EASY)
{
    background=new QImage (":/images/levelselect.png");
    pointer=new QImage(":/images/Untitled.png");
    const QDateTime now=QDateTime::currentDateTime();

    qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tSelect Stage\r\n";
}

void SelectStage::BackgroundLoad(GameWidget * widget)
{
    painter=new QPainter;
    painter->begin(widget);
    painter->drawImage(0,0,background->scaled(widget->size()));
    switch (menuItem)
    {
    case SELECT_ITEM :: EASY:
        painter->drawImage(225,201,*pointer);
        break;
    case SELECT_ITEM :: MEDIUM:
        painter->drawImage(205,270,*pointer);
        break;
    case SELECT_ITEM :: HARD:
        painter->drawImage(225,340,*pointer);
        break;
    }
     painter->end();
     widget->update();
}

void SelectStage::mousePressEvent(GameWidget *, QMouseEvent *){}

void SelectStage::keyPressEvent(GameWidget * widget, QKeyEvent * event){
    if (event->key()==Qt::Key_Escape)
    {
        widget->setCurrent(new Menu());
        widget->update();
        delete this;
    }

    if (event->key()==Qt::Key_Down)
    {
        switch (menuItem)
        {
        case SELECT_ITEM :: EASY :
            menuItem = SELECT_ITEM :: MEDIUM;
            break;

        case SELECT_ITEM :: MEDIUM:
            menuItem = SELECT_ITEM :: HARD;
            break;

        case SELECT_ITEM :: HARD:
            menuItem = SELECT_ITEM :: EASY;
            break;
        }
    }
    if (event->key()==Qt::Key_Up)
    {

        switch (menuItem)
        {
         case SELECT_ITEM :: EASY:
            menuItem = SELECT_ITEM :: HARD;
            break;
        case SELECT_ITEM :: MEDIUM:
            menuItem = SELECT_ITEM :: EASY;
            break;
        case SELECT_ITEM :: HARD:
            menuItem = SELECT_ITEM :: HARD;
            break;
        }
    }

    if (event->key()==Qt::Key_Return || event->key()==Qt::Key_Enter)
    {
        switch (menuItem)
        {
        case SELECT_ITEM :: EASY:
            widget->setCurrent(new GameStage(150));
            widget->update();
            delete this;
            break;
        case SELECT_ITEM :: MEDIUM:
            widget->setCurrent(new GameStage(100));
            widget->update();
            delete this;
            break;
        case SELECT_ITEM :: HARD:
            widget->setCurrent(new GameStage(70));
            widget->update();
            delete this;
            break;
           }
    }
}

