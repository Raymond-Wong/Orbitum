#ifndef _MainScene_H_
#define _MainScene_H_

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"

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
};

#endif