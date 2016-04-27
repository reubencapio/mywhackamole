//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#include "Utils.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include <sstream>
#include <android/log.h>
extern char* choice;
using namespace cocos2d;

static float scale = 1.0f;
static int artScaleFactor = 1;

Game* Utils::gameLayer()
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "gameLayer");
    return (Game *)Utils::layerWithTag(TAG_GAME_LAYER);
}

HUD* Utils::hudLayer()
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "hudLayer");
    return (HUD *)Utils::layerWithTag(TAG_HUD);
}
CCLayer* Utils::layerWithTag(int tag)
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "layerWithTag");
	__android_log_print(ANDROID_LOG_INFO, "Utils", "tag = %d", tag);
	CCDirector::sharedDirector()->getRunningScene();
    CCScene *sc = CCDirector::sharedDirector()->getRunningScene();
    int scenetag = sc->getTag();
    __android_log_print(ANDROID_LOG_INFO, "Utils", "scenetag = %d", scenetag);
    if (sc->getTag() == TAG_GAME_SCENE/* || sc->getTag() == TAG_CHOOSEHATEST*/){
    	__android_log_write(ANDROID_LOG_INFO, "Utils", "layer returned");
        CCLayer *layer = (CCLayer *)sc->getChildByTag(tag);
        if(layer == NULL){
        	__android_log_write(ANDROID_LOG_INFO, "Utils", "layer is NULL");
        }
        return layer;
    }
    return NULL;
}

CCSize Utils::s()
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "s()");
    return CCDirector::sharedDirector()->getWinSize();
}



cocos2d::CCAnimate* Utils::getAnimationWithFrames(int from, int to)
{
	const char* input = NULL;
	if(choice == "duterte"){
		input = "duterte_head%d.png";
	} else if(choice == "binay"){
		input = "binay_head%d.png";
	} else if(choice == "poe"){
		input = "grace_head%d.png";
	} else if(choice == "miriam"){
		input = "miriam_head%d.png";
	} else if(choice == "roxas"){
		input = "roxas_head%d.png";
	} else{
		input = "binay_head%d.png";
	}
	__android_log_write(ANDROID_LOG_INFO, "Utils", "getAnimationWithFrames");
	CCArray* frames = CCArray::create();
	for (int i = from; i <= to; i++) {
	     CCString *str = CCString::createWithFormat(input, i);
	     frames->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString()));
	}
	CCAnimation *animation = CCAnimation::create(frames, 1.0f/24.0f);
	CCAnimate *a = CCAnimate::create(animation);
	return a;
}

void Utils::scaleSprite(CCSprite* sprite)
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "scaleSprite");
    float rX = Utils::s().width / sprite->getContentSize().width;
	float rY = Utils::s().height / sprite->getContentSize().height;
	sprite->setScaleX(rX);
	sprite->setScaleY(rY);
}

float Utils::getScale()
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "getScale");
    return scale;
}

void Utils::setScale(float s)
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "setScale");
    scale = s;
}

float Utils::getArtScaleFactor()
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "getArtScaleFactor");
    return artScaleFactor;
}

void Utils::setArtScaleFactor(int s)
{
	__android_log_write(ANDROID_LOG_INFO, "Utils", "setArtScaleFactor");
    artScaleFactor = s;
}
