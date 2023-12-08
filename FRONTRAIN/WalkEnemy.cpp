#include "WalkEnemy.h"
#include "DxLib.h"
#include<cmath>


WalkEnemy::WalkEnemy()
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init(WalkEnemyStruct enemy,WalkEnemy& Wenemy)
{
	enemy.WalkEnemyX = -20.0f;
	enemy.WalkEnemyY = 360.0f;

	enemy.WalkEnemyflag = false;

	Wenemy.T = 1;
}

void WalkEnemy::Update(Player& player,Shot& shot,WalkEnemyStruct enemy[],int WenemySize, int ScrollX, TimeCount* time, WalkEnemy& Wenemy)
{
	
	//時間がたつと敵が出現
	if (time->WalkEnemyTime == 10 * Wenemy.T)
	{
		if (Wenemy.WalkEnemyAppearance == true)
		{
			for (int i = 0; i < WenemySize; i++)
			{
				if (enemy[i].WalkEnemyflag == false)
				{
					enemy[i].WalkEnemyflag = true;

					DrawString(200, 200, "出た", GetColor(255, 255, 255));
					//エネミーがランダムな場所に出現
					if (GetRand(1) == 0)
					{
						enemy[i].WalkEnemyX = -40.0f;
					}
					if (GetRand(1) == 1)
					{
						enemy[i].WalkEnemyX = 680.00f + ScrollX;
					}

					enemy[i].WalkEnemyY = 360.00f;

					Wenemy.T++;

					//一体だしたのでループから抜ける
					break;
				}

			}
			Wenemy.WalkEnemyAppearance = false;
		}

	}
	else
	{
		Wenemy.WalkEnemyAppearance = true;
	}

	for (int i = 0; i < WenemySize; i++)
	{
		if (enemy[i].WalkEnemyflag == true)
		{
			//エネミーが生きている時
			if (enemy[i].HP >= 0)
			{
				//敵の移動処理
				if (player.PlayerX - player.ScrollX <= enemy[i].WalkEnemyX)
				{
					enemy[i].WalkEnemyX -= enemy[i].WalkEnemySpeed;
				}
				else if (player.PlayerX - player.ScrollX > enemy[i].WalkEnemyX)
				{
					enemy[i].WalkEnemyX += enemy[i].WalkEnemySpeed;
				}

				//当たり判定の更新
				m_colRect.SetCenter(enemy[i].WalkEnemyX + 10 + player.ScrollX, enemy[i].WalkEnemyY + 10, enemy[i].WalkEnemyWidth, enemy[i].WalkEnemyHeight);

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
						enemy[i].HP -= shot.Damage;
						//接触している場合は当たった弾の存在を消す
						shot.Flag = 0;
					}

				}
			}

		}
	}
	
}

void WalkEnemy::Draw(int ScrollX,WalkEnemyStruct& enemy, Point& point)
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
