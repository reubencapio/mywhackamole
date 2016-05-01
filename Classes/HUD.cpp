//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include <iostream>
#include "HUD.h"
#include "Utils.h"
#include "SimpleAudioEngine.h"
#include "Game.h"
#include "Mole.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "Constants.h"
#include <android/log.h>

using namespace cocos2d;
using namespace CocosDenshion;

bool HUD::init()
{
	__android_log_write(ANDROID_LOG_INFO, "HUD", "init");
    if (!CCLayer::init()) {
        return false;        
    }
    score = 0;
    float padding = 10;
    //possible bug bentest
    carrots = CCArray::create();
    carrots->retain();
    carrotsLeft = 3;
    for(int i = 0; i < carrotsLeft; i++) {
    		CCSprite *c = CCSprite::createWithSpriteFrameName("life.png");
    		c->setAnchorPoint(ccp(1,1));
    		c->setScale(Utils::getScale());
    		__android_log_write(ANDROID_LOG_INFO, "HUD", "before setPosition");
    		c->setPosition(ccp(Utils::s().width - padding - i * (c->getContentSize().width * c->getScale()), Utils::s().height - padding));
    		__android_log_write(ANDROID_LOG_INFO, "HUD", "after setPosition");
    		carrots->addObject(c);
    		this->addChild(c,1);
    }
    scoreLabel = CCLabelTTF::create("0", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(),24 * Utils::getArtScaleFactor());
    scoreLabel->setAnchorPoint(ccp(0,1));
    scoreLabel->setScale(2);
    scoreLabel->setPosition(ccp(padding,Utils::s().height - padding));
    this->addChild(scoreLabel,1);
    __android_log_write(ANDROID_LOG_INFO, "HUD", "exit");
    return true;
}

void HUD::didScore()
{
	__android_log_write(ANDROID_LOG_INFO, "HUD", "didScore");
	score++;
	scoreLabel->setString(CCString::createWithFormat("%d",score)->getCString());
}
void HUD::missedMole()
{
	__android_log_write(ANDROID_LOG_INFO, "HUD", "missedMole");
	SimpleAudioEngine::sharedEngine()->playEffect("moles_miss.wav");
	carrotsLeft--;
	if(carrots->count() > 0) {
		this->removeChild((CCNode *)carrots->objectAtIndex(carrots->count() - 1), true);
		carrots->removeLastObject();
	}
	if(carrotsLeft <= 0) {
		if(score > CCUserDefault::sharedUserDefault()->getIntegerForKey(HIGH_SCORE)) {
			CCUserDefault::sharedUserDefault()->setIntegerForKey(HIGH_SCORE, score);
		}

		GameOver *go = (GameOver *)Utils::layerWithTag(TAG_GAMEOVER);
		go->gameover();
	}
	else {
		CCArray *moles = Utils::gameLayer()->getMoles(true);
		for(int i =0; i < moles->count(); i++) {
			Mole *m = (Mole *)moles->objectAtIndex(i);
			m->stopEarly();
		}
	}
}

void HUD::onExit()
{
	__android_log_write(ANDROID_LOG_INFO, "HUD", "onExit");
	carrots->release();
	CCLayer::onExit();
}
