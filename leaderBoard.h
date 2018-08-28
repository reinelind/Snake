#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "State.h"


class LeaderBoard: public State
{
public:

    LeaderBoard();

    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);

    template <typename T, typename S>
    void mySortTable(std::vector<std::pair<T,S> > &);

private:
    int scoreQuantity;
    QPainter *painter;
    QImage *background;
    std::vector<std::pair <QString, int>> highscores;
};

#endif // LEADERBOARD_H
