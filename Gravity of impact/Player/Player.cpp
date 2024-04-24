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

	//Playerのスピード設定
	PlayerSpeed = 1.0f;
}

void Player::Update()
{
	//3Dモデルのポジション設定
	MV1SetPosition(PlayerGraph, Playerpos);

	//前に進む
	if (CheckHitKey(KEY_INPUT_W))
	{
		Playerpos.z += PlayerSpeed;

		DrawString(280, 0, "前へ", 0xffffff);

	}
	//後ろに進む
	if (CheckHitKey(KEY_INPUT_S))
	{
		Playerpos.z -= PlayerSpeed;

		DrawString(280, 0, "後ろへ", 0xffffff);

	}
	//右に進む
	if (CheckHitKey(KEY_INPUT_D))
	{
		Playerpos.x += PlayerSpeed;

		DrawString(280, 0, "右へ", 0xffffff);

	}
	//左に進む
	if (CheckHitKey(KEY_INPUT_A))
	{
		Playerpos.x -= PlayerSpeed;

		DrawString(280, 0, "左へ", 0xffffff);

	}
}

void Player::Draw()
{
	//3Dモデルを描画する
	MV1DrawModel(PlayerGraph);
}

void Player::End()
{
}
