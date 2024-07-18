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
}

void WeakEnemy::Update()
{
	m_playTime += 0.5f;

	Animation(m_playTime);
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
	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//3D���f���`��
	MV1DrawModel(m_handle);
}

void WeakEnemy::End()
{
}
