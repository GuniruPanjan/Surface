#pragma once
#include "DxLib.h"

/// <summary>
/// �v���C���[�̊��N���X
/// </summary>
class PlayerBase
{
public:
	PlayerBase() {}
	virtual ~PlayerBase() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//�v���C���[�̗̑�
	int PlayerHp = 0;
	//�v���C���[�̃��f���i�[�ϐ�
	int PlayerModel = 0;
	//�v���C���[�̃X�s�[�h�ݒ�
	float PlayerSpeed = 0;
	//�v���C���[�̎��S�t���O
	bool PlayerDead = false;
	//�v���C���[�̃}�V���ɗ^����G�l���M�[��
	float PlayerGiveEnergy = 0.0f;

	//�v���C���[�̃|�W�V�����ݒ�
	float PlayerX = 0.0f;
	float PlayerY = 0.0f;
	float PlayerZ = 0.0f;
};
