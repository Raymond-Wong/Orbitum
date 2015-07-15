#include "Util.h"

USING_NS_CC;

void Util::scaleTo(Node* sprite, Size size) {
   sprite->setPosition(ccp(size.width/2, size.height/2));
   float winw = size.width; //获取屏幕宽度
   float winh = size.height;//获取屏幕高度

   float spx = sprite->getContentSize().width * sprite->getScaleX();
   float spy = sprite->getContentSize().height * sprite->getScaleY();

   sprite->setScaleX(winw/spx); //设置精灵宽度缩放比例
   sprite->setScaleY(winh/spy);
}

Point Util::getRandomStartPos(float radius) {
    float r = CCRANDOM_0_1() * 2 - 1;
    float x = r * radius;
    float y = getYByXAndRadius(radius, x, r);
    return Point(x, y);
}

float Util::getYByXAndRadius(float radius, float x, int dir) {
    float y = radius * radius - x * x;
    y = sqrt(y);
    if (dir < 0)
        y = -1 * y;
    return y;
}

Point Util::getMyPoint(Point p) {
    auto size = Director::getInstance()->getVisibleSize();
    float x = p.x + size.width / 2;
    float y = p.y + size.height / 2;
    return Point(x, y);
}
