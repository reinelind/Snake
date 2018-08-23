#include "gameStage.h"
#include "menu.h"
#include "SnakeObject.h"
#include "AppleObject.h"
#include "selectStage.h"
#include "leaderBoard.h"
GameStage::GameStage(int i)
    : Speed (i)
{
    snake.create();
    s.reserve(3);
    a=new AppleObject;
    GameStage::RunGame();
    background=new QImage (":/gameprocess.png");
    const QDateTime now=QDateTime::currentDateTime();
    qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tGame Stage\r\n";

}


void GameStage::RunGame()
{
    a->create();

    for (int i=0; i<=3; i++)
    {
        s.append(snake);
        s[0].x=150;
        s[0].y=120;
    }
    for (int i=1; i<(s.size()); i++)
    {
        s[i].x=s[i-1].x-10;
        s[i].y=s[0].y;
    }

    timer=new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(drawSnake()));
    timer->start(Speed);
}



void GameStage::drawSnake()
{


    for (int i=(s.size())-1;i>0;--i)
    {
        s[i].x=s[i-1].x;
        s[i].y=s[i-1].y;
    }

    if (s[0].dir==SnakeObject::DOWN)    s[0].y+=10;
    if (s[0].dir==SnakeObject::LEFT)    s[0].x-=10;
    if (s[0].dir==SnakeObject::RIGHT)   s[0].x+=10;
    if (s[0].dir==SnakeObject::UP)      s[0].y-=10;

    if ((s[0].x>=(a->x)-10 && s[0].x<=(a->x)+10) && (s[0].y>=(a->y)-10 && s[0].y<=(a->y)+10))
    {
//        s.resize(s.size()+1);
          s.push_back(snake);
        a->create();
       timer->stop();
        timer->start(Speed>0 ? Speed-=10 : Speed);
        s[(s.size())-1].create();
        ++score;
    }
    for (int i=1;i<(s.size());i++)
        if (s[0].x==s[i].x && s[0].y==s[i].y) { timer->stop(); setHighscore();}

    if ((s[0].x>547 || s[0].x<50) ||(s[0].y<50 || s[0].y>550)) { timer->stop(); setHighscore();}
}

void GameStage::setHighscore()
{


    QString str = QInputDialog::getText( 0,"GAME OVER","Enter Name:",QLineEdit::Normal,"",&Entered);
    if(Entered)
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
    painter->drawImage(0,0,background->scaled(widget->size()));
    for (int i=0; i<(s.size()); i++)
    {
        painter->setPen(s[i].clr);
        painter->fillRect(QRectF(s[i].x,s[i].y,10,10),s[i].clr);
        painter->drawRect(s[i].x,s[i].y,10,10);
    }

    painter->setBrush(a->clr);
    painter->setPen(a->clr);
    painter->drawEllipse(a->rectParams);
    QFont font=widget->font();
    font.setPointSize(30);
    font.setItalic(true);
    font.setFamily("Jet Set");
    widget->setFont(font);
    painter->setPen(QPen(Qt::white));
    painter->drawText(QPointF(425,43),QString::number(score));

    painter->end();
    if (Entered)
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

    if (event->key()==Qt::Key_Up&& s[0].dir!=SnakeObject::DOWN)
    {
        s[0].dir=SnakeObject::UP;

    }
    if (event->key()==Qt::Key_Down && s[0].dir!=SnakeObject::UP)
    {
        s[0].dir=SnakeObject::DOWN;
    }
    if (event->key()==Qt::Key_Right&& s[0].dir!=SnakeObject::LEFT)
    {
        s[0].dir=SnakeObject::RIGHT;
    }
    if (event->key()==Qt::Key_Left&& s[0].dir!=SnakeObject::RIGHT)
    {
        s[0].dir=SnakeObject::LEFT;
    }
}


