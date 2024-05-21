#include "Enemy.h"
#include<math.h>

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	enemy1->EnemyX = 150.0f;
	enemy1->EnemyY = -790.0f;
	enemy1->EnemyZ = 500.0f;
	enemy2->EnemyX = -600.0f;
	enemy2->EnemyY = -3200.0f;
	enemy2->EnemyZ = -600.0f;
	enemy3->EnemyX = -100.0f;
	enemy3->EnemyY = -4800.0f;
	enemy3->EnemyZ = 100.0f;
	enemy4->EnemyX = -100.0f;
	enemy4->EnemyY = -6890.0f;
	enemy4->EnemyZ = 100.0f;
	enemy5->EnemyX = -100.0f;
	enemy5->EnemyY = -6890.0f;
	enemy5->EnemyZ = -150.0f;

	EnemyWidth = 40.0f;

	enemy1pos = VGet(enemy1->EnemyX, enemy1->EnemyY, enemy1->EnemyZ);
	enemy2pos = VGet(enemy2->EnemyX, enemy2->EnemyY, enemy2->EnemyZ);
	enemy3pos = VGet(enemy3->EnemyX, enemy3->EnemyY, enemy3->EnemyZ);
}

void Enemy::Update(Player& player)
{

	enemy1->SetPos(enemy1pos);
	enemy1->Update();
	enemy1->m_colRect.SetCenter(enemy1->EnemyX - 20.0f, enemy1->EnemyY + 5.0f, enemy1->EnemyZ + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

	enemy2->SetPos(enemy2pos);
	enemy2->Update();
	enemy2->m_colRect.SetCenter(enemy2->EnemyX - 20.0f, enemy2->EnemyY + 5.0f, enemy2->EnemyZ + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

	enemy3->SetPos(enemy3pos);
	enemy3->Update();
	enemy3->m_colRect.SetCenter(enemy3->EnemyX - 20.0f, enemy3->EnemyY + 5.0f, enemy3->EnemyZ + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

	//õ“G‘ÎÛ‚ª‹‚½‚ç
	if (enemy1->Enemyflag == true)
	{
		//“G‚ÌˆÚ“®‘¬“x‚ðÝ’è‚·‚é
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy1pos.x;
		sbz = player.Playerpos.z - enemy1pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy1->EnemyMoveX = sbx / sb * Speed;
		enemy1->EnemyMoveZ = sbz / sb * Speed;
		
	}
	//õ“G‘ÎÛ‚ª‚¢‚È‚©‚Á‚½‚ç
	else if (enemy1->Enemyflag == false)
	{
		enemy1->EnemyMoveX = 0;
		enemy1->EnemyMoveZ = 0;
	}

	if (enemy2->Enemyflag == true)
	{
		//“G‚ÌˆÚ“®‘¬“x‚ðÝ’è‚·‚é
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy2pos.x;
		sbz = player.Playerpos.z - enemy2pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy2->EnemyMoveX = sbx / sb * Speed;
		enemy2->EnemyMoveZ = sbz / sb * Speed;
	}
	else if (enemy2->Enemyflag == false)
	{
		enemy2->EnemyMoveX = 0;
		enemy2->EnemyMoveZ = 0;
	}

	if (enemy3->Enemyflag == true)
	{
		//“G‚ÌˆÚ“®‘¬“x‚ðÝ’è‚·‚é
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy3pos.x;
		sbz = player.Playerpos.z - enemy3pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy3->EnemyMoveX = sbx / sb * Speed;
		enemy3->EnemyMoveZ = sbz / sb * Speed;
	}
	else if (enemy3->Enemyflag == false)
	{
		enemy3->EnemyMoveX = 0;
		enemy3->EnemyMoveZ = 0;
	}

	enemy1pos.x += enemy1->EnemyMoveX;
	enemy1pos.z += enemy1->EnemyMoveZ;
	enemy2pos.x += enemy2->EnemyMoveX;
	enemy2pos.z += enemy2->EnemyMoveZ;
	enemy3pos.x += enemy3->EnemyMoveX;
	enemy3pos.z += enemy3->EnemyMoveZ;

}

void Enemy::Draw()
{
	enemy1->Draw();
	enemy2->Draw();
	enemy3->Draw();
}

void Enemy::End()
{
	enemy1->~EnemyBase();
	enemy2->~EnemyBase();
	enemy3->~EnemyBase();
}
