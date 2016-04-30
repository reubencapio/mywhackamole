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

extern char* choice;

#define TAG_REPEAT_ANIM 10

bool Mole::init()
{
	__android_log_write(ANDROID_LOG_INFO, "Mole", "init");
	if ( !CCSprite::init() )
	{
		return false;
	}
	upTime = 1.0f;
	isUp = false;
	const char* input = NULL;
	if(choice == "duterte"){
		input = "duterte_head0.png";
	} else if(choice == "binay"){
		input = "binay_head0.png";
	} else if(choice == "poe"){
		input = "grace_head0.png";
	} else if(choice == "miriam"){
		input = "miriam_head0.png";
	} else if(choice == "roxas"){
		input = "roxas_head0.png";
	}else{
		input = "binay_head0.png";
	}




	this->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(input));
	//this->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("duterte_head0.png"));
	return true;
}

void Mole::start()
{
	__android_log_write(ANDROID_LOG_INFO, "Mole", "start");
	this->stopAllActions();
	isUp = true;
	didMiss = true;
	this->runAction(CCSequence::create(
			CCDelayTime::create(upTime),
			CCCallFunc::create(this,callfunc_selector(Mole::stop)),
			NULL));
	this->runAction(CCSequence::create(
				Utils::getAnimationWithFrames(0,11),
				CCCallFunc::create(this,callfunc_selector(Mole::startLoopAnimation)),
				NULL));
}

void Mole::startLoopAnimation()
{
	__android_log_write(ANDROID_LOG_INFO, "Mole", "startLoopAnimation");
	if(!isUp){
		return;
	}
	CCRepeatForever *repeat = CCRepeatForever::create((CCSequence *)CCSequence::create(
			Utils::getAnimationWithFrames(0,11),
			Utils::getAnimationWithFrames(11,0),
			NULL));
	repeat->setTag(TAG_REPEAT_ANIM);
	this->runAction(repeat);
}


void Mole::stop()
{
	__android_log_write(ANDROID_LOG_INFO, "Mole", "stop");
	this->stopAllActions();
	this->runAction(CCSequence::create(
					Utils::getAnimationWithFrames(0,0),
					CCCallFunc::create(this,callfunc_selector(Mole::reset)),
					NULL));
}

void Mole::reset()
{
	__android_log_write(ANDROID_LOG_INFO, "Mole", "reset");
	isUp = false;
	if(didMiss) {
		Utils::hudLayer()->missedMole();
	}
}

void Mole::wasTapped()
{
	__android_log_write(ANDROID_LOG_INFO, "Mole", "wasTapped");
	this->stopAllActions();
	this->runAction(Utils::getAnimationWithFrames(12,18));
	isUp = false;
}
bool Mole::getIsUp(){
	__android_log_write(ANDROID_LOG_INFO, "Mole", "getIsUp");
    return isUp;
}

void Mole::stopEarly()
{
	__android_log_write(ANDROID_LOG_INFO, "Mole", "stopEarly");
	didMiss = false;
	isUp = false;
	this->stopAllActions();
	this->stop();
}
