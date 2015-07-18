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

	//增加部分：使用Game界面中截图的sqr纹理图片创建Sprite		
	//并将Sprite添加到GamePause场景层中
	CCSprite *_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());  
	_spr->setPosition(Point(160,245)); //窗口大小(480,320)，这个相对于中心位置。
	_spr->setFlipY(true);            //翻转，因为UI坐标和OpenGL坐标不同
	_spr->setColor(cocos2d::ccGRAY); //图片颜色变灰色
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

	//增加部分：使用Game界面中截图的sqr纹理图片创建Sprite		
	//并将Sprite添加到GamePause场景层中
	CCSprite *_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());  
	_spr->setPosition(Point(160,245)); //窗口大小(480,320)，这个相对于中心位置。
	_spr->setFlipY(true);            //翻转，因为UI坐标和OpenGL坐标不同
	_spr->setColor(cocos2d::ccGRAY); //图片颜色变灰色
	mylayer->addChild(_spr);

	FloatBox* floatBox = FloatBox::create();
	mylayer->addChild(floatBox);
    floatBox->showBox(OVER_LAYER_UI_PATH);

	return myscene;  
}


