#include "Recipe31.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

CCScene* Recipe31::scene()
{
    CCScene *scene = CCScene::create();
    
    Recipe31 *layer = Recipe31::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool Recipe31::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	CCSprite* maskSprite = CCSprite::create("switch-mask.png");

	CCSprite* onSprite = CCSprite::create("switch-on.png");

	CCSprite* offSprite = CCSprite::create("switch-off.png");

	CCSprite* thumbSprite = CCSprite::create("switch-thumb.png");

	CCLabelTTF* onLabel = CCLabelTTF::create("On","Arial-BoldMT",16);

	CCLabelTTF* offLabel = CCLabelTTF::create("Off","Arial-BoldMT",16);

	CCControlSwitch* pSwitch = CCControlSwitch::create(maskSprite, onSprite ,offSprite ,thumbSprite ,onLabel ,offLabel);

	pSwitch->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(pSwitch);

	//pSwitch->addTargetWithActionForControlEvents(this,cccontrol_selector(Recipe31::switchCallBack),CCControlEventValueChanged);

	CCControlSlider* pSlider = CCControlSlider::create(
		"sliderTrack.png","sliderProgress.png","sliderThumb.png");
	pSlider->setMinimumValue(0.0f);
	pSlider->setMaximumValue(100.0f);
	pSlider->setValue(50.0f);
	pSlider->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(pSlider);

	//pSlider->addTargetWithActionForControlEvents(this,cccontrol_selector(Recipe31::sliderCallBack),CCControlEventValueChanged);

	CCSprite* minusSprite = CCSprite::create("stepper-minus.png");

	CCSprite* plusSprite = CCSprite::create("stepper-plus.png");
	CCControlStepper* pStepper = CCControlStepper::create(minusSprite,plusSprite);

	pStepper->setMinimumValue(0.0f);
	pStepper->setMaximumValue(10.0f);
	pStepper->setValue(5.0f);
	pStepper->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(pStepper);

	//pStepper->addTargetWithActionForControlEvents(this,cccontrol_selector(Recipe31::stepperCallBack),CCControlEventValueChanged);

	CCControlPotentiometer* pMeter = CCControlPotentiometer::create(
		"potentiometerTrack.png","potentiometerProgress.png","potentiometerButton.png");
	pMeter->setPosition(ccp(size.width*1/4,size.height*1/3));
	this->addChild(pMeter);
	//pMeter->addTargetWithActionForControlEvents(this,cccontrol_selector(Recipe31::potentiometerCallBack),CCControlEventValueChanged);
    
    return true;
}

