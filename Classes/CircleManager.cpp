#include "CircleManager.h"
#include "Circle.h"
#include "Config.h"
#include "Util.h"

bool CircleManager::init() {
    createCircles();
    this->scheduleUpdate();
    return true;
}

void CircleManager::createCircles() {
    Circle* circle = NULL;
    Sprite* sprite = NULL;
    auto maxR = Director::getInstance()->getVisibleSize().width / 2;

    for (int i = 0; i < LAYER_AMOUNT; i++) {
        // �����������
        circle = Circle::create();
        circle->bindSprite(Sprite::create(CIRCLE_PATH));
        circle->setMaxRadius(maxR * (i + 1) / LAYER_AMOUNT);
        circle->reset();

        // ��ӹ���
        this->addChild(circle);
        // ������ﵽ�б���
        m_circleArr.pushBack(circle);
    }
}

void CircleManager::update(float delta) {
    for (auto circle : this->m_circleArr) {
        // ������ﴦ�ڼ���״̬
        if (circle->isAlive()) {
            auto size = Director::getInstance()->getVisibleSize();
            circle->setScale(circle->scaleSmall());
            // ��������ƶ�����Ļ���
            if (circle->getBoundingBox().size.width <= 0.8) {
                circle->setMaxRadius(size.width / 2);
                circle->hide();
            } /*else if (block->isCollideWithPlayer(m_player)) {
                //m_player->hit();
                block->hide();
            }*/
        } else {
            // ���ﴦ��δ����״̬
            circle->show();
        }
    }
}
