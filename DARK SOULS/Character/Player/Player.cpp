#include "Player.h"
#include "Map/Map.h"
#include<math.h>

Player::Player():
	m_cameraAngle(0.0f),
	m_updatePosX(485.0f),
	m_updatePosY(0.0f),
	m_updatePosZ(-800.0f),
	m_stamina(0.0f),
	m_lockonTarget(false),
	m_moveAnimFrameIndex(0),
	m_moveAnimShieldFrameIndex(0),
	m_a(0),
	m_pad(0),
	m_animRollAttack(-1),
	m_avoidance(false),
	m_nextAttack1(false),
	m_nextAttack2(false),
	m_pushButton(false),
	m_avoidanceNow(false),
	m_restAction(false),
	m_dashMove(false),
	m_staminaBroke(false),
	m_nowPos(VGet(0.0f,0.0f,0.0f)),
	m_bounceMove(VGet(0.0f,0.0f,0.0f)),
	m_hpLevel(0),
	m_staminaLevel(0),
	m_animHeel(0),
	m_recoveryNumber(0),
	m_recoberyAmount(0.0f),
	m_heel(0.0f),
	m_recoberyAction(false)
{
}

Player::~Player()
{
	//���������
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animWalk);
	MV1DeleteModel(m_animRun);
	MV1DeleteModel(m_animRoll);
	MV1DeleteModel(m_animAttack1);
	MV1DeleteModel(m_animAttack2);
	MV1DeleteModel(m_animAttack3);
	MV1DeleteModel(m_animDeath);
	MV1DeleteModel(m_animHeel);

}

void Player::Init()
{
	//�v���C���[HP�̏�����
	m_hp = 150.0f;

	//�v���C���[�̃X�^�~�i������
	m_stamina = 100.0f;

	//�v���C���[�X�s�[�h������
	m_speed = 2.0f;

	//�v���C���[�������o������
	m_bounceDis = 3.0f;

	//�v���C���[�̍U���͏�����
	m_attack = 10.0f;

	//�񕜊֌W�̏�����
	m_recoberyAmount = 100.0f;
	m_heel = 0.0f;
	m_recoveryNumber = 5;
	m_recoberyAction = false;

	//��񂾂�������
	if (m_oneInit == false)
	{
		//���x��������
		m_hpLevel = 1;
		m_staminaLevel = 1;

		m_modelSize = 0.4f;

		//�v���C���[�����f���ǂݍ���
		m_handle = MV1LoadModel("Data/Player/PlayerModel.mv1");

		//�v���C���[�̑傫����ς���
		MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));

		//�v���C���[�̃A�j���[�V�����ǂݍ���
		m_animStand = MV1LoadModel("Data/PlayerAnimation/PlayerAnimStand.mv1");
		m_animWalk = MV1LoadModel("Data/PlayerAnimation/PlayerAnimWalk.mv1");
		m_animRun = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRun.mv1");
		m_animRoll = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRoll.mv1");
		m_animAttack1 = MV1LoadModel("Data/PlayerAnimation/PlayerAnimAttack1.mv1");
		m_animAttack2 = MV1LoadModel("Data/PlayerAnimation/PlayerAnimAttack2.mv1");
		m_animAttack3 = MV1LoadModel("Data/PlayerAnimation/PlayerAnimAttack3.mv1");
		m_animRollAttack = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRollAttack.mv1");
		m_animDeath = MV1LoadModel("Data/PlayerAnimation/PlayerAnimDeath.mv1");
		m_animHeel = MV1LoadModel("Data/PlayerAnimation/PlayerAnimRecovery.mv1");

		//�A�j���[�V�����A�^�b�`
		m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);
		m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);
		m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);
		m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);
		m_animation[4] = MV1AttachAnim(m_handle, 1, m_animAttack1, TRUE);
		m_animation[5] = MV1AttachAnim(m_handle, 1, m_animAttack2, TRUE);
		m_animation[6] = MV1AttachAnim(m_handle, 1, m_animAttack3, TRUE);
		m_animation[7] = MV1AttachAnim(m_handle, 1, m_animRollAttack, TRUE);
		m_animation[8] = MV1AttachAnim(m_handle, 1, m_animDeath, TRUE);
		m_animation[9] = MV1AttachAnim(m_handle, 1, m_animHeel, TRUE);

		//�A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
		m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);
		m_totalAnimTime[1] = MV1GetAttachAnimTotalTime(m_handle, m_animation[1]);
		m_totalAnimTime[2] = MV1GetAttachAnimTotalTime(m_handle, m_animation[2]);
		m_totalAnimTime[3] = MV1GetAttachAnimTotalTime(m_handle, m_animation[3]);
		m_totalAnimTime[4] = MV1GetAttachAnimTotalTime(m_handle, m_animation[4]);
		m_totalAnimTime[5] = MV1GetAttachAnimTotalTime(m_handle, m_animation[5]);
		m_totalAnimTime[6] = MV1GetAttachAnimTotalTime(m_handle, m_animation[6]);
		m_totalAnimTime[7] = MV1GetAttachAnimTotalTime(m_handle, m_animation[7]);
		m_totalAnimTime[8] = MV1GetAttachAnimTotalTime(m_handle, m_animation[8]);
		m_totalAnimTime[9] = MV1GetAttachAnimTotalTime(m_handle, m_animation[9]);


		//��U�ҋ@�ȊO�̃A�j���[�V�����f�^�b�`
		MV1DetachAnim(m_handle, m_animation[1]);
		MV1DetachAnim(m_handle, m_animation[2]);
		MV1DetachAnim(m_handle, m_animation[3]);
		MV1DetachAnim(m_handle, m_animation[4]);
		MV1DetachAnim(m_handle, m_animation[5]);
		MV1DetachAnim(m_handle, m_animation[6]);
		MV1DetachAnim(m_handle, m_animation[7]);
		MV1DetachAnim(m_handle, m_animation[8]);
		MV1DetachAnim(m_handle, m_animation[9]);
		m_animation[1] = -1;
		m_animation[2] = -1;
		m_animation[3] = -1;
		m_animation[4] = -1;
		m_animation[5] = -1;
		m_animation[6] = -1;
		m_animation[7] = -1;
		m_animation[8] = -1;
		m_animation[9] = -1;

		m_oneInit = true;
	}

	m_playTime = 0.0f;

	//�����蔻��
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_colAttackPos = Pos3(m_pos.x - 50.0f, m_pos.y + 35.0f, m_pos.z);
	m_initializationPos = Pos3(0.0f, -1000.0f, 0.0f);
	m_vec = Vec3(0.0f, m_vec.y + 2.0f, 0.0f);
	m_len = 40.0f;
	m_capsuleRadius = 12.0f;
	m_sphereRadius = 18.0f;
	m_capsuleCol.Init(m_colPos, m_vec, m_len, m_capsuleRadius);
	m_sphereCol.Init(m_colAttackPos, m_sphereRadius);
	

	m_posX = m_updatePosX;
	m_posY = m_updatePosY;
	m_posZ = m_updatePosZ;

	//�v���C���[�̃|�W�V�����ݒ�
	m_pos = VGet(m_posX, m_posY, m_posZ);
	m_drawPos = m_pos;

	//���S�A�j���[�V�����������Ă�����
	if (m_animation[8] != -1)
	{
		//�A�j���[�V�����f�^�b�`
		MV1DetachAnim(m_handle, m_animation[8]);

		//�A�j���[�V�����A�^�b�`
		m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);

		m_playTime = 0.0f;

		
		m_animation[8] = -1;
	}

	m_death = false;

	//���f���S�̂̃R���W�������̃Z�b�g�A�b�v
	//MV1SetupCollInfo(map->GetCollisionMap(), -1);
}

void Player::Update()
{
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);


	//�A�j���[�V�����ňړ����Ă���t���[���̔ԍ�����������
	m_moveAnimFrameIndex = MV1SearchFrame(m_handle, "mixamorig:Hips");

	//�����\����Ƃ��̃A�j���[�V�����̃t���[������
	m_moveAnimShieldFrameIndex = MV1SearchFrame(m_handle, "mixamorig:LeftHand");

	//�p�b�h���͏���
	m_pad = GetJoypadXInputState(DX_INPUT_KEY_PAD1, &m_xpad);

	//�A�i���O�X�e�B�b�N���g���Ĉړ�
	int analogX = 0;
	int analogY = 0;

	float SetAngleX = 0.0f;
	float SetAngleY = 0.0f;

	if (m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);
	}
	

	m_move = VGet(-analogX, 0.0f, analogY);  //�x�N�g���̒���
	m_bounceMove = VGet(analogX, 0.0f, -analogY);  //�x�N�g���̒���

	//�x�N�g���̒������擾����
	float len = VSize(m_move);
	float bounceLen = VSize(m_bounceMove);
	//�x�N�g��������0.0�`1.0�̊����ɕϊ�����
	float rate = len / 1000.0f;
	float bounceRate = bounceLen / 1000.0f;

	//�A�i���O�X�e�B�b�N�����Ȕ͈͂����O����
	rate = (rate - 0.1f) / (0.8f - 0.1f);
	rate = min(rate, 1.0f);
	rate = max(rate, 0.0f);

	bounceRate = (bounceRate - 0.1f) / (0.8f - 0.1f);
	bounceRate = min(bounceRate, 1.0f);
	bounceRate = max(bounceRate, 0.0f);


	//���x������ł���̂ňړ��x�N�g���ɔ��f����
	m_move = VNorm(m_move);
	float speed = m_speed * rate;

	m_move = VScale(m_move, speed);

	m_bounceMove = VNorm(m_bounceMove);
	float bounceDis = m_speed * bounceRate;

	m_bounceMove = VScale(m_bounceMove, bounceDis);

	//camera�̊p�x����
	//�R���g���[���[�ɂ��ړ����������肷��
	MATRIX mtx = MGetRotY(m_cameraAngle + DX_PI_F);
	m_move = VTransform(m_move, mtx);
	MATRIX reverseMtx = MGetRotY(m_cameraAngle + DX_PI_F);
	m_bounceMove = VTransform(m_bounceMove, reverseMtx);

	//�ړ���������v���C���[�ւ̌������������肷��
	//�ړ����Ă��Ȃ��ꍇ(�[���x�N�g��)�̏ꍇ�͕ύX���Ȃ�
	if (VSquareSize(m_move) > 0.0f && m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		//�A���O��������
		m_angle = atan2f(-m_move.z, m_move.x) - DX_PI_F / 2;

		SetAngleX += D2R(1.0f);
		SetAngleY += D2R(1.0f);

		//�v���C���[����������
		m_moveflag = true;
	}
	//�v���C���[�������ĂȂ�������
	else if (VSquareSize(m_move) <= 0.0f)
	{
		m_moveflag = false;
	}

	//�v���C���[�������Ă��鎞����
	if (m_hp >= 0.0f)
	{
		m_pos = VAdd(m_pos, m_move);

		Action();
	}
	

	//�U���̓����蔻����v���C���[�̐��ʂɎ����Ă���
	m_colAttackPos.x = m_pos.x + sinf(m_angle) * -25.0f;
	m_colAttackPos.z = m_pos.z - cosf(m_angle) * 25.0f;


	//�A�j���[�V�������Ԃ�i�߂�O�̃A�j���[�V�����ňړ������Ă���t���[���̍��W�擾
	m_prevPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);

	//�U�����Ă��Ȃ����̃A�j���[�V�������x
	if(m_moveAttack == false)
	{
		//�Đ����Ԃ�i�߂�
		m_playTime += 0.5f;
	}


	//A�{�^���������ꂽ��
	if (m_xpad.Buttons[12] == 1 && m_staminaBroke == false && m_recoberyAction == false)
	{
		if (m_a > 50 && m_stamina >= 0.1f)
		{
			m_avoidance = false;

			//�_�b�V����
			m_dashMove = true;

			m_speed = 3.0f;

			//�X�^�~�i����
			m_stamina -= 0.1f;
		}
		else if(m_stamina >= 10.0f)
		{
			m_avoidance = true;
		}

		if (m_a < 51)
		{
			m_a++;
		}
	}
	else
	{
		m_dashMove = false;

		m_speed = 2.0f;

		m_a = 0;
	}
	//�����U�����Ă��Ȃ����ɍ��W������
	if (m_avoidance == false && m_moveAttack == false)
	{
		m_drawPos = m_pos;
	}
	//����s����
	if (m_playTime <= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		//�t���[�����
		if (m_playTime >= 0.0f && m_playTime <= 25.0f)
		{
			m_avoidanceNow = true;
		}
		else
		{
			m_avoidanceNow = false;
		}
	}
	if (m_playTime >= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		
		m_drawPos = m_pos;

		//����I��
		m_avoidance = false;
	}
	if (m_playTime >= m_totalAnimTime[4] && m_animation[4] != -1)
	{
		m_drawPos = m_pos;

		//�U���I��
		m_moveAttack = false;
	}
	if (m_playTime >= m_totalAnimTime[5] && m_animation[5] != -1)
	{
		m_drawPos = m_pos;

		//�U���I��
		m_moveAttack = false;
	}
	if (m_playTime >= m_totalAnimTime[6] && m_animation[6] != -1)
	{
		m_drawPos = m_pos;

		//�U���I��
		m_moveAttack = false;
	}

	//�X�^�~�i�؂�
	if (m_stamina <= 0.1f)
	{
		m_staminaBroke = true;
	}
	//������悤�ɂȂ�
	else if (m_stamina >= 20.0f)
	{
		m_staminaBroke = false;
	}
	//�X�^�~�i��
	if (m_dashMove == false && m_moveAttack == false && m_avoidance == false)
	{
		if (m_stamina <= 100.0f)
		{
			m_stamina += 0.3f;
		}
	}

	Animation(m_playTime, m_pos);

	m_capsuleCol.Update(m_colPos, m_vec);

	//�}�b�v�Ƃ̓����蔻��p
	m_mapHitColl = VGet(m_colPos.x, m_colPos.y, m_colPos.z);
}

/// <summary>
/// �v���C���[�̍s���Ɋւ���������܂Ƃ߂�֐�
/// </summary>
void Player::Action()
{
	//PAD_INPUT_2��B�{�^��
	//PAD_INPUT_3��X�{�^��
	//PAD_INPUT_4��Y�{�^��
	//PAD_INPUT_5��L�{�^��
	//PAD_INPUT_7��Back�{�^��
	//PAD_INPUT_8��Start�{�^��
	//PAD_INPUT_9��L�X�e�B�b�N
	//PAD_INPUT_10��R�X�e�B�b�N

	//R�{�^���ōU��
	//��i�K�ڂ̍U��
	if (m_xpad.Buttons[9] == 1 && m_staminaBroke == false && m_recoberyAction == false)
	{
		if (m_attackNumber == 0 && m_stamina >= 10.0f)
		{
			//�U���͏�����
			m_attack = 10.0f;

			//�X�^�~�i����
			m_stamina = m_stamina - 10.0f;

			m_attackNumber = 1;

			m_moveAttack = true;
		}
		else if (m_nextAttack1 == true && m_stamina >= 10.0f)
		{
			//�U���͏�����
			m_attack = 10.0f;

			//�X�^�~�i����
			m_stamina = m_stamina - 10.0f;

			m_attackNumber = 2;

			m_moveAttack = true;
		}
		else if (m_nextAttack2 == true && m_stamina >= 10.0f)
		{
			//�U���͏�����
			m_attack = 10.0f;

			//�X�^�~�i����
			m_stamina = m_stamina - 10.0f;

			m_attackNumber = 3;

			m_moveAttack = true;
		}
	}

	//ZR�{�^���ŋ��U��
	if (m_xpad.RightTrigger)
	{
		DrawFormatString(0, 10, 0xffffff, "���U��");
	}


	//L�{�^���Ŗh��
	if (m_xpad.Buttons[8] == 1)
	{
		DrawFormatString(0, 10, 0xffffff, "�h��");
	}

	//�U�����̃A�j���[�V�����𑬂�����
	if (m_moveAttack == true)
	{
		
		if (m_animation[4] != -1 && m_playTime >= 15.0f)
		{

			m_playTime += 0.9f;

			//�U���̓����蔻�蔭��
			if (m_playTime >= 25.0f && m_playTime <= 30.0f)
			{
				m_sphereCol.Update(m_colAttackPos);
			}
			//�U���̓����蔻�������������
			else
			{
				m_sphereCol.Update(m_initializationPos);
			}


			if (m_playTime >= 30.0f)
			{
				//2�i�K�ڂ̍U������
				m_nextAttack1 = true;
			}

		}
		else if (m_animation[5] != -1 && m_playTime >= 5.0f)
		{
			m_playTime += 0.9f;

			//�U���̓����蔻�蔭��
			if (m_playTime >= 10.0f && m_playTime <= 15.0f)
			{
				m_sphereCol.Update(m_colAttackPos);
			}
			//�U���̓����蔻�������������
			else
			{
				m_sphereCol.Update(m_initializationPos);
			}

			if (m_playTime >= 15.0f)
			{
				//3�i�K�ڂ̍U������
				m_nextAttack2 = true;
			}
			
		}
		else if (m_animation[6] != -1 && m_playTime >= 15.0f)
		{
			m_playTime += 0.9f;

			//�U���̓����蔻�蔭��
			if (m_playTime >= 20.0f && m_playTime <= 25.0f)
			{
				m_sphereCol.Update(m_colAttackPos);
			}
			//�U���̓����蔻�������������
			else
			{
				m_sphereCol.Update(m_initializationPos);
			}

		}
		else
		{
			m_playTime += 0.5f;
		}

	}

	//��𒆂ɍU�����邽��
	if (m_avoidance == true)
	{
		if (m_pad & PAD_INPUT_6)
		{
			m_moveAttack = true;
		}
	}

	if (m_moveAttack == false)
	{
		//���̍U���i�K�̏�����
		m_attackNumber = 0;

		//�U������������
		m_nextAttack1 = false;
		m_nextAttack2 = false;

	}


	//�G�����b�N�I������
	if (m_lockonTarget == false)
	{
		if (m_xpad.Buttons[7] == 1 && m_pushButton == true)
		{
			m_lockonTarget = true;
			m_pushButton = false;
		}
		else if (m_xpad.Buttons[7] == 0)
		{
			m_pushButton = true;
		}
	}
	else if (m_lockonTarget == true)
	{
		DrawString(0, 100, "���b�N�I��", 0xffffff);

		if (m_xpad.Buttons[7] == 1 && m_pushButton == true)
		{
			m_lockonTarget = false;
			m_pushButton = false;
		}
		else if (m_xpad.Buttons[7] == 0)
		{
			m_pushButton = true;
		}
	}

	

	//��
	//X�{�^���������ꂽ��
	if (m_xpad.Buttons[14] == 1)
	{
		if (m_moveAttack == false && m_avoidance == false)
		{
			m_recoberyAction = true;
		}
		
	}
	else if(m_recoberyAction == false)
	{
		m_heel = 0.0f;
	}

	if (m_recoveryNumber >= 0 && m_recoberyAction == true && m_moveAttack == false && m_avoidance == false)
	{
		//HP��
		if (m_hp < 150.0f && m_heel < m_recoberyAmount)
		{
			m_heel += 0.1f;

			m_hp += m_heel;
		}

	}
	
}

/// <summary>
/// �A�j���[�V�����Ɋւ���������܂Ƃ߂�֐�
/// </summary>
void Player::Animation(float& time, VECTOR& pos)
{
	//�v���C���[�������Ă��Ȃ��Ȃ�
	if (m_moveflag == false && m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		if (m_animation[1] != -1 || m_animation[2] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1 || m_animation[9] != -1)
		{

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);

			//�A�j���[�V�����A�^�b�`
			m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);

			time = 0.0f;

			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;

		}
		
	}
	//�v���C���[����������
	//A�{�^��������
	if (m_dashMove == true && m_moveflag == true && m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1 || m_animation[9] != -1)
		{

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);



			//�A�j���[�V�����A�^�b�`
			m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;


		}
	}
	//���
	else if (m_avoidance == true && m_moveAttack == false && m_recoberyAction == false)
	{

		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1 || m_animation[9] != -1)
		{
			m_stamina = m_stamina - 10.0f;

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);


			//�A�j���[�V�����A�^�b�`
			m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;

		}
	}
	else if (m_moveflag == true && m_avoidance == false && m_moveAttack == false && m_recoberyAction == false)
	{
		if (m_animation[0] != -1 || m_animation[2] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1 || m_animation[9] != -1)
		{

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);

			//�A�j���[�V�����A�^�b�`
			m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;

		}
	}
	if (m_avoidance == false && m_moveAttack == true && m_recoberyAction == false)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1
			|| m_animation[3] != -1 || m_animation[7] != -1 || m_animation[9] != -1)
		{
			//�U��1�i�K��
			if (m_attackNumber == 1)
			{
				//��i�K�ڂ̍U����
				m_attack = m_attack * 1.0f;

				//�A�j���[�V�����f�^�b�`
				MV1DetachAnim(m_handle, m_animation[0]);
				MV1DetachAnim(m_handle, m_animation[1]);
				MV1DetachAnim(m_handle, m_animation[2]);
				MV1DetachAnim(m_handle, m_animation[3]);
				MV1DetachAnim(m_handle, m_animation[7]);
				MV1DetachAnim(m_handle, m_animation[9]);

				//�A�j���[�V�����A�^�b�`
				m_animation[4] = MV1AttachAnim(m_handle, 1, m_animAttack1, TRUE);

				time = 0.0f;

				m_animation[0] = -1;
				m_animation[1] = -1;
				m_animation[2] = -1;
				m_animation[3] = -1;
				m_animation[7] = -1;
				m_animation[9] = -1;


				m_moveAttackEnd = false;
			}

		}
		//�U��2�i�K��
		if (m_attackNumber == 2 && m_animation[4] != -1)
		{
			//2�i�K�ڂ̍U����
			m_attack = m_attack * 1.2f;

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);

			//�A�j���[�V�����A�^�b�`
			m_animation[5] = MV1AttachAnim(m_handle, 1, m_animAttack2, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;

			m_moveAttackEnd = false;

		}
		//�U��3�i�K��
		if (m_attackNumber == 3 && m_animation[5] != -1)
		{
			//3�i�K�ڂ̍U����
			m_attack = m_attack * 1.5f;

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);

			//�A�j���[�V�����A�^�b�`
			m_animation[6] = MV1AttachAnim(m_handle, 1, m_animAttack3, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;

			m_moveAttackEnd = false;

		}
		//�U��2�i�K��
		//else if (m_attackNumber == 2 && m_animation[4] != -1 && m_moveAttackEnd == true)
		//{
		//	//�A�j���[�V�����f�^�b�`
		//	MV1DetachAnim(m_handle, m_animation[0]);
		//	MV1DetachAnim(m_handle, m_animation[1]);
		//	MV1DetachAnim(m_handle, m_animation[2]);
		//	MV1DetachAnim(m_handle, m_animation[3]);
		//	MV1DetachAnim(m_handle, m_animation[4]);

		//	//�A�j���[�V�����A�^�b�`
		//	m_animation[5] = MV1AttachAnim(m_handle, 1, m_animAttack2, TRUE);

		//	time = 0.0f;

		//	m_animation[0] = -1;
		//	m_animation[1] = -1;
		//	m_animation[2] = -1;
		//	m_animation[3] = -1;
		//	m_animation[4] = -1;

		//	m_moveAttackEnd = false;

		//}
		////�U��3�i�K��
		//else if (m_attackNumber == 3 && m_animation[5] != -1 && m_moveAttackEnd == true)
		//{
		//	//�A�j���[�V�����f�^�b�`
		//	MV1DetachAnim(m_handle, m_animation[0]);
		//	MV1DetachAnim(m_handle, m_animation[1]);
		//	MV1DetachAnim(m_handle, m_animation[2]);
		//	MV1DetachAnim(m_handle, m_animation[3]);
		//	MV1DetachAnim(m_handle, m_animation[4]);
		//	MV1DetachAnim(m_handle, m_animation[5]);

		//	//�A�j���[�V�����A�^�b�`
		//	m_animation[6] = MV1AttachAnim(m_handle, 1, m_animAttack3, TRUE);

		//	time = 0.0f;

		//	m_animation[0] = -1;
		//	m_animation[1] = -1;
		//	m_animation[2] = -1;
		//	m_animation[3] = -1;
		//	m_animation[4] = -1;
		//	m_animation[5] = -1;

		//	m_moveAttackEnd = false;

		//}
	}

	//�v���C���[���񕜂����Ƃ�
	if (m_recoberyAction == true)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);

			//�A�j���[�V�����A�^�b�`
			m_animation[9] = MV1AttachAnim(m_handle, 1, m_animHeel, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
		}
	}

	//�v���C���[�����񂾎�
	if (m_hp <= 0.0f)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1 ||
			m_animation[3] != -1 || m_animation[4] != -1 || m_animation[5] != -1 ||
			m_animation[6] != -1 || m_animation[7] != -1 || m_animation[9] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);
			MV1DetachAnim(m_handle, m_animation[9]);

			//�A�j���[�V�����A�^�b�`
			m_animation[8] = MV1AttachAnim(m_handle, 1, m_animDeath, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;
			m_animation[3] = -1;
			m_animation[4] = -1;
			m_animation[5] = -1;
			m_animation[6] = -1;
			m_animation[7] = -1;
			m_animation[9] = -1;

		}
	}
	

	//�Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (time >= m_totalAnimTime[0] && m_animation[0] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[1] && m_animation[1] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[2] && m_animation[2] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		time = 0.0f;

		//����I��
		m_avoidance = false;
	}
	if (time >= m_totalAnimTime[4] && m_animation[4] != -1)
	{
		//�U���I��
		m_moveAttackEnd = true;

		time = 0.0f;

		m_moveAttack = false;
	}
	if (time >= m_totalAnimTime[5] && m_animation[5] != -1)
	{
		time = 0.0f;

		//�U���I��
		m_moveAttackEnd = true;

		m_moveAttack = false;
	}
	if (time >= m_totalAnimTime[6] && m_animation[6] != -1)
	{
		time = 0.0f;

		//�U���I��
		m_moveAttackEnd = true;

		m_moveAttack = false;
	}
	if (time >= m_totalAnimTime[7] && m_animation[7] != -1)
	{
		time = 0.0f;

		m_moveAttack = false;
	}
	if (time >= m_totalAnimTime[8] && m_animation[8] != -1)
	{
		time = 120.0f;

		m_death = true;
	}
	if (time >= m_totalAnimTime[9] && m_animation[9] != -1)
	{
		m_recoveryNumber--;

		m_recoberyAction = false;

		time = 0.0f;
	}

	//�Đ����Ԃ��Z�b�g����
	if (m_animation[0] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[0], time);
	}
	if (m_animation[1] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[1], time);
	}
	if (m_animation[2] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[2], time);
	}
	if (m_animation[3] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[3], time);

		//�A�j���[�V�������o�ߒ��̍��W�擾
		m_nowPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);
		m_moveVector = VSub(m_nowPos, m_prevPos);

		pos.x += m_moveVector.x;
		pos.z += m_moveVector.z;
	}
	if (m_animation[4] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[4], time);

		//�A�j���[�V�������o�ߒ��̍��W�擾
		m_nowPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);
		m_moveVector = VSub(m_nowPos, m_prevPos);

		pos.x += m_moveVector.x;
		pos.z += m_moveVector.z;
	}
	if (m_animation[5] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[5], time);

		//�A�j���[�V�������o�ߒ��̍��W�擾
		m_nowPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);
		m_moveVector = VSub(m_nowPos, m_prevPos);

		pos.x += m_moveVector.x;
		pos.z += m_moveVector.z;

		//2�i�K�ڂ̍U�������I��
		m_nextAttack1 = false;
	}
	if (m_animation[6] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[6], time);

		//�A�j���[�V�������o�ߒ��̍��W�擾
		m_nowPos = MV1GetFramePosition(m_handle, m_moveAnimFrameIndex);
		m_moveVector = VSub(m_nowPos, m_prevPos);

		pos.x += m_moveVector.x;
		pos.z += m_moveVector.z;

		//3�i�K�ڂ̍U�������I��
		m_nextAttack2 = false;
	}
	if (m_animation[7] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[7], time);
	}
	if (m_animation[8] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[8], time);
	}
	if (m_animation[9] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[9], time);
	}
}

void Player::HitObj(Map& map)
{
	int j;

	//�v���C���[�̎��͂ɂ���R���W�����̃|���S�����擾����
	HitDim = MV1CollCheck_Sphere(map.GetCollisionMap(), -1, map.GetVectorMapPos(), 1500.0f);

	//���o���ꂽ�|���S�����ǃ|���S��(XZ���ʂɐ����ȃ|���S��)�����|���S��(XZ���ʂɐ����ł͂Ȃ��|���S��)���𔻒f����
	for (int i = 0; i < HitDim.HitNum; i++)
	{
		//XZ���ʂɐ������ǂ����̓|���S���̖@����Y������0�Ɍ���Ȃ��߂����ǂ����Ŕ��f����
		if (HitDim.Dim[i].Normal.y < 0.000001f && HitDim.Dim[i].Normal.y > -0.0000001f)
		{
			if (HitDim.Dim[i].Position[0].y > m_pos.y + 1.0f ||
				HitDim.Dim[i].Position[1].y > m_pos.y + 1.0f ||
				HitDim.Dim[i].Position[2].y > m_pos.y + 1.0f)
			{
				//�|���S���̐����񋓂ł�����E���ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
				if (m_WallNum < PLAYER_MAX_HITCOLL)
				{
					//�|���S���̍\���̂̃A�h���X��ǃ|���S���|�C���^�z��ɕۑ�����
					m_Wall[m_WallNum] = &HitDim.Dim[i];

					//�ǃ|���S���̐������Z����
					m_WallNum++;
				}
			}
		}
	}

	//�ǃ|���S���Ɠ����蔻�菈��
	if (m_WallNum != 0)
	{
		//�ǂɓ����������ǂ����̃t���O�͏�����Ԃł́u�������Ă��Ȃ��v�ɂ��Ă���
		m_HitFlag = false;

		//�ړ��������ǂ����ŏ����𕪊�
		if (m_moveflag == true)
		{
			//�ǃ|���S���̐������J��Ԃ�
			for (int i = 0; i < m_WallNum; i++)
			{
				//i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
				m_Poly = m_Wall[i];

				//�|���S���ƃv���C���[���������Ă��Ȃ������玟�̃J�E���g��
				if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == false) continue;

				//�����ɂ�����|���S���ƃv���C���[���������Ă���Ƃ������ƂȂ̂ŁA�|���S���ɓ��������t���O�𗧂Ă�
				m_HitFlag = true;

				//�V���Ȉړ����W�ŕǃ|���S���Ɠ������Ă��Ȃ����ǂ����𔻒肷��
				for (j = 0; j < m_WallNum; j++)
				{
					//j�Ԗڂ̕ǃ|���S���Ɠ������Ă��Ȃ����ǂ����𔻒肷��
					m_Poly = m_Wall[j];

					//�������Ă����烋�[�v���甲����
					if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == true) break;
				}

				//j��m_WallNum�������ꍇ�͂ǂ̃|���S���Ƃ�������Ȃ������Ƃ������ƂȂ̂�
				//�ǂɓ��������t���O��|���������Ń��[�v���甲����
				if (j == m_WallNum)
				{
					m_HitFlag = false;
					break;
				}
			
			}
		}
		else
		{
			//�ړ����Ă��Ȃ��ꍇ�̏���

			//�ǃ|���S���̐������J��Ԃ�
			for (int i = 0; i < m_WallNum; i++)
			{
				//i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
				m_Poly = m_Wall[i];

				//�|���S���ɓ������Ă����瓖�������t���O�𗧂Ă���Ń��[�v���甲����
				if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == true)
				{
					m_HitFlag = true;
					break;
				}

			}
		}

		//�ǂɓ������Ă�����ǂ��牟���o���������s��
		if (m_HitFlag == true)
		{
			//�ǂ���̉����o�����������݂�ő吔�����J��Ԃ�
			for (int i = 0; i < PLAYER_MAX_HITCOLL; i++)
			{
				//�ǃ|���S���̐������J��Ԃ�
				for (int k = 0; k < m_WallNum; k++)
				{
					//j�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
					m_Poly = m_Wall[k];

					//�v���C���[�Ɠ������Ă��邩����
					if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == false) continue;

					//�������Ă�����K�苗�����v���C���[��ǂ̖@�������Ɉړ�������
					m_pos = VAdd(m_pos, VScale(m_Poly->Normal, m_speed));

					//�ړ�������ŕǃ|���S���ƐڐG���Ă��邩�ǂ����𔻒�
					for (j = 0; j < m_WallNum; j++)
					{
						//�������Ă����烋�[�v�𔲂���
						m_Poly = m_Wall[j];
						if (HitCheck_Capsule_Triangle(m_mapHitColl, VAdd(m_mapHitColl, VGet(0.0f, m_len, 0.0f)), m_capsuleRadius, m_Poly->Position[0], m_Poly->Position[1], m_Poly->Position[2]) == true) break;

					}

					//���ׂẴ|���S���Ɠ������Ă��Ȃ������烋�[�v�I��
					if (j == m_WallNum) break;
				}

				//i��m_WallNum�ł͂Ȃ��ꍇ�͑S���̃|���S���ŉ����o�������݂�O�ɂ��ׂĂ̕ǃ|���S���ƐڐG���Ȃ��Ȃ����Ƃ������ƂȂ̂Ń��[�v���甲����
				if (i != m_WallNum) break;
			}
		}
	}

	SaveAction(map);

	//���o�����v���C���[�̎��͂̃|���S�������������
	MV1CollResultPolyDimTerminate(HitDim);

}

void Player::SaveAction(Map& map)
{
	//�x�����\��������
	if (map.GetSavePossible() == true)
	{	
		//Y�{�^���������ꂽ��
		if (m_xpad.Buttons[15] == 1)
		{
			m_updatePosX = 95.0f;
			m_updatePosY = 0.0f;
			m_updatePosZ = -40.0f;

			m_restAction = true;
		}
	}
}

void Player::Draw()
{
	//�����x�N�g��
	Vec3 vec = m_vec.GetNormalized() * m_len * 0.5f;

	Pos3 pos1 = m_colPos + vec;
	Pos3 pos2 = m_colPos - vec;

	//�J�v�Z��3D�̕`��
	DrawCapsule3D(pos1.GetVector(), pos2.GetVector(), m_capsuleRadius, 16, m_color, 0, false);

	//�~��3D�`��
	DrawSphere3D(m_colAttackPos.GetVector(), m_sphereRadius, 16, 0xffffff, 0xffffff, false);
	//DrawSphere3D(map->GetVectorMapPos(), 1500.0f, 16, 0xffffff, 0xffffff, false);

	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_drawPos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	//3D���f���`��
	MV1DrawModel(m_handle);

	if (m_HitFlag == true)
	{
		DrawFormatString(0, 100, 0xffffff, "�ǂɓ�������");
	}
	if (m_restAction == true)
	{
		DrawFormatString(0, 80, 0xffffff, "�񕜂ł���");
	}

	DrawFormatString(0, 120, 0xffffff, "HitPoly : %d", HitDim.HitNum);
	DrawFormatString(0, 0, 0xffffff, "playTime : %f", m_playTime);
	DrawFormatString(0, 30, 0xffffff, "posX : %f posY : %f posZ : %f", m_pos.x, m_pos.y, m_pos.z);
	DrawFormatString(0, 50, 0xffffff, "DrawposX : %f DrawposY : %f DrawposZ : %f", m_drawPos.x, m_drawPos.y, m_drawPos.z);
	//�o�O�ōU����ԂɂȂ邪���[�V����������Ȃ�
	DrawFormatString(0, 180, 0xffffff, "m_attack : %d", m_moveAttack);
	DrawFormatString(0, 200, 0xffffff, "m_stamina : %f", m_stamina);
	DrawFormatString(0, 220, 0xffffff, "�A�j��0 : %d", m_animation[0]);
	DrawFormatString(0, 240, 0xffffff, "�A�j��1 : %d", m_animation[1]);
	DrawFormatString(0, 260, 0xffffff, "�A�j��2 : %d", m_animation[2]);
	DrawFormatString(0, 280, 0xffffff, "�A�j��3 : %d", m_animation[3]);
	DrawFormatString(0, 300, 0xffffff, "�A�j��4 : %d", m_animation[4]);
	DrawFormatString(0, 320, 0xffffff, "�A�j��5 : %d", m_animation[5]);
	DrawFormatString(0, 340, 0xffffff, "�A�j��6 : %d", m_animation[6]);
	DrawFormatString(0, 360, 0xffffff, "�A�j��7 : %d", m_animation[7]);
	DrawFormatString(0, 380, 0xffffff, "�A�j��8 : %d", m_animation[8]);
	DrawFormatString(0, 400, 0xffffff, "�񕜐� : %d", m_recoveryNumber);


}

void Player::End()
{
	//���������
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animWalk);
	MV1DeleteModel(m_animRun);
	MV1DeleteModel(m_animRoll);
	MV1DeleteModel(m_animAttack1);
	MV1DeleteModel(m_animAttack2);
	MV1DeleteModel(m_animAttack3);
	MV1DeleteModel(m_animDeath);
	MV1DeleteModel(m_animHeel);

}

bool Player::IsCapsuleHit(const CapsuleCol& col, const CapsuleCol& col1)
{
	bool isHit = m_capsuleCol.IsHitCapsule(col);
	bool isHitBoss = m_capsuleCol.IsHitCapsule(col1);

	if (isHit || isHitBoss)
	{
		m_color = 0xffff00;

		//�������Ă�����K�苗�����v���C���[��@�������Ɉړ�������
		m_pos = VAdd(m_pos, VScale(m_bounceMove, m_bounceDis));

		//����s���������ꍇ
		//m_pos�������Ă���
		if (m_avoidance == true)
		{
			//�������Ă�����K�苗�����v���C���[��@�������Ɉړ�������
			m_pos.x -= m_moveVector.x + m_bounceDis;
			m_pos.z -= m_moveVector.z + m_bounceDis;
			m_drawPos.x -= m_moveVector.x + m_bounceDis;
			m_drawPos.z -= m_moveVector.z + m_bounceDis;
		}
	}
	else
	{
		m_color = 0xffffff;
	}

	return isHit || isHitBoss;
}

bool Player::isSphereHit(const SphereCol& col, const SphereCol& col1, const SphereCol& col2, const SphereCol& col3, float damage, float bossdamage)
{
	bool isHit = m_capsuleCol.IsHitSphere(col);
	bool isBossAttackHit1 = m_capsuleCol.IsHitSphere(col1);
	bool isBossAttackHit2 = m_capsuleCol.IsHitSphere(col2);
	bool isBossAttackHit3 = m_capsuleCol.IsHitSphere(col3);

	//�_���[�W���󂯂�����
	if (isHit)
	{
		m_color = 0xffff00;

		//�_���[�W����񂾂��^����
		if (m_damageReceived == false)
		{
			//��𒆂̃t���[�����ƃ_���[�W���󂯂Ȃ�
			if (m_avoidanceNow == false)
			{
				m_hp = m_hp - damage;
			}
			
			m_damageReceived = true;
		}

	}
	else if (isBossAttackHit1 || isBossAttackHit2 || isBossAttackHit3)
	{
		m_color = 0xffff00;

		//�_���[�W����񂾂��^����
		if (m_damageReceived == false)
		{
			//��𒆂̃t���[�����ƃ_���[�W���󂯂Ȃ�
			if (m_avoidanceNow == false)
			{
				m_hp = m_hp - bossdamage;
			}

			m_damageReceived = true;
		}
	}
	else
	{
		m_damageReceived = false;

		m_color = 0xffffff;
	}

	return isHit || isBossAttackHit1 || isBossAttackHit2 || isBossAttackHit3;
}
