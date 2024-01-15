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

	enemy.WalkEnemyGraph = LoadGraph("date/�G�l�~�[(��).png");

}

void WalkEnemy::Update(Player& player,Shot& shot,WalkEnemyStruct enemy[],int WenemySize, float ScrollX, TimeCount* time, WalkEnemy& Wenemy)
{
	//���Ԃ����ƓG���o��
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

					//�G�l�~�[�������_���ȏꏊ�ɏo��
					if (GetRand(1) == 0)
					{
						enemy[i].WalkEnemyX = -40.0f - ScrollX;
					}
					if (GetRand(1) == 1)
					{
						enemy[i].WalkEnemyX = 680.0f - ScrollX;
					}

					enemy[i].WalkEnemyY = 360.0f;

					//��̂������̂Ń��[�v���甲����
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
			//�G�l�~�[�������Ă��鎞
			if (enemy[i].HP >= 0)
			{

				//�G�̈ړ�����
				if (player.PlayerX - player.ScrollX <= enemy[i].WalkEnemyX)
				{
					enemy[i].WalkEnemyX -= enemy[i].WalkEnemySpeed;
				}
				else if (player.PlayerX - player.ScrollX > enemy[i].WalkEnemyX)
				{
					enemy[i].WalkEnemyX += enemy[i].WalkEnemySpeed;
				}

				//�����蔻��̍X�V
				enemy[i].m_colRect.SetCenter(enemy[i].WalkEnemyX + 10 + player.ScrollX, enemy[i].WalkEnemyY + 10, enemy[i].WalkEnemyWidth, enemy[i].WalkEnemyHeight);

				//�v���C���[�̓����蔻��
				if (enemy[i].m_colRect.IsCollision(player.m_colRect) == false)
				{
					//�������ĂȂ�
				}
				//�������Ă���
				else if (enemy[i].m_colRect.IsCollision(player.m_colRect) == true)
				{
					player.HP -= Wenemy.Attack;
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

						DeleteGraph(shot.Graph);
					}

				}
			}

		}
	}
	
}

void WalkEnemy::Draw(float ScrollX,WalkEnemyStruct& enemy, Point& point)
{
	//�G�l�~�[�������Ă��鎞
	if (enemy.HP >= 0)
	{
		DrawGraph(enemy.WalkEnemyX + ScrollX, enemy.WalkEnemyY, enemy.WalkEnemyGraph, true);

		//�G�l�~�[�̓����蔻��̕\��
		enemy.m_colRect.Draw(GetColor(255, 0, 0), false);
	}
	//�G�����񂾎�
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

	//�G����ʊO���痣�ꂷ���������
	if (enemy.WalkEnemyX <= -80 || enemy.WalkEnemyY <= 50 || enemy.WalkEnemyY >= 500)
	{
		DeleteGraph(enemy.WalkEnemyGraph);
	}
	
}
