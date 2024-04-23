#pragma once
#include "DxLib.h"
#include "Player/Player.h"
#include<cmath>
class Camera
{
public:
	Camera();
	virtual ~Camera();

	void rotate(float* x, float* y, const float angle, const float mx, const float my)
	{
		const float ox = *x - mx, oy = *y - my;
		*x = ox * cos(angle) + oy * sin(angle);
		*y = -ox * sin(angle) + oy * cos(angle);
		*x += mx;
		*y += my;
	};

	//行列が必要

	void Init();
	void Update(Player& player);
	void Draw();
	void End();

	VECTOR cameraPos;

	//カメラのアングル
	float cameraAngle;

};

