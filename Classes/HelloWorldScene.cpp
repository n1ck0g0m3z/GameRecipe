#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    // ƒ{ƒ^ƒ“‰æ‘œ•\Ž¦
	CCLabelTTF* label = CCLabelTTF::create("BUtton", "Ariel", 30);
	CCSprite* btn1 = CCSprite::create("button.png");
	CCSprite* btn2 = CCSprite::create("button.png");
	btn2->setColor(ccc3(102,102,102));
	CCMenuItemSprite* msp = CCMenuItemSprite::create(btn1, btn2, this,
		menu_selector(HelloWorld::btnCallback));
	CCMenu* menu = CCMenu::create(msp, NULL);
	this->addChild(menu);
    
    return true;
}

void HelloWorld::btnCallback(CCObject* pSender)
{
    
}
