
#ifndef _RecipeBook_Recipe39_H_
#define _RecipeBook_Recipe39_H_

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe39 : public cocos2d::CCLayer
{
private:
    std::vector<cocos2d::CCPoint> points;
    CCPoint prevLocation;
    CCRenderTexture *pTarget;
    CCSprite *pBrush;
    
    CCRect getTextureRect();
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(Recipe39);
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
};

#endif // _RecipeBook_Recipe39_H_
