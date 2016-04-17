//whackyourpres
//modified from todd perkins tutorial
//reubencapio


#ifndef moleit_x_GameButton_h
#define moleit_x_GameButton_h

#include "cocos2d.h"

class GameButton : public cocos2d::CCSprite
{
    
    
    public:
    bool initWithText(const char * text, bool isBig);
    static GameButton* buttonWithText(const char * text, bool isBig);
};

#endif
