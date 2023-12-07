#include "WalkEnemy.h"
#include "DxLib.h"
#include<cmath>


WalkEnemy::WalkEnemy():
	WalkEnemyGraph(0),
	WalkEnemyX(610.00f),
	WalkEnemyY(360.00f),
	WalkEnemyWidth(20),
	WalkEnemyHeight(20),
	WalkEnemyW(0),
	WalkEnmeyH(0),
	WalkEnemySpeed(0.03f)
{
	WalkEnemyTime = GetNowCount();
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init(WalkEnemy& enemy,TimeCount* time)
{
	time->WalkEnemyTime;

	if (time->WalkEnemyTime  == 5)
	{
		DrawString(200, 200, "出た", GetColor(255, 255, 255));
		//エネミーがランダムな場所に出現
		if (GetRand(1) == 0)
		{
			enemy.WalkEnemyX = 680.00f;
		}
		if (GetRand(1) == 1)
		{
			enemy.WalkEnemyX = -20.0f;
		}

		enemy.WalkEnemyflag = true;
	}
	
	
}

void WalkEnemy::Update(Player& player,Shot& shot,WalkEnemy& enemy)
{

	if (enemy.WalkEnemyflag == true)
	{
		//エネミーが生きている時
		if (enemy.HP >= 0)
		{
			//敵の移動処理
			if (player.PlayerX - player.ScrollX <= enemy.WalkEnemyX)
			{
				enemy.WalkEnemyX -= enemy.WalkEnemySpeed;
			}
			else if (player.PlayerX - player.ScrollX > enemy.WalkEnemyX)
			{
				enemy.WalkEnemyX += enemy.WalkEnemySpeed;
			}

			//当たり判定の更新
			m_colRect.SetCenter(enemy.WalkEnemyX + 10 + player.ScrollX, enemy.WalkEnemyY + 10, enemy.WalkEnemyWidth, enemy.WalkEnemyHeight);

			//プレイヤーの当たり判定
			if (m_colRect.IsCollision(player.m_colRect) == false)
			{
				//当たってない
			}
			//当たっている
			else if (m_colRect.IsCollision(player.m_colRect) == true)
			{
				DrawString(0, 0, "当たった", GetColor(255, 255, 255));
			}

			if (shot.Flag == 1)
			{
				//敵との当たり判定
				if (m_colRect.IsCollision(shot.m_colRect) == false)
				{

				}
				else if (m_colRect.IsCollision(shot.m_colRect) == true)
				{
					DrawString(500, 0, "当たった", GetColor(255, 255, 255));
					enemy.HP -= shot.Damage;
					//接触している場合は当たった弾の存在を消す
					shot.Flag = 0;
				}

			}
		}
	}		
}

void WalkEnemy::Draw(int ScrollX,WalkEnemy& enemy, Point& point)
{
	//エネミーが生きている時
	if (enemy.HP >= 0)
	{
		enemy.WalkEnemyGraph = LoadGraph("date/エネミー(仮).png");
		//エネミーの大きさ取得
		GetGraphSize(enemy.WalkEnemyGraph, &enemy.WalkEnemyW, &enemy.WalkEnmeyH);

		DrawGraph(enemy.WalkEnemyX + ScrollX, enemy.WalkEnemyY, enemy.WalkEnemyGraph, true);

		//エネミーの当たり判定の表示
		enemy.m_colRect.Draw(GetColor(255, 0, 0), false);
		//WalkEnemyGraph = DrawBox(WalkEnemyX, WalkEnemyY, 630, 250, GetColor(255, 255, 0), true);
	}
	//敵が死んだ時
	else if (enemy.HP <= 0)
	{
		if (enemy.WalkEnemyDead == false)
		{
			DrawString(500, 0, "死んだ", GetColor(255, 255, 255));
			DeleteGraph(enemy.WalkEnemyGraph);
			point.WenemyPoint += 100;
			enemy.WalkEnemyDead = true;
			enemy.WalkEnemyflag = false;
		}
		
	}
}
