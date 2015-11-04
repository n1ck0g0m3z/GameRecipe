#include "Recipe9.h"

USING_NS_CC;

CCScene* Recipe9::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Recipe9 *layer = Recipe9::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Recipe9::init()
{
    if(!CCLayerGradient::initWithColor(ccc4(70,145,15,225),ccc4(170,220,120,255),ccp(0.0f,1.0f)))
    {
        return false;
    }


	this->setTouchMode(kCCTouchesOneByOne);

	this->setTouchEnabled(true);

    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite* player = CCSprite::create("monkey01.png");
	player->setTag(1);
	player->setPosition(ccp(player->getContentSize().height*3/2, visibleSize.width/2));
	player->setOpacity(210);
	this->addChild(player);

	this->schedule(schedule_selector(Recipe9::gameLogic),3.0);
	this->scheduleUpdate();

    return true;
}

void Recipe9::addFood()
{
	CCSize winsize = CCDirector::sharedDirector()->getWinSize();
	CCSprite* food = CCSprite::create("hamburger.png");
	int heigh = rand() % (int)winsize.height;
	food->setPosition(ccp(winsize.width + food->getContentSize().width/2,heigh));
	food->setTag(2);
	this->addChild(food);

	float duration=2.0f;

	CCMoveTo* actionMove = CCMoveTo::create(duration,ccp(food->getContentSize().width/2, food->getPositionY()));

	CCCallFuncN* actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(Recipe9::spriteMoveFinished));
	food->runAction(CCSequence::create(actionMove,actionMoveDone,NULL));
}

void Recipe9::gameLogic(float a)
{
	this->addFood();
}

void Recipe9::spriteMoveFinished(CCNode* sender)
{
	CCSprite* sprite = (CCSprite*) sender;
	bool isClean = true;	
	this->removeChild(sprite,isClean);
}

bool Recipe9::ccTouchBegan(CCTouch* touche,CCEvent* event)
{
	CCPoint location = touche->getLocation();

	CCSprite* player = (CCSprite*) this->getChildByTag(1);

	CCSize winsize =CCDirector::sharedDirector()->getVisibleSize();

	float lenght = sqrt(powf(location.x - player->getPositionX(),2.0f)+powf(location.y - player->getPositionY(),2.0f));
	float duration = lenght /winsize.width * 1.5f;
	CCMoveTo* actionMove = CCMoveTo::create(duration,location);
	player->runAction(actionMove);
	return true;
}

void Recipe9::ccTouchMoved(CCTouch* touches,CCEvent* event){}

void Recipe9::ccTouchEnded(CCTouch* touches,CCEvent* event){}

void Recipe9::update(float dt)
{
	CCSprite* player = (CCSprite*) this->getChildByTag(1);

	CCRect playerRect = CCRectMake(
		player->getPosition().x - (player->getContentSize().width/4),
		player->getPosition().y - (player->getContentSize().height/4),
		player->getContentSize().width/2,
		player->getContentSize().height/2);
	
	CCSprite *food = (CCSprite*)this->getChildByTag(2);
	if(food==NULL)return;

	CCRect foodRect = CCRectMake(
		food->getPosition().x - (food->getContentSize().width/2),
		food->getPosition().y - (food->getContentSize().height/2),
		food->getContentSize().width/2,
		food->getContentSize().height/2);

		if(playerRect.intersectsRect(foodRect))
		{
			this->removeChild(food,true);

			player->setTexture(CCTextureCache::sharedTextureCache()->addImage("monkey02.png"));
			this->scheduleOnce(schedule_selector(Recipe9::eat),0.1f);
		}
}

void Recipe9::eat(float delta)
{
	CCSprite* player = (CCSprite*) this->getChildByTag(1);
	player->setTexture(CCTextureCache::sharedTextureCache()->addImage("monkey01.png"));
}