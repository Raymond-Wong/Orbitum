#include "MainScene.h"
#include "Util.h"
#include "Config.h"
#include "FloatBox.h"

USING_NS_CC;

Scene* MainScene::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MainScene::init() {
    if (!Layer::init())
        return false;

    // 初始化背景
    initBG();
    // 初始化浮动层
    initFloatingLayer();
    return true;
}

/**
 * 初始化背景
 */
void MainScene::initBG() {
    auto size = Director::getInstance()->getVisibleSize();
    auto bg = Sprite::create(BG_PATH);
    Util::scaleTo(bg, size);
    bg->setPosition(Point(size.width / 2, size.height / 2));
    this->addChild(bg, BG_LAYER_PRIORITY);
}

void MainScene::initFloatingLayer() {
    FloatBox* floatBox = FloatBox::create();
    this->addChild(floatBox);
    floatBox->showBox(FLOATING_LAYER_UI_PATH);
}