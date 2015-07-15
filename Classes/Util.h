#ifndef _Util_H_
#define _Util_H_

#include "cocos2d.h"

USING_NS_CC;

class Util {
public:
    /**
     * 将节点对象扩大到size
     */
    static void scaleTo(Node*, Size);
    /**
     * 获取某个block的开始位置，根据当前block的半径
     */
    static Point getRandomStartPos(float radius);
    /**
     * 根据x左边和半径获取y坐标
     */
    static float getYByXAndRadius(float radius, float x, int dir);
    /**
     * 获取以屏幕中点为原点的点坐标
     */
    static Point getMyPoint(Point p);
};

#endif