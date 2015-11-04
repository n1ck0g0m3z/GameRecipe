#include "Recipe39.h"

USING_NS_CC;

#define MOTION_STREAK_TAG 10

CCScene* Recipe39::scene()
{
    CCScene *scene = CCScene::create();
    Recipe39 *layer = Recipe39::create();
    scene->addChild(layer);
    return scene;
}

bool Recipe39::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
    
    pBrush = CCSprite::create("brush.png");
    pBrush->retain();
    
    return true;
}

bool Recipe39::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    points.clear();
    
    CCPoint location = pTouch->getLocation();
    points.push_back(location);
    prevLocation = location;
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    pTarget = CCRenderTexture::create(size.width, size.height, kCCTexture2DPixelFormat_RGBA8888);
    pTarget->retain();
    pTarget->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(pTarget);
    
    return true;
}

void Recipe39::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint start = pTouch->getLocation();
    CCPoint end   = pTouch->getPreviousLocation();
    
    pTarget->begin();
    float distance = ccpDistance(start, end);
    for (int i=0; i<distance; i++)
    {
        float diff_x = end.x - start.x;
        float diff_y = end.y - start.y;
        float delta = (float)i / distance;
        CCPoint point = ccp(start.x + (diff_x*delta), start.y + (diff_y*delta));
        pBrush->setPosition(point);
        pBrush->visit();
    }
    pTarget->end();
    
    float distance2 = ccpDistance(start, prevLocation);
    if (distance2 > 15.0f)
    {
        points.push_back(start);
        prevLocation = start;
    }
}

void Recipe39::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    if (points.size()>1)
    {
        CCRect rect = this->getTextureRect();
        
        CCImage* pImage = pTarget->newCCImage();
        CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->addUIImage(pImage, NULL);
        CC_SAFE_DELETE(pImage);
        
        CCSprite* pSprite = CCSprite::createWithTexture(pTexture, rect);
        pSprite->setPosition(ccp(rect.origin.x + rect.size.width/2,  size.height - (rect.origin.y + rect.size.height/2)));
        this->addChild(pSprite);
    }
    
    this->removeChild(pTarget, true);
    pTarget->release();
}

void Recipe39::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    this->removeChild(pTarget, true);
    pTarget->release();
}

CCRect Recipe39::getTextureRect()
{
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    float minX = size.width;
    float maxX = 0;
    float minY = size.height;
    float maxY = 0;
    
    for (int i=0; i<points.size()-1; i++)
    {
        minX = MIN(minX, points[i].x);
        minX = MIN(minX, points[i+1].x);
        
        maxX = MAX(maxX, points[i].x);
        maxX = MAX(maxX, points[i+1].x);
        
        minY = MIN(minY, points[i].y);
        minY = MIN(minY, points[i+1].y);
        
        maxY = MAX(maxY, points[i].y);
        maxY = MAX(maxY, points[i+1].y);
    }
    
    float margin = pBrush->getContentSize().width * pBrush->getScale() / 2.0f;
    float width  = maxX - minX + margin * 2;
    float height = maxY - minY + margin * 2;
    
    float x = minX - margin;
    float y = size.height - maxY - margin;
    
    // ‰æ–ÊŠO‚Éo‚È‚¢‚æ‚¤‚É•â³
    x = MAX(0.0f, x);
    y = MAX(0.0f, y);
    if (minX + width > size.width)
    {
        width = size.width - x;
    }
    if (minY + height > size.height)
    {
        height = size.height - y;
    }
    
    return CCRectMake(x, y, width, height);
}


/*
bool Recipe39::ccTouchBegan(CCTouch *pTouch, CCEvent* pEvent){
	this->removeChildByTag(MOTION_STREAK_TAG ,true);
	CCPoint point = this->convertTouchToNodeSpace(pTouch);
	CCMotionStreak* streak = CCMotionStreak::create(0.5f, 1, 10, ccc3(255,255,0), "line.png");

	this->addChild(streak,5,MOTION_STREAK_TAG);

	return true;
}

void Recipe39::ccTouchMoved(CCTouch *pTouch,CCEvent *pEvent){
	CCPoint point = this->convertTouchToNodeSpace(pTouch);
    CCMotionStreak* pStreak = (CCMotionStreak*)this->getChildByTag(MOTION_STREAK_TAG);
    pStreak->setPosition(point);
}*/
