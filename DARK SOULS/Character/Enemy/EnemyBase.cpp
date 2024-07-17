#include "EnemyBase.h"

EnemyBase::EnemyBase():
	m_enemySearchFlag(false)
{
	//�G�̃X�s�[�h������
	m_speed = 2.0f;
	//�G�̃��f���ǂݍ���
	m_handle = MV1LoadModel("Data/Enemy/EnemyModel.mv1");
	//�I�u�W�F�N�g�̑傫����ς���ϐ�
	m_modelSize = 0.4f;

	//�G�̑傫���ύX
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));

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
	//3D���f���`��
	MV1DrawModel(m_handle);
}
