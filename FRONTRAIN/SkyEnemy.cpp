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

void SkyEnemy::FinalizeSky(SkyEnemyStruct& enemy)
{
	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(enemy.DeadAnimGraph[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(enemy.SkyHandle[i]);
	}

	DeleteSoundMem(enemy.SESkyEnemyDead);
}

void SkyEnemy::Init(SkyEnemyStruct& enemy, SkyEnemy& Senemy,EnemyLoadDate& date)
{
	Senemy.Attack = 1;
	Senemy.HP = 1;
	
	enemy.SkyEnemyX = 0.0f;
	enemy.SkyEnemyY = 0.0f;
	enemy.SkyEnemyDeadY = 0.0f;

	enemy.SkyEnemyDead = false;

	enemy.SkyShotDead = false;

	enemy.SkyEnemyflag = false;

	Senemy.SkyEnemyAppearance = true;

	Senemy.T = 0;

	Senemy.TUP = 30;

	Senemy.TUP2 = 100;

	Senemy.TUP3 = 240;

	Senemy.TUP4 = 600;

	enemy.S = 0;

	enemy.Time = 0;

	enemy.DeadAnimCount = 0;

	enemy.DeadAnimTime = 0;

	enemy.DeadPoint = date.SkyPoint;
	enemy.DeadPointSE = date.LoadSEPoint;

	enemy.SkyShotDeadPoint = false;
	enemy.SkyShotDeadSE = false;

	LoadDivGraph("date/死亡血しぶき.png", 4, 4, 1, 15, 15, enemy.DeadAnimGraph);

	LoadDivGraph("date/SkyEnemy.png", 3, 3, 1, 15, 20, enemy.SkyHandle);

	//enemy.SESkyEnemyDead = LoadSoundMem("SE/se_tsubureru04.mp3");

	enemy.SESkyEnemyDead = date.SkyEnemyDead;

	enemy.SE = false;

}

void SkyEnemy::Update(Player& player,Shot& shot, SkyEnemyStruct enemy[], int SenemySize, float ScrollX, TimeCount* time, SkyEnemy& Senemy,Shield& shield)
{
	//敵のスピード設定
	double tb, tbx, tby, px, py, sx, sy;

	//時間がたつと敵が出現
	//2分以下だった場合
	if (time->EnemyTime < 120)
	{
		if (time->EnemyTime == 30 + (8 * Senemy.T))
		{
			if (Senemy.SkyEnemyAppearance == true)
			{
				Senemy.T++;

				for (int i = 0; i < SenemySize; i++)
				{
					if (enemy[i].SkyEnemyflag == false)
					{
						enemy[i].SkyEnemyDead = false;

						enemy[i].Flag = false;

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
	}
	//2分たった場合出現率アップ
	else if (time->EnemyTime >= 120 && time->EnemyTime < 300)
	{
		if (time->EnemyTime == (4 * Senemy.TUP))
		{
			if (Senemy.SkyEnemyAppearance == true)
			{
				Senemy.TUP++;

				for (int i = 0; i < SenemySize; i++)
				{
					if (enemy[i].SkyEnemyflag == false)
					{
						enemy[i].SkyEnemyDead = false;

						enemy[i].Flag = false;

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
	}
	//5分たつと出現率アップ
	else if (time->EnemyTime >= 300 && time->EnemyTime < 480)
	{
		if (time->EnemyTime == (3 * Senemy.TUP2))
		{
			if (Senemy.SkyEnemyAppearance == true)
			{
				Senemy.TUP2++;

				for (int i = 0; i < SenemySize; i++)
				{
					if (enemy[i].SkyEnemyflag == false)
					{
						enemy[i].SkyEnemyDead = false;

						enemy[i].Flag = false;

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
	}
	//8分たつと出現率アップ
	else if (time->EnemyTime >= 480 && time->EnemyTime < 600)
	{
		if (time->EnemyTime == (2 * Senemy.TUP3))
		{
			if (Senemy.SkyEnemyAppearance == true)
			{
				Senemy.TUP3++;

				for (int i = 0; i < SenemySize; i++)
				{
					if (enemy[i].SkyEnemyflag == false)
					{
						enemy[i].SkyEnemyDead = false;

						enemy[i].Flag = false;

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
	}
	//10分たつと出現率アップ
	else if (time->EnemyTime >= 600)
	{
		if (time->EnemyTime == (1 * Senemy.TUP4))
		{
			if (Senemy.SkyEnemyAppearance == true)
			{
				Senemy.TUP4++;

				for (int i = 0; i < SenemySize; i++)
				{
					if (enemy[i].SkyEnemyflag == false)
					{
						enemy[i].SkyEnemyDead = false;

						enemy[i].Flag = false;

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

					//1フレームあたり6ドットで動く
					enemy[i].PX = tbx / tb * 6;
					enemy[i].PY = tby / tb * 6;

					//一体だしたので抜ける
					break;
				}
				
			}

			//当たり判定の更新
			enemy[i].m_colRect.SetCenter(static_cast<float>(enemy[i].SkyEnemyX + 7 + player.ScrollX), static_cast<float>(enemy[i].SkyEnemyY + 10), static_cast<float>(enemy[i].SkyEnemyWidth), static_cast<float>(enemy[i].SkyEnemyHeight));

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
					player.HP -= Senemy.Attack;

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
					//当たってない
				}
				else if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == true)
				{
					enemy[i].HP -= shot.Damage;
					//接触している場合は当たった弾の存在を消す
					shot.Flag = 0;

					enemy[i].SkyShotDead = true;
					enemy[i].SkyShotDeadPoint = true;

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
	if (enemy.HP > 0)
	{
		//敵のアニメーション
		if (enemy.Flag)
		{
			enemy.Time++;
			if (enemy.Time >= 20)
			{
				enemy.S++;
				if (enemy.S == 3)enemy.S = 0;

				enemy.Time = 0;
			}

			

			DrawGraph(static_cast<int>(enemy.SkyEnemyX + ScrollX), static_cast<int>(enemy.SkyEnemyY), enemy.SkyHandle[enemy.S], true);

			enemy.SkyEnemyX += static_cast<float>(enemy.PX);
			enemy.SkyEnemyY += static_cast<float>(enemy.PY);
		}
		
	}
	//敵が死んだ時
	else if (enemy.HP <= 0)
	{
		//死んだ時の演出
		if (enemy.SkyEnemyDead == false)
		{
			enemy.m_colRect.SetCenter(0, 0, 0, 0);

			enemy.DeadAnimTime++;
			if (enemy.DeadAnimTime >= 5)
			{
				enemy.DeadAnimCount++;

				enemy.DeadAnimTime = 0;
			}

			DrawGraph(static_cast<int>(enemy.SkyEnemyX + ScrollX), static_cast<int>(enemy.SkyEnemyY - 5), enemy.DeadAnimGraph[enemy.DeadAnimCount], true);

			if (enemy.SE == false)
			{
				PlaySoundMem(enemy.SESkyEnemyDead, DX_PLAYTYPE_BACK, TRUE);

				enemy.SkyEnemyDeadY = enemy.SkyEnemyY;

				enemy.SE = true;
			}
			//ポイント獲得表示
			if (enemy.SkyShotDeadPoint == true)
			{
				//1回だけ実行
				if (enemy.SkyShotDeadSE == false)
				{
					PlaySoundMem(enemy.DeadPointSE, DX_PLAYTYPE_BACK, TRUE);

					enemy.SkyShotDeadSE = true;
				}
				

				DrawGraph(static_cast<int>(enemy.SkyEnemyX + ScrollX), static_cast<int>(enemy.SkyEnemyDeadY -= 1.0f), enemy.DeadPoint, true);
			}

			if (enemy.SkyShotDead == true)
			{
				point.SenemyPoint += 50;
				
				enemy.SkyShotDead = false;
			}
			enemy.SkyEnemyflag = false;

			if (enemy.DeadAnimCount == 4)
			{
				enemy.HP = 1;

				enemy.SkyEnemyX = -640.0f;
				enemy.SkyEnemyY = -20.0f;

				enemy.SE = false;

				enemy.SkyEnemyDead = true;
				enemy.SkyShotDeadPoint = false;
				enemy.SkyShotDeadSE = false;
			}
			
		}
	}
	//演出が終わったらアニメーションを戻す
	if (enemy.SkyEnemyDead == true)
	{
		enemy.DeadAnimCount = 0;
	}
}
