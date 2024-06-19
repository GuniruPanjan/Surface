#include "Player.h"
#include<math.h>
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player() :
	cameraAngle(0.0f),
	angle(0.0f),
	PlayerAnimWalking(-1),
	PlayerAnimRun(-1),
	PlayerAnimDying(-1),
	PlayTime(0.0f),
	PlayerMove(false),
	Pad(0)
{
	for (int i = 0; i < 4; i++)
	{
		PlayerAnim[i] = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		TotalTime[i] = 0;
	}
}

Player::~Player()
{
	//���������
	MV1DeleteModel(PlayerModel);
	MV1DeleteModel(PlayerAnimWalking);
	MV1DeleteModel(PlayerAnimRun);
	MV1DeleteModel(PlayerAnimDying);
}

void Player::Init()
{
	PlayerHp = 10;
	//Player��3D���f����ǂݍ���
	PlayerModel = MV1LoadModel("PlayerData/PlayerModel.mv1");

	//Player�̑傫����ς���
	MV1SetScale(PlayerModel, VGet(0.4f, 0.4f, 0.4f));

	//Player�̃X�s�[�h��ݒ�
	PlayerSpeed = 2.0f;

	//Player�̃|�W�V�����ݒ�
	PlayerPos = VGet(0.0f, 2.0f, 0.0f);

	//Player�̃A�j���[�V�����ǂݍ���
	PlayerAnimWalking = MV1LoadModel("PlayerData/PlayerAnimWalk.mv1");
	PlayerAnimRun = MV1LoadModel("PlayerData/PlayerAnimRun.mv1");
	PlayerAnimDying = MV1LoadModel("PlayerData/PlayerAnimDying.mv1");


	//�A�j���[�V�����A�^�b�`
	PlayerAnim[0] = MV1AttachAnim(PlayerModel, 0, PlayerModel, TRUE);
	PlayerAnim[1] = MV1AttachAnim(PlayerModel, 0, PlayerAnimWalking, TRUE);
	PlayerAnim[2] = MV1AttachAnim(PlayerModel, 0, PlayerAnimRun, TRUE);
	PlayerAnim[3] = MV1AttachAnim(PlayerModel, 0, PlayerAnimDying, TRUE);

	//�A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	TotalTime[0] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[0]);
	TotalTime[1] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[1]);
	TotalTime[2] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[2]);
	TotalTime[3] = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim[3]);

	//��U�ҋ@�ӊO�̃A�j���[�V�����f�^�b�`
	MV1DetachAnim(PlayerModel, PlayerAnim[1]);
	MV1DetachAnim(PlayerModel, PlayerAnim[2]);
	MV1DetachAnim(PlayerModel, PlayerAnim[3]);
	PlayerAnim[1] = -1;
	PlayerAnim[2] = -1;
	PlayerAnim[3] = -1;

	m_pos = Pos3(PlayerPos.x - 2.0f, PlayerPos.y + 35.0f, PlayerPos.z);
	m_vec = Vec3(PlayerPos.x, PlayerPos.y, PlayerPos.z);
	m_len = 40.0f;
	m_radius = 16.0f;
	m_col.Init(m_pos, m_vec, m_len, m_radius);
}

void Player::Update()
{
	m_pos = Pos3(PlayerPos.x - 2.0f, PlayerPos.y + 35.0f, PlayerPos.z);

	//�p�b�h���͏���
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//Player�������Ă��Ȃ��Ȃ�
	if (PlayerMove == false)
	{
		if (PlayerAnim[1] != -1 || PlayerAnim[2] != -1)
		{
			//�A�j���[�V�����f�^�b�`
			MV1DetachAnim(PlayerModel, PlayerAnim[1]);
			MV1DetachAnim(PlayerModel, PlayerAnim[2]);

			//�A�j���[�V�������A�^�b�`
			PlayerAnim[0] = MV1AttachAnim(PlayerModel, 0, PlayerModel, TRUE);

			PlayTime = 0.0f;

			PlayerAnim[1] = -1;
			PlayerAnim[2] = -1;
		}


	}
	//A�{�^������������_�b�V��
	if (Pad & PAD_INPUT_1 && PlayerMove == true)
	{
		if (PlayerAnim[1] != -1 || PlayerAnim[0] != -1)
		{
			//�A�j���[�V�������f�^�b�`
			MV1DetachAnim(PlayerModel, PlayerAnim[0]);
			MV1DetachAnim(PlayerModel, PlayerAnim[1]);

			//�A�j���[�V�������A�^�b�`����
			PlayerAnim[2] = MV1AttachAnim(PlayerModel, 0, PlayerAnimRun, TRUE);

			PlayTime = 0.0f;

			PlayerAnim[0] = -1;
			PlayerAnim[1] = -1;

		}


		PlayerSpeed = 4.0f;

		DrawFormatString(0, 0, GetColor(255, 255, 255), "�_�b�V��");
	}
	//�������[�V����
	else if (PlayerMove == true)
	{
		if (PlayerAnim[0] != -1)
		{
			//�A�j���[�V����1���f�^�b�`
			MV1DetachAnim(PlayerModel, PlayerAnim[0]);

			//�A�j���[�V�������A�^�b�`����
			PlayerAnim[1] = MV1AttachAnim(PlayerModel, 0, PlayerAnimWalking, TRUE);

			PlayTime = 0.0f;

			PlayerAnim[0] = -1;

		}
		//A�{�^���������ĂȂ�������
		if ((Pad & PAD_INPUT_1) == false)
		{
			if (PlayerAnim[2] != -1)
			{
				//�A�j���[�V�������f�^�b�`
				MV1DetachAnim(PlayerModel, PlayerAnim[2]);

				//�A�j���[�V�������A�^�b�`����
				PlayerAnim[1] = MV1AttachAnim(PlayerModel, 0, PlayerAnimWalking, TRUE);

				PlayTime = 0.0f;

				PlayerAnim[2] = -1;
			}

			PlayerSpeed = 2.0f;
		}

	}

	//B�{�^���������Ă�����
	if (Pad & PAD_INPUT_2)
	{
		PlayerMove = false;
		//�v���C���[���[�d���Ȃ�
		PlayerChargingMove = true;
		//�v���C���[���G�l���M�[��^�����
		PlayerGiveEnergy = 1.0f;

		DrawString(0, 0, "�}�V���G�l���M�[��[", 0xffffff);
	}
	//�v���C���[���[�d�����Ⴏ���
	else
	{
		PlayerChargingMove = false;
	}

	//�A�i���O�X�e�B�b�N���g���Ĉړ�
	int analogX = 0;
	int analogY = 0;

	float SetAngleX = 0.0f;
	float SetAngleY = 0.0f;

	GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

	VECTOR move = VGet(-analogX, 0.0f, analogY);  //�x�N�g���̒���

	//�x�N�g���̒������擾����
	float len = VSize(move);
	//�x�N�g��������0.0�`1.0�̊����ɕϊ�����
	float rate = len / 1000.0f;

	//�A�i���O�X�e�B�b�N�����Ȕ͈͂����O����
	rate = (rate - 0.1f) / (0.8f - 0.1f);
	rate = min(rate, 1.0f);
	rate = max(rate, 0.0f);

	//���x������ł���̂ňړ��x�N�g���ɔ��f����
	move = VNorm(move);
	float speed = PlayerSpeed * rate;

	move = VScale(move, speed);

	//camera�̊p�x����
	//�R���g���[���ɂ��ړ����������肷��
	MATRIX mtx = MGetRotY(cameraAngle + DX_PI_F);
	move = VTransform(move, mtx);

	//�ړ���������v���C���[�̌������������肷��
	//�ړ����ĂȂ��ꍇ(�[���x�N�g��)�̏ꍇ�͕ύX���Ȃ�
	//�v���C���[���[�d������Ȃ����
	if (PlayerChargingMove == false)
	{
		if (VSquareSize(move) > 0.0f)
		{
			angle = atan2f(-move.z, move.x) - DX_PI_F / 2;

			SetAngleX += D2R(1.0f);
			SetAngleY += D2R(1.0f);

			//�v���C���[����������
			PlayerMove = true;
		}
		//�v���C���[�������ĂȂ�������
		else if (VSquareSize(move) <= 0.0f)
		{
			PlayerMove = false;

			DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", PlayTime);
		}

		PlayerPos = VAdd(PlayerPos, move);

	}

	//�Đ����Ԃ�i�߂�
	PlayTime += 0.5f;

	//�Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (PlayTime >= TotalTime[0] && PlayerAnim[0] != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime[1] && PlayerAnim[1] != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime[2] && PlayerAnim[2] != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime[3] && PlayerAnim[3] != -1)
	{
		PlayTime = 0.0f;
	}

	if (PlayerAnim[0] != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[0], PlayTime);
	}
	if (PlayerAnim[1] != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[1], PlayTime);
	}
	if (PlayerAnim[2] != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[2], PlayTime);
	}
	if (PlayerAnim[3] != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[3], PlayTime);
	}

	m_col.Update(m_pos, m_vec);
}

void Player::Draw()
{
	//�����x�N�g��
	Vec3 Vec = m_vec.GetNormalized() * m_len * 0.5f;

	Pos3 pos1 = m_pos + Vec;
	Pos3 pos2 = m_pos - Vec;

	DrawCapsule3D(pos1.GetVector(), pos2.GetVector(), m_radius, 16, m_color, 0, false);

	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerModel, PlayerPos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(PlayerModel, VGet(0.0f, angle, 0.0f));

	//3D���f���`��
	MV1DrawModel(PlayerModel);
}

bool Player::IsHit(const CapsuleCol& col)
{
	bool isHit = m_col.IsHit(col);

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

void Player::End()
{
	//���������
	MV1DeleteModel(PlayerModel);
	MV1DeleteModel(PlayerAnimWalking);
	MV1DeleteModel(PlayerAnimRun);
	MV1DeleteModel(PlayerAnimDying);

}
