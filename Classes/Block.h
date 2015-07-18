#ifndef _Block_H_
#define _Block_H_

#include "cocos2d.h"
#include "Entity.h"

using namespace cocos2d;

class Block : public Entity {
public:
    Block();
    ~Block();
    CREATE_FUNC(Block);
    virtual bool init();
public:
    void show();
    void hide();
    void reset();
    bool isAlive();
    bool isCollideWithPlayer(Block* other);
    Point getNextPos();
    float scaleSmall();
    void setMaxRadius(float x);
protected:
public:
    float maxRadius;
    float radius;
    float size;
    bool m_isAlive;
    Point currentPos;
    
};

#endif