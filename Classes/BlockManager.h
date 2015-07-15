#ifndef _BlockManager_H_
#define _BlockManager_H_

#include "cocos2d.h"
#include "Block.h"
USING_NS_CC;

#define LAYER_AMOUNT 10

class BlockManager : public Node {
public:
    CREATE_FUNC(BlockManager);
    virtual bool init();
    virtual void update(float delta);

    void bindPlayer(Block* player);
private:
    void createBlocks();
    Block* m_player;
    Vector<Block*> m_blockArr;
};

#endif