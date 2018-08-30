#include "Gamewidget.h"
#include "Loading.h"


void GameWidget::paintEvent(QPaintEvent *)
{
    BackgroundLoad();
}

void GameWidget::setCurrent(State *s)
{
    current=s;
}

void GameWidget::BackgroundLoad()
{
    current->BackgroundLoad(this);
}

void GameWidget::mousePressEvent(QMouseEvent * click)
{
    current->mousePressEvent(this, click);
}


void GameWidget::keyPressEvent(QKeyEvent * press)
{
    current->keyPressEvent(this,press);
}

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{

    const QDateTime now=QDateTime::currentDateTime();
    qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tIn GameWidget\r\n";
    setFixedSize(600,600);
    current=new Loading();

}

 void GameWidget::quit [[noreturn]] ()
{   const QDateTime now=QDateTime::currentDateTime();
    qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tExiting...\r\n";
    qDebug()<<now.toString("yyyy-MM-dd hh:mm:ss")<<now.timeZoneAbbreviation()<<"\tSUCCESSFUL END OF SESSION\r\n";
    qDebug()<<"================================================================================\r\n";

    exit(0);
}




