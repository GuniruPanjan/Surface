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

	//z���𒆐S�ɉ�]����
	void rotate(float* x, float* y, const float angle, const float mx, const float my)
	{
		const float ox = *x - mx, oy = *y - my;
		*x = ox * cos(angle) + oy * sin(angle);
		*y = -ox * sin(angle) + oy * cos(angle);
		*x += mx;
		*y += my;
	};

	//360�x�񂷂ɂ͍s�񂪕K�v

	void Init();
	void Update(Player& player);
	void Draw();
	void End();

	VECTOR cameraPos;

	//�J�����̏����A���O��
	float CameraHAngle, CameraVAngle;

	//�J�����̃A���O��
	float cameraAngle;

};

