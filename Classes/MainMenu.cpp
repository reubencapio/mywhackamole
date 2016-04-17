//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include "GameButton.h"
#include "Game.h"
#include "Utils.h"
#include "Constants.h"
#include <android/log.h>

using namespace cocos2d;
using namespace CocosDenshion;

//USING_NS_CC;

CCScene* MainMenu::scene()
{
    CCScene *sc = CCScene::create();
    MainMenu *m = MainMenu::create();
    sc->addChild(m, 0);
    return sc;
}

bool MainMenu::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
    
    s = CCDirector::sharedDirector()->getWinSize();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "before moles_bg.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("moles_bg.mp3");
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "after moles_bg.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect(SOUND_SPLAT);
	SimpleAudioEngine::sharedEngine()->preloadEffect("moles_miss.wav");
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "before moles-hd.plist");
    CCString* file = (Utils::getArtScaleFactor() > 1) ? CCString::create("binay.plist") : CCString::create("binay.plist");
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "after moles-hd.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(file->getCString());
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "before title-hd.png");
    file = (Utils::getArtScaleFactor() > 1) ? CCString::create("title-hd.png") : CCString::create("title.png");
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "after title-hd.png");
    CCSprite *bg = CCSprite::create(file->getCString());
    bg->setPosition(ccp(s.width/2,s.height/2));
    Utils::scaleSprite(bg);
    this->addChild(bg,-1);

    CCMenuItemSprite *playButton = CCMenuItemSprite::create(GameButton::buttonWithText("PLAY!", true), NULL, this, menu_selector(MainMenu::playGame));
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "CCMenuItemSprite::create done");
    CCMenu *menu = CCMenu::create(playButton,NULL);
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "CCMenuItemSprite::create(playButton,NULL) done");
    menu->setPosition(ccp(s.width/2,s.height/2 - s.height/3.5f));
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "setPosition done");
    this->addChild(menu,2);
    __android_log_write(ANDROID_LOG_INFO, "MainMenu", "CCMenuItemSprite::addChild done");
	return true;
}

void MainMenu::playGame()
{
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void MainMenu::mainMenu()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}
