#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "State.h"


class LeaderBoard final: public State
{
public:

    LeaderBoard();

    void BackgroundLoad(GameWidget *)               override;
    void mousePressEvent(GameWidget*,QMouseEvent *) override;
    void keyPressEvent(GameWidget*, QKeyEvent *)    override;

    template <typename T, typename S>
    void mySortTable(std::vector<std::pair<T,S> > &);

private:
    int scoreQuantity;
    QPainter *painter;
    QImage *background;
    std::vector<std::pair <QString, int>> highscores;
};

#endif // LEADERBOARD_H
