#include "Player.h"
#include<math.h>
#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	cameraAngle(0.0f),
	angle(0.0f),
	PlayerAnimStanding(0.0f),
	PlayerAnimWalking(0.0f),
	PlayerAnimRun(0.0f),
	PlayerAnimDying(0.0f),
	PlayTime(0.0f),
	PlayerMove(false),
	PlayerAnim1(0),
	PlayerAnim2(0),
	PlayerAnim3(0),
	PlayerAnim4(0),
	TotalTime1(0.0f),
	TotalTime2(0.0f),
	TotalTime3(0.0f),
	TotalTime4(0.0f)
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
}

void Player::Init()
{
	PlayerHp = 10;
	//Player��3D���f����ǂݍ���
	PlayerModel = MV1LoadModel("PlayerData/PlayerMet.mv1");

	//Player�̑傫����ς���
	MV1SetScale(PlayerModel, VGet(0.4f, 0.4f, 0.4f));

	//Player�̃X�s�[�h��ݒ�
	PlayerSpeed = 2.0f;

	//Player�̃|�W�V�����ݒ�
	PlayerPos = VGet(0.0f, 2.0f, 0.0f);

	//Player�̃A�j���[�V�����ǂݍ���
	PlayerAnimStanding = MV1LoadModel("PlayerData/PlayerAnimStanding.mv1");
	PlayerAnimWalking = MV1LoadModel("PlayerData/PlayerAnimWalk.mv1");
	PlayerAnimRun = MV1LoadModel("PlayerData/PlayerAnimRunning.mv1");
	PlayerAnimDying = MV1LoadModel("PlayerData/PlayerAnimDying.mv1");

	
	//�A�j���[�V�����A�^�b�`
	PlayerAnim1 = MV1AttachAnim(PlayerModel, 1, PlayerAnimStanding, TRUE);
	PlayerAnim2 = MV1AttachAnim(PlayerModel, 1, PlayerAnimWalking, TRUE);
	PlayerAnim3 = MV1AttachAnim(PlayerModel, 1, PlayerAnimRun, TRUE);
	PlayerAnim4 = MV1AttachAnim(PlayerModel, 1, PlayerAnimDying, TRUE);

	//��U�ҋ@�ӊO�̃A�j���[�V�����f�^�b�`
	MV1DetachAnim(PlayerModel, PlayerAnim2);
	MV1DetachAnim(PlayerModel, PlayerAnim3);
	MV1DetachAnim(PlayerModel, PlayerAnim4);
	PlayerAnim2 = -1;
	PlayerAnim3 = -1;
	PlayerAnim4 = -1;

}

void Player::Update()
{

	//�A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	TotalTime1 = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim1);
	TotalTime2 = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim2);
	TotalTime3 = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim3);
	TotalTime4 = MV1GetAttachAnimTotalTime(PlayerModel, PlayerAnim4);

	//Player�������Ă��Ȃ��Ȃ�
	if (PlayerMove == false)
	{
		

		
	}
	else if (PlayerMove == true)
	{
		if (PlayerAnim1 != -1)
		{
			//�A�j���[�V����1���f�^�b�`
			MV1DetachAnim(PlayerModel, PlayerAnim1);

			//�A�j���[�V�������A�^�b�`����
			PlayerAnim2 == MV1AttachAnim(PlayerModel, 1, PlayerAnimWalking, TRUE);

			PlayTime = 0.0f;

			PlayerAnim1 = -1;

		}
		
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
	if (VSquareSize(move) > 0.0f)
	{
		angle = atan2f(-move.z, move.x) - DX_PI_F / 2;

		SetAngleX += D2R(1.0f);
		SetAngleY += D2R(1.0f);

		//�v���C���[����������
		PlayerMove = true;
	}
	
	PlayerPos = VAdd(PlayerPos, move);

	//�Đ����Ԃ�i�߂�
	PlayTime += 0.5f;

	//�Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (PlayTime >= TotalTime1 && PlayerAnim1 != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime2 && PlayerAnim2 != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime3 && PlayerAnim3 != -1)
	{
		PlayTime = 0.0f;
	}
	if (PlayTime >= TotalTime4 && PlayerAnim4 != -1)
	{
		PlayTime = 0.0f;
	}

	if (PlayerAnim1 != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[0], PlayTime);
	}
	if (PlayerAnim2 != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[1], PlayTime);
	}
	if (PlayerAnim3 != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[2], PlayTime);
	}
	if (PlayerAnim4 != -1)
	{
		//�Đ����Ԃ��Z�b�g����
		MV1SetAttachAnimTime(PlayerModel, PlayerAnim[3], PlayTime);
	}
	
}

void Player::Draw()
{

	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerModel, PlayerPos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(PlayerModel, VGet(0.0f, angle, 0.0f));

	//3D���f���`��
	MV1DrawModel(PlayerModel);
	
}

void Player::End()
{
	//���������
	MV1DeleteModel(PlayerModel);
	MV1DeleteModel(PlayerAnimStanding);
	MV1DeleteModel(PlayerAnimWalking);
	MV1DeleteModel(PlayerAnimRun);
	MV1DeleteModel(PlayerAnimDying);


}
