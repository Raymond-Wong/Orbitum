#include "Util.h"

USING_NS_CC;

void Util::scaleTo(Node* sprite, Size size) {
   sprite->setPosition(ccp(size.width/2, size.height/2));
   float winw = size.width; //��ȡ��Ļ���
   float winh = size.height;//��ȡ��Ļ�߶�

   float spx = sprite->getContentSize().width * sprite->getScaleX();
   float spy = sprite->getContentSize().height * sprite->getScaleY();

   sprite->setScaleX(winw/spx); //���þ��������ű���
   sprite->setScaleY(winh/spy);
}
