#ifndef _MainScene_H_
#define _MainScene_H_

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
#include "Player.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

class MainScene : public Layer {
public:
    static bool isPause;
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainScene);
private:
    void initBG();
    void initFloatingLayer();
    void initBtnLayer();
    Widget* btnLayerUI;
    Player* m_player;
    void pause(Ref* target, TouchEventType type);
    void jumpEvent(Ref* target, TouchEventType type);
};

#endif