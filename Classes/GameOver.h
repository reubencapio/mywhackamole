//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#ifndef moleit_x_GameOver_h
#define moleit_x_GameOver_h

#include "cocos2d.h"
#include "Popup.h"

class GameOver : public cocos2d::CCLayer
{
    Popup *popup;
public:
    bool init();
    void replay();
    void mainMenu();
    void gameover();
    void postInFacebook();
    LAYER_CREATE_FUNC(GameOver);
};



#endif
