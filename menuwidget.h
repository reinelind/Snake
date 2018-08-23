#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QPainter>

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
     MenuWidget(QWidget *parent = 0);

private:
     void paintEvent(QPaintEvent* event) override;

};

#endif // MENUWIDGET_H
