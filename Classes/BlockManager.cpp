#include "BlockManager.h"
#include "Block.h"
#include "Config.h"
#include "Util.h"

bool BlockManager::init() {
    createBlocks();
    this->scheduleUpdate();
    return true;
}

void BlockManager::createBlocks() {
    Block* block = NULL;
    Sprite* sprite = NULL;
    auto maxR = Director::getInstance()->getVisibleSize().width / 2;

    for (int i = 0; i < LAYER_AMOUNT; i++) {
        // 创建怪物对象
        block = Block::create();
        block->bindSprite(Sprite::create(MONSTER_PATH));
        block->setMaxRadius(maxR / 2 + (maxR / 2 * (i + 1) / LAYER_AMOUNT));
        block->reset();

        // 添加怪物
        this->addChild(block);
        // 保存怪物到列表中
        m_blockArr.pushBack(block);
    }
}

void BlockManager::update(float delta) {
    for (auto block : this->m_blockArr) {
        // 如果怪物处于激活状态
        if (block->isAlive()) {
            auto size = Director::getInstance()->getVisibleSize();
            block->setPosition(Util::getMyPoint(block->getNextPos()));
            block->setScale(block->scaleSmall());
            // 如果怪物移动到屏幕左边
            if (block->getBoundingBox().size.width <= 0.8) {
                block->hide();
            } /*else if (block->isCollideWithPlayer(m_player)) {
                //m_player->hit();
                block->hide();
            }*/
        } else {
            // 怪物处于未激活状态
            block->show();
        }
    }
}

void BlockManager::bindPlayer(Block* player) {
    m_player = player;
}