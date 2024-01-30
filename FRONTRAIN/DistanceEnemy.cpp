#include "DistanceEnemy.h"
#include "DxLib.h"
#include<cmath>
#include<math.h>

DistanceEnemy::DistanceEnemy()
{
}

DistanceEnemy::~DistanceEnemy()
{
}

void DistanceEnemy::Init(DistanceEnemyStruct& enemy, DistanceEnemy& Denemy)
{
	Denemy.Attack = 2;
	Denemy.HP = 5;

	enemy.DistanceEnemyX = -30.0f;
	enemy.DistanceEnemyY = -30.0f;

	enemy.DistanceEnemyDead = false;

	enemy.DistanceShotDead = false;

	enemy.DistanceEnemyflag = false;

	Denemy.DistanceEnemyAppearance = true;

	Denemy.T = 0;

	Denemy.TUP = 15;

	enemy.Time = 0;

	enemy.ShotEnemy = 0;
	enemy.ShotDistance = 1;

	enemy.EnemyShotFlag = true;

	enemy.m_DeadAnimFrame;

	enemy.DistanceEnemyGraph = LoadGraph("date/DistanceEnemy.png");

	LoadDivGraph("date/爆発Down.png", 14, 8, 2, 30, 30, enemy.Handle);

	enemy.AnimCount = 0;

	enemy.AnimTime = 0;
}

void DistanceEnemy::EnemyShotInit(EnemyShot shot[])
{
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		shot[i].Flag = false;

		shot[i].ShotDamage = 2;

		shot[i].Graph = LoadGraph("date/銃弾.png");

		shot[i].ShotHitTime = 0;

		shot[i].ShotHitLeftCount = 0;
		shot[i].ShotHitRightCount = 0;

		LoadDivGraph("date/血しぶき(小)左.png", 2, 2, 1, 5, 5, shot[i].ShotHitGraphLeft);
		LoadDivGraph("date/血しぶき(小)右.png", 2, 2, 1, 5, 5, shot[i].ShotHitGraphRight);

		shot[i].ShotSparkTime = 0;

		shot[i].ShotSparkLeftCount = 0;
		shot[i].ShotSparkRightCount = 0;

		LoadDivGraph("date/火花(小)左.png", 2, 2, 1, 5, 5, shot[i].ShotSparkGraphLeft);
		LoadDivGraph("date/火花(小)右.png", 2, 2, 1, 5, 5, shot[i].ShotSparkGraphRight);

	}
}

void DistanceEnemy::Update(Player& player, Shot& shot, DistanceEnemyStruct enemy[], int DenemySize, float ScrollX, TimeCount* time, DistanceEnemy& Denemy,EnemyShot enemyshot[],int EnemyShotSize,Shield& shield)
{
	//時間がたつと敵が出現
	//2分以下だった場合
	if (time->EnemyTime < 120)
	{
		if (time->EnemyTime == 60 + (16 * Denemy.T))
		{
			if (Denemy.DistanceEnemyAppearance == true)
			{
				Denemy.T++;

				for (int i = 0; i < DenemySize; i++)
				{
					if (enemy[i].DistanceEnemyflag == false)
					{
						//現在時間を得る
						//enemy[i].Time = GetNowCount();

						//enemy[i].Time = 0;

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//エネミーがランダムな場所に出現
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//一体だしたのでループから抜ける
						break;
					}
				}
				Denemy.DistanceEnemyAppearance = false;
			}
		}
		else
		{
			Denemy.DistanceEnemyAppearance = true;
		}
	}
	//2分たった場合は出現率アップ
	else if (time->EnemyTime >= 120)
	{
		if (time->EnemyTime == (8 * Denemy.TUP))
		{
			if (Denemy.DistanceEnemyAppearance == true)
			{
				Denemy.TUP++;

				for (int i = 0; i < DenemySize; i++)
				{
					if (enemy[i].DistanceEnemyflag == false)
					{
						//現在時間を得る
						//enemy[i].Time = GetNowCount();

						//enemy[i].Time = 0;

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//エネミーがランダムな場所に出現
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//一体だしたのでループから抜ける
						break;
					}
				}
				Denemy.DistanceEnemyAppearance = false;
			}
		}
		else
		{
			Denemy.DistanceEnemyAppearance = true;
		}
	}
	

	for (int i = 0; i < DenemySize; i++)
	{
		if (enemy[i].DistanceEnemyflag == true)
		{
			//敵が生きている時
			if (enemy[i].HP >= 0)
			{
				//敵の移動処理
				//右から
				if (player.PlayerX - player.ScrollX + 200 < enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX -= enemy[i].DistanceEnemySpeed + 0.02f;
				}
				//右に逃げる
				else if (player.PlayerX - player.ScrollX + 200 > enemy[i].DistanceEnemyX && player.PlayerX - player.ScrollX < enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX += enemy[i].DistanceEnemySpeed;
				}
				//左から
				if (player.PlayerX - player.ScrollX - 150 > enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX += enemy[i].DistanceEnemySpeed + 0.02f;
				}
				//左に逃げる
				else if (player.PlayerX - player.ScrollX - 150 < enemy[i].DistanceEnemyX && player.PlayerX - player.ScrollX > enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX -= enemy[i].DistanceEnemySpeed;
			
				}

				//敵の攻撃行動
				/*enemy[i].ShotEnemy = (GetNowCount() - enemy[i].Time) / 1000;

				if (enemy[i].ShotEnemy == 4 * enemy[i].ShotDistance)
				{
					enemy[i].EnemyShotFlag = false;

					for (int j = 0; j < EnemyShotSize; j++)
					{
						enemyshot[j].Flag = false;
					}

					enemy[i].ShotDistance++;
				}*/

				enemy[i].Time++;
				if (enemy[i].Time >= 4000)
				{
					enemy[i].EnemyShotFlag = false;

					for (int j = 0; j < EnemyShotSize; j++)
					{
						enemyshot[j].Flag = false;
					}

					enemy[i].Time = 0;
				}



				//当たり判定の更新
				enemy[i].m_colRect.SetCenter(enemy[i].DistanceEnemyX + 10 + player.ScrollX, enemy[i].DistanceEnemyY + 10, enemy[i].DistanceEnemyWidth, enemy[i].DistanceEnemyHeight);

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
						player.HP -= Denemy.Attack;

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

						if (enemy[i].HP <= 0)
						{
							enemy[i].DistanceShotDead = true;
						}

					}

				}
			}
			
		}
	}
}

//敵の攻撃行動
void DistanceEnemy::EnemyShotUpdate(DistanceEnemyStruct enemy[], EnemyShot& shot, int enemySize, Player& player, float ScrollX, Shield& shield)
{
	for (int i = 0; i < enemySize; i++)
	{
		if (enemy[i].EnemyShotFlag == false)
		{
			if (shot.Flag == false)
			{
				shot.Flag = true;
				shot.X = enemy[i].DistanceEnemyX;
				shot.Y = enemy[i].DistanceEnemyY + enemy[i].DistanceEnemyHeight / 2;

				//弾の移動速度を設定する
				double sb, sbx, sby, ax, ay, sx, sy;

				sx = shot.X;
				sy = shot.Y;

				//標的の場所
				ax = player.PlayerX - ScrollX;
				ay = player.PlayerY;

				sbx = ax - sx;
				sby = ay - sy;

				sb = sqrt(sbx * sbx + sby * sby);

				//1フレームあたり10ドットで動く
				shot.PX = sbx / sb * 5;
				shot.PY = sby / sb * 5;

				//一つ弾を出したので弾を出すループから抜ける
				break;
			}
		}
	    enemy[i].EnemyShotFlag = true;
	}

	if (shot.Flag == true)
	{

		//盾との接触判定
		if (shield.LeftFlag == true || shield.RightFlag == true)
		{
			//盾との当たり判定
			if (shot.m_colRect.IsCollision(shield.m_colRect) == false)
			{
				//当たってない

			}
			else if (shot.m_colRect.IsCollision(shield.m_colRect) == true)
			{

				//接触した弾の存在を消す
				shot.Flag = false;
			}
		}


		//プレイヤーとの当たり判定
		if (shot.m_colRect.IsCollision(player.m_colRect) == false)
		{

		}
		else if (shot.m_colRect.IsCollision(player.m_colRect) == true)
		{
			//1回だけ実行
			if (player.PlayerDamage == false)
			{
				player.HP -= shot.ShotDamage;

				player.PlayerDamage = true;
			}

			//接触している場合は当たった弾の存在を消す
			shot.Flag = false;
		}

	}
}

void DistanceEnemy::Draw(float ScrollX, DistanceEnemyStruct& enemy, Point& point, Player& player,int DownAnimGraph,Shot shot[])
{
	//エネミーが生きている時
	if (enemy.HP > 0)
	{
		if (enemy.DistanceEnemyX + ScrollX > player.PlayerX)
		{
			DrawGraph(enemy.DistanceEnemyX + ScrollX, enemy.DistanceEnemyY - 3, enemy.DistanceEnemyGraph, true);
		}
		else if (enemy.DistanceEnemyX + ScrollX < player.PlayerX)
		{
			DrawTurnGraph(enemy.DistanceEnemyX + ScrollX, enemy.DistanceEnemyY - 3, enemy.DistanceEnemyGraph, true);
		}

		for (int s = 0; s < SHOT; s++)
		{
			//プレイヤーの弾が当たった時
			if (enemy.m_colRect.IsCollision(shot[s].m_colRect) == true)
			{
				shot[s].ShotSparkTime++;

				//プレイヤーよりエネミーが右にいる場合
				if (enemy.DistanceEnemyX + ScrollX > player.PlayerX)
				{
					if (shot[s].ShotSparkTime >= 10)
					{
						shot[s].ShotSparkCountRight++;

						shot[s].ShotSparkTime = 0;
					}

					DrawGraph(shot[s].X, shot[s].Y, shot[s].ShotSparkGraphRight[shot[s].ShotSparkCountRight], true);
				}
				//プレイヤーよりエネミーが左にいる場合
				if (enemy.DistanceEnemyX + ScrollX < player.PlayerX)
				{
					if (shot[s].ShotSparkTime >= 10)
					{
						shot[s].ShotSparkCountLeft++;

						shot[s].ShotAnimTime = 0;
					}

					DrawGraph(shot[s].X, shot[s].Y, shot[s].ShotSparkGraphLeft[shot[s].ShotSparkCountLeft], true);
				}
			}

			shot[s].ShotSparkCountRight = 0;
			shot[s].ShotSparkCountLeft = 0;

			
		}


		//エネミーの当たり判定の表示
		//enemy.m_colRect.Draw(GetColor(255, 0, 0), false);
	}
	//敵が死んだ時
	else if (enemy.HP <= 0)
	{	

		if (enemy.DistanceEnemyDead == false)
		{
			enemy.AnimTime++;
			if (enemy.AnimTime >= 2)
			{
				enemy.AnimCount++;
				
				enemy.AnimTime = 0;
			}

			DrawGraph(enemy.DistanceEnemyX + ScrollX, enemy.DistanceEnemyY - 3, enemy.Handle[enemy.AnimCount], true);


			
				if (enemy.DistanceShotDead == true)
				{
					point.DenemyPoint += 120;

					enemy.DistanceShotDead = false;
				}

				enemy.DistanceEnemyflag = false;

				if (enemy.AnimCount == 13)
				{

					/*DrawRectRotaGraph(static_cast<int>(enemy.DistanceEnemyX), static_cast<int>(enemy.DistanceEnemyY)
						, srcX, srcY, kWidth, kHeight, 1.0, 0.0, DownAnimGraph, true, false);*/

					enemy.HP = 5;

					enemy.DistanceEnemyX = -30.0f;
					enemy.DistanceEnemyY = -30.0f;

					enemy.DistanceEnemyDead = true;

				}

			
		}
		

	}
	if (enemy.DistanceEnemyDead == true)
	{
		enemy.AnimCount = 0;
	}
}

void DistanceEnemy::DrawShot(EnemyShot shot[],int EnemyShotSize,int ScrollX,Player& player,Shield& shield)
{
	//弾の移動
	//発射してる弾数だけ
	for (int i = 0; i < EnemyShotSize; i++)
	{
		if (shot[i].Flag == true)
		{
			//shot[i].Graph = LoadGraph("date/銃弾.png");

			shot[i].X += shot[i].PX;
			shot[i].Y += shot[i].PY;

			DrawGraph(shot[i].X + ScrollX, shot[i].Y, shot[i].Graph, true);

			//あたり判定の更新
			shot[i].m_colRect.SetCenter(shot[i].X + ScrollX, shot[i].Y, shot[i].Width, shot[i].Height);

			shot[i].m_colRect.Draw(GetColor(0, 0, 255), false);

			//画面上に行きすぎたら消す
			if (shot[i].Y <= -10)
			{
				shot[i].Flag = false;

				//DeleteGraph(shot[i].Graph);
			}


			//盾に当たった時
			//盾が右だった場合
			if (shield.RightFlag == true)
			{
				if (shot[i].m_colRect.IsCollision(shield.m_colRect) == true)
				{

					shot[i].ShotSparkTime++;
					if (shot[i].ShotSparkTime >= 10)
					{
						shot[i].ShotSparkRightCount++;

						shot[i].ShotSparkTime = 0;
					}

					DrawGraph(shot[i].X + ScrollX, shot[i].Y, shot[i].ShotSparkGraphRight[shot[i].ShotSparkRightCount], true);

				}
			}
			//盾が左だった場合
			if (shield.LeftFlag == true)
			{
				if (shot[i].m_colRect.IsCollision(shield.m_colRect) == true)
				{
					shot[i].ShotSparkTime++;
					if (shot[i].ShotSparkTime >= 10)
					{
						shot[i].ShotSparkLeftCount++;

						shot[i].ShotSparkTime = 0;
					}

					DrawGraph(shot[i].X + ScrollX, shot[i].Y, shot[i].ShotSparkGraphLeft[shot[i].ShotSparkLeftCount], true);

				}
			}

			shot[i].ShotSparkRightCount = 0;
			shot[i].ShotSparkLeftCount = 0;

			//プレイヤーに当たった時
			
			if (shot[i].m_colRect.IsCollision(player.m_colRect) == true)
			{
				//プレイヤーが左だった場合
				if (shot[i].X + ScrollX > player.PlayerX)
				{
					shot[i].ShotHitTime++;
					if (shot[i].ShotHitTime >= 10)
					{
						shot[i].ShotHitLeftCount++;

						shot[i].ShotHitTime = 0;
					}

					DrawGraph(shot[i].X + ScrollX, shot[i].Y, shot[i].ShotHitGraphLeft[shot[i].ShotHitLeftCount], true);
				}
				//プレイヤーが右だった場合
				if (shot[i].X + ScrollX < player.PlayerX)
				{
					shot[i].ShotHitTime++;
					if (shot[i].ShotHitTime >= 10)
					{
						shot[i].ShotHitRightCount++;

						shot[i].ShotHitTime = 0;
					}

					DrawGraph(shot[i].X + ScrollX, shot[i].Y, shot[i].ShotHitGraphRight[shot[i].ShotHitRightCount], true);
				}

			}

			shot[i].ShotHitLeftCount = 0;
			shot[i].ShotHitRightCount = 0;

		}
		if (shot[i].Flag == false)
		{
			//あたり判定を終わらせる
			shot[i].m_colRect.SetCenter(0, 0, 0, 0);
		}
	}
	
}
