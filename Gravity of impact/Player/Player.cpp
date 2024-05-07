#include "Player.h"
#include<math.h>
//重力加速度
#define GravitationalAcceleration 9.80665 / 2

#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	PlayerGravity(0.0f),
	Playerweight(0.0f)
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
	PlayerY = 30.0f;
	PlayerZ = 0.0f;

	//Playerの重さ
	Playerweight = 1.0f;

	//Playerの重力
	PlayerGravity = Playerweight * GravitationalAcceleration;

	//Playerの初期位置
	Playerpos = VGet(PlayerX, PlayerY, PlayerZ);

	//Playerの回転状態初期化
	PlayerAngle = VGet(0.0f, D2R(0.0f), 0.0f);

	//3Dモデルを読み込む
	PlayerGraph = MV1LoadModel("data/Sting-Sword lowpoly.mv1");

	//Playerのスピード設定
	PlayerSpeed = 1.0f;
}

void Player::Update()
{
	

	//前に進む
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
	//後ろに進む
	if (CheckHitKey(KEY_INPUT_S))
	{
		Playerpos.z -= PlayerSpeed;

	}
	//右に進む
	if (CheckHitKey(KEY_INPUT_D))
	{
		Playerpos.x += PlayerSpeed;

		//if (PlayerAngle.y <= 1.5f)
		//{
		//	PlayerAngle.y += D2R(1.0f);
		//}

	}
	//左に進む
	if (CheckHitKey(KEY_INPUT_A))
	{
		Playerpos.x -= PlayerSpeed;

		//if (PlayerAngle.y >= -1.5f)
		//{
		//	PlayerAngle.y -= D2R(1.0f);
		//}

	}

	//Playerに重力を与え続ける
	Playerpos.y -= PlayerGravity;

	m_colrect.SetCenter(Playerpos.x - static_cast<float>(5), Playerpos.y, Playerpos.z + static_cast<float>(30), 10.0f, 1.0f, -60.0f);
}

void Player::Draw()
{
	//3Dモデルのポジション設定
	MV1SetPosition(PlayerGraph, Playerpos);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(PlayerGraph, PlayerAngle);

	//3Dモデルを描画する
	MV1DrawModel(PlayerGraph);

	DrawFormatString(500, 0, 0xffffff, "%f", PlayerAngle.y);
	DrawFormatString(500, 20, 0xffffff, "%f", PlayerAngle.x);

	//当たり判定を描画する
	m_colrect.Draw(GetColor(255, 0, 0), false);

}

void Player::End()
{
}
