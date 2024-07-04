#include "Enemy/Enemy.h"

Enemy::Enemy() :
	PlayTime(0.0f),
	EnemyWark(-1)
{
	for (int i = 0; i < 3; i++)
	{
		EnemyAnim[i] = 0;
		TotalTime[i] = 0;
	}
}

Enemy::~Enemy()
{
	//���������
	MV1DeleteModel(EnemyModel);
	MV1DeleteModel(EnemyWark);
}

void Enemy::Init()
{
	EnemyX = 200.0f;
	EnemyY = 0.0f;
	EnemyZ = 0.0f;

	//���f���ǂݍ���
	EnemyModel = MV1LoadModel("EnemyData/EnemyModel.mv1");
	EnemyWark = MV1LoadModel("EnemyData/EnemyWalking.mv1");

	EnemyAnim[0] = MV1AttachAnim(EnemyModel, 0, EnemyModel, TRUE);
	EnemyAnim[1] = MV1AttachAnim(EnemyModel, 0, EnemyWark, TRUE);

	//�G�l�~�[�̑傫����ς���
	MV1SetScale(EnemyModel, VGet(0.45f, 0.45f, 0.45f));

	//�A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	TotalTime[0] = MV1GetAttachAnimTotalTime(EnemyModel, EnemyAnim[0]);
	TotalTime[1] = MV1GetAttachAnimTotalTime(EnemyModel, EnemyAnim[1]);

	//��U�ҋ@�ȊO�̃A�j���[�V�������f�^�b�`����
	MV1DetachAnim(EnemyModel, EnemyAnim[0]);

	EnemyPos = VGet(EnemyX, EnemyY, EnemyZ);

	m_pos = Pos3(EnemyPos.x + 4.0f, EnemyPos.y + 45.0f, EnemyPos.z);
	m_vec = Vec3(0.0f, 2.0f, 0.0f);
	m_size = Size(300.0f, 100.0f, 300.0f);
	m_len = 40.0f;
	m_radius = 25.0f;
	m_rect.Init(m_pos, m_size);
	m_col.Init(m_pos, m_vec, m_len, m_radius);
}

void Enemy::Update()
{
	m_pos = Pos3(EnemyPos.x + 4.0f, EnemyPos.y + 45.0f, EnemyPos.z);

	//�A�j���[�V�������Đ�����
	PlayTime += 0.5f;

	//�Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (PlayTime >= TotalTime[1] && EnemyAnim[1] != -1)
	{
		PlayTime = 0.0f;
	}

	if (EnemyAnim[1] != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(EnemyModel, EnemyAnim[1], PlayTime);
	}

	m_col.Update(m_pos, m_vec);
}

void Enemy::Draw()
{
	//�����x�N�g��
	Vec3 Vec = m_vec.GetNormalized() * m_len * 0.5f;

	Pos3 pos1 = m_pos + Vec;
	Pos3 pos2 = m_pos - Vec;

	DrawCapsule3D(pos1.GetVector(), pos2.GetVector(), m_radius, 16, m_color, 0, false);

	float halfW = m_size.width * 0.5f;
	float halfH = m_size.height * 0.5f;
	float halfD = m_size.depth * 0.5f;

	float right = m_pos.x + halfW;
	float left = m_pos.x - halfW;
	float top = m_pos.y + halfH;
	float bottom = m_pos.y - halfH;
	float front = m_pos.z - halfD;
	float back = m_pos.z + halfD;

#if true
	// ���̐�
	DrawLine3D(VGet(left, bottom, front), VGet(right, bottom, front), m_color);
	DrawLine3D(VGet(left, top, front), VGet(right, top, front), m_color);
	DrawLine3D(VGet(left, bottom, back), VGet(right, bottom, back), m_color);
	DrawLine3D(VGet(left, top, back), VGet(right, top, back), m_color);
	// �c�̐�
	DrawLine3D(VGet(left, top, front), VGet(left, bottom, front), m_color);
	DrawLine3D(VGet(right, top, front), VGet(right, bottom, front), m_color);
	DrawLine3D(VGet(left, top, back), VGet(left, bottom, back), m_color);
	DrawLine3D(VGet(right, top, back), VGet(right, bottom, back), m_color);
	// �O��̐�
	DrawLine3D(VGet(left, top, front), VGet(left, top, back), m_color);
	DrawLine3D(VGet(left, bottom, front), VGet(left, bottom, back), m_color);
	DrawLine3D(VGet(right, top, front), VGet(right, top, back), m_color);
	DrawLine3D(VGet(right, bottom, front), VGet(right, bottom, back), m_color);

#else
	DrawCube3D(VGet(left, top, back), VGet(right, bottom, front), m_color, 0, false);
#endif

	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(EnemyModel, EnemyPos);

	//3D���f���`��
	MV1DrawModel(EnemyModel);
}

bool Enemy::IsHit(const CapsuleCol& col)
{
	bool isHit = m_col.IsHitCapsule(col);

	if (isHit)
	{
		m_color = 0xffff00;
	}
	else
	{
		m_color = 0xffffff;
	}

	return false;
}

void Enemy::End()
{
	//���������
	MV1DeleteModel(EnemyModel);
	MV1DeleteModel(EnemyWark);
}
