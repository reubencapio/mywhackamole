LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := helloworld/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/Game.cpp \
                   ../../Classes/GameButton.cpp \
                   ../../Classes/GameOver.cpp \
                   ../../Classes/HUD.cpp \
                   ../../Classes/MainMenu.cpp \
                   ../../Classes/Mole.cpp \
                   ../../Classes/Pause.cpp \
                   ../../Classes/Popup.cpp \
                   ../../Classes/Utils.cpp
                   
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes    

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog                

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) $(call import-module,cocos2dx)
