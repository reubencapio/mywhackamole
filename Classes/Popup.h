//whackyourpres
//modified from todd perkins tutorial
//reubencapio

#ifndef moleit_x_Popup_h
#define moleit_x_Popup_h

#include "cocos2d.h"

class Popup : public cocos2d::CCSprite
{
    cocos2d::CCMenu *menu;
public:
    bool initWithTitle(const char* title);
    static Popup* popupWithTitle(const char* title);
    void show(bool shouldShow);
    void addButtonWithText(const char* text, CCObject*target, cocos2d::SEL_MenuHandler selector);
};



#endif
