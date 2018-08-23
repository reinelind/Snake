#include "menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent)
{
}


void MenuWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(QPen(QColor(255,0,0,255),this->width()*2));
    painter.drawLine(0,0,this->width(),this->height());
}
