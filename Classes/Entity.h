#ifndef _Entity_H_
#define _Entity_H_

#include "cocos2d.h"
USING_NS_CC;

class Entity : public Node {
public:
    Entity();
    ~Entity();
    // 获取该实体对应的精灵对象
    Sprite* getSprite();
    // 设置该实体内部的精灵对象
    void bindSprite(Sprite* sprite);
private:
    Sprite* m_sprite;
};

#endif