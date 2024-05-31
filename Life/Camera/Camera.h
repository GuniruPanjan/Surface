#pragma once
#include "DxLib.h"
#include "Player/Player.h"
#include <cmath>

class Camera
{
public:
	Camera();
	virtual ~Camera();

	void Init();
	void Update(Player& player);
	void Draw();
	void End();

	DINPUT_JOYSTATE input;

	//�J�����̃|�W�V����
	VECTOR cameraPos = VGet(0.0f, 0.0f, 0.0f);
	//�J�����̃^�[�Q�b�g
	VECTOR cameraTarget = VGet(0.0f, 0.0f, 0.0f);

	//�J�����̃A���O��
	VECTOR cameraAngle = VGet(0.0f, 0.0f, 0.0f);
};

