#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "state.h"


class LeaderBoard: public State
{
public:
    void BackgroundLoad(GameWidget *);
    void mousePressEvent(GameWidget*,QMouseEvent*);
    void keyPressEvent(GameWidget*, QKeyEvent*);
    LeaderBoard();// default constructor

    template <typename T, typename S>
    void mySortTable(std::vector<std::pair<T,S> > &);

private:
    QPainter *painter;
    QImage *background;
    std::vector<std::pair <QString, int>> highscores;
    int scoreQuantity;
};

#endif // LEADERBOARD_H
