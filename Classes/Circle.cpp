#include "Circle.h"
#include "Config.h"
#include "Util.h"

Circle::Circle() {
    auto size = Director::getInstance()->getVisibleSize();
    this->radius = size.width / 2;
    this->size = ORI_CIRCLE_SCALE;
    this->m_isAlive = false;
}

Circle::~Circle() {}

bool Circle::init() {
    return true;
}

void Circle::show() {
    if (getSprite() != NULL) {
        setVisible(true);
        m_isAlive = true;
    }
}

void Circle::hide() {
    if (getSprite() != NULL) {
        setVisible(false);
        reset();
        m_isAlive = false;
    }
}

void Circle::reset() {
    if (getSprite() != NULL) {
        // 初始化怪物坐标
        auto size = Director::getInstance()->getVisibleSize();
        this->radius = this->maxRadius;
        this->size = ORI_CIRCLE_SCALE * this->maxRadius / (size.width / 2);
        this->setScale(this->size);
        auto cSize = this->getBoundingBox().size;
        this->setPosition(Point(size.width / 2, size.height / 2));
    }
}

bool Circle::isAlive() {
    return m_isAlive;
}

float Circle::scaleSmall() {
    auto vs = Director::getInstance()->getVisibleSize();
    float ori_scale = ORI_CIRCLE_SCALE * this->maxRadius / (vs.width / 2);
    float diff = ori_scale * SCALE_RATE / this->maxRadius;
    this->size -= diff;
    return this->size;
}

void Circle::setMaxRadius(float x) {
    this->maxRadius = x;
}