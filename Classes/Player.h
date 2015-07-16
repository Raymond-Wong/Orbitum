#ifndef _Player_H_
#define _Player_H_

#include "cocos2d.h"
#include "Block.h"

#define JUMP_ACTION_TAG 1

using namespace cocos2d;

class Player : public Block {
public:
    Player();
    ~Player();
    CREATE_FUNC(Player);
    virtual bool init();
    bool m_isJumping;
public:
    void jump();
    void hit();
    int getiHP();
private:
    int m_iHP;
};

#endif