#include "Game.h"
#include "SimpleAudioEngine.h"
#include "Mole.h"
#include "Constants.h"
#include "HUD.h"
#include "Utils.h"
#include "Pause.h"
#include "MainMenu.h"
#include "GameOver.h"
#include <string>
#include "JniURL.h"
#include "ToggleAds.h"
#include <android/log.h>
//#include "ChooseHatest.h"

using namespace cocos2d;
using namespace CocosDenshion;

extern char* choice;

CCScene* Game::scene()
{
	toggleAdsJNI("off");
	//showAdJNI(1);
	//toggleAdsJNITest("off");
	__android_log_write(ANDROID_LOG_INFO, "Game", "scene");
    CCScene *sc = CCScene::create();
    sc->setTag(TAG_GAME_SCENE);
    Game *g = Game::create();
    sc->addChild(g, 0, TAG_GAME_LAYER);
    //ChooseHatest *cf = ChooseHatest::create();
    //sc->addChild(cf, 1, TAG_CHOOSEHATEST);
    HUD *h = HUD::create();
    sc->addChild(h,1,TAG_HUD);
    Pause *p = Pause::create();
    sc->addChild(p,1,TAG_PAUSE);
    GameOver *go = GameOver::create();
    sc->addChild(go,1,TAG_GAMEOVER);
    return sc;
}

bool Game::init()
{
	__android_log_write(ANDROID_LOG_INFO, "Game", "init");

	if ( !CCLayer::init() )
	{
		return false;
	}
	
	molesAtOnce = 4;
	timeBetweenMoles = 0.5f;
	increaseMolesAtTime = 2.0f;

	return true;
}

void Game::initializeGame()
{
	__android_log_write(ANDROID_LOG_INFO, "Game", "initializeGame");
	moles = CCArray::create();
	moles->retain();

	const char* input = NULL;
	if(choice == "duterte"){
		input = "duterte.mp3";
	} else if(choice == "binay"){
		input = "binay.mp3";
	} else if(choice == "poe"){
		input = "poe.mp3";
	} else if(choice == "miriam"){
		input = "santiago.mp3";
	} else if(choice == "roxas"){
		input = "roxas.mp3";
	}else{
		input = "binay.mp3";
	}

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(input, true);
	__android_log_print(ANDROID_LOG_INFO, "Game", "choice = %s", choice);
	Mole *mole = (Mole *)Mole::create();
	float hPad = Utils::s().width/2 - (mole->getContentSize().width * Utils::getScale()) * 3.5f;
	float vPad = Utils::s().height/2 - (mole->getContentSize().height * Utils::getScale()) * 2.1;
	delete mole;


	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 5; j++){
			Mole *mole = (Mole *)Mole::create();
			mole->setScale(Utils::getScale());
			mole->setPosition(ccp(j * mole->getContentSize().width * Utils::getScale() + hPad, i * mole->getContentSize().height * Utils::getScale() + vPad));
			moles->addObject(mole);
			this->addChild(mole,1);
		}
	}

	CCString *file = (Utils::getArtScaleFactor() > 1) ? ccs("black_background.png") : ccs("black_background.png");
	CCSprite *bg = CCSprite::create(file->getCString());
	bg->setPosition(ccp(Utils::s().width/2,Utils::s().height/2));
	Utils::scaleSprite(bg);
	this->addChild(bg,0);
	this->schedule(schedule_selector(Game::tick));
}

void Game::tick(float dt)
{
	__android_log_write(ANDROID_LOG_INFO, "Game", "tick");
	timeElapsed += dt;
	increaseElapsed += dt;
	totalTime += dt;
	if(timeElapsed >= timeBetweenMoles && this->getMoles(true)->count() < molesAtOnce)
	{
		this->showMole();
		timeElapsed = 0;
	}

	if(increaseElapsed >= increaseMolesAtTime) {
		int maxMolesAtOnce = 12;
		if(molesAtOnce < maxMolesAtOnce) {
			molesAtOnce++;
			float minMoleTime = 0.5f;
			timeBetweenMoles -= (timeBetweenMoles > minMoleTime) ? .05 : 0;
			increaseMolesAtTime += 10.0f;
		}
		increaseElapsed = 0;
	}
}

void Game::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	__android_log_write(ANDROID_LOG_INFO, "Game", "ccTouchesBegan");
    CCTouch *touch = (CCTouch *)pTouches->anyObject();
    CCPoint location = touch->locationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    for(int i = 0; i < moles->count(); i++) {
    		Mole *mole = (Mole *)moles->objectAtIndex(i);
    		if(!mole->getIsUp()) {
    			continue;
    		}
    		if(CCRect::CCRectContainsPoint(mole->boundingBox(), location)) {
    			mole->wasTapped();
    			SimpleAudioEngine::sharedEngine()->playEffect(SOUND_SPLAT);
    			Utils::hudLayer()->didScore();
    			break;
    		}
    }
}

void Game::showMole()
{
	__android_log_write(ANDROID_LOG_INFO, "Game", "showMole");
	Mole *mole = (Mole *)this->getMoles(false)->randomObject();
	mole->start();
}

CCArray* Game::getMoles(bool isUp)
{
	__android_log_write(ANDROID_LOG_INFO, "Game", "getMoles");
    CCArray *ary = CCArray::create();
    for(int i = 0; i < moles->count();i++) {
    		Mole *mole = (Mole *)moles->objectAtIndex(i);
    		if(mole->getIsUp() == isUp)
    		{
    			ary->addObject(mole);
    		}
    }
	return ary;
}

void Game::onExit()
{
	__android_log_write(ANDROID_LOG_INFO, "Game", "onExit");
	moles->release();
	CCLayer::onExit();
}

void Game::onEnterTransitionDidFinish()
{
	__android_log_write(ANDROID_LOG_INFO, "Game", "onEnterTransitionDidFinish");
	this->setTouchEnabled(true);
	this->initializeGame();

}
