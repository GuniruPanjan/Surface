#include "Player.h"
#include<math.h>
//重力加速度
#define GravitationalAcceleration 9.80665 / 2

#define D2R(deg) ((deg)*DX_PI_F/180.0f)

Player::Player():
	PlayerGravity(0.0f),
	Playerweight(0.0f),
	PlayerRespawn(0.0f),
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
	//Playerの初期座標
	PlayerX = 0.0f;
	PlayerY = 30.0f;
	PlayerZ = 0.0f;

	//Playerの重さ
	Playerweight = 1.0f;

	//Playerの重力
	PlayerGravity = Playerweight * static_cast<float>(GravitationalAcceleration);

	//Playerの初期位置
	Playerpos = VGet(PlayerX, PlayerY, PlayerZ);

	//Playerの回転状態初期化
	PlayerAngle = VGet(-1.55f, D2R(0.0f), 0.0f);

	//3Dモデルを読み込む
	PlayerGraph = MV1LoadModel("data/Sword.mv1");

	//Playerの大きさを変える
	MV1SetScale(PlayerGraph, VGet(0.05f, 0.05f, 0.05f));

	//Playerのスピード設定
	PlayerSpeed = 1.0f;

	//Playerがリスポーンできる地点
	PlayerRespawn = -7500.0f;

	//Playerが動けるように初期化
	PlayerMoveFlag = true;
}

void Player::Update()
{
	//アナログスティックを使って移動
	int analogX = 0;
	int analogY = 0;

	GetJoypadAnalogInput(&analogX, &analogY, DX_INPUT_PAD1);

	VECTOR move = VGet(-analogX, 0.0f, analogY);  //ベクトルの長さ

	//ベクトルの長さを取得する
	float len = VSize(move);
	//ベクトル長さを0.0～1.0の割合に変換する
	float rate = len / 1000.0f;

	//アナログスティック無効な範囲を除外する
	rate = (rate - 0.1f) / (0.8f - 0.1f);
	rate = min(rate, 1.0f);
	rate = max(rate, 0.0f);

	//速度が決定できるので移動ベクトルに反映する
	move = VNorm(move);
	float speed = PlayerSpeed * rate;

	move = VScale(move, speed);

	//cameraの角度から
	//コントローラによる移動方向を決定する
	MATRIX mtx = MGetRotY(cameraAngle + DX_PI_F);
	move = VTransform(move, mtx);

	//移動方向からプライヤーの向く方向を決定する
	//移動してない場合(ゼロベクトル)の場合は変更しない
	if (VSquareSize(move) > 0.0f)
	{
		angle = atan2f(move.z, -move.x) - DX_PI_F / 2;
	}
	//Playerが動くフラグがTrueなら
	if (PlayerMoveFlag == true)
	{
		Playerpos = VAdd(Playerpos, move);
	}

	

	//Playerが動くフラグがTrueなら
	//if (PlayerMoveFlag == true)
	//{
	//	//前に進む
	//	if (CheckHitKey(KEY_INPUT_W))
	//	{
	//		Playerpos.z += PlayerSpeed;

	//	}
	//	//後ろに進む
	//	if (CheckHitKey(KEY_INPUT_S))
	//	{
	//		Playerpos.z -= PlayerSpeed;

	//	}
	//	//右に進む
	//	if (CheckHitKey(KEY_INPUT_D))
	//	{
	//		Playerpos.x += PlayerSpeed;
	//	}
	//	//左に進む
	//	if (CheckHitKey(KEY_INPUT_A))
	//	{
	//		Playerpos.x -= PlayerSpeed;
	//	}
	//}

	//Playerに重力を与え続ける
	Playerpos.y -= PlayerGravity;

	//Playerが落ち続けたら初期位置に戻す
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
	//3Dモデルのポジション設定
	MV1SetPosition(PlayerGraph, Playerpos);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(PlayerGraph, VGet(-1.55f, angle, 0.0f));

	//3Dモデルを描画する
	MV1DrawModel(PlayerGraph);
}

void Player::End()
{
}
