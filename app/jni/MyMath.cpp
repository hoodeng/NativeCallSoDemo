//
// Created by 吴登 on 17/10/26.
//

#include "lib/include/SoMath.h"
#include "jni.h"
#include "string.h"
#include "assert.h"
#include "android/log.h"

const char *JNIREG_CLASS = "vip/com/nativecallsodemo/JavaMath";

jint native_add(JNIEnv *env, jobject obj, jint i, jint j) {
    __android_log_print(ANDROID_LOG_VERBOSE, "JNI", "native add");

    SoMath ba;

    return ba.add(i, j);
}

jint native_sub(JNIEnv *env, jobject obj, jint i, jint j) {
    __android_log_print(ANDROID_LOG_VERBOSE, "JNI", "native sub");

    SoMath ba;

    return ba.sub(i, j);
}

jint native_mul(JNIEnv *env, jobject obj, jint i, jint j) {
    __android_log_print(ANDROID_LOG_VERBOSE, "JNI", "native mul");

    SoMath ba;

    return ba.mul(i, j);
}

jint native_div(JNIEnv *env, jobject obj, jint i, jint j) {
    __android_log_print(ANDROID_LOG_VERBOSE, "JNI", "native div");
    SoMath ba;

    return ba.div(i, j);
}


static JNINativeMethod gMethods[] = {
        {"add", "(II)I", (void *) native_add},
        {"sub", "(II)I", (void *) native_sub},
        {"mul", "(II)I", (void *) native_mul},
        {"div", "(II)I", (void *) native_div}
};


static int registerNativeMethods(JNIEnv *env, const char *className,
                                 JNINativeMethod *gMethods, int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}


static int registerNatives(JNIEnv *env) {
    if (!registerNativeMethods(env, JNIREG_CLASS, gMethods,
                               sizeof(gMethods) / sizeof(gMethods[0]))) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    __android_log_print(ANDROID_LOG_DEFAULT, "JNI", "onLoad");

    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);

    if (!registerNatives(env)) {//注册
        return -1;
    }
/* success -- return valid version number */
    result = JNI_VERSION_1_4;

    return result;
}