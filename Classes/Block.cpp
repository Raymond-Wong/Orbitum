#include "Block.h"
#include "Config.h"
#include "Util.h"

Block::Block() {
    auto size = Director::getInstance()->getVisibleSize();
    this->radius = size.width / 2;
    this->size = ORI_SCALE;
    this->currentPos = Util::getRandomStartPos(this->radius);
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
        auto size = Director::getInstance()->getVisibleSize();
        this->radius = this->maxRadius;
        this->currentPos = Util::getRandomStartPos(this->radius);
        this->size = ORI_SCALE * this->maxRadius / (size.width / 2);
        this->setPosition(Util::getMyPoint(this->currentPos));
        this->setScale(this->size);
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

Point Block::getNextPos() {
    int area = 0;
    int diff[4] = {1, 1, -1, -1};
    if (this->currentPos.x >= 0 && this->currentPos.y >= 0) {
        this->currentPos.x -= CIRCLE_RATE;
        area = 0;
    } else if (this->currentPos.x < 0 && this->currentPos.y >= 0) {
        if (abs(this->currentPos.x) <= this->radius) {
            this->currentPos.x -= CIRCLE_RATE;
            area = 1;
        } else {
            this->currentPos.x += CIRCLE_RATE;
            area = 2;
        }
    } else if (this->currentPos.x < 0 && this->currentPos.y < 0) {
        this->currentPos.x += CIRCLE_RATE;
        area = 2;
    } else {
        if (this->currentPos.x < this->radius) {
            this->currentPos.x += CIRCLE_RATE;
            area = 3;
        } else {
            this->currentPos.x -= CIRCLE_RATE;
            area = 0;
        }
    }
    this->radius -= SCALE_RATE;
    this->currentPos.y = Util::getYByXAndRadius(this->radius, this->currentPos.x, diff[area]);
    return this->currentPos;
}

float Block::scaleSmall() {
    auto vs = Director::getInstance()->getVisibleSize();
    float ori_scale = ORI_SCALE * this->maxRadius / (vs.width / 2);
    float diff = ori_scale * SCALE_RATE / this->maxRadius;
    this->size -= diff;
    return this->size;
}

void Block::setMaxRadius(float x) {
    this->maxRadius = x;
}