#include "FloatBox.h"
#include "Util.h"
#include "Config.h"

using namespace cocos2d;

bool FloatBox::init() {
	return true;
}

void FloatBox::showBox( const char* widgetName ) {
    Size size = Director::getInstance()->getVisibleSize();
    this->floatingLayerUI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile(widgetName);
    auto floatingLayer = Helper::seekWidgetByName(this->floatingLayerUI, "floatingLayer");
    Util::scaleTo(this->floatingLayerUI, size);
    this->floatingLayerUI->setPosition(Point(-2, -2));
    this->addChild(this->floatingLayerUI, FLOATING_LAYER_PRIORITY);
    floatingLayer->addTouchEventListener(this, toucheventselector(FloatBox::fadeOutFloatingLayer));
}

void FloatBox::fadeOutFloatingLayer(Ref* target, TouchEventType type) {
    if (type == TouchEventType::TOUCH_EVENT_ENDED) {
        this->floatingLayerUI->setVisible(false);
        Config::isPause = false;
    }
}


