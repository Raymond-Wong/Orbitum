#ifndef GAMEPAUSE_H_
#define GAMEPAUSE_H_

#include "cocos2d.h"

using namespace cocos2d;

class GamePause : public Layer {
public:
	GamePause();
	~GamePause();
	CREATE_FUNC(GamePause);
	virtual bool init();
    static cocos2d::CCScene* scene(CCRenderTexture* sqr);
	static cocos2d::CCScene* overScene(CCRenderTexture* sqr);
};
#endif