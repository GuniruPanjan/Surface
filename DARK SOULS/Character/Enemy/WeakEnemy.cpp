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

	//�G�̍U���͏�����
	m_attack = 10.0f;

	//�G�̃X�s�[�h������
	m_speed = 0.01f;

	m_posX = 500.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;

	m_pos = VGet(m_posX, m_posY, m_posZ);

	//��񂾂�������
	if (m_oneInit == false)
	{
		//�����蔻��
		m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
		m_colDeathPos = Pos3(0.0f, -1000.0f, 0.0f);
		m_colSearchPos = Pos3(0.0f, m_pos.y + 35.0f, 0.0f);
		m_colDistancePos = Pos3(m_pos.x, m_pos.y + 35.0f, m_pos.z);
		m_colAttackPos = Pos3(m_pos.x - 50.0f, m_pos.y + 35.0f, m_pos.z);
		m_initializationPos = Pos3(0.0f, -1000.0f, 0.0f);
		m_vec = Vec3(0.0f, m_pos.y + 2.0f, 0.0f);
		m_deathVec = Vec3(0.0f, 0.0f, 0.0f);
		m_len = 40.0f;
		m_capsuleRadius = 14.0f;
		m_searchRadius = 120.0f;
		m_distanceRadius = 80.0f;
		m_attackRadius = 18.0f;
		m_capsuleCol.Init(m_colPos, m_vec, m_len, m_capsuleRadius);
		m_colSearch.Init(m_colSearchPos, m_searchRadius);
		m_colDistance.Init(m_colDistancePos, m_distanceRadius);
		m_colAttack.Init(m_colAttackPos, m_attackRadius);

		m_oneInit = true;
	}
	
}

void WeakEnemy::Update(Player& player)
{
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_colDistancePos = Pos3(m_pos.x, m_pos.y + 35.0f, m_pos.z);

	m_playTime += 0.5f;

	//���G�Ŕ������ꂽ����&�G���U�����ĂȂ���
	if (m_enemySearchFlag == true && m_moveAttack == false)
	{
		float X = m_pos.x - player.GetPosX();
		float Z = m_pos.z - player.GetPosZ();

		//�v���C���[�̕�������
		m_angle = atan2f(X, Z);

		//�@���x�N�g��
		m_moveTurning = atan2f(-X, Z);
		m_moveReverseTurning = atan2f(X, -Z);
	}

	Action(player);

	//�U�����ĂȂ��Ȃ�
	if (m_moveAttack == false)
	{
		//�G���ړ�����
		m_pos = VAdd(m_pos, m_move);
	}
	

	//�U������𐳖ʂɎ����Ă���
	m_colAttackPos.x = m_pos.x + sinf(m_angle) * -25.0f;
	m_colAttackPos.z = m_pos.z - cosf(m_angle) * 25.0f;

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
		m_colDistance.Update(m_colDistancePos);
	}

	//���G�̓����蔻��𐳖ʂɎ����Ă���
	m_colSearchPos.x = m_pos.x + sinf(m_angle) * -80.0f;
	m_colSearchPos.z = m_pos.z - cosf(m_angle) * 80.0f;
	
}

/// <summary>
/// �v���C���[�ւ̍U����ԍ����̎����Ȃǂ��܂Ƃ߂�֐�
/// </summary>
/// <param name="player"></param>
void WeakEnemy::Action(Player& player)
{
	//�G�ɔ������ꂽ�ꍇ
	if (m_enemySearchFlag == true)
	{
		//�v���C���[�ƓG�̑��΋������Z�o
		VECTOR tracking = VSub(player.GetPos(), m_pos);

		//�p�x���o���v���C���[�̎�������^��������
		MATRIX mtx = MGetRotY(D2R(m_moveTurning) + DX_PI_F / 2);
		MATRIX mtxR = MGetRotY(D2R(m_moveReverseTurning) - DX_PI_F / 2);

		if (m_enemyWait == false)
		{
			m_speed = 0.01f;

			m_move = VScale(tracking, m_speed);
		}
		//�G���߂��ɂ������̏���
		else
		{
			m_move = VNorm(tracking);

			m_speed = 0.3f;

			m_move = VScale(m_move, m_speed);

			//�����_����0���o���獶����
			if (m_randomAction == 0)
			{
				m_move = VTransform(m_move, mtx);

				m_moveAttack = false;
			}
			//�����_����1���o����E����
			if (m_randomAction == 1)
			{
				m_move = VTransform(m_move, mtxR);

				m_moveAttack = false;
			}
			//�����_����2���o����U��
			if (m_randomAction == 2)
			{
				//�A�j���[�V�����t���[�����ɍU�����������
				if (m_playTime >= 22 && m_playTime <= 35)
				{
					m_colAttack.Update(m_colAttackPos);
				}
				else
				{
					m_colAttack.Update(m_initializationPos);
				}

				m_moveAttack = true;
			}
			if (m_randomAction != 0 && m_randomAction != 1 && m_randomAction != 2)
			{
				m_moveAttack = false;
			}
			
		}
		
	}
	//�G�ɔ�������ĂȂ��Ƃ�
	else
	{
		//�G�������Ȃ��悤�ɂ���
		m_move = VGet(0.0f, 0.0f, 0.0f);
	}
	
	m_randomNextActionTime += 0.1f;

	if (m_randomNextActionTime >= 50.0f)
	{
		m_randomAction = GetRand(2);

		m_randomNextActionTime = 0.0f;
	}

}

void WeakEnemy::Animation(float& time)
{
	//�G���v���C���[�������ĂȂ��Ƃ�
	if (m_enemySearchFlag == false)
	{
		if (m_animation[3] != -1 || m_animation[4] != -1 || m_animation[5] != -1 ||
			m_animation[6] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);


			//�A�j���[�V�����A�^�b�`
			m_animation[0] = MV1AttachAnim(m_handle, 0, m_animStand, TRUE);

			time = 0.0f;

			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;

		}
	}
	//�G���v���C���[����������(�Ր�Ԑ�)
	if (m_enemySearchFlag == true && m_enemyWait == false)
	{
		if (m_animation[0] != -1 || m_animation[4] != -1 || m_animation[5] != -1 ||
			m_animation[6] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);


			//�A�j���[�V�����A�^�b�`
			m_animation[3] = MV1AttachAnim(m_handle, 0, m_animWalk, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;

		}
	}
	//�G�̎˒������ɓ������Ƃ�
	//������
	if (m_randomAction == 0 && m_enemyWait == true)
	{
		if (m_animation[0] != -1 || m_animation[3] != -1 || m_animation[5] != -1 ||
			m_animation[6] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);

			//�A�j���[�V�����A�^�b�`
			m_animation[4] = MV1AttachAnim(m_handle, 0, m_animLeftWalking, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[3] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;

		}
	}
	//�E����
	if (m_randomAction == 1 && m_enemyWait == true)
	{
		if (m_animation[0] != -1 || m_animation[3] != -1 || m_animation[4] != -1 ||
			m_animation[6] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[6]);

			//�A�j���[�V�����A�^�b�`
			m_animation[5] = MV1AttachAnim(m_handle, 0, m_animRightWalking, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[6] = -1;

		}
	}
	//�U�����[�V����
	if (m_randomAction == 2 && m_enemyWait == true)
	{
		if (m_animation[0] != -1 || m_animation[3] != -1 || m_animation[4] != -1 ||
			m_animation[5] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);

			//�A�j���[�V�����A�^�b�`
			m_animation[6] = MV1AttachAnim(m_handle, 0, m_animAttack1, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
		}
	}

	//�G�����񂾂玀�ʃA�j���[�V����������
	if (m_hp <= 0.0f)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[3] != -1 ||
			m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);

			//�A�j���[�V�����A�^�b�`
			m_animation[2] = MV1AttachAnim(m_handle, 0, m_animDeath, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;

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
	if (time >= m_totalAnimTime[4] && m_animation[4] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[5] && m_animation[5] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[6] && m_animation[6] != -1)
	{
		m_randomNextActionTime = 50.0f;

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
	if (m_animation[4] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[4], time);
	}
	if (m_animation[5] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[5], time);
	}
	if (m_animation[6] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[6], time);
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

		//��苗���͈͕̔`��
		DrawSphere3D(m_colDistancePos.GetVector(), m_distanceRadius, 16, m_distanceColor, m_distanceColor, false);

		//�U������`��
		DrawSphere3D(m_colAttackPos.GetVector(), m_attackRadius, 16, 0xffffff, 0xffffff, false);
	}

	//3D���f���|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//3D���f���`��
	MV1DrawModel(m_handle);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	//DrawFormatString(0, 320, 0xffffff, "m_colposX : %f m_colposY : %f m_colposZ : %f", m_colPos.x, m_colPos.y, m_colPos.z);
	//DrawFormatString(0, 220, 0xffffff, "m_EnemyHp : %f", m_hp);
	//DrawFormatString(0, 180, 0xffffff, "m_randomTime : %f", m_randomNextActionTime);
	//DrawFormatString(0, 160, 0xffffff, "m_randomAction : %f", m_randomAction);
	//DrawFormatString(0, 140, 0xffffff, "m_playTime : %f", m_playTime);

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

bool WeakEnemy::isDistanceHit(const CapsuleCol& col)
{
	bool isHit = m_colDistance.IsHitCapsule(col);

	//���͈͓��Ƀv���C���[����������
	if (isHit)
	{
		m_distanceColor = 0xffff00;

		m_enemyWait = true;
	}
	else
	{
		m_distanceColor = 0xffffff;

		m_enemyWait = false; 
	}

	return isHit;
}
