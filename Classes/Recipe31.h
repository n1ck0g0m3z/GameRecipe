#ifndef __RECIPE31_SCENE_H__
#define __RECIPE31_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Recipe31 : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();

	void setControlSwitch();
	void switchCallBack(CCObject* pSender, CCControlEvent controlEvent);
	void setControlSlider();
    void sliderCallBack(CCObject* pSender, CCControlEvent controlEvent);
	void setControlStepper();
    void stepperCallBack(CCObject* pSender, CCControlEvent controlEvent);
	void setControlColor();
    void colorCallBack(CCObject* pSender, CCControlEvent controlEvent);
	void setControlPotentiometer();
    void potentiometerCallBack(CCObject* pSender, CCControlEvent controlEvent);

    CREATE_FUNC(Recipe31);
};

#endif 
