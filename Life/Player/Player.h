#pragma once
#include "PlayerBase.h"
class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();
	void End();

	void SetCameraAngle(float angle) { cameraAngle = angle; }

	//�J�������
	float cameraAngle;
	float angle;
	//Player�̃|�W�V�����ݒ�
	VECTOR PlayerPos = VGet(0.0f, 0.0f, 0.0f);
	//Player�̃A�j���[�V�����ǂݍ���
	int PlayerAnimStanding, PlayerAnimRun, PlayerAnimWalking, PlayerAnimDying;
	//Player�̃A�j���[�V�����i�[�ϐ�
	int PlayerAnim[4];
	int PlayerAnim1, PlayerAnim2, PlayerAnim3, PlayerAnim4;

	//�A�j���[�V�����̍Đ�����
	float PlayTime;

	//�A�j���[�V�����̑��Đ�����
	float TotalTime[4];
	float TotalTime1, TotalTime2, TotalTime3, TotalTime4;

	//Player���������t���O
	bool PlayerMove;

};

