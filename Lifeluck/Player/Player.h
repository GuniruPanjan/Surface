#pragma once
#include "PlayerBase.h"
#include "Col/CapsuleCol.h"
#include<memory>

class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();

	CapsuleCol GetCol() const { return m_col; }
	bool IsHit(const CapsuleCol& col);

	void End();

	void SetCameraAngle(float angle) { cameraAngle = angle; }

	//�J�������
	float cameraAngle;
	float angle;
	//Player�̃|�W�V�����ݒ�
	VECTOR PlayerPos = VGet(0.0f, 0.0f, 0.0f);
	//Player�̃A�j���[�V�����ǂݍ���
	int PlayerAnimRun, PlayerAnimWalking, PlayerAnimDying;
	//Player�̃A�j���[�V�����i�[�ϐ�
	int PlayerAnim[4];

	//�A�j���[�V�����̍Đ�����
	float PlayTime;

	//�A�j���[�V�����̑��Đ�����
	float TotalTime[4];

	//Player���������t���O
	bool PlayerMove;

	//Player�̃J�v�Z���^�̓����蔻��
	int HitCapsule;

	//Pad���͎擾
	int Pad;
private:
	Pos3 m_pos;
	Vec3 m_vec;
	float m_len;
	float m_radius;
	CapsuleCol m_col;

	unsigned int m_color = 0xffffff;
};

