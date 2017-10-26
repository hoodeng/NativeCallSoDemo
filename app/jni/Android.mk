LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_MODULE    := somath
LOCAL_SRC_FILES := lib/libsomath.so

LOCAL_EXPORT_C_INCLUDES := lib/include
include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE    := mymath
LOCAL_SRC_FILES := MyMath.cpp
LOCAL_LDLIBS    += -L$(SYSROOT)/lib -llog
LOCAL_CFLAGS    := -g

LOCAL_SHARED_LIBRARIES := somath
include $(BUILD_SHARED_LIBRARY)