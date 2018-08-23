#ifndef GAME_H
#define GAME_H
#include "gamewidget.h"

class Game
{
public:

        static Game& Instance()
        {
                static Game theSingleInstance;
                return theSingleInstance;
        }
        void run ()
        {
           g.show();
        }
private:

        GameWidget g;
        Game(){}
        Game(const Game& root);
        Game& operator=(const Game&);
};

#endif // GAME_H
