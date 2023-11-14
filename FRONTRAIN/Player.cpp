#include "Player.h"
#include "Shot.h"
#include "DxLib.h"

class Shot;

Player::Player():
	HP(100),
	Speed(2),
	playerGraph(0),
	PlayerX(640 / 2),
	PlayerY(480 / 2),
	PlayerShotFlag(false),
	PlayerW(0),
	PlayerH(0)
{

}

Player::~Player()
{
}

void Player::Init()
{
	DrawGraph(PlayerX, PlayerY, playerGraph, true);

	//プレイヤーの大きさを得る
	GetGraphSize(playerGraph, &PlayerW, &PlayerH);
}

void Player::Update()
{
	

	//左キーを押したとき
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PlayerX -= Speed;
	}
	//右キーを押したとき
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		PlayerX += Speed;
	}

	//弾の発射処理
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		//前フレームでショットボタンを押したか保存されている変数がfalseだったら弾を発射
		if (PlayerShotFlag == false)
		{
			//画面上に出てない弾の数を調べる
			for (int i = 0; i < SHOT; i++)
			{
				//弾が画面上に出てない場合は弾を出す
				if (shot[i]->ShotFlag == false)
				{
					//弾の位置をセット
					shot[i].X = (PlayerW - shot[i].Wdit) + PlayerX;
					shot[i].Y = (PlayerH - shot[i].Hight) + PlayerY;

					//弾は現時点をもって存在する
					shot[i].ShotFlag = true;

					//弾を出すループから抜ける
					break;
				}
			}
		}
		//前フレームでショットボタンを押したか保存されている変数が
		PlayerShotFlag = true;
	}
	else
	{
		//ショットボタンが押されていなかったらfalseを代入
		PlayerShotFlag = false;
	}
}

void Player::Draw()
{
	playerGraph = DrawCircle(PlayerX , PlayerY, 3, GetColor(255, 255, 255), true);
}
