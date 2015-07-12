#include "Block.h"

Block::Block() {
    this->m_isAlive = false;
}

Block::~Block() {}

bool Block::init() {
    return true;
}

void Block::show() {
    if (getSprite() != NULL) {
        setVisible(true);
        m_isAlive = true;
    }
}

void Block::hide() {
    if (getSprite() != NULL) {
        setVisible(false);
        reset();
        m_isAlive = false;
    }
}

void Block::reset() {
    if (getSprite() != NULL) {
        // 初始化怪物坐标
        setPosition(Point(800 + CCRANDOM_0_1() * 1500, 150 - CCRANDOM_0_1() * 80));
    }
}

bool Block::isAlive() {
    return m_isAlive;
}

bool Block::isCollideWithPlayer(Block* other) {
    Rect entityRect = other->getBoundingBox();
    Point monsterPos = getPosition();
    return entityRect.containsPoint(monsterPos);
}