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
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "initWithText");
    CCString* btnFrame = (isBig) ? CCString::create("button.png") : CCString::create("button.png");
    if(text == "Post SCORE in Facebook"){
    	btnFrame = CCString::create("blue_button.png");
    }
    int fSize = 18 * Utils::getArtScaleFactor();
    this->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(btnFrame->getCString()));
    CCLabelTTF *label = CCLabelTTF::create(text, CCString::createWithFormat("%s.ttf",FONT_MAIN)->getCString(), fSize + isBig * fSize);
    label->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
    this->addChild(label,1);
    CCLabelTTF *labelShadow = CCLabelTTF::create(text, CCString::createWithFormat("%s.ttf",FONT_MAIN)->getCString(), fSize + isBig * fSize);
    labelShadow->setPosition(ccp(this->getContentSize().width/2 - (2 + isBig * 2),this->getContentSize().height/2));
    labelShadow->setColor(ccBLACK);
    labelShadow->setOpacity(150);
    this->addChild(labelShadow,0);
    this->setScale(Utils::getScale());
    return true;
}

GameButton* GameButton::buttonWithText(const char * text, bool isBig)
{
    __android_log_write(ANDROID_LOG_INFO, "GameButton", "buttonWithText");
    GameButton *btn = new GameButton();
    btn->initWithText(text, isBig);
    btn->autorelease();
    return btn;
}




