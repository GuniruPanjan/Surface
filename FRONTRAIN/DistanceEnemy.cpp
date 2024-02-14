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

void DistanceEnemy::FinalizeDistanceEnemy(DistanceEnemyStruct& enemy)
{
	for (int i = 0; i < 14; i++)
	{
		DeleteGraph(enemy.Handle[i]);
	}

	DeleteGraph(enemy.DistanceEnemyGraph);

	DeleteSoundMem(enemy.SEDistanceEnemy);

	DeleteSoundMem(enemy.SEDistanceDead);

	DeleteSoundMem(enemy.SEDistanceDamage);
}

void DistanceEnemy::FinalizeDistanceEnemyShot(EnemyShot shot[])
{
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		DeleteGraph(shot[i].Graph);

		for (int j = 0; j < 2; j++)
		{
			DeleteGraph(shot[i].ShotHitGraphLeft[j]);

			DeleteGraph(shot[i].ShotHitGraphRight[j]);

			DeleteGraph(shot[i].ShotSparkGraphLeft[j]);

			DeleteGraph(shot[i].ShotSparkGraphRight[j]);
		}

		DeleteSoundMem(shot[i].SEDistanceShot);
	}
}

void DistanceEnemy::Init(DistanceEnemyStruct& enemy, DistanceEnemy& Denemy, EnemyLoadDate& date)
{
	Denemy.Attack = 2;
	Denemy.HP = 5;

	enemy.DistanceEnemySpeed = 0.04f;

	enemy.DistanceEnemyX = -30.0f;
	enemy.DistanceEnemyY = -30.0f;
	enemy.DistanceEnemyDeadY = -30.0f;

	enemy.DistanceEnemyDead = false;

	enemy.DistanceShotDead = false;

	enemy.DistanceEnemyflag = false;

	Denemy.DistanceEnemyAppearance = true;

	Denemy.T = 0;

	Denemy.TUP = 15;

	Denemy.TUP2 = 50;

	enemy.Time = 0;

	enemy.ShotEnemy = 0;
	enemy.ShotDistance = 1;

	enemy.EnemyShotFlag = true;

	enemy.m_DeadAnimFrame;

	enemy.DeadPoint = date.DistancePoint;
	enemy.DeadPointSE = date.LoadSEPoint;

	enemy.DistanceShotDeadPoint = false;
	enemy.DistanceShotDeadSE = false;

	//enemy.DistanceEnemyGraph = LoadGraph("date/DistanceEnemy.png");

	enemy.DistanceEnemyGraph = date.DistanceEnemyGraph;

	LoadDivGraph("date/爆発Down.png", 14, 8, 2, 30, 30, enemy.Handle);

	enemy.AnimCount = 0;

	enemy.AnimTime = 0;

	//enemy.SEDistanceEnemy = LoadSoundMem("SE/中型ロボットの駆動音2.mp3");

	enemy.SEDistanceEnemy = date.DistanceEnmeySound;

	//enemy.SEDistanceDead = LoadSoundMem("SE/爆発2.mp3");

	enemy.SEDistanceDead = date.DistanceEnemyDeadSound;

	//enemy.SEDistanceDamage = LoadSoundMem("SE/金属叩き.mp3");

	enemy.SEDistanceDamage = date.DistanceEnemyDamageSound;

	enemy.SE1 = false;
	enemy.SE2 = false;

	Denemy.HPUP = 8;
	Denemy.HPUP2 = 15;
}

void DistanceEnemy::EnemyShotInit(EnemyShot shot[], EnemyLoadDate& date)
{
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		shot[i].Flag = false;

		shot[i].ShotDamage = 2;

		//shot[i].Graph = LoadGraph("date/銃弾.png");

		shot[i].Graph = date.ShotDistance;

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

		//shot[i].SEDistanceShot = LoadSoundMem("SE/拳銃を撃つ.mp3");

		shot[i].SEDistanceShot = date.DistanceEnemyShotSound;
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
	else if (time->EnemyTime >= 120 && time->EnemyTime < 300)
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
	//5分たつと出現率アップ
	else if (time->EnemyTime >= 300)
	{
		if (time->EnemyTime == (6 * Denemy.TUP2))
		{
			if (Denemy.DistanceEnemyAppearance == true)
			{
				Denemy.TUP2++;

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
			if (enemy[i].HP > 0)
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

				//プレイヤーが近くだったら攻撃行動実行
				if (player.PlayerX - ScrollX + 320 >= enemy[i].DistanceEnemyX && player.PlayerX - ScrollX - 320 <= enemy[i].DistanceEnemyX)
				{
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
				}
				



				//当たり判定の更新
				enemy[i].m_colRect.SetCenter(static_cast<float>(enemy[i].DistanceEnemyX + 10 + player.ScrollX), static_cast<float>(enemy[i].DistanceEnemyY + 10), static_cast<float>(enemy[i].DistanceEnemyWidth), static_cast<float>(enemy[i].DistanceEnemyHeight));

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

					//敵を消滅させる
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
						
						PlaySoundMem(enemy[i].SEDistanceDamage, DX_PLAYTYPE_BACK, TRUE);

						//接触している場合は当たった弾の存在を消す
						shot.Flag = 0;

						if (enemy[i].HP <= 0)
						{
							enemy[i].DistanceShotDead = true;

							enemy[i].DistanceShotDeadPoint = true;
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
				PlaySoundMem(shot.SEDistanceShot, DX_PLAYTYPE_BACK, TRUE);

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

				//1フレームあたり5ドットで動く
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

void DistanceEnemy::Draw(float ScrollX, DistanceEnemyStruct& enemy, Point& point, Player& player,int DownAnimGraph,Shot shot[], TimeCount* time)
{
	//エネミーが生きている時
	if (enemy.HP > 0)
	{
		if (enemy.SE1 == false)
		{
			PlaySoundMem(enemy.SEDistanceEnemy, DX_PLAYTYPE_BACK, TRUE);

			enemy.SE1 = true;
		}
		//プレイヤーより右なら
		if (enemy.DistanceEnemyX + ScrollX > player.PlayerX)
		{
			DrawGraph(static_cast<int>(enemy.DistanceEnemyX + ScrollX), static_cast<int>(enemy.DistanceEnemyY - 3), enemy.DistanceEnemyGraph, true);
		}
		//プレイヤーより左なら
		else if (enemy.DistanceEnemyX + ScrollX < player.PlayerX)
		{
			DrawTurnGraph(static_cast<int>(enemy.DistanceEnemyX + ScrollX), static_cast<int>(enemy.DistanceEnemyY - 3), enemy.DistanceEnemyGraph, true);
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
					
				
					DrawGraph(static_cast<int>(shot[s].X), static_cast<int>(shot[s].Y), shot[s].ShotSparkGraphRight[shot[s].ShotSparkCountRight], true);

					if (shot[s].ShotSparkCountRight >= 3)
					{
						shot[s].X = -30;
					}
			
					
				}
				//プレイヤーよりエネミーが左にいる場合
				if (enemy.DistanceEnemyX + ScrollX < player.PlayerX)
				{
					if (shot[s].ShotSparkTime >= 10)
					{
						shot[s].ShotSparkCountLeft++;

						shot[s].ShotAnimTime = 0;
					}

					
					DrawGraph(static_cast<int>(shot[s].X), static_cast<int>(shot[s].Y), shot[s].ShotSparkGraphLeft[shot[s].ShotSparkCountLeft], true);

					if (shot[s].ShotSparkCountLeft >= 3)
					{
						shot[s].X = -30;
					}

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
		//死んだ時の演出
		if (enemy.SE2 == false)
		{
			PlaySoundMem(enemy.SEDistanceDead, DX_PLAYTYPE_BACK, TRUE);

			enemy.DistanceEnemyDeadY = enemy.DistanceEnemyY;

			enemy.SE2 = true;
		}

		if (enemy.DistanceEnemyDead == false)
		{
			enemy.AnimTime++;
			if (enemy.AnimTime >= 2)
			{
				enemy.AnimCount++;
				
				enemy.AnimTime = 0;
			}

			DrawGraph(static_cast<int>(enemy.DistanceEnemyX + ScrollX), static_cast<int>(enemy.DistanceEnemyY - 3), enemy.Handle[enemy.AnimCount], true);

			//ポイント獲得表示
			if (enemy.DistanceShotDeadPoint == true)
			{
				//1回だけ実行
				if (enemy.DistanceShotDeadSE == false)
				{
					PlaySoundMem(enemy.DeadPointSE, DX_PLAYTYPE_BACK, TRUE);

					enemy.DistanceShotDeadSE = true;
				}
			

				DrawGraph(enemy.DistanceEnemyX + ScrollX, enemy.DistanceEnemyDeadY -= 1.0f, enemy.DeadPoint, true);
			}

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

				//2分以下だった場合
				if (time->EnemyTime < 120)
				{
					enemy.HP = 5;
				}
				//2分たった場合は耐久力アップ
				else if (time->EnemyTime >= 120 && time->EnemyTime < 300)
				{
					enemy.HP = HPUP;
				}
				//5分たつと耐久力アップ
				else if (time->EnemyTime >= 300)
				{
					enemy.HP = HPUP2;
				}
				

				enemy.DistanceEnemyX = -30.0f;
				enemy.DistanceEnemyY = -30.0f;

				//死んだ場合当たり判定を終わらせる
				enemy.m_colRect.SetCenter(0, 0, 0, 0);

				enemy.SE2 = false;

				enemy.DistanceEnemyDead = true;

				enemy.DistanceShotDeadPoint = false;

				enemy.DistanceShotDeadSE = false;

			}

			
		}
		

	}
	//演出が終わったらアニメーションを戻す
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

			DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].Graph, true);

			//あたり判定の更新
			shot[i].m_colRect.SetCenter(static_cast<float>(shot[i].X + ScrollX), static_cast<float>(shot[i].Y), static_cast<float>(shot[i].Width), static_cast<float>(shot[i].Height));

			shot[i].m_colRect.Draw(GetColor(0, 0, 255), false);

			//画面外に行きすぎたら消す
			if (shot[i].Y <= -10)
			{
				shot[i].Flag = false;
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

					DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].ShotSparkGraphRight[shot[i].ShotSparkRightCount], true);

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

					DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].ShotSparkGraphLeft[shot[i].ShotSparkLeftCount], true);

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

					DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].ShotHitGraphLeft[shot[i].ShotHitLeftCount], true);
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

					DrawGraph(static_cast<int>(shot[i].X + ScrollX), static_cast<int>(shot[i].Y), shot[i].ShotHitGraphRight[shot[i].ShotHitRightCount], true);
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
