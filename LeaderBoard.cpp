#include "LeaderBoard.h"
#include "MenuStage.h"


LeaderBoard::LeaderBoard(): scoreQuantity(0)
{
    highscores.reserve(10);
    background=new QImage (":/images/leaderboard.png");
    const QDateTime now=QDateTime::currentDateTime();
    QString tempString,tempScoreString;


    qDebug() << now.toString("yyyy-MM-dd hh:mm:ss") << now.timeZoneAbbreviation() << "\tLeaderBoard Stage\r\n";

    QFile table("Highscores.txt");

    if (table.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!table.atEnd())
        {
            int tempScore;
            QString str=table.readLine();
            tempString=str.split(" ")[0];
            tempScore=str.split(" ")[1].toInt();
            highscores.push_back(std::make_pair(tempString,tempScore));
            scoreQuantity++;
        }
    }
    else
    {
        qDebug()<<"Error: File not opened\r\n";
    }


    mySortTable(highscores);
    scoreQuantity=scoreQuantity>10 ? 10 : scoreQuantity;
}

void LeaderBoard::BackgroundLoad(GameWidget *widget)
{
    painter=new QPainter;
    painter->begin(widget);
    painter->drawImage(0,0,background->scaled(widget->size()));
    QFont font=widget->font();
    font.setPointSize(25);
    font.setItalic(true);
    font.setFamily("Jet Set");
    widget->setFont(font);

    for (int i=0; i<scoreQuantity; i++)
    {

        painter->setPen(QPen(Qt::white));
        QString str=QString::number(i+1)+(i==0 ? "st" : (i==1 ? "nd" : (i==2 ? "rd" : "th")));
        painter->drawText(QPointF(25,90+(i*35)),str);
        painter->drawText(QPointF(161,90+(i*35)),highscores[i].first);
        painter->drawText(QPointF(440,90+(i*35)),QString::number(highscores[i].second));

    }
    painter->end();

}

void LeaderBoard::mousePressEvent(GameWidget *, QMouseEvent *){}

void LeaderBoard::keyPressEvent(GameWidget * widget, QKeyEvent *event)
{
    if (event->key()==Qt::Key_Escape)
    {
        widget->setCurrent(new Menu());
        widget->update();
        delete this;
    }
}

template <typename F, typename S>
void LeaderBoard::mySortTable(std::vector <std::pair<F,S> > & myVectorOfPairs)
{
    for (int i=0; i<scoreQuantity-1; i++)
     for (int j=i+1; j<scoreQuantity; j++)
         if (myVectorOfPairs[i].second<myVectorOfPairs[j].second)
         {
             F tempF=myVectorOfPairs[i].first;
             S tempS=myVectorOfPairs[i].second;

             myVectorOfPairs[i].first = myVectorOfPairs[j].first;
             myVectorOfPairs[i].second = myVectorOfPairs[j].second;
             myVectorOfPairs[j].first = tempF;
             myVectorOfPairs[j].second = tempS;
         }
}
