#include "Player.h"

Player::Player()
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

	//Player�̏����ʒu
	Playerpos = VGet(PlayerX, PlayerY, PlayerZ);

	//3D���f����ǂݍ���
	PlayerGraph = MV1LoadModel("data/Sting-Sword lowpoly.mv1");

	//Player�̃X�s�[�h�ݒ�
	PlayerSpeed = 1.0f;
}

void Player::Update()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerGraph, Playerpos);

	//�O�ɐi��
	if (CheckHitKey(KEY_INPUT_W))
	{
		Playerpos.z += PlayerSpeed;

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

		DrawString(280, 0, "�E��", 0xffffff);

	}
	//���ɐi��
	if (CheckHitKey(KEY_INPUT_A))
	{
		Playerpos.x -= PlayerSpeed;

		DrawString(280, 0, "����", 0xffffff);

	}
}

void Player::Draw()
{
	//3D���f����`�悷��
	MV1DrawModel(PlayerGraph);
}

void Player::End()
{
}
