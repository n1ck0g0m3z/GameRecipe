#ifndef __RECIPE17_SCENE_H__
#define __RECIPE17_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe17 : public cocos2d::CCLayerGradient
{
protected:
	int m_points;
	int m_actionType;

public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
	virtual bool Recipe17::ccTouchBegan(CCTouch *touch,CCEvent* event);
	void Recipe17::addFood();
	void Recipe17::gameLogic(float a);
	void Recipe17::spriteMoveFinished(CCNode *sender);
	void Recipe17::update(float dt);
	void Recipe17::eat(float delta);
	void Recipe17::menuCloseCallback(CCObject* pSender);
	void Recipe17::changeMode(CCObject* sender);

    CREATE_FUNC(Recipe17);
};

#endif // __RECIPE6_SCENE_H__

