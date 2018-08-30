#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QtDebug>
#include <QDateTime>
#include <QInputDialog>
#include <utility>
#include <vector>
#include <algorithm>

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    class State *current;

    GameWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent *);

    void setCurrent(State *s);
    void BackgroundLoad(void);

    void quit [[noreturn]] (void);
private:

    QImage *image;
    QTimer *timer;
protected:

};


#endif // GAMEWIDGET_H
