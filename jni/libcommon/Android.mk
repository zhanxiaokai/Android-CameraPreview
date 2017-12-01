LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
./matrix.cpp \
./thread.cpp 

MESSAGE_QUEUE_FILES = \
./message_queue/handler.cpp \
./message_queue/message_queue.cpp 

EGL_CORE_FILES = \
./egl_core/egl_core.cpp \
./egl_core/egl_share_context.cpp

OPENSL_ES_FILES = \
./opensl_media/opensl_es_context.cpp 

OPENGL_ES_FILES = \
./opengl_media/movie_frame.cpp \
./opengl_media/texture/texture_frame.cpp \
./opengl_media/texture/gpu_texture_frame.cpp \
./opengl_media/texture/yuv_texture_frame.cpp \
./opengl_media/texture_copier/texture_frame_copier.cpp \
./opengl_media/texture_copier/gpu_texture_frame_copier.cpp \
./opengl_media/texture_copier/yuv_texture_frame_copier.cpp \
./opengl_media/render/video_gl_surface_render.cpp 

LOCAL_SRC_FILES += $(MESSAGE_QUEUE_FILES)
LOCAL_SRC_FILES += $(EGL_CORE_FILES)
LOCAL_SRC_FILES += $(OPENSL_ES_FILES)
LOCAL_SRC_FILES += $(OPENGL_ES_FILES)

LOCAL_MODULE := libcommontool
include $(BUILD_STATIC_LIBRARY)

