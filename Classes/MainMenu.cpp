//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include "MainMenu.h"
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
const char* choice = NULL;
//USING_NS_CC;

CCScene* MainMenu::scene()
{
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "scene");
    CCScene *sc = CCScene::create();
    MainMenu *m = MainMenu::create();
    sc->addChild(m, 0);
    return sc;
}

bool MainMenu::init()
{
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "init");
	if ( !CCLayer::init() )
	{
		return false;
	}
    
    s = CCDirector::sharedDirector()->getWinSize();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("binay.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("roxas.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("poe.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("duterte.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("santiago.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect(SOUND_SPLAT);
	SimpleAudioEngine::sharedEngine()->preloadEffect("moles_miss.wav");
	//other choice would have hd plist(not implemented, too lazy)
    CCString* file = (Utils::getArtScaleFactor() > 1) ? CCString::create("binay.plist") : CCString::create("binay.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(file->getCString());
    file = (Utils::getArtScaleFactor() > 1) ? CCString::create("title-hd.png") : CCString::create("title.png");
    CCSprite *bg = CCSprite::create(file->getCString());
    bg->setPosition(ccp(s.width/2,s.height/2));
    Utils::scaleSprite(bg);
    this->addChild(bg,-1);

    CCLabelTTF *scoreLabel = CCLabelTTF::create(CCString::createWithFormat("HIGH: %d", CCUserDefault::sharedUserDefault()->getIntegerForKey(HIGH_SCORE))->getCString(), CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(),24 * Utils::getArtScaleFactor());
    scoreLabel->setAnchorPoint(ccp(0,1));
    scoreLabel->setScale(2);
    scoreLabel->setColor(ccc3(0,0,0));
    scoreLabel->setPosition(ccp(10,Utils::s().height - 10));
    this->addChild(scoreLabel,10);
/*
    CCMenuItemSprite *playButton = CCMenuItemSprite::create(GameButton::buttonWithText("PLAY!",false), NULL, this, menu_selector(MainMenu::playGame));
    CCMenu *menu = CCMenu::create(playButton,NULL);
    menu->setPosition(ccp(s.width/2,s.height/2 - s.height/4.0f));
    this->addChild(menu,2);
*/

    CCMenuItemSprite *binayButton = CCMenuItemSprite::create(GameButton::buttonWithText("BINAY!",false), NULL, this, menu_selector(MainMenu::binay));
    CCMenu *binaymenu = CCMenu::create(binayButton,NULL);
    binaymenu->setPosition(ccp(s.width/9.1,s.height/2 - s.height/4.0f));
    this->addChild(binaymenu,2);

    CCMenuItemSprite *poeButton = CCMenuItemSprite::create(GameButton::buttonWithText("POE!",false), NULL, this, menu_selector(MainMenu::poe));
    CCMenu *poemenu = CCMenu::create(poeButton,NULL);
    poemenu->setPosition(ccp(s.width/3.8,s.height/2 - s.height/4.0f));
    this->addChild(poemenu,2);

    CCMenuItemSprite *duterteButton = CCMenuItemSprite::create(GameButton::buttonWithText("DUTERTE!",false), NULL, this, menu_selector(MainMenu::duterte));
    CCMenu *dutertemenu = CCMenu::create(duterteButton,NULL);
    dutertemenu->setPosition(ccp(s.width/2.1,s.height/2 - s.height/4.0f));
    this->addChild(dutertemenu,2);

    CCMenuItemSprite *miriamButton = CCMenuItemSprite::create(GameButton::buttonWithText("MIRIAM!",false), NULL, this, menu_selector(MainMenu::miriam));
    CCMenu *miriammenu = CCMenu::create(miriamButton,NULL);
    miriammenu->setPosition(ccp(s.width/1.5,s.height/2 - s.height/4.0f));
    this->addChild(miriammenu,2);

    CCMenuItemSprite *roxasButton = CCMenuItemSprite::create(GameButton::buttonWithText("ROXAS!",false), NULL, this, menu_selector(MainMenu::roxas));
    CCMenu *roxasmenu = CCMenu::create(roxasButton,NULL);
    roxasmenu->setPosition(ccp(s.width/1.2,s.height/2 - s.height/4.0f));
    this->addChild(roxasmenu,2);
	return true;
}

/*
void MainMenu::playGame()
{
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "playGame");
	//showMessageBoxJNI("test","test");
	//CCDirector::sharedDirector()->replaceScene(Game::scene());
    CCDirector::sharedDirector()->replaceScene(ChooseHatest::scene());
}
*/

void MainMenu::mainMenu()
{
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "mainMenu");
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}


void MainMenu::poe()
{
	choice = "poe";
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "poe");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void MainMenu::miriam()
{
	choice = "miriam";
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "miriam");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void MainMenu::duterte()
{
	choice = "duterte";
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "duterte");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void MainMenu::binay()
{
	choice = "binay";
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "binay");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void MainMenu::roxas()
{
	choice = "roxas";
	__android_log_write(ANDROID_LOG_INFO, "MainMenu", "roxas");
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}
