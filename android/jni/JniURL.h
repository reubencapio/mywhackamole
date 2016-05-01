#ifndef __ANDROID_JNI_URL_H__
#define __ANDROID_JNI_URL_H__

extern "C"
{
    extern void openURLJNI(const char* url);
	extern void toggleAdsJNI(const char* url);
	extern void toggleAdsJNITest(const char* url);
	//extern void showAdJNI(bool show);
}

#endif
