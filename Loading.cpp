#include "Loading.h"
#include "MenuStage.h"


Loading::Loading()
{
    background=new QImage (":/images/IMAGE.png");
    timer=new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(TimerSlot()));
     timer->start(15);
     const QDateTime now=QDateTime::currentDateTime();
     qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tLoading Stage\r\n";
}


void Loading::BackgroundLoad(GameWidget *widget)
{
    painter=new QPainter;
    painter->begin(widget);
    painter->drawImage(0,0,this->background->scaled(widget->size()));
    painter->setPen(QPen (Qt::green,50));
    painter->drawLine(0,590,15*xEndPos,590);
    painter->end();
    if (xEndPos==-1)
    {
        timer->stop();
        delete painter;
        delete timer;
        widget->setCurrent(new Menu());
        delete this;
    }
    widget->update();
}

void Loading::keyPressEvent(GameWidget*,QKeyEvent *){}
void Loading::mousePressEvent(GameWidget*, QMouseEvent *){}


void Loading::TimerSlot()
{
    xEndPos++;
    if (xEndPos>=39)
    {
        xEndPos=-1;
    }

}
