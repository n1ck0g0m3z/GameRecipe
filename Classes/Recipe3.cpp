#include "Recipe3.h"

USING_NS_CC;

CCScene* Recipe3::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Recipe3 *layer = Recipe3::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Recipe3::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite* player = CCSprite::create("monkey01.png");
	player->setPosition(ccp(player->getContentSize().width *3/2, visibleSize.height/2));
	this->addChild(player);
	player->setTag(1);

    return true;
}

