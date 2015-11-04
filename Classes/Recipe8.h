#ifndef __RECIPE8_SCENE_H__
#define __RECIPE8_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe8 : public cocos2d::CCLayerGradient
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	virtual bool Recipe8::ccTouchBegan(CCTouch* touches,CCEvent* event);
	virtual void Recipe8::ccTouchMoved(CCTouch* touches,CCEvent* event);
	virtual void Recipe8::ccTouchEnded(CCTouch* touches,CCEvent* event);
	void Recipe8::addFood();
	void Recipe8::gameLogic(float a);
	void Recipe8::spriteMoveFinished(CCNode* sender);
	void Recipe8::update(float dt);


    // implement the "static node()" method manually
    CREATE_FUNC(Recipe8);
};

#endif // __RECIPE7_SCENE_H__

