/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.reubencapio.whackyourboss;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;
import org.cocos2dx.lib.Cocos2dxRenderer;

//import com.google.android.gms.ads.AdView; //don't uncomment will cause error
//import com.google.android.gms.ads.*;
import com.google.ads.AdRequest;
import com.google.ads.AdView;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.LinearLayout;

public class whackyourboss extends Cocos2dxActivity{
	private Cocos2dxGLSurfaceView mGLView;
	public static AdView adView;
	static LinearLayout linear;
	
    public static whackyourboss me = null;
    private static Handler handler;
	
	protected void onCreate(Bundle savedInstanceState){
		Log.w("whackyourboss", "onCreate");
		
		super.onCreate(savedInstanceState);
		whackyourboss.me = this;
		
		handler = new Handler(){
		public void handleMessage(Message msg)
	    {
			Log.w("whackyourboss", "handleMessage");
	          switch (msg.what)
	          {
	               case 1:
	                  setShowAd(true);
	                  break;
	               case 0:
	                  setShowAd(false);
	                  break;
	          }
	     }
		};
		
		
		
		if (detectOpenGLES20()) {
			// get the packageName,it's used to set the resource path
			String packageName = getApplication().getPackageName();
			super.setPackageName(packageName);
			
            // FrameLayout
            /*ViewGroup.LayoutParams framelayout_params =
                new ViewGroup.LayoutParams(ViewGroup.LayoutParams.FILL_PARENT,
                                           ViewGroup.LayoutParams.FILL_PARENT);
            FrameLayout framelayout = new FrameLayout(this);
            framelayout.setLayoutParams(framelayout_params);

            // Cocos2dxEditText layout
            ViewGroup.LayoutParams edittext_layout_params =
                new ViewGroup.LayoutParams(ViewGroup.LayoutParams.FILL_PARENT,
                                           ViewGroup.LayoutParams.WRAP_CONTENT);
            Cocos2dxEditText edittext = new Cocos2dxEditText(this);
            edittext.setLayoutParams(edittext_layout_params);

            // ...add to FrameLayout
            framelayout.addView(edittext);

            // Cocos2dxGLSurfaceView
	        mGLView = new Cocos2dxGLSurfaceView(this);

            // ...add to FrameLayout
            framelayout.addView(mGLView);

	        mGLView.setEGLContextClientVersion(2);
	        if(Build.FINGERPRINT.startsWith("generic")){
	        	mGLView.setEGLConfigChooser(8,8,8,8,16,0);
	        }
	        	        
	        mGLView.setCocos2dxRenderer(new Cocos2dxRenderer());
            mGLView.setTextField(edittext);

            // Set framelayout as the content view
			setContentView(framelayout);
			*/
			setContentView(R.layout.main);
            mGLView = (Cocos2dxGLSurfaceView) findViewById(R.id.game_gl_surfaceview);

            mGLView.setEGLContextClientVersion(2);
            mGLView.setCocos2dxRenderer(new Cocos2dxRenderer());

            adView = (AdView)this.findViewById(R.id.adView);
            adView.setVisibility(AdView.VISIBLE);
            
            adView.loadAd(new AdRequest());
		}
		else {
			Log.d("activity", "don't support gles2.0");
			finish();
		}	
	}
	
	 @Override
	 protected void onPause() {
		 Log.w("whackyourboss", "onPause");
	     super.onPause();
	     mGLView.onPause();
	 }

	 @Override
	 protected void onResume() {
		 Log.w("whackyourboss", "onResume");
	     super.onResume();
	     mGLView.onResume();
	     //adView.stopLoading();
	 }
	 /*
	 public static void toggleAds(String a_switch) {
		 Log.w("whackyourboss", "toggleAds");
	 }
	 */
	 public void setShowAd(boolean visible)
	 {
		 Log.w("whackyourboss", "setShowAd");
	      AdView adView = (AdView) this.findViewById(R.id.adView);
	      if (visible)
	      {
	           adView.setVisibility(AdView.VISIBLE);
	           adView.bringToFront();
	      }
	      else
	      {
	           adView.setVisibility(AdView.INVISIBLE);
	      }
	 }

	 public static void toggleAds(String a_switch)
	 {
		 boolean visible = true;
		 if(a_switch.equals("off")){
			 visible = false;
		 }
		 Log.w("whackyourboss", "showAd");
	      Message msg = new Message();
	      if (visible)
	          msg.what = 1;
	      else
	          msg.what = 0;

	      handler.sendMessage(msg);
	 }
	 
	 
	 
	 private boolean detectOpenGLES20() 
	 {
	     ActivityManager am =
	            (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
	     ConfigurationInfo info = am.getDeviceConfigurationInfo();
	     return (info.reqGlEsVersion >= 0x20000 || Build.FINGERPRINT.startsWith("generic"));
	 }
	
     static {
         System.loadLibrary("game");
     }
}
