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

	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerGraph, Playerpos);
}

void Player::Update()
{
}

void Player::Draw()
{
	//3D���f����`�悷��
	MV1DrawModel(PlayerGraph);
}

void Player::End()
{
}
