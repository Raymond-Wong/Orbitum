#include "Player.h"
#include "Config.h"
#include "FloatBox.h"
#include "Util.h"

Player::Player() {
    m_isJumping = false;
    m_iHP = 0;
}

Player::~Player() {}

bool Player::init() {
    return true;
}

void Player::jump() {
    if (getSprite() == NULL || m_isJumping || Config::isPause) {
        return;
    }
    auto size = Director::getInstance()->getVisibleSize();
    if (size.width / 2 - this->radius < 10) {
        return;
    }
    m_isJumping = true;
    this->size = 0.15;
    float xdiff = this->currentPos.x > 0 ? 1 : -1;
    float ydiff = this->currentPos.y > 0 ? 1 : -1;
    auto jump = JumpBy::create(0.2f, Point(xdiff * size.width / 11, ydiff * size.width / 11), size.width / 10, 1);
    auto scale = ScaleTo::create(0.2f, this->size);
    auto callFunc = CallFunc::create([&](){
        auto vs = Director::getInstance()->getVisibleSize();
        this->currentPos = Point(this->getPosition().x - vs.width / 2, this->getPosition().y - vs.width / 2);
        this->radius += vs.width / 11;
        this->maxRadius = this->maxRadius > this->radius ? this->maxRadius : this->radius;
        this->setScale(0.1);
        m_isJumping = false;
    });
    auto actions = Spawn::create(jump, scale, NULL);
    auto jumpActions = Sequence::create(actions, callFunc, NULL);
    this->runAction(jumpActions);
}

void Player::hit() {
    if (getSprite() == NULL) {
        return;
    }

    Config::isPause = true;
}

int Player::getiHP() {
    return m_iHP;
}