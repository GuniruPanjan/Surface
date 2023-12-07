#include "Player.h"
#include "WalkEnemy.h"
#include "DxLib.h"
#include "GraphMode.h"
#include<math.h>



class Shot;
MapEd maped;
Map map;
GraphMode graph;

Player::Player():
	HP(100),
	Speed(2.0f),
	playerGraph(-1),
	Aiming(-1),
	AimingW(0),
	AimingH(0),
	MouseX(0),
	MouseY(0),
	PlayerWidth(16),
	PlayerHeight(16),
	PlayerX(640.00f / 12),
	PlayerY(480.00f - 100.0f),
	ScrollX(0),
	ScrollY(0),
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

void Player::Update(Player& player,Map& map)
{
	//player.PlayerY += player.Gravity;
	if (m_colRect.IsCollision(map.m_colRect) == true)
	{
		DrawString(200, 100, "地面にいる", GetColor(255, 255, 255));
	}

	int Pw, Ph, PwM, PhM;
	Pw = player.PlayerX + 8; //右辺
	Ph = player.PlayerY + 8; //下辺
	PwM = player.PlayerX - 8; //左辺
	PhM = player.PlayerY - 8; //上辺

	//左キーを押したとき
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		player.PlayerX -= Speed;
		//左端から先にいかない
		if (player.PlayerX < 8)
		{
			player.PlayerX = 8;
		}
	}
	//右キーを押したとき
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		player.PlayerX += player.Speed;
		//真ん中から先に行くと画面がついてくる
		if (player.PlayerX >= graph.GraphModeWIDTH / 4)
		{
			player.PlayerRight = true;
			player.PlayerX = graph.GraphModeWIDTH / 4;
		}
		
	}
	//移動してないと画面が止まる
	else if (player.PlayerX <= graph.GraphModeWIDTH / 2)
	{
		//停止中は画面のスクロールは行わない
		player.PlayerRight = false;
		
		
	}

	if (player.PlayerRight == true)
	{
		//プレイヤー操作からスクロール量を算出する
		player.ScrollX -= Speed;
		player.ScrollY = 0;
	}
	
	
	//当たり判定の更新
	m_colRect.SetCenter(player.PlayerX, player.PlayerY, player.PlayerWidth, player.PlayerHeight);


	

	//マウスの座標取得
	GetMousePoint(&player.MouseX, &player.MouseY);
	
}


void Player::ShotUpdate(Player& player,Shot shot[], int shotSize)
{
	

	//マウスキー(左クリック)が押されると発射
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		//弾が入っていると撃てる
		if (player.Bullet > 0)
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

						player.Bullet--;

						//一つ弾を出したので弾を出すループから抜ける
						break;
					}
				}
				player.PlayerShotFlag = true;
			}
		}
		else if (player.Bullet <= 0)
		{
			DrawString(100, 100, "弾切れ", GetColor(255, 255, 255));
		}
	}
	else
	{
		player.PlayerShotFlag = false;
	}

	//右クリックで弾をリロード
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		player.Bullet = 12;
	}
}

void Player::Draw()
{

	
	playerGraph = DrawCircle(PlayerX, PlayerY, 8, GetColor(255, 255, 255), true);

	//プレイヤーの大きさを得る
	GetGraphSize(playerGraph, &PlayerW, &PlayerH);
	
	Aiming = LoadGraph("date/標準(仮).png");

	//プレイヤーの当たり判定の表示
	m_colRect.Draw(GetColor(0, 0, 255), false);

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

		//当たり判定の更新
		shot.m_colRect.SetCenter(shot.X, shot.Y, shot.Width, shot.Height);

		//画面の外にはみ出したらフラグを戻す
		if (shot.X > 640 || shot.X < 0 || shot.Y > 480 || shot.Y < 0)
		{
			shot.Flag = false;
		}

		

		DrawGraph(shot.X, shot.Y, shot.Graph, true);

		shot.m_colRect.Draw(GetColor(0, 255, 0), false);
	}

}



	
