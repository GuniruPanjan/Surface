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
	//Playerの3Dモデルを読み込む
	PlayerModel = MV1LoadModel("PlayerData/PlayerMet.mv1");

	//Playerの大きさを変える
	MV1SetScale(PlayerModel, VGet(0.4f, 0.4f, 0.4f));

	//Playerのポジション設定
	PlayerPos = VGet(0.0f, 2.0f, 0.0f);
}

void Player::Update()
{
	
}

void Player::Draw()
{
	//3Dモデルのポジション設定
	MV1SetPosition(PlayerModel, PlayerPos);

	//3Dモデル描画
	MV1DrawModel(PlayerModel);

}

void Player::End()
{
	//メモリ解放
	MV1DeleteModel(PlayerModel);
}
