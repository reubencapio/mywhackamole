//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#ifndef moleit_x_Pause_h
#define moleit_x_Pause_h

#include "cocos2d.h"
#include "Popup.h"

class Pause : public cocos2d::CCLayer
{
    Popup *popup;
    cocos2d::CCMenuItemSprite *pauseButton;
public:
    bool init();
    void pause();
    void resume();
    void mainMenu();
    void togglePause(bool paused);
    LAYER_CREATE_FUNC(Pause);
};



#endif
