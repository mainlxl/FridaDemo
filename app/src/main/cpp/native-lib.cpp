#include <jni.h>
#include <string>
#include <md5.h>

extern "C" JNIEXPORT jstring
Java_com_mainli_fridademo_MainActivity_stringFromJNI(JNIEnv
                                                     *env, jobject) {
    return env->NewStringUTF("Hello from C++");
}
extern "C" JNIEXPORT jstring
Java_com_mainli_fridademo_MainActivity_md5(JNIEnv
                                           *env,
                                           jobject, jstring input) {
    // 将jstring转换为C字符串
    const char *msg = env->GetStringUTFChars(input, NULL);
    if (msg == NULL) {
        return env->NewStringUTF("输入参数错误");
    }

    char result_buffer[33]; // 32字符MD5哈希 + null终止符

    if (md5_string(msg, result_buffer) != 0) {
        env->ReleaseStringUTFChars(input, msg);
        return env->NewStringUTF("MD5计算失败");
    }

    // 释放Java字符串资源
    env->ReleaseStringUTFChars(input, msg);

    return env->NewStringUTF(result_buffer);
}