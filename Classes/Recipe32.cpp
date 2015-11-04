#include "Recipe32.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

CCScene* Recipe32::scene()
{
    CCScene *scene = CCScene::create();
    
    Recipe32 *layer = Recipe32::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool Recipe32::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCSize editBoxSize = CCSizeMake(200,50);

	CCEditBox *pEditBox = CCEditBox::create(editBoxSize,CCScale9Sprite::create("sprite9.png"));
	pEditBox->setPosition(ccp(size.width/2,size.height/2));

	pEditBox->setFontColor(ccBLUE);

	pEditBox->setPlaceHolder("name");

	pEditBox->setMaxLength(8);

	pEditBox->setReturnType(kKeyboardReturnTypeDone);
	pEditBox->setDelegate(this);

	this->addChild(pEditBox);
    return true;
}

void Recipe32::editBoxEditingDidBegin(CCEditBox* editBox){
	CCLOG("did begin");
}
void Recipe32::editBoxEditingDidEnd(CCEditBox* editBox){
	CCLOG("did end : %s", editBox->getText());
}
void Recipe32::editBoxTextChanged(CCEditBox *editBox, const std::string& text){
	CCLOG("change %s", text.c_str());
}
void Recipe32::editBoxReturn(CCEditBox* editBox){
	CCLOG("return");
}