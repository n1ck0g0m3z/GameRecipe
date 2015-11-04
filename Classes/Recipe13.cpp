#include "Recipe13.h"
#include "menuScene.h"

USING_NS_CC;

CCScene* Recipe13::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Recipe13 *layer = Recipe13::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Recipe13::init()
{
      if ( !CCLayerGradient::initWithColor(ccc4(170,145,25,255),ccc4(17,220,160,255),ccp(0.0f,1.0f)))
    {
        return false;
    }

	m_points = 0;
	m_actionType = 1;

	this->setTouchMode(kCCTouchesOneByOne);

	this->setTouchEnabled(true);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    CCSprite *player = CCSprite::create("monkey01.png");
	player->setTag(1);
	player->setPosition(ccp(player->getContentSize().height*3/2, visibleSize.width/2));
	player->setOpacity(210);
	this->addChild(player);

	this->schedule(schedule_selector(Recipe13::gameLogic),3.0);
	this->scheduleUpdate();

	CCMenuItemImage* pCloseItem = CCMenuItemImage::create(
		"button_close.png",
		"button_close_pressed.png",
		this,
		menu_selector(Recipe13::menuCloseCallback));
		
	pCloseItem->setPosition(ccp(
		visibleSize.width - pCloseItem->getContentSize().width/2,
		pCloseItem->getContentSize().height/2));

	//CCMenu* pMenu = CCMenu::create(pCloseItem,NULL);

	//pMenu->setPosition(CCPointZero);

//	this->addChild(pMenu);

	CCSprite* item1 = CCSprite::create("button_close.png");
	CCSprite* item2 = CCSprite::create("button_close.png");

	item2->setColor(ccc3(102,102,255));

	CCMenuItemSprite* pCloseItem2 = 
		CCMenuItemSprite::create(item1,item2,this,
		menu_selector(Recipe13::menuCloseCallback));
	
	pCloseItem2->setPosition(ccp(
		visibleSize.width -pCloseItem->getContentSize().width*3/2,
		pCloseItem->getContentSize().height/2));

	CCMenu* pMenu2 = CCMenu::create(pCloseItem,pCloseItem2,NULL);
	pMenu2->setPosition(CCPointZero);
	this->addChild(pMenu2);

	CCMenuItemImage* menuItemOff = CCMenuItemImage::create(
		"button_check_off.png",
		"button_check_off_pressed.png",NULL);
	
	CCMenuItemImage* menuItemOn = CCMenuItemImage::create(
		"button_check_on.png",
		"button_check_on_pressed.png",NULL);


	CCMenuItemToggle* toggleItem =
		CCMenuItemToggle::createWithTarget(this,menu_selector(Recipe13::changeMode),menuItemOff,menuItemOn,NULL);

	toggleItem->setPosition(ccp(
		toggleItem->getContentSize().width/2,
		visibleSize.height - toggleItem->getContentSize().height/2));

	CCMenu* toggleMenu = CCMenu::create(toggleItem,NULL);

	toggleMenu->setPosition(0,0);
	toggleMenu->setTag(3);

	this->addChild(toggleMenu);

	CCLabelTTF *scoreLabel = CCLabelTTF::create("SCORE","aria",48);
	scoreLabel->setPosition(ccp(visibleSize.width/2,visibleSize.height - scoreLabel->getContentSize().height/2));
	scoreLabel->setTag(10);
	this->addChild(scoreLabel);

	CCLabelTTF* pointsLabel = CCLabelTTF::create("0","arial",48);
	pointsLabel->setPosition(ccp(scoreLabel->getPositionX() + scoreLabel->getContentSize().width,
							visibleSize.height - pointsLabel->getContentSize().height/2));
	pointsLabel->setTag(11);
	this->addChild(pointsLabel);
		return true;
}

void Recipe13::addFood()
{
	CCSize winsize = CCDirector::sharedDirector()->getWinSize();
	CCSprite* food = CCSprite::create("hamburger.png");
	int heigh = rand() % (int)winsize.height;
	food->setPosition(ccp(winsize.width + food->getContentSize().width/2,heigh));
	food->setTag(2);
	this->addChild(food);

	float duration=2.0f;

	CCMoveTo* actionMove = CCMoveTo::create(duration,ccp(food->getContentSize().width*3/2, food->getPositionY()));

	CCCallFuncN* actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(Recipe13::spriteMoveFinished));
	food->runAction(CCSequence::create(actionMove,actionMoveDone,NULL));


	CCActionInterval* action1;
	CCActionInterval* action2;

	ccBezierConfig beizer;
	beizer.controlPoint_1 = ccp(winsize.width, winsize.height);
	beizer.controlPoint_2 = ccp(winsize.width/2, -winsize.height);
	beizer.endPosition = ccp(0, winsize.height);

	switch (this->m_actionType)
	{
	case 1:
		action1 = CCScaleTo::create(duration,4.0f);
		food->runAction(action1);
		break;
	case 2:
		action1 = CCRotateBy::create(duration, 360);
		food->runAction(action1);
		action2 = CCRepeatForever::create(action1);
		break;
	case 3:
		action1 = CCScaleTo::create(duration,4.0f);
		action2 = CCRotateBy::create(duration, 360);
		food->runAction(action1);
		food->runAction(action2);
		break;
	case 4:
		action1 = CCRotateBy::create(0.5f, -360);
		action2 = CCRepeatForever::create(action1);
		food->runAction(action2);
		break;
	case 5:
		action1 = CCJumpBy::create(duration, ccp(0,0),100,5);
		food->runAction(action1);
		break;
	case 6:
		action1 = CCScaleTo::create(duration/2.0f ,4.0f);
		action2 = CCJumpBy::create(duration/2.0f,ccp(0,0),100,3);
		food->runAction(CCSequence::create(action1,action2,NULL));
		break;
	case 7:
		action1 = CCFadeIn::create(duration/2.0f);
		action2 = action1->reverse();
		
		food->runAction(CCSequence::create(action1,action2,NULL));
		break;
	case 8:
		food->stopAllActions();
		action1 = CCBezierBy::create(duration,beizer);
		food->runAction(CCSequence::create(action1,actionMoveDone,NULL));
		break;
	default:
		break;
	}
	this->m_actionType = (this->m_actionType + 1)%9;
}

void Recipe13::gameLogic(float a)
{
	this->addFood();
}

void Recipe13::spriteMoveFinished(CCNode* sender)
{
	CCSprite* sprite = (CCSprite*) sender;
	bool isClean = true;	
	this->removeChild(sprite,isClean);
}

bool Recipe13::ccTouchBegan(CCTouch* touche,CCEvent* event)
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


void Recipe13::update(float dt)
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

		if(playerRect.intersectsRect(foodRect) && player->isVisible())
		{
			this->removeChild(food,true);

			player->setTexture(CCTextureCache::sharedTextureCache()->addImage("monkey02.png"));
			this->scheduleOnce(schedule_selector(Recipe13::eat),0.1f);
		}
}

void Recipe13::eat(float delta)
{
	CCSprite* player = (CCSprite*) this->getChildByTag(1);
	player->setTexture(CCTextureCache::sharedTextureCache()->addImage("monkey01.png"));

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	this->m_points += player->getPositionX()/(winSize.width/4) + 1;

	CCLabelTTF* label = (CCLabelTTF*)this->getChildByTag(11);

	CCString* points = CCString::createWithFormat("%d", this->m_points);

	label->setString(points->getCString());
}

void Recipe13::menuCloseCallback(CCObject* pSender)
{
	//CCDirector::sharedDirector()->end();
	CCScene* nextScene = menuScene::scene();
	CCScene* pScene = CCTransitionFade::create(0.5f,nextScene);
	CCDirector::sharedDirector()->replaceScene(pScene);
}

void Recipe13::changeMode(CCObject* sender)
{
	int selectedIndex =
		dynamic_cast<CCMenuItemToggle*>(sender)->getSelectedIndex();

	CCSprite* player = (CCSprite*) this->getChildByTag(1);

	player->setVisible(selectedIndex == 0);
}