#include "Recipe5.h"

USING_NS_CC;

CCScene* Recipe5::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Recipe5 *layer = Recipe5::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


bool Recipe5::init()
{

    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	
	CCSprite* player = CCSprite::create("monkey01.png");
	player->setOpacity(210);
	player->setPosition(ccp(player->getContentSize().width *3/2, visibleSize.height/2));
	this->addChild(player);
	player->setTag(1);

	this->schedule(schedule_selector(Recipe5::gameLogic),3.0);
    
    return true;
}

	void Recipe5::addFood()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *food = CCSprite::create("hamburger.png");
	int height = rand() % (int)winSize.height;
	food->setPosition(ccp(winSize.width + food->getContentSize().width/2,height));
	food->setTag(2);
	this->addChild(food);

	float duration = 2.0f;

	CCMoveTo* actionMove = CCMoveTo::create(duration, ccp(food->getContentSize().width/2, food->getPositionY()));


	CCCallFuncN* actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(Recipe5::spriteMoveFinished));
	food->runAction(CCSequence::create(actionMove, actionMoveDone,NULL));
}

void Recipe5::gameLogic(float a)
{
	this->addFood();
}

void Recipe5::spriteMoveFinished(CCNode* sender)
{
	CCSprite* sprite = (CCSprite *)sender;
	bool isCleanUp = true;
	this->removeChild(sprite, isCleanUp);
}