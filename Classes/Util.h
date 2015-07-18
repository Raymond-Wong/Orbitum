#ifndef _Util_H_
#define _Util_H_

#include "cocos2d.h"

USING_NS_CC;

class Util {
public:
    /**
     * ���ڵ��������size
     */
    static void scaleTo(Node*, Size);
    /**
     * ��ȡĳ��block�Ŀ�ʼλ�ã����ݵ�ǰblock�İ뾶
     */
    static Point getRandomStartPos(float radius);
    /**
     * ����x��ߺͰ뾶��ȡy����
     */
    static float getYByXAndRadius(float radius, float x, int dir);
    /**
     * ��ȡ����Ļ�е�Ϊԭ��ĵ�����
     */
    static Point getMyPoint(Point p);
};

#endif