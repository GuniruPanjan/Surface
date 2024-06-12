#pragma once
#include "EnemyBase.h"

class Enemy : public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void Update();
	void Draw();
	void End();

private:
	//�G�l�~�[�̃��[�V�����i�[�ϐ�
	int EnemyAnim[3];
	//���[�V�����̃g�[�^������
	float TotalTime[3];

	//�G�l�~�[�̃��[�V�����ǂݍ��ݕϐ�
	int EnemyWark;

	//�Đ�����
	float PlayTime;
};

