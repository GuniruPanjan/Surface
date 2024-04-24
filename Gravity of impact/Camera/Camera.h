#pragma once
#include "DxLib.h"
#include "Player/Player.h"
#include<cmath>

#define CAMERA_LOOK_AT_DISTANCE 200.0f;

class Camera
{
public:
	Camera();
	virtual ~Camera();

	//z軸を中心に回転する
	void rotate(float* x, float* y, const float angle, const float mx, const float my)
	{
		const float ox = *x - mx, oy = *y - my;
		*x = ox * cos(angle) + oy * sin(angle);
		*y = -ox * sin(angle) + oy * cos(angle);
		*x += mx;
		*y += my;
	};

	//360度回すには行列が必要

	void Init();
	void Update(Player& player);
	void Draw();
	void End();

	VECTOR cameraPos;

	//カメラの初期アングル
	float CameraHAngle, CameraVAngle;

	//カメラのアングル
	float cameraAngle;

};

