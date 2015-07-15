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
        // �����������
        block = Block::create();
        block->bindSprite(Sprite::create(MONSTER_PATH));
        block->setMaxRadius(maxR / 2 + (maxR / 2 * (i + 1) / LAYER_AMOUNT));
        block->reset();

        // ��ӹ���
        this->addChild(block);
        // ������ﵽ�б���
        m_blockArr.pushBack(block);
    }
}

void BlockManager::update(float delta) {
    for (auto block : this->m_blockArr) {
        // ������ﴦ�ڼ���״̬
        if (block->isAlive()) {
            auto size = Director::getInstance()->getVisibleSize();
            block->setPosition(Util::getMyPoint(block->getNextPos()));
            block->setScale(block->scaleSmall());
            // ��������ƶ�����Ļ���
            if (block->getBoundingBox().size.width <= 0.8) {
                block->hide();
            } /*else if (block->isCollideWithPlayer(m_player)) {
                //m_player->hit();
                block->hide();
            }*/
        } else {
            // ���ﴦ��δ����״̬
            block->show();
        }
    }
}

void BlockManager::bindPlayer(Block* player) {
    m_player = player;
}