#pragma once
#include "DxLib.h"
#include<memory>
//���������̃A�j���[�V����
#define  ANIMATION   30

/// <summary>
/// �L�����N�^�[�̊��N���X
/// </summary>
class CharacterBase
{
public:
	CharacterBase() :
		m_hp(0.0f),
		m_attack(0.0f),
		m_handle(-1),
		m_modelSize(0.0f),
		m_angle(0.0f),
		m_speed(0.0f),
		m_dead(false),
		m_posX(0.0f),
		m_posY(0.0f),
		m_posZ(0.0f),
		m_moveflag(false),
		m_moveAttack(false),
		m_moveAttackEnd(true),
		m_attackNumber(0),
		m_playerTime(0.0f),
		m_animStand(-1),
		m_animWalk(-1),
		m_animRun(-1),
		m_animRoll(-1),
		m_animAttack1(-1),
		m_animAttack2(-1),
		m_animAttack3(-1),
		m_move(VGet(0.0f, 0.0f, 0.0f)),
		m_pos(VGet(m_posX, m_posY, m_posZ)),
		m_drawPos(VGet(0.0f, 0.0f, 0.0f)),
		m_prevPos(VGet(0.0f, 0.0f, 0.0f)),
		m_nowPos(VGet(0.0f, 0.0f, 0.0f)),
		m_moveVector(VGet(0.0f, 0.0f, 0.0f))
	{
		for (int i = 0; i < ANIMATION; i++)
		{
			m_animation[i] = -1;
			m_totalAnimTime[i] = 0.0f;
		}
	
	}

	virtual ~CharacterBase(){}

	//virtual�Ōp������Ăяo��

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

protected:
	float m_hp;  //�L������HP
	float m_attack;  //�L�����̍U����
	int m_handle;  //�L�����̃��f���n���h��
	float m_modelSize;  //�L�����̃��f���T�C�Y
	float m_angle;  //�L�����̃A���O��
	float m_speed;  //�L�����̃X�s�[�h
	bool m_dead;   //�L�����̎��S����
	float m_posX;  //�L������X���W
	float m_posY;  //�L������Y���W
	float m_posZ;  //�L������Z���W
	bool m_moveflag;  //�L�����������������f����t���O
	bool m_moveAttack;  //�L�������U���������ǂ������f����t���O
	bool m_moveAttackEnd;  //�L�����̍U�����I���������ǂ������f����t���O
	int m_attackNumber;   //�L�����̍U�������i�K�ڂ����f����ϐ�
	float m_playerTime;  //�L�����̃A�j���[�V������i�߂鎞��
	int m_animStand;  //�L�����̌o���Ă���A�j���[�V�����i�[�ϐ�
	int m_animWalk;   //�L�����̕����A�j���[�V�����i�[�ϐ�
	int m_animRun;    //�L�����̑���A�j���[�V�����i�[�ϐ�
	int m_animRoll;   //�L�����̃��[�f�B���O�A�j���[�V�����i�[�ϐ�
	int m_animAttack1;   //�L�����̍U���A�j���[�V�����i�[�ϐ�
	int m_animAttack2;   //�L�����̍U���A�j���[�V�����i�[�ϐ�
	int m_animAttack3;   //�L�����̍U���A�j���[�V�����i�[�ϐ�
	int m_animation[ANIMATION];  //�L�����̃A�j���[�V�����i�[�ϐ�
	float m_totalAnimTime[ANIMATION];  //�L�����̃A�j���[�V�����Đ�����
	VECTOR m_move;  //�L�����̈ړ�
	VECTOR m_pos;  //�L�����̃|�W�V����
	VECTOR m_drawPos;   //�L�����̃��f����`�悷��|�W�V����
	VECTOR m_prevPos;  //�L�����̃A�j���[�V�����ňړ����Ă���t���[���̍��W�擾
	VECTOR m_nowPos;  //�L�����̃A�j���[�V������̍��W���擾����
	VECTOR m_moveVector;  //�L�����̃A�j���[�V�����ł̍��W�ړ��l������
};

