#include "SelectStage.h"
#include "Menu.h"
#include "GameStage.h"

SelectStage::SelectStage()
    : MenuItem (1)
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
    switch (MenuItem)
    {
    case 1:
        painter->drawImage(225,201,*pointer);
        break;
    case 2:
        painter->drawImage(205,270,*pointer);
        break;
    case 3:
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
        switch (MenuItem)
        {
        case 1:
            MenuItem = 2;
            break;

        case 2:
            MenuItem = 3;
            break;

        case 3:
            MenuItem = 1;
            break;
        }
    }
    if (event->key()==Qt::Key_Up)
    {

        switch (MenuItem)
        {
        case 1:
            MenuItem = 3;
            break;
        case 2:
            MenuItem = 1;
            break;
        case 3:
            MenuItem = 2;
            break;
        }
    }

    if (event->key()==Qt::Key_Return || event->key()==Qt::Key_Enter)
    {
        switch (MenuItem)
        {
        case 1:
            widget->setCurrent(new GameStage(200));
            widget->update();
            delete this;
            break;
        case 2:
            widget->setCurrent(new GameStage(130));
            widget->update();
            delete this;
            break;
        case 3:
            widget->setCurrent(new GameStage(110));
            widget->update();
            delete this;
            break;
           }
    }
}

