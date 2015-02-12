/*
* Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include <android/sensor.h>
#include <android_native_app_glue.h>
#include <android/looper.h>
#include <android/log.h>
#include <time.h>
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "NewJni", __VA_ARGS__))
#define LOOPER_ID 1
#define SAMP_PER_SEC 100

ASensorEventQueue* sensorEventQueue;

/* globals for sensors */
ALooper *looper;
ASensorManager *sensorManager;
ASensorEventQueue *sensorEventQueue;
ASensor *sensor;

ASensorEvent event;

/* sensor event callback */
/*
int get_sensor_events(int fd, int events, void *data)
{
  while(ASensorEventQueue_getEvents(sensorEventQueue, &event, 1)>0)
  {
    if (event.type == ASENSOR_TYPE_ACCELEROMETER) {
          LOGI("accelerometer: x=%f y=%f z=%f",
              event.acceleration.x, event.acceleration.y,
              event.acceleration.z);
    }
  }
}
*/

jstring
Java_com_example_newjni_NewJni_stringFromJNI( JNIEnv* env, jobject thiz )
{
	
    LOGI("stringFromJNI0000000000000000000");
    while(ASensorEventQueue_getEvents(sensorEventQueue, &event, 1)>0)
      {
    	LOGI("stringFromJNI1111111111111");
        if (event.type == ASENSOR_TYPE_ACCELEROMETER) {
              LOGI("accelerometer: x=%f y=%f z=%f",
                  event.acceleration.x, event.acceleration.y,
                  event.acceleration.z);
        }
      }
    return (*env)->NewStringUTF(env,"Hello from JNI !");
}

