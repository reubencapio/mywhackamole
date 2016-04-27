#include "AppDelegate.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>

#include "Constants.h"
#include "Game.h"
#include "GameButton.h"
#include "HUD.h"
#include "MainMenu.h"
#include "Mole.h"
#include "Pause.h"
#include "Popup.h"
#include "Utils.h"

#define  LOG_TAG    "main"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;
using namespace cocos2d::extension;

extern "C"
{

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	__android_log_write(ANDROID_LOG_INFO, "JNI", "JNI_OnLoad");
    JniHelper::setJavaVM(vm);

    return JNI_VERSION_1_4;
}

void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit(JNIEnv*  env, jobject thiz, jint w, jint h)
{
	__android_log_write(ANDROID_LOG_INFO, "JNI", "Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit");
    if (!CCDirector::sharedDirector()->getOpenGLView())
    {
    	__android_log_write(ANDROID_LOG_INFO, "JNI", "not getOpenGLView");
        CCEGLView *view = &CCEGLView::sharedOpenGLView();
        view->setFrameSize(w, h);
        // set the design resolution screen size, if you want to use Design Resoulution scaled to current screen, please uncomment next line.
        // view->setDesignResolutionSize(480, 320);

        AppDelegate *pAppDelegate = new AppDelegate();
        CCApplication::sharedApplication().run();
    }
    else
    {
    	__android_log_write(ANDROID_LOG_INFO, "JNI", "getOpenGLView");
        ccDrawInit();
        ccGLInvalidateStateCache();
        
        CCShaderCache::sharedShaderCache()->reloadDefaultShaders();
        CCTextureCache::reloadAllTextures();
        CCNotificationCenter::sharedNotificationCenter()->postNotification(EVNET_COME_TO_FOREGROUND, NULL);
        CCDirector::sharedDirector()->setGLDefaultValues(); 
    }
}

}
