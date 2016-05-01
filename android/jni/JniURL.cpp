#include "JniURL.h"
#include "JniHelper.h"
#include <android/log.h>

#include <jni.h>

using namespace cocos2d;

extern "C"
{

    void openURLJNI(const char* url)
    {
		__android_log_write(ANDROID_LOG_INFO, "JNI", "openURLJNI");
        JniMethodInfo t;
        if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/lib/Cocos2dxActivity"
                        ,"openURL"
                        ,"(Ljava/lang/String;)V"))
        {
            jstring StringArg1 = t.env->NewStringUTF(url);
            t.env->CallStaticVoidMethod(t.classID,t.methodID, StringArg1);
        }

    }
	
	void toggleAdsJNI(const char* a_switch)
    {
		__android_log_write(ANDROID_LOG_INFO, "JNI", "toggleAdsJNI");
        JniMethodInfo t;
        if (JniHelper::getStaticMethodInfo(t, "com/reubencapio/whackyourboss/whackyourboss"
                        ,"toggleAds"
                        ,"(Ljava/lang/String;)V"))
        {
			__android_log_write(ANDROID_LOG_INFO, "JNI", "toggleAdsJNI inside if");
            jstring StringArg1 = t.env->NewStringUTF(a_switch);
            t.env->CallStaticVoidMethod(t.classID,t.methodID, StringArg1);
        }

    }
	
	void toggleAdsJNITest(const char* a_switch)
    {
		__android_log_write(ANDROID_LOG_INFO, "JNI", "toggleAdsJNITest");
        JniMethodInfo t;
        if (JniHelper::getStaticMethodInfo(t, "org/cocos2dx/lib/Cocos2dxActivity"
                        ,"toggleAdstest"
                        ,"(Ljava/lang/String;)V"))
        {
            jstring StringArg1 = t.env->NewStringUTF(a_switch);
            t.env->CallStaticVoidMethod(t.classID,t.methodID, StringArg1);
        }

    }
	
	/*
	void showAdJNI(bool show)
    {
		__android_log_write(ANDROID_LOG_INFO, "JNI", "showAdJNI");
		JniMethodInfo t;
	
		if (JniHelper::getStaticMethodInfo(t, "com/reubencapio/whackyourboss/whackyourboss"
                        ,"showAd"
                        ,"(Ljava/lang/boolean;)V"))
        {
			__android_log_write(ANDROID_LOG_INFO, "JNI", "toggleAdsJNI inside if");
            jboolean boolArg1 = show;
            t.env->CallStaticVoidMethod(t.classID,t.methodID, boolArg1);
        }


	}
	*/
	
}
