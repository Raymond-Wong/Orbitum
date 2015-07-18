#include "HelloWorldScene.h"
using namespace std;
USING_NS_CC;

HelloWorld::HelloWorld() : m_world(NULL)
                         , m_basketball(NULL)
                         
{

}

HelloWorld::~HelloWorld()
{
}
Scene* HelloWorld::createScene()
{
   
	Scene* scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -150));
	auto layer = HelloWorld::create(scene->getPhysicsWorld());
	scene->addChild(layer);

    return scene;
}

HelloWorld* HelloWorld::create(PhysicsWorld* world)
{
	HelloWorld* pRet = new HelloWorld();
	if (pRet && pRet->init(world))
	{
		return pRet;
	}
	pRet = NULL;
	return NULL;
}

bool HelloWorld::init(PhysicsWorld* world)
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	m_world = world;
	isCut = false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
	Size winSize = Director::getInstance()->getWinSize();
    
	Node* bound = Node::create();
	PhysicsBody* boundBody = PhysicsBody::createEdgeBox(winSize);
	boundBody->setDynamic(false);
	bound->setPhysicsBody(boundBody);
	bound->setPosition(winSize.width / 2, winSize.height / 2);
	bound->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	addChild(bound);

	Node* ground = Node::create();
	ground->setPhysicsBody(PhysicsBody::createEdgeSegment(Vec2(0,300), Vec2(winSize.width, 300)));
	ground->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	ground->getPhysicsBody()->setDynamic(false);
	addChild(ground);

	m_rope = Sprite::create("rope.png");
	m_rope->setPhysicsBody(PhysicsBody::createBox(m_rope->getContentSize()));
	m_rope->getPhysicsBody()->setDynamic(true);
	m_rope->setPosition(Point(winSize.width / 2 - m_rope->getContentSize().width / 2 - 5, winSize.height - m_rope->getContentSize().height / 2 - 10));
	addChild(m_rope);

	Node* ropeBase = Node::create();
	ropeBase->setPhysicsBody(PhysicsBody::createEdgeSegment(Vec2(0, 0), Vec2(0, 0)));
	ropeBase->getPhysicsBody()->setDynamic(false);
	ropeBase->setPosition(Point(winSize.width / 2, winSize.height - m_rope->getContentSize().height / 2 - 10));
	addChild(ropeBase);

	JP = PhysicsJointPin::construct(m_rope->getPhysicsBody(), ropeBase->getPhysicsBody(), ropeBase->getPosition());
	m_world->addJoint(JP);

	m_basketball = Sprite::create("basketball.png");
	m_basketball->setPhysicsBody(PhysicsBody::createBox(m_basketball->getContentSize()));
	m_basketball->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	m_basketball->setPosition(winSize.width / 2 - m_rope->getContentSize().width - 5 - m_basketball->getContentSize().width / 2,
		                      winSize.height - m_rope->getContentSize().height / 2 - 10);
	m_basketball->getPhysicsBody()->setDynamic(true);
	m_basketball->setTag(1);
	addChild(m_basketball);

	JF = PhysicsJointFixed::construct(m_rope->getPhysicsBody(), m_basketball->getPhysicsBody(), m_basketball->getPosition());
	m_world->addJoint(JF);

	m_box1 = Sprite::create("box.png");
	m_box1->setPhysicsBody(PhysicsBody::createBox(m_box1->getContentSize()));
	m_box1->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	m_box1->setPosition(300, 300 + m_box1->getContentSize().height / 2);
	m_box1->getPhysicsBody()->setDynamic(true);
	m_box1->setTag(2);
	addChild(m_box1);

	m_box2 = Sprite::create("box.png");
	m_box2->setPhysicsBody(PhysicsBody::createBox(m_box2->getContentSize()));
	m_box2->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	m_box2->setPosition(winSize.width - 300, 300 + m_box2->getContentSize().height / 2);
	m_box2->getPhysicsBody()->setDynamic(true);
	m_box2->setTag(2);
	addChild(m_box2);

	m_cat1 = Sprite::create("man.png");
	m_cat1->setPhysicsBody(PhysicsBody::createBox(m_cat1->getContentSize()));
	m_cat1->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	m_cat1->setPosition(300 - m_box1->getContentSize().width / 2 - m_cat1->getContentSize().width / 2 - 15, 300 + m_cat1->getContentSize().height / 2);
	m_cat1->getPhysicsBody()->setDynamic(true);
	m_cat1->setTag(3);
	addChild(m_cat1);

	m_cat2 = Sprite::create("man.png");
	m_cat2->setPhysicsBody(PhysicsBody::createBox(m_cat2->getContentSize()));
	m_cat2->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
	m_cat2->setPosition(winSize.width - 300 + m_box2->getContentSize().width / 2 + m_cat2->getContentSize().width / 2 + 15, 300 + m_cat2->getContentSize().height / 2);
	m_cat2->getPhysicsBody()->setDynamic(true);
	m_cat2->setTag(3);
	addChild(m_cat2);

	touchEvent();

	CCLabelTTF *label = CCLabelTTF::create("Restart", "Arial", 20);
	auto restart = CCMenuItemLabel::create(label, CC_CALLBACK_1(HelloWorld::restart, this));
	restart->setPosition(Point(50, winSize.height - 30));
	auto menu = Menu::create(restart, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    return true;
}

void HelloWorld::touchEvent()
{
	streak = MotionStreak::create(0.5f, 10, 30, Color3B::WHITE, "flash.png");
	this->addChild(streak, 2);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event){
		return true;
	};
	listener->onTouchMoved = [&](Touch* touch, Event* event){
		auto touch_pre = touch->getPreviousLocation();
		auto touch_pos = touch->getLocation();
		streak->setPosition(touch_pos);
		if (!isCut)
		{
			if (m_rope->getBoundingBox().containsPoint(touch->getLocation()))
			{
				isCut = true;
				m_world->removeJoint(JF);
			}
		}
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

bool HelloWorld::onContactBegan(PhysicsContact& contact)
{
	int TagA = contact.getShapeA()->getBody()->getNode()->getTag();
	int TagB = contact.getShapeB()->getBody()->getNode()->getTag();

	if (TagA == 1 && TagB == 3) {
		contact.getShapeB()->getBody()->getNode()->getParent()->removeChild(contact.getShapeB()->getBody()->getNode());
		showParticleFireworks();
	}
	else if (TagA == 3 && TagB == 1) {
		contact.getShapeA()->getBody()->getNode()->getParent()->removeChild(contact.getShapeA()->getBody()->getNode());
		showParticleFireworks();
	}

	return true;
}

void HelloWorld::showParticleFireworks()
{
	Size winSize = Director::getInstance()->getWinSize();
	ParticleFireworks* fireworks = ParticleFireworks::create();
	fireworks->setPosition(winSize.width / 2, winSize.height / 2);
	addChild(fireworks);
}

void HelloWorld::restart(Ref* ref)
{
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(scene);
}






