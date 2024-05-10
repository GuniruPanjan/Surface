#include "Player.h"
#include<math.h>
//�d�͉����x
#define GravitationalAcceleration 9.80665 / 2

#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	PlayerGravity(0.0f),
	Playerweight(0.0f),
	PlayerRespawn(0.0f)
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
	PlayerGravity = Playerweight * GravitationalAcceleration;

	//Player�̏����ʒu
	Playerpos = VGet(PlayerX, PlayerY, PlayerZ);

	//Player�̉�]��ԏ�����
	PlayerAngle = VGet(-1.55f, D2R(0.0f), 0.0f);

	//3D���f����ǂݍ���
	PlayerGraph = MV1LoadModel("data/Sword.mv1");

	//Player�̑傫����ς���
	MV1SetScale(PlayerGraph, VGet(0.05f, 0.05f, 0.05f));

	//Player�̃X�s�[�h�ݒ�
	PlayerSpeed = 1.0f;

	//Player�����X�|�[���ł���n�_
	PlayerRespawn = -7500.0f;
}

void Player::Update()
{
	

	//�O�ɐi��
	if (CheckHitKey(KEY_INPUT_W))
	{
		Playerpos.z += PlayerSpeed;

		//if (PlayerAngle.y <= 0.0f)
		//{
		//	PlayerAngle.y += D2R(1.0f);
		//}
		//if (PlayerAngle.y >= 0.0f)
		//{
		//	PlayerAngle.y -= D2R(1.0f);
		//}

	}
	//���ɐi��
	if (CheckHitKey(KEY_INPUT_S))
	{
		Playerpos.z -= PlayerSpeed;

	}
	//�E�ɐi��
	if (CheckHitKey(KEY_INPUT_D))
	{
		Playerpos.x += PlayerSpeed;

		//if (PlayerAngle.y <= 1.5f)
		//{
		//	PlayerAngle.y += D2R(1.0f);
		//}

	}
	//���ɐi��
	if (CheckHitKey(KEY_INPUT_A))
	{
		Playerpos.x -= PlayerSpeed;

		//if (PlayerAngle.y >= -1.5f)
		//{
		//	PlayerAngle.y -= D2R(1.0f);
		//}

	}

	//Player�ɏd�͂�^��������
	Playerpos.y -= PlayerGravity;

	//Player�������������珉���ʒu�ɖ߂�
	if (Playerpos.y <= PlayerRespawn)
	{
		Playerpos.x = 0.0f;
		Playerpos.y = 30.0f;
		Playerpos.z = 0.0f;
	}

	m_colrect.SetCenter(Playerpos.x - static_cast<float>(5), Playerpos.y, Playerpos.z + static_cast<float>(5), 10.0f, 1.0f, -60.0f);
}

void Player::Draw()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerGraph, Playerpos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(PlayerGraph, PlayerAngle);

	//3D���f����`�悷��
	MV1DrawModel(PlayerGraph);

	//DrawFormatString(500, 0, 0xffffff, "%f", Playerpos.y);
	//DrawFormatString(500, 20, 0xffffff, "%f", Playerpos.x);
	//DrawFormatString(500, 40, 0xffffff, "%f", Playerpos.z);


	//�����蔻���`�悷��
	//m_colrect.Draw(GetColor(255, 0, 0), false);

}

void Player::End()
{
}
