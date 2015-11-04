#include "Recipe28.h"
#define FLIP_DURATION 1.0f
#define CARD_FACE_TAG 1
#define CARD_BACK_TAG 2

USING_NS_CC;

CCScene* Recipe28::scene()
{
    CCScene *scene = CCScene::create();
    
    Recipe28 *layer = Recipe28::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool Recipe28::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCSprite *card = CCSprite::create("card.png");
	card->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(card,CARD_FACE_TAG,CARD_FACE_TAG);
	card->setVisible(false);

	CCSprite *card2 = CCSprite::create("card_face.png");
	card2->setPosition(card->getPosition());
	this->addChild(card2,CARD_BACK_TAG,CARD_BACK_TAG);
	
	CCOrbitCamera* turn = CCOrbitCamera::create(FLIP_DURATION / 2.0f, 1 ,0 , 0.0f, 90.0f, 0, 0);
	CCHide *hide = CCHide::create();
	CCCallFunc *func = CCCallFunc::create(this, callfunc_selector(Recipe28::flipCard));
	card2->runAction(CCSequence::create(turn, hide, func, NULL));
    
    return true;
}

void Recipe28::flipCard(){
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCShow* show =CCShow::create();

	CCSprite *card = CCSprite::create("card.png");
	card->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(card,CARD_FACE_TAG,CARD_FACE_TAG);
	card->setVisible(false);

	CCSprite *card2 = CCSprite::create("card_face.png");
	card2->setPosition(card->getPosition());
	this->addChild(card2,CARD_BACK_TAG,CARD_BACK_TAG);
	
	CCOrbitCamera* turn = CCOrbitCamera::create(FLIP_DURATION / 2.0f, 1 ,0 , 0.0f, 90.0f, 0, 0);
	CCOrbitCamera* turn2 = CCOrbitCamera::create(FLIP_DURATION / 2.0f, 1 ,0 , 270.0f, 90.0f, 0, 0);
	CCHide *hide = CCHide::create();
	CCCallFunc *func = CCCallFunc::create(this, callfunc_selector(Recipe28::flipCard2));
	card2->runAction(CCSequence::create(show,turn,turn2, hide, func, NULL));
}

void Recipe28::flipCard2(){
	CCSprite* card = (CCSprite*)this->getChildByTag(CARD_FACE_TAG);
	CCShow *show = CCShow::create();
	CCOrbitCamera* turn = CCOrbitCamera::create(FLIP_DURATION/2.0f,1,0,270.0f,90.0f,0,0);
	card->runAction(CCSequence::create(show,turn,NULL));
}