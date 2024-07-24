#include "Player.h"
#include<math.h>
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	m_cameraAngle(0.0f),
	m_lockonTarget(false),
	m_moveAnimFrameIndex(0),
	m_moveAnimShieldFrameIndex(0),
	m_a(0),
	m_pad(0),
	m_animRollAttack(-1),
	m_avoidance(false),
	m_nextAttack1(false),
	m_nextAttack2(false),
	m_nowPos(VGet(0.0f,0.0f,0.0f))
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

}

void Player::Init()
{
	//�v���C���[HP�̏�����
	m_hp = 150.0f;

	//�v���C���[�X�s�[�h������
	m_speed = 2.0f;

	//�v���C���[�̍U���͏�����
	m_attack = 10.0f;

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


	//�A�j���[�V�����A�^�b�`
	m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);
	m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);
	m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);
	m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);
	m_animation[4] = MV1AttachAnim(m_handle, 1, m_animAttack1, TRUE);
	m_animation[5] = MV1AttachAnim(m_handle, 1, m_animAttack2, TRUE);
	m_animation[6] = MV1AttachAnim(m_handle, 1, m_animAttack3, TRUE);
	m_animation[7] = MV1AttachAnim(m_handle, 1, m_animRollAttack, TRUE);


	//�A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);
	m_totalAnimTime[1] = MV1GetAttachAnimTotalTime(m_handle, m_animation[1]);
	m_totalAnimTime[2] = MV1GetAttachAnimTotalTime(m_handle, m_animation[2]);
	m_totalAnimTime[3] = MV1GetAttachAnimTotalTime(m_handle, m_animation[3]);
	m_totalAnimTime[4] = MV1GetAttachAnimTotalTime(m_handle, m_animation[4]);
	m_totalAnimTime[5] = MV1GetAttachAnimTotalTime(m_handle, m_animation[5]);
	m_totalAnimTime[6] = MV1GetAttachAnimTotalTime(m_handle, m_animation[6]);
	m_totalAnimTime[7] = MV1GetAttachAnimTotalTime(m_handle, m_animation[7]);

	//��U�ҋ@�ȊO�̃A�j���[�V�����f�^�b�`
	MV1DetachAnim(m_handle, m_animation[1]);
	MV1DetachAnim(m_handle, m_animation[2]);
	MV1DetachAnim(m_handle, m_animation[3]);
	MV1DetachAnim(m_handle, m_animation[4]);
	MV1DetachAnim(m_handle, m_animation[5]);
	MV1DetachAnim(m_handle, m_animation[6]);
	MV1DetachAnim(m_handle, m_animation[7]);
	m_animation[1] = -1;
	m_animation[2] = -1;
	m_animation[3] = -1;
	m_animation[4] = -1;
	m_animation[5] = -1;
	m_animation[6] = -1;
	m_animation[7] = -1;

	m_posX = 0.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;

	//�v���C���[�̃|�W�V�����ݒ�
	m_pos = VGet(m_posX, m_posY, m_posZ);
	m_drawPos = m_pos;

	//�����蔻��
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_colAttackPos = Pos3(m_pos.x - 50.0f, m_pos.y + 35.0f, m_pos.z);
	m_initializationPos = Pos3(0.0f, -1000.0f, 0.0f);
	m_vec = Vec3(m_pos.x, m_pos.y + 2.0f, m_pos.z);
	m_len = 40.0f;
	m_capsuleRadius = 12.0f;
	m_sphereRadius = 18.0f;
	m_capsuleCol.Init(m_colPos, m_vec, m_len, m_capsuleRadius);
	m_sphereCol.Init(m_colAttackPos, m_sphereRadius);
}

void Player::Update()
{
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	//m_colAttackPos = Pos3(m_pos.x, m_pos.y + 35.0f, m_pos.z - 25.0f);

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

	if (m_avoidance == false && m_moveAttack == false)
	{
		GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);
	}
	

	m_move = VGet(-analogX, 0.0f, analogY);  //�x�N�g���̒���

	//�x�N�g���̒������擾����
	float len = VSize(m_move);
	//�x�N�g��������0.0�`1.0�̊����ɕϊ�����
	float rate = len / 1000.0f;

	//�A�i���O�X�e�B�b�N�����Ȕ͈͂����O����
	rate = (rate - 0.1f) / (0.8f - 0.1f);
	rate = min(rate, 1.0f);
	rate = max(rate, 0.0f);

	//���x������ł���̂ňړ��x�N�g���ɔ��f����
	m_move = VNorm(m_move);
	float speed = m_speed * rate;

	m_move = VScale(m_move, speed);

	//camera�̊p�x����
	//�R���g���[���[�ɂ��ړ����������肷��
	MATRIX mtx = MGetRotY(m_cameraAngle + DX_PI_F);
	m_move = VTransform(m_move, mtx);

	//�ړ���������v���C���[�ւ̌������������肷��
	//�ړ����Ă��Ȃ��ꍇ(�[���x�N�g��)�̏ꍇ�͕ύX���Ȃ�
	if (VSquareSize(m_move) > 0.0f && m_avoidance == false && m_moveAttack == false)
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

	m_pos = VAdd(m_pos, m_move);

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
	if (m_xpad.Buttons[12] == 1)
	{
		if (m_a > 50)
		{
			m_avoidance = false;

			m_speed = 3.0f;
		}
		else
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
		m_a = 0;
	}
	//�����U�����Ă��Ȃ����ɍ��W������
	if (m_avoidance == false && m_moveAttack == false)
	{
		m_drawPos = m_pos;
	}

	if (m_playTime >= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		
		m_drawPos = m_pos;

		//����I��
		m_avoidance = false;
	}
	if (m_playTime >= m_totalAnimTime[4] && m_animation[4] != -1)
	{
		//�U���I��
		m_moveAttack = false;
	}
	if (m_playTime >= m_totalAnimTime[5] && m_animation[5] != -1)
	{
		//�U���I��
		m_moveAttack = false;
	}
	if (m_playTime >= m_totalAnimTime[6] && m_animation[6] != -1)
	{
		//�U���I��
		m_moveAttack = false;
	}

	Action();

	Animation(m_a, m_playTime, m_pos);

	m_capsuleCol.Update(m_colPos, m_vec);
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
	if (m_xpad.Buttons[9] == 1)
	{
		if (m_attackNumber == 0)
		{
			m_attackNumber = 1;

			m_moveAttack = true;
		}
		else if (m_nextAttack1 == true)
		{
			m_attackNumber = 2;

			m_moveAttack = true;
		}
		else if (m_nextAttack2 == true)
		{
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


			if (m_playTime >= 25.0f)
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

			if (m_playTime >= 10.0f)
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
		if (m_xpad.Buttons[7] == 1)
		{
			m_lockonTarget = true;
		}
	}
	else if (m_lockonTarget == true)
	{
		DrawString(0, 100, "���b�N�I��", 0xffffff);

		if (m_xpad.Buttons[7] == 1)
		{
			m_lockonTarget = false;
		}
	}
	
}

/// <summary>
/// �A�j���[�V�����Ɋւ���������܂Ƃ߂�֐�
/// </summary>
void Player::Animation(int& A, float& time, VECTOR& pos)
{
	//�v���C���[�������Ă��Ȃ��Ȃ�
	if (m_moveflag == false && m_avoidance == false && m_moveAttack == false)
	{
		if (m_animation[1] != -1 || m_animation[2] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1)
		{

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);

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

		}
		
	}
	//�v���C���[����������
	//A�{�^��������
	if (A > 50 && m_moveflag == true && m_avoidance == false && m_moveAttack == false)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1)
		{

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);



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


		}
	}
	else if (m_avoidance == true && m_moveAttack == false)
	{

		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1)
		{

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);


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
		}
	}
	else if (m_moveflag == true && m_avoidance == false && m_moveAttack == false)
	{
		if (m_animation[0] != -1 || m_animation[2] != -1 || m_animation[3] != -1
			|| m_animation[4] != -1 || m_animation[5] != -1 || m_animation[6] != -1
			|| m_animation[7] != -1)
		{

			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[2]);
			MV1DetachAnim(m_handle, m_animation[3]);
			MV1DetachAnim(m_handle, m_animation[4]);
			MV1DetachAnim(m_handle, m_animation[5]);
			MV1DetachAnim(m_handle, m_animation[6]);
			MV1DetachAnim(m_handle, m_animation[7]);

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
		}
	}
	if (m_avoidance == false && m_moveAttack == true)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1
			|| m_animation[3] != -1 || m_animation[7] != -1)
		{
			//�U��1�i�K��
			if (m_attackNumber == 1)
			{
				//�A�j���[�V�����f�^�b�`
				MV1DetachAnim(m_handle, m_animation[0]);
				MV1DetachAnim(m_handle, m_animation[1]);
				MV1DetachAnim(m_handle, m_animation[2]);
				MV1DetachAnim(m_handle, m_animation[3]);
				MV1DetachAnim(m_handle, m_animation[7]);

				//�A�j���[�V�����A�^�b�`
				m_animation[4] = MV1AttachAnim(m_handle, 1, m_animAttack1, TRUE);

				time = 0.0f;

				m_animation[0] = -1;
				m_animation[1] = -1;
				m_animation[2] = -1;
				m_animation[3] = -1;
				m_animation[7] = -1;


				m_moveAttackEnd = false;
			}

		}
		//�U��2�i�K��
		else if (m_attackNumber == 2 && m_animation[4] != -1 && time >= m_totalAnimTime[4])
		{
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
		else if (m_attackNumber == 3 && m_animation[5] != -1 && time >= m_totalAnimTime[5])
		{
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
		time = 0.0f;

		//�U���I��
		m_moveAttackEnd = true;

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

	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_drawPos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	//3D���f���`��
	MV1DrawModel(m_handle);

	DrawFormatString(0, 0, 0xffffff, "playTime : %f", m_playTime);
	DrawFormatString(0, 30, 0xffffff, "posX : %f posY : %f posZ : %f", m_pos.x, m_pos.y, m_pos.z);
	DrawFormatString(0, 50, 0xffffff, "DrawposX : %f DrawposY : %f DrawposZ : %f", m_drawPos.x, m_drawPos.y, m_drawPos.z);
	DrawFormatString(0, 200, 0xffffff, "m_cameraAngle : %f", m_cameraAngle);



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

}

bool Player::IsHit(const CapsuleCol& col)
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
