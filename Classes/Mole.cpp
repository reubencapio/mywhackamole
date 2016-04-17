//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include "Mole.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"
#include "Game.h"
#include <sstream>
#include <string>
#include "Utils.h"
#include "HUD.h"
#include <android/log.h>

using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

#define TAG_REPEAT_ANIM 6

bool Mole::init()
{
	__android_log_write(ANDROID_LOG_INFO, "Mole", "init started");
	if ( !CCSprite::init() )
	{
		return false;
	}
	upTime = 2.0f;
	isUp = false;
	__android_log_write(ANDROID_LOG_INFO, "Mole", "setDisplayFrame will be called");
	this->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("binay_head1.png"));
	__android_log_write(ANDROID_LOG_INFO, "Mole", "init end");
	return true;
}

void Mole::start()
{
	if(this == NULL){
		__android_log_write(ANDROID_LOG_INFO, "Mole", "shit!");
	}
	__android_log_write(ANDROID_LOG_INFO, "Mole", "start");
	this->stopAllActions();
	__android_log_write(ANDROID_LOG_INFO, "Mole", "stopAllActions done");
	isUp = true;
	__android_log_write(ANDROID_LOG_INFO, "Mole", "isUp set");
	didMiss = true;
	__android_log_write(ANDROID_LOG_INFO, "Mole", "didMiss set");
	this->runAction(CCSequence::create(
			CCDelayTime::create(upTime),
			CCCallFunc::create(this,callfunc_selector(Mole::stop)),
			NULL));
	__android_log_write(ANDROID_LOG_INFO, "Mole", "getAnimationWithFrames will be called");
	this->runAction(CCSequence::create(
				Utils::getAnimationWithFrames(1,5),
				CCCallFunc::create(this,callfunc_selector(Mole::startLoopAnimation)),
				NULL));
}

void Mole::startLoopAnimation()
{
	if(!isUp){
		return;
	}
	CCRepeatForever *repeat = CCRepeatForever::create((CCSequence *)CCSequence::create(
			Utils::getAnimationWithFrames(1,5),
			Utils::getAnimationWithFrames(1,5)->reverse(),
			NULL));
	repeat->setTag(TAG_REPEAT_ANIM);
	this->runAction(repeat);
}


void Mole::stop()
{
	this->stopAllActions();
	this->runAction(CCSequence::create(
					Utils::getAnimationWithFrames(1,5)->reverse(),
					CCCallFunc::create(this,callfunc_selector(Mole::reset)),
					NULL));
}

void Mole::reset()
{
	isUp = false;
	if(didMiss) {
		Utils::hudLayer()->missedMole();
	}
}

void Mole::wasTapped()
{
	this->stopAllActions();
	this->runAction(Utils::getAnimationWithFrames(3,1));
	isUp = false;
}
bool Mole::getIsUp(){
    return isUp;
}

void Mole::stopEarly()
{
	didMiss = false;
	isUp = false;
	this->stopAllActions();
	this->stop();
}
