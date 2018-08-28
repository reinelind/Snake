#ifndef APPLEOBJECT_H
#define APPLEOBJECT_H
#include "Gameobject.h"


class AppleObject final : public GameObject
{

public:
    void setX(const int) override;
    void setY(const int) override;
    int getX() const     override;
    int getY() const     override;
    void setObjectTraits() override;


private:   
    QRectF rectParams;
    QColor color;
    int x,y;


};

#endif // APPLEOBJECT_H
