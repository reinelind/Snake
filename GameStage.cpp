#include "GameStage.h"
#include "MenuStage.h"
#include "GameStage.h"
#include "AppleObject.h"
#include "SelectStage.h"
#include "LeaderBoard.h"

#include <ctime>
#include <memory>

GameStage::GameStage(int sp)
    : speed (sp), score (0), entered (false), dir(DIRECTION::RIGHT)
{


    srand(static_cast<ulong>(time(nullptr)));


    snakeFactory = std::make_unique <SnakeFactory>();
    appleFactory = std::make_unique <AppleFactory>();
    painter=std::make_unique <QPainter>();
    timer=std::make_unique <QTimer>();
    background=std::make_unique < QImage >(":/images/gameprocess.png");

    apple = appleFactory->create();
    apple->setObjectTraits();
    snkVec.reserve(3);
    const QDateTime now=QDateTime::currentDateTime();
    GameStage::RunGame();

     qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tGame Stage\r\n";
}

void GameStage::RunGame()
{
    do
    {
        apple->setX(rand()%490+50);
        apple->setY(rand()%490+50);
    } while (apple->getX() % 10 != 0 && apple->getY() %10 != 0);

    for (uint i=0; i <= 3; i++)
    {
        snkVec.push_back(snakeFactory->create());
        snkVec[i]->setObjectTraits();
    }

    snkVec.front()->setY(180);
    snkVec.front()->setX(150);



    for (uint i=1; i<(snkVec.size()); i++)
    {
        snkVec[i]->setX(snkVec[i-1]->getX()-10);
        snkVec[i]->setY(snkVec[i-1]->getY());
        snkVec[i]->setObjectTraits();
    }


    connect(timer.get(), SIGNAL(timeout()),this,SLOT(moveSnake()));
    timer->start(speed);
}

void GameStage::moveSnake()
{
    for (ulong i=(snkVec.size())-1;i>0;--i)
    {
        snkVec[i]->setX(snkVec[i-1]->getX());
        snkVec[i]->setY(snkVec[i-1]->getY());
    }

    if (this->getDir()==GameStage::DOWN)
        snkVec.front()->setY(snkVec.front()->getY()+10);
    if (this->getDir()==GameStage::LEFT)
        snkVec.front()->setX(snkVec.front()->getX()-10);
    if (this->getDir()==GameStage::RIGHT)
        snkVec.front()->setX(snkVec.front()->getX()+10);
    if (this->getDir()==GameStage::UP)
        snkVec.front()->setY(snkVec.front()->getY()-10);

    if ((snkVec.front()->getX()>=(apple->getX())-10
         && snkVec.front()->getX()<=(apple->getX())+10)
            && (snkVec.front()->getY()>=(apple->getY())-10
                && snkVec.front()->getY()<=(apple->getY())+10))
    {
        snkVec.push_back(snakeFactory->create());
        snkVec.back()->setX(snkVec[snkVec.size()-2]->getX());
        snkVec.back()->setX(snkVec[snkVec.size()-2]->getY());

        do
        {
            apple->setX(rand()%490+50);
            apple->setY(rand()%490+50);
        } while (apple->getX() % 10 != 0 && apple->getY() % 10 != 0);
        snkVec.back()->setObjectTraits();
        ++score;
    }
    for (uint i=1;i<(snkVec.size()); i++)
        if (snkVec.front()->getX()==snkVec[i]->getX()
                && snkVec.front()->getY()==snkVec[i]->getY())
        {
            timer->stop();
            setHighscore();
        }

    if ((snkVec.front()->getX()>547
         || snkVec.front()->getX()<50)
            ||(snkVec.front()->getY()<50 || snkVec.front()->getY()>550))
    { timer->stop();
        setHighscore();}
}

void GameStage::setHighscore()
{


    QString str = QInputDialog::getText( nullptr,"GAME OVER","Enter Name:",QLineEdit::Normal,"",&entered);
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


    painter->begin(widget);
    painter->drawImage(0,0,background->scaled(widget->size()));
    painter->setPen(snkVec.front()->getColor());
    for (uint i = 0; i < snkVec.size(); i++)
    {
        painter->fillRect(QRectF(snkVec[i]->getX(),snkVec[i]->getY(),10,10),snkVec[i]->getColor());
        painter->drawRect(snkVec[i]->getX(),snkVec[i]->getY(),10,10);
    }

    painter->setBrush(apple->getColor());
    painter->setPen(apple->getColor());
    painter->drawEllipse(QRectF(apple->getX(),apple->getY(),10,10));
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

    if (event->key()==Qt::Key_Up && this->getDir()!=GameStage::DOWN)
    {
        this->setDir(GameStage::UP);

    }
    if (event->key()==Qt::Key_Down && this->getDir()!=GameStage::UP)
    {
        this->setDir(GameStage::DOWN);
    }
    if (event->key()==Qt::Key_Right&& this->getDir()!=GameStage::LEFT)
    {
        this->setDir(GameStage::RIGHT);
    }
    if (event->key()==Qt::Key_Left&& this->getDir()!=GameStage::RIGHT)
    {
        this->setDir(GameStage::LEFT);
    }
}

void GameStage::setDir(GameStage::DIRECTION direction)
{
    dir = direction;
}

GameStage::DIRECTION GameStage::getDir()
{
    return dir;
}



