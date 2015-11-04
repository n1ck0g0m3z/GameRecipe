#include "menuScene.h"
#include <string>
#include "Recipe3.h"
#include "Recipe4.h"
#include "Recipe5.h"
#include "Recipe6.h"
#include "Recipe7.h"
#include "Recipe8.h"
#include "Recipe9.h"
#include "Recipe10.h"
#include "Recipe11.h"
#include "Recipe12.h"
#include "Recipe13.h"
#include "Recipe14.h"
#include "Recipe15.h"
#include "Recipe16.h"
#include "Recipe17.h"
#include "Recipe26.h"
#include "Recipe28.h"
#include "Recipe30.h"
#include "Recipe31.h"
#include "Recipe32.h"
#include "Recipe34.h"
#include "Recipe39.h"

using namespace std;

USING_NS_CC;

CCScene* menuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    menuScene *layer = menuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool menuScene::init()
{
		const char *a[] = {"Recipe 3","Recipe 4","Recipe 5","Recipe 6","Recipe 7",
						"Recipe 8","Recipe 9","Recipe 10","Recipe 11","Recipe 12",
						"Recipe 13","Recipe 14","Recipe 15","Recipe 16","Recipe 17",
						"Recipe 26","Recipe 28","Recipe 30","Recipe 31","Recipe 32","Recipe 34",
						"Recipe 39",};
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();


	for(int i = 0 ; i<22 ;i++){

		CCScale9Sprite* sprite = CCScale9Sprite::create("button1.png");
		CCLabelTTF* label = CCLabelTTF::create(a[i], "Ariel", 30);
		CCControlButton* btn = CCControlButton::create(label, sprite);
		btn->setPreferredSize(CCSizeMake(200, 40));
		btn->setPosition(ccp(visibleSize.width / 2-200+(i / 11)*400, visibleSize.height / 2 + 250 - (i % 11) * 50));
		btn->addTargetWithActionForControlEvents(this, cccontrol_selector(menuScene::btnPushCallback), CCControlEventTouchUpInside);
		btn->setTag(i+10);

		this->addChild(btn);
	}

    return true;
}

void menuScene::btnPushCallback(CCObject* pSender, CCControlEvent controlEvent)
{
	CCScene* nextScene = nullptr;

	CCControlButton* btn = (CCControlButton*)pSender;

	int tag = btn->getTag();

	switch (tag){
		case 10:
			nextScene = Recipe3::scene();
			break;
		case 11:
			nextScene = Recipe4::scene();
			break;
		case 12:
			nextScene = Recipe5::scene();
			break;
		case 13:
			nextScene = Recipe6::scene();
			break;
		case 14:
			nextScene = Recipe7::scene();
			break;
		case 15:
			nextScene = Recipe8::scene();
			break;
		case 16:
			nextScene = Recipe9::scene();
			break;
		case 17:
			nextScene = Recipe10::scene();
			break;
		case 18:
			nextScene = Recipe11::scene();
			break;
		case 19:
			nextScene = Recipe12::scene();
			break;
		case 20:
			nextScene = Recipe13::scene();
			break;
		case 21:
			nextScene = Recipe14::scene();
			break;
		case 22 :
			nextScene = Recipe15::scene();
			break;
		case 23 :
			nextScene = Recipe16::scene();
			break;
		case 24 :
			nextScene = Recipe17::scene();
			break;
		case 25 :
			nextScene = Recipe26::scene();
			break;
		case 26 :
			nextScene = Recipe28::scene();
			break;
		case 27 :
			nextScene = Recipe30::scene();
			break;
		case 28 :
			nextScene = Recipe31::scene();
			break;
		case 29 :
			nextScene =	Recipe32::scene();
			break;
		case 30 :
			nextScene =	Recipe34::scene();
			break;
		case 31 :
			nextScene =	Recipe39::scene();
			break;
		default:
		break;
	}

	CCScene* pScene = CCTransitionFade::create(2.7f, nextScene);
	CCDirector::sharedDirector()->replaceScene(pScene);
	
	CCScale9Sprite* sprite = CCScale9Sprite::create("HelloWorld.png");
	this->addChild(sprite);
	sprite->setPosition(960/2,640/2);
	
}
