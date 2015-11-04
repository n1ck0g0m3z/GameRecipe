#include "Recipe26.h"

USING_NS_CC;

CCScene* Recipe26::scene()
{
    CCScene *scene = CCScene::create();
    
    Recipe26 *layer = Recipe26::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool Recipe26::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
	CCSprite* pSprite = CCSprite::create("test.png");
	pSprite->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));

	CCSprite* pMask = CCSprite::create("mask_star.png");
	pMask->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));

	CCClippingNode* pClip = CCClippingNode::create();
	pClip->setStencil(pMask);
	pClip->setAlphaThreshold(0.0f);
	pClip->addChild(pSprite);

	this->addChild(pClip);
    return true;
}

