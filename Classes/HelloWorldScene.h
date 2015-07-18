#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
	static HelloWorld* create(PhysicsWorld* world);
    bool init(PhysicsWorld* world);
	bool onContactBegan(PhysicsContact& contact);
	void showParticleFireworks();
	void touchEvent();
	void restart(Ref* ref);

private:
	HelloWorld();
	~HelloWorld();
	PhysicsWorld* m_world;
	Sprite* m_basketball;
	PhysicsJointPin* JP;
	PhysicsJointFixed* JF;
	Sprite* m_rope;
	MotionStreak* streak;
	Sprite* m_cat1;
	Sprite* m_cat2;
	Sprite* m_box1;
	Sprite* m_box2;
	bool isCut;
};

#endif // __HELLOWORLD_SCENE_H__
