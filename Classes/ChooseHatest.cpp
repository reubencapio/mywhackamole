/*
//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include "ChooseHatest.h"
#include "SimpleAudioEngine.h"
#include "GameButton.h"
#include "Game.h"
#include "Utils.h"
#include "Constants.h"
#include "MessageJni.h"
#include <android/log.h>
#include "ChooseHatest.h"

//#include "/jni/helloworld/main.cpp"

using namespace cocos2d;
using namespace CocosDenshion;

//USING_NS_CC;

CCScene* ChooseHatest::scene()
{
	__android_log_write(ANDROID_LOG_INFO, "ChooseHatest", "scene");
    CCScene *sc = CCScene::create();
    ChooseHatest *m = ChooseHatest::create();
    sc->addChild(m, 0);
    return sc;
}

bool ChooseHatest::init()
{
	__android_log_write(ANDROID_LOG_INFO, "ChooseHatest", "init");
	if ( !CCLayer::init() )
	{
		return false;
	}

    CCString* file = (Utils::getArtScaleFactor() > 1) ? CCString::create("binay.plist") : CCString::create("binay.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(file->getCString());
    file = (Utils::getArtScaleFactor() > 1) ? CCString::create("title-hd.png") : CCString::create("title.png");

    s = CCDirector::sharedDirector()->getWinSize();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	//other choice would have hd plist(not implemented, too lazy)
    file = (Utils::getArtScaleFactor() > 1) ? CCString::create("title-hd.png") : CCString::create("title.png");
    CCSprite *bg = CCSprite::create(file->getCString());
    bg->setPosition(ccp(s.width/2,s.height/2));
    Utils::scaleSprite(bg);
    this->addChild(bg,-1);

    CCMenuItemSprite *miriamButton = CCMenuItemSprite::create(GameButton::buttonWithText("MIRIAM!",false), NULL, this, menu_selector(ChooseHatest::miriam));
    CCMenu *miriammenu = CCMenu::create(miriamButton,NULL);
    miriammenu->setPosition(ccp(s.width/5,s.height/2 - s.height/4.0f));
    this->addChild(miriammenu,2);

    CCMenuItemSprite *poeButton = CCMenuItemSprite::create(GameButton::buttonWithText("POE!",false), NULL, this, menu_selector(ChooseHatest::poe));
    CCMenu *poemenu = CCMenu::create(poeButton,NULL);
    poemenu->setPosition(ccp(s.width/5,s.height/2 - s.height/4.0f));
    this->addChild(poemenu,2);

    CCMenuItemSprite *duterteButton = CCMenuItemSprite::create(GameButton::buttonWithText("DUTERTE!",false), NULL, this, menu_selector(ChooseHatest::duterte));
    CCMenu *dutertemenu = CCMenu::create(duterteButton,NULL);
    dutertemenu->setPosition(ccp(s.width/3,s.height/2 - s.height/4.0f));
    this->addChild(dutertemenu,2);

    CCMenuItemSprite *binayButton = CCMenuItemSprite::create(GameButton::buttonWithText("BINAY!",false), NULL, this, menu_selector(ChooseHatest::binay));
    CCMenu *binaymenu = CCMenu::create(binayButton,NULL);
    binaymenu->setPosition(ccp(s.width/2,s.height/2 - s.height/4.0f));
    this->addChild(binaymenu,2);

    CCMenuItemSprite *roxasButton = CCMenuItemSprite::create(GameButton::buttonWithText("ROXAS!",false), NULL, this, menu_selector(ChooseHatest::roxas));
    CCMenu *roxasmenu = CCMenu::create(roxasButton,NULL);
    roxasmenu->setPosition(ccp(s.width/1,s.height/2 - s.height/4.0f));
    this->addChild(roxasmenu,2);


	return true;
}

void ChooseHatest::poe()
{
	choice = "poe";
	__android_log_write(ANDROID_LOG_INFO, "ChooseHatest", "poe");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void ChooseHatest::miriam()
{
	choice = "miriam";
	__android_log_write(ANDROID_LOG_INFO, "ChooseHatest", "miriam");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void ChooseHatest::duterte()
{
	choice = "duterte";
	__android_log_write(ANDROID_LOG_INFO, "ChooseHatest", "duterte");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void ChooseHatest::binay()
{
	choice = "binay";
	__android_log_write(ANDROID_LOG_INFO, "ChooseHatest", "binay");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void ChooseHatest::roxas()
{
	choice = "roxas";
	__android_log_write(ANDROID_LOG_INFO, "ChooseHatest", "roxas");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}
*/
