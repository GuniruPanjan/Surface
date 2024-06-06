#include "Enemy/EnemyNormal.h"

EnemyNormal::EnemyNormal():
	PlayTime(0.0f)
{
	for (int i = 0; i < 3; i++)
	{
		EnemyAnim[i] = 0;
		TotalTime[i] = 0;
	}
}

EnemyNormal::~EnemyNormal()
{
}

void EnemyNormal::Init()
{
	EnemyX = 200.0f;
	EnemyY = 0.0f;
	EnemyZ = 0.0f;

	//���f���ǂݍ���
	EnemyModel = MV1LoadModel("EnemyData/EnemyModel.mv1");

	EnemyAnim[0] = MV1AttachAnim(EnemyModel, 0, EnemyModel, TRUE);

	//�G�l�~�[�̑傫����ς���
	MV1SetScale(EnemyModel, VGet(0.45f, 0.45f, 0.45f));

	//�A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	TotalTime[0] = MV1GetAttachAnimTotalTime(EnemyModel, EnemyAnim[0]);

	EnemyPos = VGet(EnemyX, EnemyY, EnemyZ);
}

void EnemyNormal::Update()
{

	//�A�j���[�V�������Đ�����
	PlayTime += 0.5f;

	//�Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (PlayTime >= TotalTime[0] && EnemyAnim[0] != -1)
	{
		PlayTime = 0.0f;
	}

	if (EnemyAnim[0] != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(EnemyModel, EnemyAnim[0], PlayTime);
	}

}

void EnemyNormal::Draw()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(EnemyModel, EnemyPos);

	//3D���f���`��
	MV1DrawModel(EnemyModel);
}

void EnemyNormal::End()
{
	//���������
	MV1DeleteModel(EnemyModel);
}
