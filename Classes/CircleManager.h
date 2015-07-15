#ifndef _CircleManager_H_
#define _CircleManager_H_

#include "cocos2d.h"
#include "Circle.h"
USING_NS_CC;

#define LAYER_AMOUNT 10

class CircleManager : public Node {
public:
    CREATE_FUNC(CircleManager);
    virtual bool init();
    virtual void update(float delta);

private:
    void createCircles();
    Vector<Circle*> m_circleArr;
};

#endif