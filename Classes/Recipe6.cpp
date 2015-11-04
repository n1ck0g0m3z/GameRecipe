#include "Recipe6.h"

USING_NS_CC;

CCScene* Recipe6::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Recipe6 *layer = Recipe6::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Recipe6::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite* player = CCSprite::create("monkey01.png");
	player->setTag(1);
	player->setOpacity(210);
	player->setPosition(ccp(player->getContentSize().width*3/2,visibleSize.height/2));
	this->addChild(player);

	this->schedule(schedule_selector(Recipe6::gameLogic),3.0);

	if(!CCLayerGradient::initWithColor(ccc4(20,70,5,225),ccc4(170,220,120,255),ccp(-1.0f,-1.0f)))
	{
		return false;	
	}
    
      return true;
}

	void Recipe6::addFood()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *food = CCSprite::create("hamburger.png");
	int height = rand() % (int)winSize.height;
	food->setPosition(ccp( food->getContentSize().width/2,height));
	food->setTag(2);
	this->addChild(food);

	float duration = 2.0f;

	CCMoveTo* actionMove = CCMoveTo::create(duration, ccp(food->getContentSize().width/2, food->getPositionY()));


	CCCallFuncN* actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(Recipe6::spriteMoveFinished));
	food->runAction(CCSequence::create(actionMove, actionMoveDone,NULL));
}

void Recipe6::gameLogic(float a)
{
	this->addFood();
}

void Recipe6::spriteMoveFinished(CCNode* sender)
{
	CCSprite* sprite = (CCSprite *)sender;
	bool isCleanUp = true;
	this->removeChild(sprite, isCleanUp);
}