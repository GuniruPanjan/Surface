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
	CharacterBase():
		m_hp(0.0f),
		m_attack(0.0f),
		m_handle(-1),
		m_modelSize(0.0f),
		m_speed(0.0f),
		m_dead(false),
		m_posX(0.0f),
		m_posY(0.0f),
		m_posZ(0.0f),
		m_pos(VGet(m_posX,m_posY,m_posZ))
	{
		for (int i = 0; i < ANIMATION; i++)
		{
			m_animation[i] = -1;
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
	float m_speed;  //�L�����̃X�s�[�h
	bool m_dead;   //�L�����̎��S����
	float m_posX;  //�L������X���W
	float m_posY;  //�L������Y���W
	float m_posZ;  //�L������Z���W
	int m_animation[ANIMATION];  //�L�����̃A�j���[�V�����i�[�ϐ�
	VECTOR m_pos;  //�L�����̃|�W�V����
};

