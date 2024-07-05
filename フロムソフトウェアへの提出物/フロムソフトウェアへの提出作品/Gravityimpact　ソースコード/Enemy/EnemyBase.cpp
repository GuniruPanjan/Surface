#include "EnemyBase.h"
// �d�͉����x
#define GravitationalAcceleration 9.80665 / 2

EnemyBase::EnemyBase() :
	EnemyX(0.0f),
	EnemyY(0.0f),
	EnemyZ(0.0f),
	EnemyMoveX(0.0f),
	EnemyMoveZ(0.0f),
	EnemyWidth(0.0f),
	Angle(0.0f),
	Enemyflag(false)
{
	//�G�̃X�s�[�h������
	Speed = 1.5f;
	//�G�̃m�b�N�o�b�N������
	KnockBack = 10.0f;

	//�I�u�W�F�N�g�̑傫����ς���ϐ�
	float Scale = 0.5f;

	//�G��3D���f���ǂݍ���
	EnemyModel = MV1LoadModel("data/Enemy.mv1");

	//�G�̑傫����ύX
	MV1SetScale(EnemyModel, VGet(Scale, Scale, Scale));
}

EnemyBase::~EnemyBase()
{
	//���������
	MV1DeleteModel(EnemyModel);
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