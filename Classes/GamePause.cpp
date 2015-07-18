#include "GamePause.h"
#include "Floatbox.h"
#include "Config.h"


GamePause::GamePause() {

}

GamePause::~GamePause() {}

bool GamePause::init () {
    return true;
}

CCScene* GamePause::scene(CCRenderTexture* sqr) {
	
	CCScene *myscene = CCScene::create();  
	GamePause* mylayer = GamePause::create();
	myscene->addChild(mylayer);

	//���Ӳ��֣�ʹ��Game�����н�ͼ��sqr����ͼƬ����Sprite		
	//����Sprite��ӵ�GamePause��������
	CCSprite *_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());  
	_spr->setPosition(Point(160,245)); //���ڴ�С(480,320)��������������λ�á�
	_spr->setFlipY(true);            //��ת����ΪUI�����OpenGL���겻ͬ
	_spr->setColor(cocos2d::ccGRAY); //ͼƬ��ɫ���ɫ
	mylayer->addChild(_spr);

	FloatBox* floatBox = FloatBox::create();
	mylayer->addChild(floatBox);
    floatBox->showBox(FLOATING_LAYER_UI_PATH);

	return myscene;  
}

CCScene* GamePause::overScene(CCRenderTexture* sqr) {
    CCScene *myscene = CCScene::create();  
	GamePause* mylayer = GamePause::create();
	myscene->addChild(mylayer);

	//���Ӳ��֣�ʹ��Game�����н�ͼ��sqr����ͼƬ����Sprite		
	//����Sprite��ӵ�GamePause��������
	CCSprite *_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());  
	_spr->setPosition(Point(160,245)); //���ڴ�С(480,320)��������������λ�á�
	_spr->setFlipY(true);            //��ת����ΪUI�����OpenGL���겻ͬ
	_spr->setColor(cocos2d::ccGRAY); //ͼƬ��ɫ���ɫ
	mylayer->addChild(_spr);

	FloatBox* floatBox = FloatBox::create();
	mylayer->addChild(floatBox);
    floatBox->showBox(OVER_LAYER_UI_PATH);

	return myscene;  
}


