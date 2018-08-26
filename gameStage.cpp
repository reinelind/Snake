#include "GameStage.h"
#include "Menu.h"
#include "SnakeObject.h"
#include "AppleObject.h"
#include "SelectStage.h"
#include "LeaderBoard.h"

#include <mutex>
#include <condition_variable>

GameStage::GameStage(int i)
    : Speed (i), entered (), score (0)
{
    snake.create();
    snkVec.reserve(3);

    apple=new AppleObject;

    background=new QImage (":/images/gameprocess.png");
    const QDateTime now=QDateTime::currentDateTime();
    qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tGame Stage\r\n";
    GameStage::RunGame();



}

void GameStage::RunGame()
{
    apple->create();

    for (uint i=0; i<=3; i++)
    {
        snkVec.push_back(snake);
    }

    snkVec[0].x=150;
    snkVec[0].y=120;


    for (uint i=1; i<(snkVec.size()); i++)
    {
        snkVec[i].x=snkVec[i-1].x-10;
        snkVec[i].y=snkVec[0].y;
    }

    timer=new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(drawSnake()));
    timer->start(Speed);
}

void GameStage::drawSnake()
{
    for (uint i=(snkVec.size())-1;i>0;--i)
    {
        snkVec[i].x=snkVec[i-1].x;
        snkVec[i].y=snkVec[i-1].y;
    }

    if (snkVec[0].getDir()==SnakeObject::DOWN)    snkVec[0].y+=10;
    if (snkVec[0].getDir()==SnakeObject::LEFT)    snkVec[0].x-=10;
    if (snkVec[0].getDir()==SnakeObject::RIGHT)   snkVec[0].x+=10;
    if (snkVec[0].getDir()==SnakeObject::UP)      snkVec[0].y-=10;

    if ((snkVec[0].x>=(apple->x)-10 && snkVec[0].x<=(apple->x)+10)
            && (snkVec[0].y>=(apple->y)-10 && snkVec[0].y<=(apple->y)+10))
    {

        snkVec.push_back(snake);
        apple->create();
        snkVec[(snkVec.size())-1].create();
        ++score;
    }
    for (int i=1;i<(snkVec.size()); i++)
        if (snkVec[0].x==snkVec[i].x && snkVec[0].y==snkVec[i].y) { timer->stop(); setHighscore();}

    if ((snkVec[0].x>547 || snkVec[0].x<50) ||(snkVec[0].y<50 || snkVec[0].y>550)) { timer->stop(); setHighscore();}
}

void GameStage::setHighscore()
{


    QString str = QInputDialog::getText( 0,"GAME OVER","Enter Name:",QLineEdit::Normal,"",&entered);
    if(entered)
    {

        QFile Highscore("Highscores.txt");

        Highscore.open(QFile::Append);
        QTextStream myText(&Highscore);

        Highscore.flush();
        myText << QString(str) ;
        Highscore.flush();
        myText << " ";
        Highscore.flush();
        myText << QString::number(score);
        Highscore.flush();
        myText << " \r\n" ;
        Highscore.close();
    }
    else
        exit(0);
}


void GameStage::BackgroundLoad(GameWidget * widget)
{

    painter=new QPainter;
    painter->begin(widget);
    painter->setRenderHints(QPainter::Antialiasing);
    painter->drawImage(0,0,background->scaled(widget->size()));
    for (int i=0; i<(snkVec.size()); i++)
    {
        painter->setPen(snkVec[i].getColor());
        painter->fillRect(QRectF(snkVec[i].x,snkVec[i].y,10,10),snkVec[i].getColor());
        painter->drawRect(snkVec[i].x,snkVec[i].y,10,10);
    }

    painter->setBrush(apple->getColor());
    painter->setPen(apple->getColor());
    painter->drawEllipse(apple->getRect());
    QFont font=widget->font();
    font.setPointSize(30);
    font.setItalic(true);
    font.setFamily("Jet Set");
    widget->setFont(font);
    painter->setPen(QPen(Qt::white));
    painter->drawText(QPointF(425,43),QString::number(score));

    painter->end();
    if (entered)
        widget->setCurrent(new LeaderBoard);

    widget->update();
}

void GameStage::mousePressEvent(GameWidget *, QMouseEvent *){}

void GameStage::keyPressEvent(GameWidget * widget, QKeyEvent * event){
    if (event->key()==Qt::Key_Escape)
    {
        widget->setCurrent(new Menu());
        widget->update();
        delete this;
    }

    if (event->key()==Qt::Key_Up && snkVec[0].getDir()!=SnakeObject::DOWN)
    {
        snkVec[0].setDir(SnakeObject::UP);

    }
    if (event->key()==Qt::Key_Down && snkVec[0].getDir()!=SnakeObject::UP)
    {
        snkVec[0].setDir(SnakeObject::DOWN);
    }
    if (event->key()==Qt::Key_Right&& snkVec[0].getDir()!=SnakeObject::LEFT)
    {
        snkVec[0].setDir(SnakeObject::RIGHT);
    }
    if (event->key()==Qt::Key_Left&& snkVec[0].getDir()!=SnakeObject::RIGHT)
    {
        snkVec[0].setDir(SnakeObject::LEFT);
    }
}

