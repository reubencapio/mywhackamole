/*#include "ToggleAds.h"
#include "JniHelper.h"

#include <jni.h>

using namespace cocos2d;

extern "C"
{

    void toggleAdsJNI(int a_switch)
    {
		h
        JniMethodInfo t;
        if (JniHelper::getStaticMethodInfo(t, "com/reubencapio/whackyourboss/whackyourboss"
                        ,"toggleAds"
                        ,"(Ljava/lang/Int;)V"))
        {
            jint IntArg1 = t.env->NewInt(a_switch);
            t.env->CallStaticVoidMethod(t.classID,t.methodID, IntArg1);
        }

    }
}
*/