#include "Player.h"
#include<math.h>
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	m_cameraAngle(0.0f),
	m_moveAnimFrameIndex(0),
	m_a(0),
	m_pad(0)
{
}

Player::~Player()
{
	//���������
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animWalk);
	MV1DeleteModel(m_animRun);

}

void Player::Init()
{
	//�v���C���[HP�̏�����
	m_hp = 150.0f;

	//�v���C���[�X�s�[�h������
	m_speed = 2.0f;

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

	//�A�j���[�V�����ňړ����Ă���t���[���̔ԍ�����������
	m_moveAnimFrameIndex = MV1SearchFrame(m_animRoll, "mixamorig:Hips");

	//�A�j���[�V�����A�^�b�`
	m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);
	m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);
	m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);
	m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);

	//�A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);
	m_totalAnimTime[1] = MV1GetAttachAnimTotalTime(m_handle, m_animation[1]);
	m_totalAnimTime[2] = MV1GetAttachAnimTotalTime(m_handle, m_animation[2]);
	m_totalAnimTime[3] = MV1GetAttachAnimTotalTime(m_handle, m_animation[3]);

	//�A�j���[�V�����ňړ����Ă���t���[���𖳌��ɂ���
	MV1SetFrameUserLocalMatrix(m_animRoll, m_moveAnimFrameIndex, MV1GetFrameLocalMatrix(m_animRoll, m_moveAnimFrameIndex));

	//��U�ҋ@�ȊO�̃A�j���[�V�����f�^�b�`
	MV1DetachAnim(m_handle, m_animation[1]);
	MV1DetachAnim(m_handle, m_animation[2]);
	MV1DetachAnim(m_handle, m_animation[3]);
	m_animation[1] = -1;
	m_animation[2] = -1;
	m_animation[3] = -1;


	//�v���C���[���|�W�V�����ݒ�
	m_pos = VGet(m_posX, m_posY, m_posZ);
}

void Player::Update()
{
	//�p�b�h���͏���
	m_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�A�i���O�X�e�B�b�N���g���Ĉړ�
	int analogX = 0;
	int analogY = 0;

	float SetAngleX = 0.0f;
	float SetAngleY = 0.0f;

	GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

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
	//�v���C���[���[�d������Ȃ����
	if (VSquareSize(m_move) > 0.0f)
	{
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

	//�A�j���[�V�������Ԃ�i�߂�O�́u�A�j���[�V�����ňړ������Ă���t���[���̍��W�v���擾���Ă���


	//�Đ����Ԃ�i�߂�
	m_playerTime += 0.5f;


	//A�{�^���������ꂽ��
	if (m_pad & PAD_INPUT_1)
	{
		if (m_a < 51)
		{
			m_a++;
		}
	}
	else
	{
		m_a = 0;
	}


	Animation(m_a, m_playerTime);
}

/// <summary>
/// �A�j���[�V�����Ɋւ���������܂Ƃ߂�֐�
/// </summary>
/// <param name="time"></param>
void Player::Animation(int& A, float& time)
{
	//�v���C���[�������Ă��Ȃ��Ȃ�
	if (m_moveflag == false)
	{
		if (m_animation[1] != -1 || m_animation[2] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);


			//�A�j���[�V�����A�^�b�`
			m_animation[0] = MV1AttachAnim(m_handle, 1, m_animStand, TRUE);

			time = 0.0f;

			m_animation[1] = -1;
			m_animation[2] = -1;
		}
		
	}
	//�v���C���[����������
	//A�{�^��������
	if (A > 50 && m_moveflag == true)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);

			//�A�j���[�V�����A�^�b�`
			m_animation[2] = MV1AttachAnim(m_handle, 1, m_animRun, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;

		}
	}
	else if (m_pad & PAD_INPUT_1)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[2] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[2]);

			//�A�j���[�V�����A�^�b�`
			m_animation[3] = MV1AttachAnim(m_handle, 1, m_animRoll, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[2] = -1;


		}
	}
	else if (m_moveflag == true)
	{
		if (m_animation[0] != -1 || m_animation[2] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[2]);


			//�A�j���[�V�����A�^�b�`
			m_animation[1] = MV1AttachAnim(m_handle, 1, m_animWalk, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[2] = -1;
		}
	}

	//�Đ����Ԃ��A�j���[�V�����̑��E�����ԂɒB������Đ����Ԃ�0�ɖ߂�
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
	}
}

void Player::Draw()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	//3D���f���`��
	MV1DrawModel(m_handle);
}

void Player::End()
{
	//���������
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animWalk);
	MV1DeleteModel(m_animRun);

}
