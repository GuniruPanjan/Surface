#include "Enemy.h"

WeakEnemy::WeakEnemy()
{
	for (int i = 0; i < ENEMY_NOW; ++i)
	{
		enemy[i] = ;
	}
}

WeakEnemy::~WeakEnemy()
{
}

void WeakEnemy::Init()
{
	//�G���G�l�~�[��HP�̏�����
	m_hp = 200.0f;

	//�G�̃X�s�[�h������
	m_speed = 2.0f;

	//�I�u�W�F�N�g�̑傫����ς���ϐ�
	m_modelSize = 0.4f;

	//�G�̑傫���ύX
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));
}

void WeakEnemy::Update()
{
}

void WeakEnemy::Draw()
{
}

void WeakEnemy::End()
{
}
