#include "SceneGame.h"
#include "DxLib.h"
#include <cmath>

namespace
{
	constexpr float kCameraDist = 96;
	constexpr float kCameraHeight = 32;
}

SceneGame::SceneGame():
	cameraAngle(0.0f)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	cameraAngle = -DX_PI_F / 2;
}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	if ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT))
	{
		cameraAngle += 0.05f;
	}
	if ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT))
	{
		cameraAngle -= 0.05f;
	}


	SetCameraNearFar(1.0f, 180.0f);
	VECTOR cameraPos;
	cameraPos.x = cosf(cameraAngle) * kCameraDist;
	cameraPos.y = kCameraHeight;
	cameraPos.z = sinf(cameraAngle) * kCameraDist;
	SetCameraPositionAndTarget_UpVecY(cameraPos, VGet(0, 0, 0));

	for (int x = -50; x <= 50; x += 10)
	{
		DrawLine3D(VGet(static_cast<float>(x), 0, -50), VGet(static_cast<float>(x), 0, 50), 0xffff00);
	}
	for (int z = -50; z <= 50; z += 10)
	{
		DrawLine3D(VGet(-50, 0, static_cast<float>(z)), VGet(50, 0, static_cast<float>(z)), 0xff0000);
	}



	return std::shared_ptr<SceneGame>();
}

void SceneGame::Draw()
{
}

void SceneGame::End()
{
}
