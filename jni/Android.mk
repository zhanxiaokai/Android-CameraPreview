LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_CFLAGS += -D__STDC_CONSTANT_MACROS
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/libcommon 
    
LOCAL_SRC_FILES := \
ChangbaRecordingPreviewScheduler.cpp 

LOCAL_STATIC_LIBRARIES := libcommontool libcamerapreview 

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog
# Link with OpenGL ES
LOCAL_LDLIBS += -lGLESv2
LOCAL_LDLIBS += -lz
#LOCAL_LDLIBS += -lgomp
LOCAL_LDLIBS += -landroid 
LOCAL_LDLIBS += -lEGL

LOCAL_MODULE := libsongstudio
include $(BUILD_SHARED_LIBRARY)
include $(call all-makefiles-under,$(LOCAL_PATH))