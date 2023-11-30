#include "Player.h"
#include "WalkEnemy.h"
#include "DxLib.h"
#include "Map.h"
#include "GraphMode.h"
#include<math.h>



class Shot;
MapEd maped;
Map map;
GraphMode graph;

Player::Player():
	HP(100),
	Speed(2),
	playerGraph(-1),
	Aiming(-1),
	AimingW(0),
	AimingH(0),
	MouseX(0),
	MouseY(0),
	PlayerX(640 / 12),
	PlayerY(480 - 108.1),
	PlayerShotFlag(false),
	PlayerW(0),
	PlayerH(0),
	W(0),
	H(0),
	PlayerRight(false)
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

}

void Player::InitShot(Shot& shot, int shotGraph)
{
	shot.Graph = shotGraph;

	shot.Flag = false;

	GetGraphSize(shot.Graph, &shot.Width, &shot.Height);
}

void Player::Update()
{
	

	//左キーを押したとき
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PlayerX -= Speed;
		//左端から先にいかない
		if (PlayerX < 8)
		{
			PlayerX = 8;
		}
	}
	//右キーを押したとき
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		PlayerX += Speed;
		//真ん中から先に行くと画面がついてくる
		if (PlayerX >= graph.GraphModeWIDTH / 2)
		{
			PlayerRight = true;
			PlayerX = graph.GraphModeWIDTH / 2;
		}
	}

	int Pw, Ph, PwM, PhM;
	float bby;
	Pw = PlayerX + 8; //右辺
	Ph = PlayerY + 8; //下辺
	PwM = PlayerX - 8; //左辺
	PhM = PlayerY - 8; //上辺

	if (map.GetChipParm(Pw, Ph) == (0, 1) || map.GetChipParm(PwM, PhM) == (0, 1))
	{
		PlayerY;
	}
	if (map.GetChipParm(Pw,Ph) == (0,1) || map.GetChipParm(PwM, PhM) == (0,1))
	{
		

		//ブロックに当たっていたら壁を上る
		PlayerY -= 20;
		
	}
	else if(map.GetChipParm(Pw,Ph) == (0,0))
	{
		//下にブロックが無かったら下へ移動
		PlayerY += 20;
	}

	//マウスの座標取得
	GetMousePoint(&MouseX, &MouseY);
	
}

void Player::ShotUpdate(Player& player,Shot shot[], int shotSize)
{
	//マウスキー(左クリック)が押されると発射
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		if (player.PlayerShotFlag == false)
		{
			for (int i = 0; i < shotSize; i++)
			{
				if (shot[i].Flag == false)
				{
					shot[i].Flag = true;
					shot[i].X = player.PlayerX;
					shot[i].Y = player.PlayerY;

					//弾の移動速度を設定する
					double sb, sbx, sby, ax, ay, sx, sy;

					sx = shot[i].X + shot[i].Width / 2;
					sy = shot[i].Y + shot[i].Height / 2;

					ax = player.MouseX + player.AimingW / 2;
					ay = player.MouseY + player.AimingH / 2;

					sbx = ax - sx;
					sby = ay - sy;

					sb = sqrt(sbx * sbx + sby * sby);

					//1フレームあたり10ドットで動く
					shot[i].AimX = sbx / sb * 10;
					shot[i].AimY = sby / sb * 10;

					//一つ弾を出したので弾を出すループから抜ける
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
	
}

void Player::Draw()
{

	
	playerGraph = DrawCircle(PlayerX, PlayerY, 8, GetColor(255, 255, 255), true);

	//プレイヤーの大きさを得る
	GetGraphSize(playerGraph, &PlayerW, &PlayerH);
	
	Aiming = LoadGraph("date/標準(仮).png");

	//照準の大きさを得る
	GetGraphSize(Aiming, &AimingW, &AimingH);

	DrawGraph(MouseX, MouseY, Aiming, true);
}

void Player::DrawShot(Shot& shot)
{
	//弾の移動
	//発射してる弾数だけ
	if (shot.Flag)
	{
		shot.X += shot.AimX;
		shot.Y += shot.AimY;

		//画面の外にはみ出したらフラグを戻す
		if (shot.X > 640 || shot.X < 0 || shot.Y > 480 || shot.Y < 0)
		{
			shot.Flag = false;
		}

		DrawGraph(shot.X, shot.Y, shot.Graph, true);
	}

}



	
