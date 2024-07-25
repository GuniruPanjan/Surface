#include "Character/Player/Player.h"
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
	m_speed = 1.5f;

	m_posX = 0.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;

	m_pos = VGet(m_posX, m_posY, m_posZ);

	//�����蔻��
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_colDeathPos = Pos3(0.0f, -1000.0f, 0.0f);
	m_colSearchPos = Pos3(0.0f, m_pos.y + 35.0f, 0.0f);
	m_vec = Vec3(m_pos.x, m_pos.y + 2.0f, m_pos.z);
	m_deathVec = Vec3(0.0f, 0.0f, 0.0f);
	m_len = 40.0f;
	m_capsuleRadius = 14.0f;
	m_searchRadius = 100.0f;
	m_capsuleCol.Init(m_colPos, m_vec, m_len, m_capsuleRadius);
	m_colSearch.Init(m_colSearchPos, m_searchRadius);
}

void WeakEnemy::Update(Player& player)
{
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);

	m_playTime += 0.5f;

	//���G�Ŕ������ꂽ����
	if (m_enemySearchFlag == true)
	{
		float X = m_pos.x - player.GetPosX();
		float Z = m_pos.z - player.GetPosZ();

		m_angle = atan2f(X, Z);
	}

	//�G���ړ�����
	m_pos = VAdd(m_pos, m_move);

	Animation(m_playTime);

	//�G�����S������
	if (m_hp <= 0.0f)
	{
		DrawFormatString(0, 240, 0xffffff, "�G������");

		m_capsuleCol.Update(m_colDeathPos, m_deathVec);

		m_colSearch.Update(m_colDeathPos);
	}
	else
	{
		m_capsuleCol.Update(m_colPos, m_vec);

		//�Ƃ肠�����u���Ƃ�
		m_colSearch.Update(m_colSearchPos);
	}

	//���G�̓����蔻��𐳖ʂɎ����Ă���
	m_colSearchPos.x = m_pos.x + sinf(m_angle) * -80.0f;
	m_colSearchPos.z = m_pos.z - cosf(m_angle) * 80.0f;
	
}

void WeakEnemy::Animation(float& time)
{
	//�G���v���C���[�������ĂȂ��Ƃ�
	if (m_enemySearchFlag == false)
	{
		if (m_animation[3] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[3]);

			//�A�j���[�V�����A�^�b�`
			m_animation[0] = MV1AttachAnim(m_handle, 0, m_animStand, TRUE);

			time = 0.0f;

			m_animation[3] = -1;
		}
	}
	//�G���v���C���[����������(�Ր�Ԑ�)
	if (m_enemySearchFlag == true)
	{
		if (m_animation[0] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);

			//�A�j���[�V�����A�^�b�`
			m_animation[3] = MV1AttachAnim(m_handle, 0, m_animWalk, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
		}
	}

	//�G�����񂾂玀�ʃA�j���[�V����������
	if (m_hp <= 0.0f)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[3] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[3]);


			//�A�j���[�V�����A�^�b�`
			m_animation[2] = MV1AttachAnim(m_handle, 0, m_animDeath, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[3] = -1;

		}
	}

	//�Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (time >= m_totalAnimTime[0] && m_animation[0] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[2] && m_animation[2] != -1)
	{
		time = 120.0f;
	}
	if (time >= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		time = 0.0f;
	}

	//�Đ����Ԃ��Z�b�g����
	if (m_animation[0] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[0], time);
	}
	if (m_animation[2] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[2], time);
	}
	if (m_animation[3] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[3], time);
	}
}

void WeakEnemy::Draw()
{
	//�����x�N�g��
	Vec3 vec = m_vec.GetNormalized() * m_len * 0.5f;

	Pos3 pos1 = m_colPos + vec;
	Pos3 pos2 = m_colPos - vec;

	if (m_hp > 0.0f)
	{
		DrawCapsule3D(pos1.GetVector(), pos2.GetVector(), m_capsuleRadius, 16, m_color, 0, false);

		//���G�͈͉~��3D�`��
		DrawSphere3D(m_colSearchPos.GetVector(), m_searchRadius, 16, m_seachColor, m_seachColor, false);
	}

	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//3D���f���`��
	MV1DrawModel(m_handle);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	DrawFormatString(0, 320, 0xffffff, "m_colposX : %f m_colposY : %f m_colposZ : %f", m_colPos.x, m_colPos.y, m_colPos.z);
	DrawFormatString(0, 220, 0xffffff, "m_EnemyHp : %f", m_hp);

	if (m_enemySearchFlag == true)
	{
		DrawFormatString(0, 250, 0xffffff, "�������ꂽ");
	}
}

void WeakEnemy::End()
{
}

bool WeakEnemy::isSphereHit(const SphereCol& col, float damage)
{
	bool isHit = m_capsuleCol.IsHitSphere(col);

	//�_���[�W���󂯂�����
	if (isHit)
	{
		m_color = 0xffff00;

		//�_���[�W����񂾂��^����
		if (m_damageReceived == false)
		{
			m_hp = m_hp - damage;

			m_damageReceived = true;
		}
		
	}
	else
	{
		m_damageReceived = false;

		m_color = 0xffffff;
	}

	return isHit;
}

bool WeakEnemy::isSeachHit(const CapsuleCol& col)
{
	bool isHit = m_colSearch.IsHitCapsule(col);

	//�v���C���[������������
	if (isHit)
	{
		m_seachColor = 0xffff00;

		m_enemySearchFlag = true;
	}
	else
	{
		m_seachColor = 0xffffff;

		m_enemySearchFlag = false;
	}

	return isHit;
}
