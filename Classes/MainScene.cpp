#include "MainScene.h"
#include "Util.h"
#include "Config.h"
#include "FloatBox.h"
#include "BlockManager.h"
#include "CircleManager.h"

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
    // 初始化方块管理器
    BlockManager* blockMgr = BlockManager::create();
    this->addChild(blockMgr, BLOCK_LAYER_PRIORITY);
    //blockMgr->bindPlayer(m_player);
    // 初始化圆圈管理器
    CircleManager* circleMgr = CircleManager::create();
    this->addChild(circleMgr, CIRCLE_LAYER_PRIORITY);
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