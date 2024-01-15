#include "WalkEnemy.h"
#include "DxLib.h"
#include<cmath>


WalkEnemy::WalkEnemy()
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init(WalkEnemyStruct& enemy,WalkEnemy& Wenemy)
{
	Wenemy.Attack = 2;
	Wenemy.HP = 10;

	enemy.WalkEnemyX = -20.0f;
	enemy.WalkEnemyY = 360.0f;

	enemy.WalkEnemyflag = false;

	Wenemy.T = 1;

	enemy.WalkEnemyGraph = LoadGraph("date/エネミー(仮).png");

}

void WalkEnemy::Update(Player& player,Shot& shot,WalkEnemyStruct enemy[],int WenemySize, float ScrollX, TimeCount* time, WalkEnemy& Wenemy)
{
	//時間がたつと敵が出現
	if (time->WalkEnemyTime == 5 * Wenemy.T)
	{
		if (Wenemy.WalkEnemyAppearance == true)
		{
			Wenemy.T++;

			for (int i = 0; i < WenemySize; i++)
			{
				if (enemy[i].WalkEnemyflag == false)
				{
					enemy[i].WalkEnemyflag = true;

					//エネミーがランダムな場所に出現
					if (GetRand(1) == 0)
					{
						enemy[i].WalkEnemyX = -40.0f - ScrollX;
					}
					if (GetRand(1) == 1)
					{
						enemy[i].WalkEnemyX = 680.0f - ScrollX;
					}

					enemy[i].WalkEnemyY = 360.0f;

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
				enemy[i].m_colRect.SetCenter(enemy[i].WalkEnemyX + 10 + player.ScrollX, enemy[i].WalkEnemyY + 10, enemy[i].WalkEnemyWidth, enemy[i].WalkEnemyHeight);

				//プレイヤーの当たり判定
				if (enemy[i].m_colRect.IsCollision(player.m_colRect) == false)
				{
					//当たってない
				}
				//当たっている
				else if (enemy[i].m_colRect.IsCollision(player.m_colRect) == true)
				{
					player.HP -= Wenemy.Attack;
				}

				if (shot.Flag == 1)
				{
					//敵との当たり判定
					if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == false)
					{

					}
					else if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == true)
					{
						enemy[i].HP -= shot.Damage;
						//接触している場合は当たった弾の存在を消す
						shot.Flag = 0;

						DeleteGraph(shot.Graph);
					}

				}
			}

		}
	}
	
}

void WalkEnemy::Draw(float ScrollX,WalkEnemyStruct& enemy, Point& point)
{
	//エネミーが生きている時
	if (enemy.HP >= 0)
	{
		DrawGraph(enemy.WalkEnemyX + ScrollX, enemy.WalkEnemyY, enemy.WalkEnemyGraph, true);

		//エネミーの当たり判定の表示
		enemy.m_colRect.Draw(GetColor(255, 0, 0), false);
	}
	//敵が死んだ時
	else if (enemy.HP <= 0)
	{
		if (enemy.WalkEnemyDead == false)
		{
			DeleteGraph(enemy.WalkEnemyGraph);
			point.WenemyPoint += 100;
			enemy.WalkEnemyDead = true;
			enemy.WalkEnemyflag = false;
		}

	}

	//敵が画面外から離れすぎたら消す
	if (enemy.WalkEnemyX <= -80 || enemy.WalkEnemyY <= 50 || enemy.WalkEnemyY >= 500)
	{
		DeleteGraph(enemy.WalkEnemyGraph);
	}
	
}
