#pragma once
#include "DxLib.h"

/// <summary>
/// �G�l�~�[�̊��N���X
/// </summary>
class EnemyBase
{
public:
	EnemyBase() {}
	virtual ~EnemyBase() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

protected:
	//�G�l�~�[�̃��f���i�[�ϐ�
	int EnemyModel = -1;
	//�G�l�~�[�̃X�s�[�h�ݒ�
	float EnemySpeed = 0.0f;

	//�G�l�~�[�̃|�W�V�����ݒ�
	float EnemyX = 0.0f;
	float EnemyY = 0.0f;
	float EnemyZ = 0.0f;

	VECTOR EnemyPos = VGet(0.0f, 0.0f, 0.0f);
};


