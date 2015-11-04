#ifndef __RECIPE12_SCENE_H__
#define __RECIPE12_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe12 : public cocos2d::CCLayerGradient
{
protected:
	int m_points;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	virtual bool Recipe12::ccTouchBegan(CCTouch* touch,CCEvent* event);
	void Recipe12::addFood();
	void Recipe12::gameLogic(float a);
	void Recipe12::spriteMoveFinished(CCNode* sender);
	void Recipe12::update(float dt);
	void Recipe12::eat(float delta);
	void Recipe12::menuCloseCallback(CCObject* pSender);
	void Recipe12::changeMode(CCObject* sender);

    // implement the "static node()" method manually
    CREATE_FUNC(Recipe12);
};

#endif // __HELLOWORLD_SCENE_H__

