#ifndef __RECIPE34_SCENE_H__
#define __RECIPE34_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe34 : public cocos2d::CCLayer, public CCScrollViewDelegate
{
public:
	void scrollViewDidScroll(CCScrollView* view);
	void scrollViewDidZoom(CCScrollView* view);

    virtual bool init();  

    static cocos2d::CCScene* scene();

    CREATE_FUNC(Recipe34);
};

#endif 