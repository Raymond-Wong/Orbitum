#ifndef _FloatBox_H_
#define _FloatBox_H_

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

class FloatBox : public Node {
public:
    CREATE_FUNC(FloatBox);
    virtual bool init();

public:
	void showBox(const char* widgetName);

private:
    Widget* floatingLayerUI;
    void fadeOutFloatingLayer(Ref* target, TouchEventType type);
};

#endif