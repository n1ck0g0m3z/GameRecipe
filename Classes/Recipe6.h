#ifndef __RECIPE6_SCENE_H__
#define __RECIPE6_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe6 : public cocos2d::CCLayerGradient
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

	void gameLogic(float a);
	void addFood();
	void spriteMoveFinished(CCNode* sender);
    
	void btnCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(Recipe6);
};

#endif // __RECIPE6_SCENE_H__

