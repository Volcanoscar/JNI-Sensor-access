package com.example.newjni;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class NewJni extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
        TextView  tv = new TextView(this);
        tv.setText( String.valueOf(stringFromJNI()) );
        sensorValue();
        setContentView(tv);
	}
	public native String  stringFromJNI();

	public native void sensorValue();
   // public native String  unimplementedStringFromJNI();

    static {
        System.loadLibrary("newjni");
    }

}
