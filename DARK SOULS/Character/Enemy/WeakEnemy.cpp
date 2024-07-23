#include "WeakEnemy.h"

WeakEnemy::WeakEnemy()
{
}

WeakEnemy::~WeakEnemy()
{
}

void WeakEnemy::Init()
{
	//�G��HP������
	m_hp = 200.0f;

	//�G�̃X�s�[�h������
	m_speed = 2.0f;

	m_posX = 0.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;

	m_pos = VGet(m_posX, m_posY, m_posZ);

	//�����蔻��
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_vec = Vec3(m_pos.x, m_pos.y + 2.0f, m_pos.z);
	m_len = 40.0f;
	m_capsuleRadius = 14.0f;
	m_capsuleCol.Init(m_colPos, m_vec, m_len, m_capsuleRadius);
}

void WeakEnemy::Update()
{
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);

	m_playTime += 0.5f;

	Animation(m_playTime);

	m_capsuleCol.Update(m_colPos, m_vec);
}

void WeakEnemy::Animation(float& time)
{
	//�Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (time >= m_totalAnimTime[0] && m_animation[0] != -1)
	{
		time = 0.0f;
	}

	//�Đ����Ԃ��Z�b�g����
	if (m_animation[0] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[0], time);
	}
}

void WeakEnemy::Draw()
{
	//�����x�N�g��
	Vec3 vec = m_vec.GetNormalized() * m_len * 0.5f;

	Pos3 pos1 = m_colPos + vec;
	Pos3 pos2 = m_colPos - vec;

	DrawCapsule3D(pos1.GetVector(), pos2.GetVector(), m_capsuleRadius, 16, m_color, 0, false);

	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//3D���f���`��
	MV1DrawModel(m_handle);

	DrawFormatString(0, 320, 0xffffff, "m_colposX : %f m_colposY : %f m_colposZ : %f", m_colPos.x, m_colPos.y, m_colPos.z);
}

void WeakEnemy::End()
{
}

bool WeakEnemy::isHit(const CapsuleCol& col)
{
	bool isHit = m_capsuleCol.IsHitCapsule(col);

	if (isHit)
	{
		m_color = 0xffff00;
	}
	else
	{
		m_color = 0xffffff;
	}

	return isHit;
}

bool WeakEnemy::isSphereHit(const SphereCol& col)
{
	bool isHit = m_capsuleCol.IsHitSphere(col);

	if (isHit)
	{
		m_color = 0xffff00;
	}
	else
	{
		m_color = 0xffffff;
	}

	return isHit;
}
