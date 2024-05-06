#include "Player.h"
#include<math.h>

#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	PlayerGravity(0.0f)
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
	PlayerY = 10.0f;
	PlayerZ = 0.0f;

	PlayerGravity = 1.0f;

	//Player�̏����ʒu
	Playerpos = VGet(PlayerX, PlayerY, PlayerZ);

	//Player�̉�]��ԏ�����
	PlayerAngle = VGet(0.0f, D2R(0.0f), 0.0f);

	//3D���f����ǂݍ���
	PlayerGraph = MV1LoadModel("data/Sting-Sword lowpoly.mv1");

	//Player�̃X�s�[�h�ݒ�
	PlayerSpeed = 1.0f;
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
		

		DrawString(280, 0, "�O��", 0xffffff);

	}
	//���ɐi��
	if (CheckHitKey(KEY_INPUT_S))
	{
		Playerpos.z -= PlayerSpeed;

		DrawString(280, 0, "����", 0xffffff);

	}
	//�E�ɐi��
	if (CheckHitKey(KEY_INPUT_D))
	{
		Playerpos.x += PlayerSpeed;

		//if (PlayerAngle.y <= 1.5f)
		//{
		//	PlayerAngle.y += D2R(1.0f);
		//}
		

		DrawString(280, 0, "�E��", 0xffffff);

	}
	//���ɐi��
	if (CheckHitKey(KEY_INPUT_A))
	{
		Playerpos.x -= PlayerSpeed;

		//if (PlayerAngle.y >= -1.5f)
		//{
		//	PlayerAngle.y -= D2R(1.0f);
		//}
		

		DrawString(280, 0, "����", 0xffffff);

	}

	//Player�ɏd�͂�^��������
	Playerpos.y -= PlayerGravity;

	m_colrect.SetCenter(Playerpos.x - static_cast<float>(5), Playerpos.y, Playerpos.z - static_cast<float>(30), 10.0f, 1.0f, 60.0f);
}

void Player::Draw()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerGraph, Playerpos);

	//3D���f���̉�]�n���Z�b�g����
	MV1SetRotationXYZ(PlayerGraph, PlayerAngle);



	//3D���f����`�悷��
	MV1DrawModel(PlayerGraph);

	DrawFormatString(500, 0, 0xffffff, "%f", PlayerAngle.y);
	DrawFormatString(500, 20, 0xffffff, "%f", PlayerAngle.x);

	//�����蔻���`�悷��
	m_colrect.Draw(GetColor(255, 0, 0), false);

}

void Player::End()
{
}
