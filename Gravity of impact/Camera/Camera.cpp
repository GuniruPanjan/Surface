#include "Camera.h"


namespace
{
	constexpr float kCameraDist = 96;
	constexpr float kCameraHeight = 32;
}

Camera::Camera() :
	cameraAngle(0.0f)
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

	cameraPos = VGet(kCameraDist, kCameraHeight, kCameraDist);

	cameraAngle = 0.05f;
}

void Camera::Update(Player& player)
{

	SetCameraNearFar(1.0f, 180.0f);

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

	SetCameraPositionAndTarget_UpVecY(cameraPos, VGet(0, 0, 0));
}

void Camera::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "%f", cameraPos.x);
	DrawFormatString(0, 20, 0xffffff, "%f", cameraPos.y);
	DrawFormatString(0, 40, 0xffffff, "%f", cameraPos.z);


	for (int x = -50; x <= 50; x += 10)
	{
		DrawLine3D(VGet(static_cast<float>(x), 0, -50), VGet(static_cast<float>(x), 0, 50), 0xffff00);
	}
	for (int z = -50; z <= 50; z += 10)
	{
		DrawLine3D(VGet(-50, 0, static_cast<float>(z)), VGet(50, 0, static_cast<float>(z)), 0xff0000);
	}
}

void Camera::End()
{
}
