#ifndef __RECIPE13_SCENE_H__
#define __RECIPE13_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe13 : public cocos2d::CCLayerGradient
{
protected:
	int m_points;
	int m_actionType;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();
    
	virtual bool Recipe13::ccTouchBegan(CCTouch* touch,CCEvent* event);
	void Recipe13::addFood();
	void Recipe13::gameLogic(float a);
	void Recipe13::spriteMoveFinished(CCNode* sender);
	void Recipe13::update(float dt);
	void Recipe13::eat(float delta);
	void Recipe13::menuCloseCallback(CCObject* pSender);
	void Recipe13::changeMode(CCObject* sender);

    // implement the "static node()" method manually
    CREATE_FUNC(Recipe13);
};

#endif // __HELLOWORLD_SCENE_H__

