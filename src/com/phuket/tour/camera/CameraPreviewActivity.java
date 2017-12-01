package com.phuket.tour.camera;

import com.phuket.tour.camera.preview.ChangbaRecordingPreviewScheduler;
import com.phuket.tour.camera.preview.ChangbaRecordingPreviewView;
import com.phuket.tour.camera.preview.ChangbaVideoCamera;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.Toast;

public class CameraPreviewActivity extends Activity {

	private RelativeLayout recordScreen;
	private ChangbaRecordingPreviewView surfaceView;
	private ChangbaVideoCamera videoCamera;
	private ChangbaRecordingPreviewScheduler previewScheduler;

	private ImageView switchCameraBtn;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_camera_preview);
		findView();
		bindListener();
		initCameraResource();
	}

	private void bindListener() {
		switchCameraBtn.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				previewScheduler.switchCameraFacing();
			}
		});
	}

	private void findView() {
		recordScreen = (RelativeLayout) findViewById(R.id.recordscreen);
		switchCameraBtn = (ImageView) findViewById(R.id.img_switch_camera);
		surfaceView = new ChangbaRecordingPreviewView(this);
		recordScreen.addView(surfaceView, 0);
		surfaceView.getLayoutParams().width = getWindowManager().getDefaultDisplay().getWidth();
		surfaceView.getLayoutParams().height = getWindowManager().getDefaultDisplay().getWidth();
	}

	private void initCameraResource() {
		videoCamera = new ChangbaVideoCamera(this);
		previewScheduler = new ChangbaRecordingPreviewScheduler(surfaceView, videoCamera) {
			public void onPermissionDismiss(final String tip) {
				mHandler.post(new Runnable() {
					@Override
					public void run() {
						Toast.makeText(CameraPreviewActivity.this, tip, Toast.LENGTH_SHORT).show();
					}
				});
			}
		};
	}

	private Handler mHandler = new Handler() {
		public void handleMessage(Message msg) {
		}
	};
}
