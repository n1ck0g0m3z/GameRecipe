#ifndef __RECIPE28_SCENE_H__
#define __RECIPE28_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe28 : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();

    CREATE_FUNC(Recipe28);

	void Recipe28::flipCard();
	void Recipe28::flipCard2();
};

#endif 

