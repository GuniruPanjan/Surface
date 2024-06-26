#pragma once
#include "PlayerBase.h"
#include "Col/CapsuleCol.h"
#include "Col/SphereCol.h"
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
	bool IsHitSearch(const SphereCol& col);

	void End();

	void SetCameraAngle(float angle) { cameraAngle = angle; }

	//�J�������
	float cameraAngle;
	float angle;
	//Player�̃|�W�V�����ݒ�
	VECTOR PlayerPos = VGet(0.0f, 0.0f, 0.0f);
	//Player�̃A�j���[�V�����ǂݍ���
	int PlayerAnimRun, PlayerAnimWalking, PlayerAnimDying, PlayerAnimCode;
	//Player�̃A�j���[�V�����i�[�ϐ�
	int PlayerAnim[5];

	//�A�j���[�V�����̍Đ�����
	float PlayTime;

	//�A�j���[�V�����̑��Đ�����
	float TotalTime[5];

	//Player���������t���O
	bool PlayerMove;

	//Pad���͎擾
	int Pad;

	
private:
	//�v���C���[�̈ړ�
	VECTOR move;

	//�}�V���̋߂��ɂ���ƃ}�V���̃G�l���M�[���[�ł��锻��
	bool m_playercan;
	//�}�V�����G�l���M�[��[���Ă���s��
	bool m_playercharging;

	//�����蔻��p�̃����o�ϐ�
	Pos3 m_pos;
	Vec3 m_vec;
	float m_len;
	float m_radius;
	CapsuleCol m_col;

	unsigned int m_color = 0xffffff;
};

