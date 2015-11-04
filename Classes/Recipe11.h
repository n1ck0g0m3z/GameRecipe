#ifndef __RECIPE11_SCENE_H__
#define __RECIPE11_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe11 : public cocos2d::CCLayerGradient
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

	virtual bool Recipe11::ccTouchBegan(CCTouch* touch,CCEvent* event);
	void Recipe11::addFood();
	void Recipe11::gameLogic(float a);
	void Recipe11::spriteMovefinished(CCNode* sender);
	void Recipe11::update(float dt);
	void Recipe11::eat(float delta);
	void Recipe11::menuCloseCallback(CCObject* pSender);
	void Recipe11::changeMode(CCObject* sender);

    // implement the "static node()" method manually
    CREATE_FUNC(Recipe11);
};

#endif // __HELLOWORLD_SCENE_H__

