#include "com_phuket_tour_camera_preview_ChangbaRecordingPreviewScheduler.h";
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "./camera_preview/mv_recording_preview_controller.h"
#include <sys/types.h>
#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>

#define LOG_TAG "ChangbaRecordingPreviewScheduler"

static MVRecordingPreviewController *previewController = 0;

JNIEXPORT void JNICALL Java_com_phuket_tour_camera_preview_ChangbaRecordingPreviewScheduler_switchCameraFacing
(JNIEnv * env, jobject obj) {
	if(NULL != previewController) {
		previewController->switchCameraFacing();
	}
}

JNIEXPORT void JNICALL Java_com_phuket_tour_camera_preview_ChangbaRecordingPreviewScheduler_prepareEGLContext
(JNIEnv * env, jobject obj, jobject surface, jint screenWidth, jint screenHeight, jint cameraFacingId) {
	previewController = new MVRecordingPreviewController();
	JavaVM *g_jvm = NULL;
	env->GetJavaVM(&g_jvm);
	jobject g_obj = env->NewGlobalRef(obj);
	if (surface != 0 && NULL != previewController) {
		ANativeWindow* window = ANativeWindow_fromSurface(env, surface);
		if (window != NULL) {
			previewController->prepareEGLContext(window, g_jvm, g_obj, screenWidth, screenHeight, cameraFacingId);
		}
	}
}

JNIEXPORT void JNICALL Java_com_phuket_tour_camera_preview_ChangbaRecordingPreviewScheduler_createWindowSurface
(JNIEnv * env, jobject obj, jobject surface) {
	if (surface != 0 && NULL != previewController) {
		ANativeWindow* window = ANativeWindow_fromSurface(env, surface);
		if (window != NULL) {
			previewController->createWindowSurface(window);
		}
	}
}

JNIEXPORT void JNICALL Java_com_phuket_tour_camera_preview_ChangbaRecordingPreviewScheduler_resetRenderSize
(JNIEnv * env, jobject obj, jint screenWidth, jint screenHeight) {
	if(NULL != previewController) {
		previewController->resetRenderSize(screenWidth, screenHeight);
	}
}

JNIEXPORT void JNICALL Java_com_phuket_tour_camera_preview_ChangbaRecordingPreviewScheduler_destroyWindowSurface
(JNIEnv * env, jobject obj) {
	if(NULL != previewController) {
		previewController->destroyWindowSurface();
	}
}

JNIEXPORT void JNICALL Java_com_phuket_tour_camera_preview_ChangbaRecordingPreviewScheduler_destroyEGLContext
(JNIEnv * env, jobject obj) {
	if(NULL != previewController) {
		previewController->destroyEGLContext();
		delete previewController;
		previewController = NULL;
	}
}

JNIEXPORT void JNICALL Java_com_phuket_tour_camera_preview_ChangbaRecordingPreviewScheduler_notifyFrameAvailable
(JNIEnv * env, jobject obj) {
	if(NULL != previewController) {
		previewController->notifyFrameAvailable();
	}
}
