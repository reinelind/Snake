#include "Menu.h"
#include "SelectStage.h"
#include "LeaderBoard.h"

Menu::Menu()
    :MenuItem (1)
{
    const QDateTime now=QDateTime::currentDateTime();

    background=new QImage (":/images/MainMenu.png");
    pointer=new QImage(":/images/Untitled.png");

    qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tMenu Stage\r\n";
}

void Menu::BackgroundLoad(GameWidget * widget)
{
    painter=new QPainter (widget);
    painter->drawImage(0,0,this->background->scaled(widget->size()));
    switch (MenuItem)
    {
    case 1:
        painter->drawImage(175,215,*pointer);
        break;
    case 2:
        painter->drawImage(145,290,*pointer);
        break;
    case 3:
        painter->drawImage(235,374,*pointer);
        break;
    }

    painter->end();
    widget->update();
}

void Menu::mousePressEvent(GameWidget*, QMouseEvent *){}
void Menu::keyPressEvent(GameWidget* widget,QKeyEvent * event)
{
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
    if (event->key()==Qt::Key_Down)
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
    if (event->key()==Qt::Key_Enter || event->key()==Qt::Key_Return)
        switch (MenuItem)
        {
        case 1:
            widget->setCurrent(new SelectStage());
            break;
        case 2:
            widget->setCurrent(new LeaderBoard());
            break;
        case 3:
            widget->quit();
            break;
        }
}


