#include "Camera.h"


namespace
{
	constexpr float kCameraDist = 96;
	constexpr float kCameraHeight = 32;
}

Camera::Camera() :
	cameraAngle(0.0f),
	CameraHAngle(0.0f),
	CameraVAngle(0.0f)
{
}

Camera::~Camera()
{
}

void Camera::Init()
{
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	cameraAngle = 0.05f;

	//基準となるカメラの座標
	cameraPos = VGet(kCameraDist, kCameraHeight, kCameraDist);

	SetCameraNearFar(1.0f, 500.0f);
}

void Camera::Update(Player& player)
{
	


	//左キー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT)
	{
		rotate(&cameraPos.x, &cameraPos.z, +cameraAngle, 0.0f, 0.0f);
	}
	//右キー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT)
	{
		rotate(&cameraPos.x, &cameraPos.z, -cameraAngle, 0.0f, 0.0f);
	}
	//上キー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP)
	{
		rotate(&cameraPos.y, &cameraPos.z, +cameraAngle, 0.0f, 0.0f);
	}
	//下キー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_DOWN)
	{
		rotate(&cameraPos.y, &cameraPos.z, -cameraAngle, 0.0f, 0.0f);
	}


	SetCameraPositionAndTarget_UpVecY(cameraPos, player.Playerpos);

	DrawFormatString(300, 0, 0xffffff, "%f", player.Playerpos.x);
	DrawFormatString(300, 20, 0xffffff, "%f", player.Playerpos.y);
	DrawFormatString(300, 40, 0xffffff, "%f", player.Playerpos.z);
}

void Camera::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "%f", cameraPos.x);
	DrawFormatString(0, 20, 0xffffff, "%f", cameraPos.y);
	DrawFormatString(0, 40, 0xffffff, "%f", cameraPos.z);

	

	//SetCameraPositionAndAngle(cameraPos, kCameraDist, kCameraHeight, kCameraDist);
	
}

void Camera::End()
{
}
