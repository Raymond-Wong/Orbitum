#include "Entity.h"

Entity::Entity() {
    this->m_sprite = NULL;
}

Entity::~Entity() {
}

Sprite* Entity::getSprite() {
    return this->m_sprite;
}

void Entity::bindSprite(Sprite* s) {
    this->m_sprite = s;
    this->addChild(m_sprite);

    auto spriteSize = m_sprite->getContentSize();
    //m_sprite->setPosition(Point(spriteSize.width / 2, spriteSize.height / 2));
    this->setContentSize(spriteSize);
}