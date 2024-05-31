#include "Player.h"

Player::Player()
{
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

	//Player�̃|�W�V�����ݒ�
	PlayerPos = VGet(0.0f, 2.0f, 0.0f);
}

void Player::Update()
{
	
}

void Player::Draw()
{
	//3D���f���̃|�W�V�����ݒ�
	MV1SetPosition(PlayerModel, PlayerPos);

	//3D���f���`��
	MV1DrawModel(PlayerModel);

}

void Player::End()
{
	//���������
	MV1DeleteModel(PlayerModel);
}
