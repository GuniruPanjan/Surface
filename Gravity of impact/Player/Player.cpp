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
	//Playerの初期座標
	PlayerX = 0.0f;
	PlayerY = 10.0f;
	PlayerZ = 0.0f;

	//Playerの初期位置
	Playerpos = VGet(PlayerX, PlayerY, PlayerZ);

	//3Dモデルを読み込む
	PlayerGraph = MV1LoadModel("data/Sting-Sword lowpoly.mv1");

	//3Dモデルのポジション設定
	MV1SetPosition(PlayerGraph, Playerpos);
}

void Player::Update()
{
}

void Player::Draw()
{
	//3Dモデルを描画する
	MV1DrawModel(PlayerGraph);
}

void Player::End()
{
}
