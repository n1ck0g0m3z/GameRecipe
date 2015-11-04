f#include "Recipe4.h"

USING_NS_CC;

CCScene* Recipe4::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Recipe4 *layer = Recipe4::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Recipe4::init()
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

	this->schedule(schedule_selector(Recipe4::gameLogic),3.0);
    
    return true;
}

	void Recipe4::addFood()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *food = CCSprite::create("hamburger.png");
	int height = rand() % (int)winSize.height;
	food->setPosition(ccp(winSize.width + food->getContentSize().width/2,height));
	food->setTag(2);
	this->addChild(food);

	float duration = 2.0f;

	CCMoveTo* actionMove = CCMoveTo::create(duration, ccp(food->getContentSize().width*3/2, food->getPositionY()));

	food->runAction(actionMove);
}

void Recipe4::gameLogic(float a)
{
	this->addFood();
}