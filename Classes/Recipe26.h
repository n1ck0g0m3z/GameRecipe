#ifndef __RECIPE26_SCENE_H__
#define __RECIPE26_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe26 : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(Recipe26);
};

#endif // __RECIPE7_SCENE_H__

