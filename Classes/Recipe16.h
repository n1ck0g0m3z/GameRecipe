#ifndef __RECIPE16_SCENE_H__
#define __RECIPE16_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe16 : public cocos2d::CCLayerGradient
{
protected:
	int m_points;
	int m_actionType;
public:
    
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
	virtual bool Recipe16::ccTouchBegan(CCTouch *touch,CCEvent* event);
	void Recipe16::addFood();
	void Recipe16::gameLogic(float a);
	void Recipe16::spriteMoveFinished(CCNode *sender);
	void Recipe16::update(float dt);
	void Recipe16::eat(float delta);
	void Recipe16::menuCloseCallback(CCObject* pSender);
	void Recipe16::changeMode(CCObject* sender);

    CREATE_FUNC(Recipe16);
};

#endif 
