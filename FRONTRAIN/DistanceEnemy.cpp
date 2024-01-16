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

	enemy.DistanceEnemyX = 0.0f;
	enemy.DistanceEnemyY = 0.0f;

	enemy.DistanceEnemyDead = false;

	enemy.DistanceShotDead = false;

	enemy.DistanceEnemyflag = false;

	Denemy.DistanceEnemyAppearance = true;

	Denemy.T = 1;

	enemy.DistanceEnemyGraph = LoadGraph("date/�G�l�~�[��.png");
}

void DistanceEnemy::Update(Player& player, Shot& shot, DistanceEnemyStruct enemy[], int DenemySize, float ScrollX, TimeCount* time, DistanceEnemy& Denemy)
{
	//���Ԃ����ƓG���o��
	if (time->EnemyTime == 10 * Denemy.T)
	{
		if (Denemy.DistanceEnemyAppearance == true)
		{
			Denemy.T++;

			for (int i = 0; i < DenemySize; i++)
			{
				if (enemy[i].DistanceEnemyflag == false)
				{
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

	for (int i = 0; i < DenemySize; i++)
	{
		if (enemy[i].DistanceEnemyflag == true)
		{
			//�G�������Ă��鎞
			if (enemy[i].HP >= 0)
			{
				//�G�̈ړ�����
				if (player.PlayerX - player.ScrollX + 200 <= enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX -= enemy[i].DistanceEnemySpeed;
				}
				else if (player.PlayerX - player.ScrollX - 100 > enemy[i].DistanceEnemyX)
				{
					enemy[i].DistanceEnemyX += enemy[i].DistanceEnemySpeed;
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
					player.HP -= Denemy.Attack;
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

						enemy[i].DistanceShotDead = true;

						DeleteGraph(shot.Graph);
					}

				}
			}
			
		}
	}
}

void DistanceEnemy::Draw(float ScrollX, DistanceEnemyStruct& enemy, Point& point)
{
	//�G�l�~�[�������Ă��鎞
	if (enemy.HP >= 0)
	{
		DrawGraph(enemy.DistanceEnemyX + ScrollX, enemy.DistanceEnemyY, enemy.DistanceEnemyGraph, true);

		//�G�l�~�[�̓����蔻��̕\��
		enemy.m_colRect.Draw(GetColor(255, 0, 0), false);
	}
	//�G�����񂾎�
	else if (enemy.HP <= 0)
	{
		if (enemy.DistanceEnemyDead == false)
		{
			DeleteGraph(enemy.DistanceEnemyGraph);
			if (enemy.DistanceShotDead == true)
			{
				point.DenemyPoint += 120;

				enemy.DistanceShotDead = false;
			}
			
			enemy.DistanceEnemyflag = false;
			enemy.DistanceEnemyDead = true;
		}

	}
}
