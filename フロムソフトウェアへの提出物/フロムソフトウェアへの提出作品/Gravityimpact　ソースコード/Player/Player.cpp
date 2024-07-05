#include "Player.h"
#include<math.h>
//�d�͉����x
#define GravitationalAcceleration 9.80665 / 2

#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	PlayerGravity(0.0f),
	Playerweight(0.0f),
	cameraAngle(0.0f),
	angle(0.0f)
{
}

Player::~Player()
{
	MV1DeleteModel(PlayerGraph);
}

void Player::Init()
{
	//Player�̏������W
	PlayerX = 0.0f;
	PlayerY = 30.0f;
	PlayerZ = 0.0f;

	//Player�̏d��
	Playerweight = 1.0f;

	//Player�̏d��
	PlayerGravity = Playerweight * static_cast<float>(GravitationalAcceleration);

	//Player�̏����ʒu
	Playerpos = VGet(PlayerX, PlayerY, PlayerZ);

	//Player�̉�]��ԏ�����
	//PlayerAngle = VGet(-1.55f, D2R(0.0f), 0.0f);

	//3D���f����ǂݍ���
	PlayerGraph = MV1LoadModel("data/Box.mv1");

	//Player�̑傫����ς���
	MV1SetScale(PlayerGraph, VGet(0.05f, 0.05f, 0.06f));

	//Player�̃X�s�[�h�ݒ�
	PlayerSpeed = 1.0f;

	//Player�����X�|�[���ł���n�_
	PlayerRespawn = -7500.0f;

	//Player��������悤�ɏ�����
	PlayerMoveFlag = true;
}

void Player::Update()
{
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
		angle = atan2f(move.z, -move.x) - DX_PI_F / 2;

		SetAngleX += D2R(1.0f);
		SetAngleY += D2R(1.0f);
	}
	//Player�������t���O��True�Ȃ�
	if (PlayerMoveFlag == true)
	{
		Playerpos = VAdd(Playerpos, move);
	}
	

	//Player�ɏd�͂�^��������
	Playerpos.y -= PlayerGravity;

	//Player��������������v���C���[���S����
	if (Playerpos.y <= PlayerRespawn)
	{
		PlayerDead = true;
	}

	//Player�����S�����珉���ʒu�ɖ߂�
	if (PlayerDead == true)
	{
		Playerpos.x = 0.0f;
		Playerpos.y = 30.0f;
		Playerpos.z = 0.0f;
	}

	m_colrect.SetCenter(Playerpos.x - static_cast<float>(5), Playerpos.y - static_cast<float>(6), Playerpos.z + static_cast<float>(5), 10.0f, 10.0f, -10.0f);
}

void Player::Draw()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerGraph, Playerpos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(PlayerGraph, VGet(-1.55f, angle, 0.0f));

	//3D���f����`�悷��
	MV1DrawModel(PlayerGraph);
}

void Player::End()
{
}
