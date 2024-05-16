#include "EnemyBase.h"

EnemyBase::EnemyBase():
	Speed(0.0f),
	KnockBack(0.0f),
	EnemyModel(0.0f),
	EnemyX(0.0f),
	EnemyY(0.0f),
	EnemyZ(0.0f)
{
}

EnemyBase::~EnemyBase()
{
	MV1DeleteModel(EnemyModel);
}

void EnemyBase::Init()
{
	//�G�̃X�s�[�h������
	Speed = 0.1f;
	//�G�̃m�b�N�o�b�N������
	KnockBack = 10.0f;
	//�G��3D���f���ǂݍ���
	EnemyModel = MV1LoadModel("data/Enemy.mv1");

}

void EnemyBase::Update()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(EnemyModel, pos);
}

void EnemyBase::Draw()
{
	//3D���f���`��
	MV1DrawModel(EnemyModel);
}

void EnemyBase::End()
{
}
