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

	LoadDivGraph("date/����Down.png", 14, 8, 2, 30, 30, enemy.Handle);

	enemy.AnimCount = 0;

	enemy.AnimTime = 0;
}

void DistanceEnemy::EnemyShotInit(EnemyShot shot[])
{
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		shot[i].Flag = false;

		shot[i].ShotDamage = 2;

		shot[i].Graph = LoadGraph("date/�e�e��.png");
	}
}

void DistanceEnemy::Update(Player& player, Shot& shot, DistanceEnemyStruct enemy[], int DenemySize, float ScrollX, TimeCount* time, DistanceEnemy& Denemy,EnemyShot enemyshot[],int EnemyShotSize,Shield& shield)
{
	//���Ԃ����ƓG���o��
	//2���ȉ��������ꍇ
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
						//���ݎ��Ԃ𓾂�
						//enemy[i].Time = GetNowCount();

						//enemy[i].Time = 0;

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
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
	//2���������ꍇ�͏o�����A�b�v
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
						//���ݎ��Ԃ𓾂�
						//enemy[i].Time = GetNowCount();

						//enemy[i].Time = 0;

						enemy[i].DistanceEnemyDead = false;

						enemy[i].DistanceEnemyflag = true;

						//�G�l�~�[�������_���ȏꏊ�ɏo��
						if (GetRand(1) == 0)
						{
							enemy[i].DistanceEnemyX = -40.0f - ScrollX;
						}
						if (GetRand(1) == 1)
						{
							enemy[i].DistanceEnemyX = 680.0f - ScrollX;
						}

						enemy[i].DistanceEnemyY = 360.0f;

						//��̂������̂Ń��[�v���甲����
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
			//�G�������Ă��鎞
			if (enemy[i].HP >= 0)
			{
				//�G�̈ړ�����
				//�E����
				if (player.PlayerX - player.ScrollX + 200 < enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX -= enemy[i].DistanceEnemySpeed;
				}
				//�E�ɓ�����
				else if (player.PlayerX - player.ScrollX + 200 > enemy[i].DistanceEnemyX && player.PlayerX - player.ScrollX < enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX += enemy[i].DistanceEnemySpeed;
				}
				//������
				if (player.PlayerX - player.ScrollX - 150 > enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX += enemy[i].DistanceEnemySpeed;
				}
				//���ɓ�����
				else if (player.PlayerX - player.ScrollX - 150 < enemy[i].DistanceEnemyX && player.PlayerX - player.ScrollX > enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX -= enemy[i].DistanceEnemySpeed;
			
				}

				//�G�̍U���s��
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



				//�����蔻��̍X�V
				enemy[i].m_colRect.SetCenter(enemy[i].DistanceEnemyX + 10 + player.ScrollX, enemy[i].DistanceEnemyY + 10, enemy[i].DistanceEnemyWidth, enemy[i].DistanceEnemyHeight);

				//�v���C���[�̓����蔻��
				if (enemy[i].m_colRect.IsCollision(player.m_colRect) == false)
				{
					//�������ĂȂ�
				}
				//�������Ă���
				else if (enemy[i].m_colRect.IsCollision(player.m_colRect) == true)
				{
					//1�񂾂����s
					if (player.PlayerDamage == false)
					{
						player.HP -= Denemy.Attack;

						player.PlayerDamage = true;
					}

					enemy[i].HP = -1;
				}

				if (shot.Flag == 1)
				{
					//�G�Ƃ̓����蔻��
					if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == false)
					{

					}
					else if (enemy[i].m_colRect.IsCollision(shot.m_colRect) == true)
					{
						enemy[i].HP -= shot.Damage;
						
						//�ڐG���Ă���ꍇ�͓��������e�̑��݂�����
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

//�G�̍U���s��
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

				//�e�̈ړ����x��ݒ肷��
				double sb, sbx, sby, ax, ay, sx, sy;

				sx = shot.X;
				sy = shot.Y;

				//�W�I�̏ꏊ
				ax = player.PlayerX - ScrollX;
				ay = player.PlayerY;

				sbx = ax - sx;
				sby = ay - sy;

				sb = sqrt(sbx * sbx + sby * sby);

				//1�t���[��������10�h�b�g�œ���
				shot.PX = sbx / sb * 5;
				shot.PY = sby / sb * 5;

				//��e���o�����̂Œe���o�����[�v���甲����
				break;
			}
		}
	    enemy[i].EnemyShotFlag = true;
	}

	if (shot.Flag == true)
	{

		//���Ƃ̐ڐG����
		if (shield.LeftFlag == true || shield.RightFlag == true)
		{
			//���Ƃ̓����蔻��
			if (shot.m_colRect.IsCollision(shield.m_colRect) == false)
			{
				//�������ĂȂ�

			}
			else if (shot.m_colRect.IsCollision(shield.m_colRect) == true)
			{
				//�e�̏ꏊ���ړ�
				shot.PX = -10.0f;
				shot.PY = -10.0f;

				//�ڐG�����e�̑��݂�����
				shot.Flag = false;
			}
		}


		//�v���C���[�Ƃ̓����蔻��
		if (shot.m_colRect.IsCollision(player.m_colRect) == false)
		{

		}
		else if (shot.m_colRect.IsCollision(player.m_colRect) == true)
		{
			//1�񂾂����s
			if (player.PlayerDamage == false)
			{
				player.HP -= shot.ShotDamage;

				player.PlayerDamage = true;
			}

			//�e�̏ꏊ���ړ�
			shot.PX = -10.0f;
			shot.PY = -10.0f;


			//�ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			shot.Flag = false;
		}

	}
}

void DistanceEnemy::Draw(float ScrollX, DistanceEnemyStruct& enemy, Point& point, Player& player,int DownAnimGraph)
{
	//�G�l�~�[�������Ă��鎞
	if (enemy.HP >= 0)
	{
		if (enemy.DistanceEnemyX + ScrollX > player.PlayerX)
		{
			DrawGraph(enemy.DistanceEnemyX + ScrollX, enemy.DistanceEnemyY - 3, enemy.DistanceEnemyGraph, true);
		}
		else if (enemy.DistanceEnemyX + ScrollX < player.PlayerX)
		{
			DrawTurnGraph(enemy.DistanceEnemyX + ScrollX, enemy.DistanceEnemyY - 3, enemy.DistanceEnemyGraph, true);
		}

		//�G�l�~�[�̓����蔻��̕\��
		//enemy.m_colRect.Draw(GetColor(255, 0, 0), false);
	}
	//�G�����񂾎�
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

void DistanceEnemy::DrawShot(EnemyShot shot[],int EnemyShotSize,int ScrollX)
{
	//�e�̈ړ�
	//���˂��Ă�e������
	for (int i = 0; i < EnemyShotSize; i++)
	{
		if (shot[i].Flag)
		{
			//shot[i].Graph = LoadGraph("date/�e�e.png");

			shot[i].X += shot[i].PX;
			shot[i].Y += shot[i].PY;

			DrawGraph(shot[i].X + ScrollX, shot[i].Y, shot[i].Graph, true);

			//�����蔻��̍X�V
			shot[i].m_colRect.SetCenter(shot[i].X + ScrollX, shot[i].Y, shot[i].Width, shot[i].Height);

			shot[i].m_colRect.Draw(GetColor(0, 0, 255), false);

			//��ʏ�ɍs�������������
			if (shot[i].Y <= -10)
			{
				shot[i].Flag = false;

				//DeleteGraph(shot[i].Graph);
			}


		}
	}
	
}
