#include "MainScene.h"
#include "Util.h"
#include "Config.h"
#include "FloatBox.h"
#include "BlockManager.h"
#include "CircleManager.h"
#include "Player.h"

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

    auto size = Director::getInstance()->getVisibleSize();

    // 初始化玩家
    m_player = Player::create();
    m_player->bindSprite(Sprite::create(PLAYER_PATH));
    m_player->setMaxRadius(0.4 * size.width / 2);
    m_player->reset();
    this->addChild(m_player, BLOCK_LAYER_PRIORITY);

    // 初始化背景
    initBG();
    // 初始化按钮层
    initBtnLayer();
    // 初始化浮动层
    //initFloatingLayer();
    // 初始化圆圈管理器
    CircleManager* circleMgr = CircleManager::create();
    this->addChild(circleMgr, CIRCLE_LAYER_PRIORITY);
    // 初始化方块管理器
    BlockManager* blockMgr = BlockManager::create();
    this->addChild(blockMgr, BLOCK_LAYER_PRIORITY);
    blockMgr->bindPlayer(m_player);
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

void MainScene::initBtnLayer() {
    Size size = Director::getInstance()->getVisibleSize();
    this->btnLayerUI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile(BTN_LAYER_UI_PATH);
    auto pauseBtn = (Button*)Helper::seekWidgetByName(this->btnLayerUI, "PauseBtn");
    this->addChild(this->btnLayerUI, BTN_LAYER_PRIORITY);
    pauseBtn->addTouchEventListener(this, toucheventselector(MainScene::pause));
    auto jumpBtn = (Button*)Helper::seekWidgetByName(this->btnLayerUI, "JumpBtn");
    jumpBtn->addTouchEventListener(this, toucheventselector(MainScene::jumpEvent));
}

void MainScene::pause(Ref* target, TouchEventType type) {
    if (type == TouchEventType::TOUCH_EVENT_ENDED && !Config::isPause) {
        Config::isPause = true;
        FloatBox* floatBox = FloatBox::create();
        this->addChild(floatBox);
        floatBox->showBox(FLOATING_LAYER_UI_PATH);
    }
}

void MainScene::jumpEvent(Ref* target, TouchEventType type) {
    if (type == TouchEventType::TOUCH_EVENT_ENDED) {
        this->m_player->jump();
    }
}