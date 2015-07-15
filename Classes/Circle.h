#ifndef _Circle_H_
#define _Circle_H_

#include "cocos2d.h"
#include "Entity.h"

using namespace cocos2d;

class Circle : public Entity {
public:
    Circle();
    ~Circle();
    CREATE_FUNC(Circle);
    virtual bool init();
public:
    void show();
    void hide();
    void reset();
    bool isAlive();
    float scaleSmall();
    void setMaxRadius(float x);
private:
    float maxRadius;
    float radius;
    float size;
    bool m_isAlive;
};

#endif