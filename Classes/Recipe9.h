#ifndef __RECIPE9_SCENE_H__
#define __RECIPE9_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe9 : public cocos2d::CCLayerGradient
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

	virtual bool Recipe9::ccTouchBegan(CCTouch* touches,CCEvent* event);
	virtual void Recipe9::ccTouchMoved(CCTouch* touches,CCEvent* event);
	virtual void Recipe9::ccTouchEnded(CCTouch* touches,CCEvent* event);
	void Recipe9::addFood();
	void Recipe9::gameLogic(float a);
	void Recipe9::spriteMoveFinished(CCNode* sender);
	void Recipe9::update(float dt);
	void Recipe9::eat(float delta);

    // implement the "static node()" method manually
    CREATE_FUNC(Recipe9);
};

#endif // __RECIPE3_SCENE_H__

