#ifndef __RECIPE3_SCENE_H__
#define __RECIPE3_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe3 : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	void btnCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(Recipe3);
};

#endif // __RECIPE3_SCENE_H__

