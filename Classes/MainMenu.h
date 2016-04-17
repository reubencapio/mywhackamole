#ifndef __MAINMENU_H__
#define __MAINMENU_H__

#include "cocos2d.h"

using namespace cocos2d;

class MainMenu : public cocos2d::CCLayer {
    cocos2d::CCSize s;

public:
    virtual bool init();
    virtual void playGame();
    static void mainMenu();
    static CCScene* scene();
    LAYER_CREATE_FUNC(MainMenu);
}; // __MAINMENU_H__


#endif
