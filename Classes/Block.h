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
private:
    bool m_isAlive;
};

#endif