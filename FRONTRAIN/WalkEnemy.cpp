#include "WalkEnemy.h"
#include "DxLib.h"


WalkEnemy::WalkEnemy():
	WalkEnemyGraph(0),
	WalkEnemyX(610.00f),
	WalkEnemyY(360.00f),
	WalkEnemyWidth(20),
	WalkEnemyHeight(20),
	WalkEnemyW(0),
	WalkEnmeyH(0),
	WalkEnemySpeed(0.03f)
{
}

WalkEnemy::~WalkEnemy()
{
}

void WalkEnemy::Init()
{
	

	

}

void WalkEnemy::Update(Player& player,Shot& shot,WalkEnemy& enemy)
{
	//�G�l�~�[�������Ă��鎞
	if (enemy.HP >= 0)
	{
		//�G�̈ړ�����
		if (player.PlayerX - player.ScrollX <= enemy.WalkEnemyX)
		{
			enemy.WalkEnemyX -= enemy.WalkEnemySpeed;
		}
		else if (player.PlayerX - player.ScrollX > enemy.WalkEnemyX)
		{
			enemy.WalkEnemyX += enemy.WalkEnemySpeed;
		}

		//�����蔻��̍X�V
		m_colRect.SetCenter(enemy.WalkEnemyX + 10 + player.ScrollX, enemy.WalkEnemyY + 10, enemy.WalkEnemyWidth, enemy.WalkEnemyHeight);

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
				enemy.HP -= shot.Damage;
				//�ڐG���Ă���ꍇ�͓��������e�̑��݂�����
				shot.Flag = 0;
			}

		}
	}
	
}

void WalkEnemy::Draw(int ScrollX,WalkEnemy& enemy, Point& point)
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
		}
		
	}
}
