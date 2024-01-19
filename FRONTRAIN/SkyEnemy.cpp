#include "SkyEnemy.h"
#include "DxLib.h"
#include<cmath>
#include<math.h>

SkyEnemy::SkyEnemy()
{
}

SkyEnemy::~SkyEnemy()
{
}

void SkyEnemy::Init(SkyEnemyStruct& enemy, SkyEnemy& Senemy)
{
	Senemy.Attack = 1;
	Senemy.HP = 1;
	
	enemy.SkyEnemyX = 0.0f;
	enemy.SkyEnemyY = 0.0f;

	enemy.SkyEnemyDead = false;

	enemy.SkyShotDead = false;

	enemy.SkyEnemyflag = false;

	Senemy.SkyEnemyAppearance = true;

	Senemy.T = 0;

	enemy.SkyEnemyGraph = LoadGraph("date/空のエネミー.png");
}

void SkyEnemy::Update(Player& player,Shot& shot, SkyEnemyStruct enemy[], int SenemySize, float ScrollX, TimeCount* time, SkyEnemy& Senemy,Shield& shield)
{
	//敵のスピード設定
	double tb, tbx, tby, px, py, sx, sy;

	//時間がたつと敵が出現
	if (time->EnemyTime == 180 + (3 * Senemy.T))
	{
		if (Senemy.SkyEnemyAppearance == true)
		{
			Senemy.T++;

			for (int i = 0; i < SenemySize; i++)
			{
				if (enemy[i].SkyEnemyflag == false)
				{
					enemy[i].SkyEnemyflag = true;

					//エネミーがランダムな場所に出現
					
					enemy[i].SkyEnemyX = GetRand(640) - ScrollX;

					enemy[i].SkyEnemyY = -10.0f;

					//一体だしたのでループから抜ける
					break;
				}
			}
			Senemy.SkyEnemyAppearance = false;
		}
	}
	else
	{
		Senemy.SkyEnemyAppearance = true;
	}

	for (int i = 0; i < SenemySize; i++)
	{
		if (enemy[i].SkyEnemyflag == true)
		{
			//敵が生きている時
			if (enemy[i].HP >= 0)
			{
				if (enemy[i].Flag == false)
				{
					enemy[i].Flag = true;
					//敵の移動処理
					sx = enemy[i].SkyEnemyX + enemy[i].SkyEnemyWidth / 2;
					sy = enemy[i].SkyEnemyY + enemy[i].SkyEnemyHeight / 2;
					px = player.PlayerX - ScrollX + player.PlayerWidth / 2;
					py = player.PlayerY + player.PlayerHeight / 2;

					tbx = px - sx;
					tby = py - sy;

					tb = sqrt(tbx * tbx + tby * tby);

					//1フレームあたり7ドットで動く
					enemy[i].PX = tbx / tb * 7;
					enemy[i].PY = tby / tb * 7;

					//一体だしたので抜ける
					break;
				}
				
			}

			//当たり判定の更新
			enemy[i].m_colRect.SetCenter(enemy[i].SkyEnemyX + 5 + player.ScrollX, enemy[i].SkyEnemyY + 5, enemy[i].SkyEnemyWidth, enemy[i].SkyEnemyHeight);

			//プレイヤーの当たり判定
			if (enemy[i].m_colRect.IsCollision(player.m_colRect) == false)
			{
				//当たってない
			}
			//当たっている
			else if (enemy[i].m_colRect.IsCollision(player.m_colRect) == true)
			{
				player.HP -= Senemy.Attack;

				enemy[i].HP = -1;

				DeleteGraph(enemy[i].SkyEnemyGraph);
			}

			if (shot.Flag == 1)
			{
				//敵との当たり判定
				if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == false)
				{
					//当たってない
				}
				else if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == true)
				{
					enemy[i].HP -= shot.Damage;
					//接触している場合は当たった弾の存在を消す
					shot.Flag = 0;

					enemy[i].SkyShotDead = true;

					DeleteGraph(shot.Graph);
				}
			}
			//盾との当たり判定
			if (shield.LeftFlag == true || shield.RightFlag == true)
			{
				//盾と接触
				if (enemy[i].m_colRect.IsCollision(shield.m_colRect) == false)
				{
					//当たってない
				}
				else if (enemy[i].m_colRect.IsCollision(shield.m_colRect) == true)
				{
					//盾に当たったら死ぬ
					enemy[i].HP = -1;
				}
			}


		}
	}

}

void SkyEnemy::Draw(float ScrollX, SkyEnemyStruct& enemy, Point& point)
{
	//敵が生きている時
	if (enemy.HP >= 0)
	{
		if (enemy.Flag)
		{
			DrawGraph(enemy.SkyEnemyX + ScrollX, enemy.SkyEnemyY, enemy.SkyEnemyGraph, true);

			enemy.SkyEnemyX += enemy.PX;
			enemy.SkyEnemyY += enemy.PY;

			//敵との当たり判定
			enemy.m_colRect.Draw(GetColor(255, 0, 0), false);
		}
		
	}
	//敵が死んだ時
	else if (enemy.HP <= 0)
	{
		if (enemy.SkyEnemyDead == false)
		{
			enemy.m_colRect.SetCenter(0, 0, 0, 0);
			DeleteGraph(enemy.SkyEnemyGraph);
			if (enemy.SkyShotDead == true)
			{
				point.SenemyPoint += 50;
				
				enemy.SkyShotDead = false;
			}
			enemy.SkyEnemyflag = false;
			enemy.SkyEnemyDead = true;
		}
	}
}
