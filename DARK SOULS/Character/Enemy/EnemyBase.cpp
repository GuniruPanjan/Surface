#include "EnemyBase.h"

EnemyBase::EnemyBase():
	m_enemySearchFlag(false)
{
	//�G�̃A�j���[�V�����ǂݍ���


	//�G�̃��f���ǂݍ���
	m_handle = MV1LoadModel("Data/Enemy/EnemyModel.mv1");
}

EnemyBase::~EnemyBase()
{
	//���������
	MV1DeleteModel(m_handle);
}

void EnemyBase::Init()
{
}

void EnemyBase::Update()
{

}

void EnemyBase::Draw()
{
	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//3D���f���`��
	MV1DrawModel(m_handle);
}

void EnemyBase::End()
{
	//���������
	MV1DeleteModel(m_handle);
}
