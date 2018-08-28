#include "GameStage.h"
#include "Menu.h"
#include "GameStage.h"
#include "AppleObject.h"
#include "SelectStage.h"
#include "LeaderBoard.h"

GameStage::GameStage(int sp)
    : Speed (sp), score (0), entered (false)
{
    srand(static_cast<ulong>(time(nullptr)));

    snakeFactory = new SnakeFactory;
    appleFactory = new AppleFactory;

    snake = snakeFactory->create();
    apple = appleFactory->create();


    snkVec.reserve(3);

    background=new QImage (":/images/gameprocess.png");
    const QDateTime now=QDateTime::currentDateTime();
    qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tGame Stage\r\n";
    GameStage::RunGame();
}

void GameStage::RunGame()
{
    apple->setX(rand()%490+50);
    apple->setY(rand()%490+50);

    apple->setObjectTraits();

    for (uint i=0; i <= 3; i++)
    {
        snkVec.push_back(snake);
        snkVec[i]->setObjectTraits();
    }

    snkVec.front()->setX(150);
    snkVec.front()->setY(180);


    for (uint i=1; i<(snkVec.size()); i++)
    {
        snkVec[i]->setX(snkVec[i-1]->getX()-10);
        snkVec[i]->setY(snkVec.front()->getY());
    }

    timer=new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(moveSnake()));
    timer->start(Speed);
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
        snkVec.front()->setY(snkVec.front()->getY()+10);

    if ((snkVec.front()->getX()>=(apple->getX())-10
         && snkVec.front()->getX()<=(apple->getX())+10)
            && (snkVec.front()->getY()>=(apple->getY())-10
                && snkVec.front()->getY()<=(apple->getY())+10))
    {
        snkVec.push_back(snake);
        apple->setX(rand()%490+50);
        apple->setY(rand()%490+50);
        snkVec.back();
        ++score;
    }
    for (int i=1;i<(snkVec.size()); i++)
        if (snkVec.front()->getX()==snkVec[i]->getX() && snkVec.front()->getY()==snkVec[i]->getY()) { timer->stop(); setHighscore();}

    if ((snkVec.front()->getX()>547 || snkVec.front()->getX()<50) ||(snkVec.front()->getY()<50 || snkVec.front()->getY()>550)) { timer->stop(); setHighscore();}
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

    painter=new QPainter;
    painter->begin(widget);
    painter->setRenderHints(QPainter::Antialiasing);
    painter->drawImage(0,0,background->scaled(widget->size()));
    for (auto vec : snkVec)
    {
        painter->setPen(Qt::white);
        painter->fillRect(QRectF(vec->getX(),vec->getY(),10,10),Qt::white);
        painter->drawRect(vec->getX(),vec->getY(),10,10);
    }

    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
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



