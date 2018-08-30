#include "Game.h"
#include "gamewidget.h"


void Game::run()
{
    GameWidget *g=new GameWidget;
    g->show();
    qDebug()<<"Game launched.";
}
