#ifndef SNAKEOBJECT_H
#define SNAKEOBJECT_H
#include "Gameobject.h"

class SnakeObject final : public GameObject
{
public:

    SnakeObject();

    void setX(const int) override;
    void setY(const int) override;
    int getX() const     override;
    int getY() const     override;
    void setObjectTraits() override;
    QColor getColor () const  override;
    QRectF getRect ()  const    override;




private:

    QRectF rectParams;
    QColor color;
    int num;
    int x, y;

    GameWidget* widget;

};

#endif // SNAKEOBJECT_H
