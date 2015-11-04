#include "Recipe7.h"

USING_NS_CC;

CCScene* Recipe7::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Recipe7 *layer = Recipe7::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Recipe7::init()
{
	if(!CCLayerGradient::initWithColor(ccc4(70,145,15,225),ccc4(170,220,120,255),ccp(0.0f,1.0f)))//thsi is the background
    {
        return false;
    }

	//this->setTouchMode(kCCTouchesAllAtOnce);
	this->setTouchMode(kCCTouchesOneByOne);
	
	this->setTouchEnabled(true);

    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite* player = CCSprite::create("monkey01.png");
	player->setTag(1);
	player->setPosition(ccp(player->getContentSize().height*3/2, visibleSize.width/2));
	player->setOpacity(210);
	this->addChild(player);

	this->schedule(schedule_selector(Recipe7::gameLogic),3.0);
    
    return true;
}

void Recipe7::addFood()
{
	CCSize winsize = CCDirector::sharedDirector()->getWinSize();
	CCSprite* food = CCSprite::create("hamburger.png");
	int heigh = rand() % (int)winsize.height;
	food->setPosition(ccp(winsize.width + food->getContentSize().width/2,heigh));
	food->setTag(2);
	this->addChild(food);

	float duration=2.0f;

	CCMoveTo* actionMove = CCMoveTo::create(duration,ccp(food->getContentSize().width/2, food->getPositionY()));

	CCCallFuncN* actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(Recipe7::spriteMoveFinished));
	food->runAction(CCSequence::create(actionMove,actionMoveDone,NULL));
}

void Recipe7::gameLogic(float a)
{
	this->addFood();
}

void Recipe7::spriteMoveFinished(CCNode* sender)
{
	CCSprite* sprite = (CCSprite*) sender;
	bool isClean = true;
	this->removeChild(sprite,isClean);
}

bool Recipe7::ccTouchBegan(CCTouch* touche,CCEvent* event)
{
	//CCTouch* touch = (CCTouch*) touches;
	CCPoint location =touche->getLocation();
	//location =CCDirector::sharedDirector()->convertToGL(location);

	CCSprite *player =(CCSprite*) this->getChildByTag(1);

	CCSize winsize = CCDirector::sharedDirector()->getVisibleSize();//difference with the book

	float lenght = sqrtf(powf(location.x - player->getPositionX(),2.0f)+powf(location.y -player->getPositionY(),2.0f));
	float duration = lenght / winsize.width * 1.5f;
	CCMoveTo * actionMove = CCMoveTo :: create(duration, location);
	player->runAction(actionMove);
	return true;
}

void Recipe7::ccTouchMoved(CCTouch* touches,CCEvent* event){}

void Recipe7::ccTouchEnded(CCTouch* touches,CCEvent* event){}