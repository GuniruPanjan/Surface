#include "WalkEnemy.h"
#include "DxLib.h"
#include<cmath>


WalkEnemy::WalkEnemy():
	T(0),
	TUP(20),
	WalkEnemyAppearance(true)
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init(WalkEnemyStruct enemy[], WalkEnemy& Wenemy,int WenemySize)
{
	for (int i = 0; i < WenemySize; i++)
	{
		enemy[i].WalkEnemyX = -30.0f;
		enemy[i].WalkEnemyY = -30.0f;

		enemy[i].WalkEnemyDead = false;

		enemy[i].WalkShotDead = false;

		enemy[i].WalkEnemyflag = false;

		enemy[i].AnimTime = 0;

		enemy[i].RightAnim = 11;

		enemy[i].LeftAnim = 0;

		LoadDivGraph("date/WalkEnemy.png", 12, 6, 2, 20, 25, enemy[i].WalkEnemyGraph);

		LoadDivGraph("date/爆発Down.png", 14, 8, 2, 30, 30, enemy[i].Handle);

		enemy[i].AnimCount = 9;

		enemy[i].AnimTimeDead = 0;
	}

	Wenemy.Attack = 2;

	Wenemy.HP = 10;

	Wenemy.WalkEnemyAppearance = true;

	Wenemy.T = 0;

	Wenemy.TUP = 20;

}

void WalkEnemy::Update(Player& player,Shot& shot,WalkEnemyStruct enemy[],int WenemySize, float ScrollX, TimeCount* time, WalkEnemy& Wenemy)
{
	//時間がたつと敵が出現
	//2分以下の場合
	if (time->EnemyTime < 120)
	{
		if (time->EnemyTime == 10 + (12 * Wenemy.T))
		{
			if (Wenemy.WalkEnemyAppearance == true)
			{
				Wenemy.T++;

				for (int i = 0; i < WenemySize; i++)
				{
					if (enemy[i].WalkEnemyflag == false)
					{
						enemy[i].WalkEnemyDead = false;

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
	}
	//2分経過したら出現率アップ
	else if (time->EnemyTime >= 120)
	{
		if (time->EnemyTime == (6 * Wenemy.TUP))
		{
			if (Wenemy.WalkEnemyAppearance == true)
			{
				Wenemy.TUP++;

				for (int i = 0; i < WenemySize; i++)
				{
					if (enemy[i].WalkEnemyflag == false)
					{
						enemy[i].WalkEnemyDead = false;

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
				enemy[i].m_colRect.SetCenter(enemy[i].WalkEnemyX + 10 + player.ScrollX, enemy[i].WalkEnemyY + 10, enemy[i].WalkEnemyWidth - 5, enemy[i].WalkEnemyHeight);

				//プレイヤーの当たり判定
				if (enemy[i].m_colRect.IsCollision(player.m_colRect) == false)
				{
					//当たってない
				}
				//当たっている
				else if (enemy[i].m_colRect.IsCollision(player.m_colRect) == true)
				{
					//1回だけ実行
					if (player.PlayerDamage == false)
					{
						player.HP -= Wenemy.Attack;

						player.PlayerDamage = true;
					}

					enemy[i].HP = -1;
					
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

						enemy[i].WalkShotDead = true;
						
					}

				}

			}

		}
	}
	
}

void WalkEnemy::Draw(float ScrollX,WalkEnemyStruct enemy[], Point& point,int WenemySize,Player& player,Shot shot[])
{
	for (int i = 0; i < WenemySize; i++)
	{
		//エネミーが生きている時
		if (enemy[i].HP > 0)
		{


			//プレイヤーよりエネミーが右にいる場合
			if (enemy[i].WalkEnemyX + player.ScrollX > player.PlayerX)
			{
				enemy[i].AnimTime++;
				if (enemy[i].AnimTime >= 10)
				{
					enemy[i].RightAnim--;

					enemy[i].AnimTime = 0;
				}

				if (enemy[i].RightAnim == 6)enemy[i].RightAnim = 10;

				DrawGraph(enemy[i].WalkEnemyX + ScrollX, enemy[i].WalkEnemyY - 5, enemy[i].WalkEnemyGraph[enemy[i].RightAnim], true);
			}
			//プレイヤーよりエネミーが左にいる場合
			if (enemy[i].WalkEnemyX + player.ScrollX < player.PlayerX)
			{
				enemy[i].AnimTime++;
				if (enemy[i].AnimTime >= 10)
				{
					enemy[i].LeftAnim++;

					enemy[i].AnimTime = 0;
				}

				if (enemy[i].LeftAnim == 6)enemy[i].LeftAnim = 1;

				DrawGraph(enemy[i].WalkEnemyX + ScrollX, enemy[i].WalkEnemyY - 5, enemy[i].WalkEnemyGraph[enemy[i].LeftAnim], true);
			}

			for (int s = 0; s < SHOT; s++)
			{
				//プレイヤーの弾が当たった時
				if (enemy[i].m_colRect.IsCollision(shot[s].m_colRect) == true)
				{
					shot[s].ShotAnimTime++;

					//プレイヤーよりエネミーが右にいる場合
					if (enemy[i].WalkEnemyX + player.ScrollX > player.PlayerX)
					{
						if (shot[s].ShotAnimTime >= 10)
						{
							shot[s].ShotAnimCountRight++;

							shot[s].ShotAnimTime = 0;
						}

						DrawGraph(shot[s].X, shot[s].Y, shot[s].ShotAnimGraphRight[shot[s].ShotAnimCountRight], true);

					}
					//プレイヤーよりエネミーが左にいる場合
					if (enemy[i].WalkEnemyX + player.ScrollX < player.PlayerX)
					{
						if (shot[s].ShotAnimTime >= 10)
						{
							shot[s].ShotAnimCountLeft++;

							shot[s].ShotAnimTime = 0;
						}

						DrawGraph(shot[s].X, shot[s].Y, shot[s].ShotAnimGraphLeft[shot[s].ShotAnimCountLeft], true);

					}


				}
				shot[s].ShotAnimCountRight = 0;
				shot[s].ShotAnimCountLeft = 0;
			}

			


			//エネミーの当たり判定の表示
			//enemy[i].m_colRect.Draw(GetColor(255, 0, 0), false);
		}
		//敵が死んだ時
		else if (enemy[i].HP <= 0)
		{
			if (enemy[i].WalkEnemyDead == false)
			{
				enemy[i].AnimTimeDead++;
				if (enemy[i].AnimTimeDead >= 5)
				{
					enemy[i].AnimCount++;

					enemy[i].AnimTimeDead = 0;
				}

				DrawGraph(enemy[i].WalkEnemyX + ScrollX, enemy[i].WalkEnemyY - 5, enemy[i].Handle[enemy[i].AnimCount], true);

				enemy[i].m_colRect.SetCenter(0, 0, 0, 0);
				if (enemy[i].WalkShotDead == true)
				{
					point.WenemyPoint += 100;

					enemy[i].WalkShotDead = false;
				}

				enemy[i].WalkEnemyflag = false;

				if (enemy[i].AnimCount == 13)
				{
					enemy[i].HP = 10;

					enemy[i].WalkEnemyX = -30.0f;
					enemy[i].WalkEnemyY = -30.0f;



					enemy[i].WalkEnemyDead = true;
				}

				
			}

		}
		if (enemy[i].WalkEnemyDead == true)
		{
			enemy[i].AnimCount = 9;
		}

	}
	
	
	
}
