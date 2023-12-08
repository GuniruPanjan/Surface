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
	
	//���Ԃ����ƓG���o��
	if (time->WalkEnemyTime == 10 * Wenemy.T)
	{
		if (Wenemy.WalkEnemyAppearance == true)
		{
			for (int i = 0; i < WenemySize; i++)
			{
				if (enemy[i].WalkEnemyflag == false)
				{
					enemy[i].WalkEnemyflag = true;

					DrawString(200, 200, "�o��", GetColor(255, 255, 255));
					//�G�l�~�[�������_���ȏꏊ�ɏo��
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
				m_colRect.SetCenter(enemy[i].WalkEnemyX + 10 + player.ScrollX, enemy[i].WalkEnemyY + 10, enemy[i].WalkEnemyWidth, enemy[i].WalkEnemyHeight);

				//�v���C���[�̓����蔻��
				if (m_colRect.IsCollision(player.m_colRect) == false)
				{
					//�������ĂȂ�
				}
				//�������Ă���
				else if (m_colRect.IsCollision(player.m_colRect) == true)
				{
					DrawString(0, 0, "��������", GetColor(255, 255, 255));
				}

				if (shot.Flag == 1)
				{
					//�G�Ƃ̓����蔻��
					if (m_colRect.IsCollision(shot.m_colRect) == false)
					{

					}
					else if (m_colRect.IsCollision(shot.m_colRect) == true)
					{
						DrawString(500, 0, "��������", GetColor(255, 255, 255));
						enemy[i].HP -= shot.Damage;
						//�ڐG���Ă���ꍇ�͓��������e�̑��݂�����
						shot.Flag = 0;
					}

				}
			}

		}
	}
	
}

void WalkEnemy::Draw(int ScrollX,WalkEnemyStruct& enemy, Point& point)
{
	//�G�l�~�[�������Ă��鎞
	if (enemy.HP >= 0)
	{
		enemy.WalkEnemyGraph = LoadGraph("date/�G�l�~�[(��).png");
		//�G�l�~�[�̑傫���擾
		GetGraphSize(enemy.WalkEnemyGraph, &enemy.WalkEnemyW, &enemy.WalkEnmeyH);

		DrawGraph(enemy.WalkEnemyX + ScrollX, enemy.WalkEnemyY, enemy.WalkEnemyGraph, true);

		//�G�l�~�[�̓����蔻��̕\��
		enemy.m_colRect.Draw(GetColor(255, 0, 0), false);
		//WalkEnemyGraph = DrawBox(WalkEnemyX, WalkEnemyY, 630, 250, GetColor(255, 255, 0), true);
	}
	//�G�����񂾎�
	else if (enemy.HP <= 0)
	{
		if (enemy.WalkEnemyDead == false)
		{
			DrawString(500, 0, "����", GetColor(255, 255, 255));
			DeleteGraph(enemy.WalkEnemyGraph);
			point.WenemyPoint += 100;
			enemy.WalkEnemyDead = true;
			enemy.WalkEnemyflag = false;
		}

	}
	
}
