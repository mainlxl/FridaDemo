#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring
Java_com_mainli_fridademo_MainActivity_stringFromJNI(JNIEnv
*env,jobject) {
return env->NewStringUTF("Hello from C++");
}