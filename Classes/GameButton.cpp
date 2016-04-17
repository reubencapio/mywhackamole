//whackyourpres
//modified from todd perkins tutorial
//reubencapio


#include "GameButton.h"
#include "Constants.h"
#include "Utils.h"
#include <android/log.h>
//#include <string>

using namespace cocos2d;

bool GameButton::initWithText(const char * text, bool isBig)
{
    if (!CCSprite::init()) {
        return false;
    }
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "before button_big or button_small");
    CCString* btnFrame = (isBig) ? CCString::create("button.png") : CCString::create("button.png");
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "after button_big or button_small");
    int fSize = 18 * Utils::getArtScaleFactor();
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "after getArtScaleFactor");
    this->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(btnFrame->getCString()));
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "before ttf");
    CCLabelTTF *label = CCLabelTTF::create(text, CCString::createWithFormat("%s.ttf",FONT_MAIN)->getCString(), fSize + isBig * fSize);
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "after ttf");
    label->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
    this->addChild(label,1);
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "before ttf 2");
    CCLabelTTF *labelShadow = CCLabelTTF::create(text, CCString::createWithFormat("%s.ttf",FONT_MAIN)->getCString(), fSize + isBig * fSize);
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "after ttf 2");
    labelShadow->setPosition(ccp(this->getContentSize().width/2 - (2 + isBig * 2),this->getContentSize().height/2));
    labelShadow->setColor(ccBLACK);
    labelShadow->setOpacity(150);
    this->addChild(labelShadow,0);
    
    this->setScale(Utils::getScale());
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "returned");
    return true;
}

GameButton* GameButton::buttonWithText(const char * text, bool isBig)
{
    GameButton *btn = new GameButton();
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "initWithText called");
    btn->initWithText(text, isBig);
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "autorelease called");
    btn->autorelease();
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "autorelease done");
    return btn;
}




