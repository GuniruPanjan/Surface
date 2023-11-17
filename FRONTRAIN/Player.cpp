#include "Player.h"
#include "DxLib.h"
#include<math.h>

class Shot;

Player::Player():
	HP(100),
	Speed(2),
	playerGraph(0),
	Aiming(0),
	AimingW(0),
	AimingH(0),
	MouseX(0),
	MouseY(0),
	PlayerX(640 / 2),
	PlayerY(480 / 2),
	PlayerShotFlag(false),
	PlayerW(0),
	PlayerH(0),
	ShotGraph(0),
	W(0),
	H(0)
{
	//弾初期化
	memset(shot, 0, sizeof(shot));

	
}

Player::~Player()
{
}

void Player::Init()
{
	DrawGraph(PlayerX, PlayerY, playerGraph, true);

	//プレイヤーの大きさを得る
	GetGraphSize(playerGraph, &PlayerW, &PlayerH);

	//照準の大きさを得る
	GetGraphSize(Aiming, &AimingW, &AimingH);


	//弾の描画
	for (int i = 0; i < SHOT; i++)
	{
		if (shot[i].Flag)
		{
			DrawGraph(shot[i].X, shot[i].Y, shot[i].Graph, true);
		}
	}


	for (int i = 0; i < SHOT; i++)
	{
		W, H;
		//弾画像のサイズ取得
		GetGraphSize(ShotGraph, &W, &H);

		//フラグを全部falseにしておく
		//グラフィックハンドルと画像のサイズを代入
		shot[i].Flag = false;
		shot[i].Graph = ShotGraph;
		shot[i].Width = W;
		shot[i].Height = H;
	}
	
	

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

	//マウスの座標取得
	GetMousePoint(&MouseX, &MouseY);
	
}

void Player::ShotUpdate()
{
	//マウスキー(左クリック)が押されると発射
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		if (PlayerShotFlag == false)
		{
			for (int i = 0; i < SHOT; i++)
			{
				if (shot[i].Flag == false)
				{
					shot[i].Flag = true;
					shot[i].X = PlayerX;
					shot[i].Y = PlayerY;

					//弾の移動速度を設定する
					double sb, sbx, sby, ax, ay, sx, sy;

					sx = shot[i].X + shot[i].Width / 2;
					sy = shot[i].Y + shot[i].Height / 2;

					ax = MouseX + AimingW / 2;
					ay = MouseY + AimingH / 2;

					sbx = ax - sx;
					sby = ay - sy;

					sb = sqrt(sbx * sbx + sby * sby);

					//1フレームあたり10ドットで動く
					shot[i].AimX = sbx / sb * 10;
					shot[i].AimY = sby / sb * 10;

					break;
				}
			}
			PlayerShotFlag = true;
		}

		
	}
	else
	{
		PlayerShotFlag = false;
	}

	//弾を移動させる処理
	for (int i = 0; i < SHOT; i++)
	{
		//発射してる弾だけ
		if (shot[i].Flag)
		{
			shot[i].X += shot[i].AimX;
			shot[i].Y += shot[i].AimY;

			//画面の外にはみ出したらフラグを戻す
			if (shot[i].X > 640 || shot[i].X < 0 || shot[i].Y > 480 || shot[i].Y < 0)
			{
				shot[i].Flag = false;
			}
		}
	}
}

void Player::Draw()
{
	

	//弾画像読み込み
	for (int i = 0; i < SHOT; i++)
	{
		ShotGraph = DrawCircle(shot[i].X, shot[i].Y, 2, GetColor(0, 0, 0), true);
	}

	playerGraph = DrawCircle(PlayerX, PlayerY, 8, GetColor(255, 255, 255), true);
	
	Aiming = LoadGraphScreen(MouseX, MouseY, "date/標準(仮).png", true);
}


	
