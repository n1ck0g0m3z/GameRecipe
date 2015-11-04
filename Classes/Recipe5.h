#ifndef __RECIPE5_SCENE_H__
#define __RECIPE5_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe5 : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	void gameLogic(float a);
	void addFood();
	void spriteMoveFinished(CCNode* sender);

    // implement the "static node()" method manually
    CREATE_FUNC(Recipe5);
};

#endif // __HELLOWORLD_SCENE_H__

