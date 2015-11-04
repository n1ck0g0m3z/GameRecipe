#ifndef __RECIPE30_SCENE_H__
#define __RECIPE30_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe30 : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();

    CREATE_FUNC(Recipe30);
};

#endif 

