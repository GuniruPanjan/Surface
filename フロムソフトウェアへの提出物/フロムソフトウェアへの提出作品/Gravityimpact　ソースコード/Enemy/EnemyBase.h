#pragma once
#include "DxLib.h"
#include "Player/Player.h"
#include "Rect.h"
#include<memory>

class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtual�Ōp������Ăяo��
	virtual void Update();
	virtual void Draw();

	//���f���n���h���̎擾
	int GetModelHandle() { return EnemyModel; }

	//�|�W�V������getter/setter
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	//�G�̃X�s�[�h
	float Speed;

	//�G�̃m�b�N�o�b�N�З�
	float KnockBack;

	//�G�̓����蕝
	float EnemyWidth;

	//�G�̈ړ��x�N�g��
	float EnemyMoveX, EnemyMoveZ;

	//�G�̍��G�s���t���O
	bool Enemyflag;

	//�G��3D���f���i�[�p�ϐ�
	int EnemyModel;

	//�G�̓����蔻���`
	Rect m_colRect;

	//�G�̍��W
	float EnemyX, EnemyY, EnemyZ;

	//�p�x���擾
	float Angle;

	//�G�̍��W�Ǝ��@�̃x�N�g�����Z�o
	VECTOR SubVector = VGet(0.0f, 0.0f, 0.0f);

	//�G�̃|�W�V����
	VECTOR pos = VGet(0.0f, 0.0f, 0.0f);

};

