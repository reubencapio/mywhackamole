//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include <iostream>
#include "Popup.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include <android/log.h>

using namespace cocos2d;
using namespace CocosDenshion;

bool Popup::initWithTitle(const char *title)
{
    if (!CCSprite::init()) {
        return false;
    }   
    __android_log_write(ANDROID_LOG_INFO, "Popup", "initWithTitle");
    CCSprite *m = CCSprite::createWithSpriteFrameName("menu.png");
    m->setPosition(ccp(Utils::s().width/2,Utils::s().height/2));
    m->setScale(2);
    this->addChild(m,1);
    __android_log_write(ANDROID_LOG_INFO, "Popup", "before getArtScaleFactor");
    CCLabelTTF *titleLabel = CCLabelTTF::create(title, CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    __android_log_write(ANDROID_LOG_INFO, "Popup", "after getArtScaleFactor");
    titleLabel->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (m->getContentSize().height/2 * m->getScale()) - titleLabel->getContentSize().height * 2));
    this->addChild(titleLabel,1);
    this->setVisible(false);
    return true;
}


Popup* Popup::popupWithTitle(const char *title)
{
    __android_log_write(ANDROID_LOG_INFO, "Popup", "popupWithTitle");
    Popup *pop = new Popup();
    pop->initWithTitle(title);
    pop->autorelease();
    return pop;
}

void Popup::show(bool shouldShow)
{
    __android_log_write(ANDROID_LOG_INFO, "Popup", "show");
    Game *g = Utils::gameLayer();
    if (shouldShow) {
        g->pauseSchedulerAndActions();
    }
    else {
        g->resumeSchedulerAndActions();
    }
    
    for (int i = 0; i < g->getChildrenCount(); i++) {
        CCNode *n = (CCNode *)g->getChildren()->objectAtIndex(i);
        if (shouldShow) {
            n->pauseSchedulerAndActions();
        }
        else {
            n->resumeSchedulerAndActions();
        }
    }
    
    this->setVisible(shouldShow);
    if(shouldShow)
    {
    		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    }
    else
    {
        	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }

}

void Popup::addButtonWithText(const char* text, CCObject*target, SEL_MenuHandler selector)
{
    __android_log_write(ANDROID_LOG_INFO, "Popup", "addButtonWithText");
    CCMenuItemSprite *btn = CCMenuItemSprite::create(GameButton::buttonWithText(text, false), NULL, target, selector);
    if (menu == NULL) {
        menu = CCMenu::create(btn,NULL);
        this->addChild(menu,1);
    }
    else {
        menu->addChild(btn, 1);
    }

    menu->alignItemsVerticallyWithPadding(btn->getContentSize().height/5);
}




