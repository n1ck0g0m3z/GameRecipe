#ifndef __RECIPE15_SCENE_H__
#define __RECIPE15_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe15 : public cocos2d::CCLayerGradient
{
protected:
	int m_points;
	int m_actionType;
public:
    
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
	virtual bool Recipe15::ccTouchBegan(CCTouch *touch,CCEvent* event);
	void Recipe15::addFood();
	void Recipe15::gameLogic(float a);
	void Recipe15::spriteMoveFinished(CCNode *sender);
	void Recipe15::update(float dt);
	void Recipe15::eat(float delta);
	void Recipe15::menuCloseCallback(CCObject* pSender);
	void Recipe15::changeMode(CCObject* sender);

    CREATE_FUNC(Recipe15);
};

#endif 

