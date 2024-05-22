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
	enemy1->EnemyY = -810.0f;
	enemy1->EnemyZ = 500.0f;
	enemy2->EnemyX = -600.0f;
	enemy2->EnemyY = -3200.0f;
	enemy2->EnemyZ = -600.0f;
	enemy3->EnemyX = -100.0f;
	enemy3->EnemyY = -4800.0f;
	enemy3->EnemyZ = 100.0f;
	enemy4->EnemyX = -100.0f;
	enemy4->EnemyY = -6400.0f;
	enemy4->EnemyZ = 100.0f;
	enemy5->EnemyX = -100.0f;
	enemy5->EnemyY = -6400.0f;
	enemy5->EnemyZ = -150.0f;

	EnemyWidth = 40.0f;

	enemy1pos = VGet(enemy1->EnemyX, enemy1->EnemyY, enemy1->EnemyZ);
	enemy2pos = VGet(enemy2->EnemyX, enemy2->EnemyY, enemy2->EnemyZ);
	enemy3pos = VGet(enemy3->EnemyX, enemy3->EnemyY, enemy3->EnemyZ);
	enemy4pos = VGet(enemy4->EnemyX, enemy4->EnemyY, enemy4->EnemyZ);
	enemy5pos = VGet(enemy5->EnemyX, enemy5->EnemyY, enemy5->EnemyZ);
}

void Enemy::Update(Player& player)
{

	enemy1->SetPos(enemy1pos);
	enemy1->Update();
	enemy1->m_colRect.SetCenter(enemy1pos.x - 20.0f, enemy1pos.y + 5.0f, enemy1pos.z + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

	enemy2->SetPos(enemy2pos);
	enemy2->Update();
	enemy2->m_colRect.SetCenter(enemy2pos.x - 20.0f, enemy2pos.y + 5.0f, enemy2pos.z + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

	enemy3->SetPos(enemy3pos);
	enemy3->Update();
	enemy3->m_colRect.SetCenter(enemy3pos.x - 20.0f, enemy3pos.y + 5.0f, enemy3pos.z + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

	enemy4->SetPos(enemy4pos);
	enemy4->Update();
	enemy4->m_colRect.SetCenter(enemy4pos.x - 20.0f, enemy4pos.y + 5.0f, enemy4pos.z + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

	enemy5->SetPos(enemy5pos);
	enemy5->Update();
	enemy5->m_colRect.SetCenter(enemy5pos.x - 20.0f, enemy5pos.y + 5.0f, enemy5pos.z + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

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

	if (enemy4->Enemyflag == true)
	{
		//“G‚ÌˆÚ“®‘¬“x‚ðÝ’è‚·‚é
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy4pos.x;
		sbz = player.Playerpos.z - enemy4pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy4->EnemyMoveX = sbx / sb * Speed;
		enemy4->EnemyMoveZ = sbz / sb * Speed;
	}
	else if (enemy4->Enemyflag == false)
	{
		enemy4->EnemyMoveX = 0;
		enemy4->EnemyMoveZ = 0;
	}

	if (enemy5->Enemyflag == true)
	{
		//“G‚ÌˆÚ“®‘¬“x‚ðÝ’è‚·‚é
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy5pos.x;
		sbz = player.Playerpos.z - enemy5pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy5->EnemyMoveX = sbx / sb * Speed;
		enemy5->EnemyMoveZ = sbz / sb * Speed;
	}
	else if (enemy5->Enemyflag == false)
	{
		enemy5->EnemyMoveX = 0;
		enemy5->EnemyMoveZ = 0;
	}

	//“G‚ªƒvƒŒƒCƒ„[‚É“–‚½‚Á‚½‚çƒvƒŒƒCƒ„[Ž€–S
	if (enemy1->m_colRect.IsCollision(player.m_colrect) == true)
	{
		player.PlayerDead = true;
	}

	enemy1pos.x += enemy1->EnemyMoveX;
	enemy1pos.z += enemy1->EnemyMoveZ;
	enemy2pos.x += enemy2->EnemyMoveX;
	enemy2pos.z += enemy2->EnemyMoveZ;
	enemy3pos.x += enemy3->EnemyMoveX;
	enemy3pos.z += enemy3->EnemyMoveZ;
	enemy4pos.x += enemy4->EnemyMoveX;
	enemy4pos.z += enemy4->EnemyMoveZ;
	enemy5pos.x += enemy5->EnemyMoveX;
	enemy5pos.z += enemy5->EnemyMoveZ;

}

void Enemy::Draw()
{
	enemy1->Draw();
	enemy2->Draw();
	enemy3->Draw();
	enemy4->Draw();
	enemy5->Draw();

	enemy1->m_colRect.Draw(GetColor(255, 0, 0), false);
}

void Enemy::End()
{
	enemy1->~EnemyBase();
	enemy2->~EnemyBase();
	enemy3->~EnemyBase();
	enemy4->~EnemyBase();
	enemy5->~EnemyBase();
}
