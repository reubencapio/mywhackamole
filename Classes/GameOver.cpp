//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include <iostream>
#include "GameOver.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"
#include "JniURL.h"
#include <android/log.h>

using namespace cocos2d;

bool GameOver::init()
{
	__android_log_write(ANDROID_LOG_INFO, "GameOver", "init");
    if (!CCLayer::init()) {
        return false;
    }


    popup = Popup::popupWithTitle("-GAME OVER-");
    popup->addButtonWithText("REPLAY", this, menu_selector(GameOver::replay));
    popup->addButtonWithText("MAIN", this, menu_selector(GameOver::mainMenu));
    popup->addButtonWithText("Post SCORE in Facebook", this, menu_selector(GameOver::postInFacebook));
    this->addChild(popup,1);
    
    return true;
}

void GameOver::postInFacebook()
{
	openURLJNI("https://www.facebook.com/");
}

void GameOver::gameover()
{
	__android_log_write(ANDROID_LOG_INFO, "GameOver", "gameover");
	popup->show(true);
}

void GameOver::replay()
{
	__android_log_write(ANDROID_LOG_INFO, "GameOver", "replay");
	CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void GameOver::mainMenu()
{
	__android_log_write(ANDROID_LOG_INFO, "GameOver", "mainMenu");
	MainMenu::mainMenu();
}




