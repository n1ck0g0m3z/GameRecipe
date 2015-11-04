#ifndef __RECIPE10_SCENE_H__
#define __RECIPE10_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe10 : public cocos2d::CCLayerGradient
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	virtual bool Recipe10::ccTouchBegan(CCTouch* touches,CCEvent* event);
	virtual void Recipe10::ccTouchMoved(CCTouch* touches,CCEvent* event);
	virtual void Recipe10::ccTouchEnded(CCTouch* touches,CCEvent* event);
	void Recipe10::addFood();
	void Recipe10::gameLogic(float a);
	void Recipe10::spriteMoveFinished(CCNode* sender);
	void Recipe10::update(float dt);
	void Recipe10::eat(float delta);
	void Recipe10::menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(Recipe10);
};

#endif // __RECIPE3_SCENE_H__

