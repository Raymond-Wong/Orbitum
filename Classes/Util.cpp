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
