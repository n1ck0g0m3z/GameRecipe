#ifndef __RECIPE32_SCENE_H__
#define __RECIPE32_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe32 : public cocos2d::CCLayer, public CCEditBoxDelegate
{
private:
	void editBoxEditingDidBegin(CCEditBox* editBox);
	void editBoxEditingDidEnd(CCEditBox* editBox);
	void editBoxTextChanged(CCEditBox *editBox, const std::string& text);
	void editBoxReturn(CCEditBox* editBox);

public:
    virtual bool init();  

    static cocos2d::CCScene* scene();

    CREATE_FUNC(Recipe32);
};

#endif 