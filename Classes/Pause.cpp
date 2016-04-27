//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include <iostream>
#include "Pause.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"
#include <android/log.h>

using namespace cocos2d;

bool Pause::init()
{
    __android_log_write(ANDROID_LOG_INFO, "Pause", "init");
    if (!CCLayer::init()) {
        return false;
    }   

    pauseButton = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("pause_button.png"), NULL,this,menu_selector(Pause::pause));
    CCMenu *menu = CCMenu::create(pauseButton,NULL);
    menu->setPosition(ccp(Utils::s().width - pauseButton->getContentSize().width/2,pauseButton->getContentSize().height/2));
    this->addChild(menu,1);

    popup = Popup::popupWithTitle("-PAUSED-");
    popup->addButtonWithText("RESUME", this, menu_selector(Pause::resume));
    popup->addButtonWithText("MAIN", this, menu_selector(Pause::mainMenu));
    this->addChild(popup,1);

    return true;
}

void Pause::pause()
{
    __android_log_write(ANDROID_LOG_INFO, "Pause", "pause");
	this->togglePause(true);
}

void Pause::resume()
{
    __android_log_write(ANDROID_LOG_INFO, "Pause", "resume");
	this->togglePause(false);
}

void Pause::mainMenu()
{
    __android_log_write(ANDROID_LOG_INFO, "Pause", "mainMenu");
	MainMenu::mainMenu();
}

void Pause::togglePause(bool paused)
{
    __android_log_write(ANDROID_LOG_INFO, "Pause", "togglePause");
	popup->show(paused);
	Utils::gameLayer()->setTouchEnabled(!paused);
	pauseButton->setVisible(!paused);
}




