#include "Menu.h"
#include "SelectStage.h"
#include "LeaderBoard.h"

Menu::Menu()
    : menuItem (MENU_ITEM::START)
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
    switch (menuItem)
    {
    case MENU_ITEM::START:
        painter->drawImage(175,215,*pointer);
        break;
    case MENU_ITEM::HIGHSCORES:
        painter->drawImage(145,290,*pointer);
        break;
    case MENU_ITEM::QUIT:
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
        switch (menuItem)
        {
        case MENU_ITEM::START:
            menuItem = MENU_ITEM::QUIT ;
            break;
        case MENU_ITEM::HIGHSCORES:
            menuItem = MENU_ITEM::START;
            break;
        case MENU_ITEM::QUIT:
            menuItem = MENU_ITEM::HIGHSCORES;
            break;

        }
    }
    if (event->key()==Qt::Key_Down)
        switch (menuItem)
        {
        case MENU_ITEM::QUIT :
            menuItem = MENU_ITEM::START;
            break;

        case MENU_ITEM::START :
            menuItem = MENU_ITEM::HIGHSCORES;
            break;

        case MENU_ITEM::HIGHSCORES :
            menuItem = MENU_ITEM::QUIT;
            break;
        }
    if (event->key()==Qt::Key_Enter || event->key()==Qt::Key_Return)
        switch (menuItem)
        {
        case MENU_ITEM::START :
            widget->setCurrent(new SelectStage());
            break;
        case MENU_ITEM::HIGHSCORES:
            widget->setCurrent(new LeaderBoard());
            break;
        case MENU_ITEM::QUIT:
            widget->quit();
            break;
        }
}


