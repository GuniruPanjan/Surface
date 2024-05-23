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

	enemy1->pos = VGet(enemy1->EnemyX, enemy1->EnemyY, enemy1->EnemyZ);
	enemy2->pos = VGet(enemy2->EnemyX, enemy2->EnemyY, enemy2->EnemyZ);
	enemy3->pos = VGet(enemy3->EnemyX, enemy3->EnemyY, enemy3->EnemyZ);
	enemy4->pos = VGet(enemy4->EnemyX, enemy4->EnemyY, enemy4->EnemyZ);
	enemy5->pos = VGet(enemy5->EnemyX, enemy5->EnemyY, enemy5->EnemyZ);
}

void Enemy::Update(Player& player)
{
	//プレイヤーが死んだら初期位置に戻す
	if (player.PlayerDead == true)
	{
		enemy1->pos = VGet(enemy1->EnemyX, enemy1->EnemyY, enemy1->EnemyZ);
		enemy2->pos = VGet(enemy2->EnemyX, enemy2->EnemyY, enemy2->EnemyZ);
		enemy3->pos = VGet(enemy3->EnemyX, enemy3->EnemyY, enemy3->EnemyZ);
		enemy4->pos = VGet(enemy4->EnemyX, enemy4->EnemyY, enemy4->EnemyZ);
		enemy5->pos = VGet(enemy5->EnemyX, enemy5->EnemyY, enemy5->EnemyZ);

		enemy1->SetPos(enemy1->pos);
		enemy1->Update();
		enemy1->m_colRect.SetCenter(enemy1->pos.x - 20.0f, enemy1->pos.y + 5.0f, enemy1->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		enemy2->SetPos(enemy2->pos);
		enemy2->Update();
		enemy2->m_colRect.SetCenter(enemy2->pos.x - 20.0f, enemy2->pos.y + 5.0f, enemy2->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		enemy3->SetPos(enemy3->pos);
		enemy3->Update();
		enemy3->m_colRect.SetCenter(enemy3->pos.x - 20.0f, enemy3->pos.y + 5.0f, enemy3->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		enemy4->SetPos(enemy4->pos);
		enemy4->Update();
		enemy4->m_colRect.SetCenter(enemy4->pos.x - 20.0f, enemy4->pos.y + 5.0f, enemy4->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		enemy5->SetPos(enemy5->pos);
		enemy5->Update();
		enemy5->m_colRect.SetCenter(enemy5->pos.x - 20.0f, enemy5->pos.y + 5.0f, enemy5->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

	}
	//プレイヤーが死んでいなかったら
	else if (player.PlayerDead == false)
	{
		enemy1->SetPos(enemy1->pos);
		enemy1->Update();
		enemy1->m_colRect.SetCenter(enemy1->pos.x - 20.0f, enemy1->pos.y + 5.0f, enemy1->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		enemy2->SetPos(enemy2->pos);
		enemy2->Update();
		enemy2->m_colRect.SetCenter(enemy2->pos.x - 20.0f, enemy2->pos.y + 5.0f, enemy2->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		enemy3->SetPos(enemy3->pos);
		enemy3->Update();
		enemy3->m_colRect.SetCenter(enemy3->pos.x - 20.0f, enemy3->pos.y + 5.0f, enemy3->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		enemy4->SetPos(enemy4->pos);
		enemy4->Update();
		enemy4->m_colRect.SetCenter(enemy4->pos.x - 20.0f, enemy4->pos.y + 5.0f, enemy4->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		enemy5->SetPos(enemy5->pos);
		enemy5->Update();
		enemy5->m_colRect.SetCenter(enemy5->pos.x - 20.0f, enemy5->pos.y + 5.0f, enemy5->pos.z + 20.0f, EnemyWidth, EnemyWidth, -EnemyWidth);

		//エネミーを動かす
		enemy1->pos.x += enemy1->EnemyMoveX;
		enemy1->pos.z += enemy1->EnemyMoveZ;
		enemy2->pos.x += enemy2->EnemyMoveX;
		enemy2->pos.z += enemy2->EnemyMoveZ;
		enemy3->pos.x += enemy3->EnemyMoveX;
		enemy3->pos.z += enemy3->EnemyMoveZ;
		enemy4->pos.x += enemy4->EnemyMoveX;
		enemy4->pos.z += enemy4->EnemyMoveZ;
		enemy5->pos.x += enemy5->EnemyMoveX;
		enemy5->pos.z += enemy5->EnemyMoveZ;
	}
	
	//索敵対象が居たら
	if (enemy1->Enemyflag == true)
	{
		//敵の移動速度を設定する
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy1->pos.x;
		sbz = player.Playerpos.z - enemy1->pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy1->EnemyMoveX = sbx / sb * Speed;
		enemy1->EnemyMoveZ = sbz / sb * Speed;
		
	}
	//索敵対象がいなかったら
	else if (enemy1->Enemyflag == false)
	{
		enemy1->EnemyMoveX = 0;
		enemy1->EnemyMoveZ = 0;
	}

	if (enemy2->Enemyflag == true)
	{
		//敵の移動速度を設定する
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy2->pos.x;
		sbz = player.Playerpos.z - enemy2->pos.z;

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
		//敵の移動速度を設定する
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy3->pos.x;
		sbz = player.Playerpos.z - enemy3->pos.z;

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
		//敵の移動速度を設定する
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy4->pos.x;
		sbz = player.Playerpos.z - enemy4->pos.z;

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
		//敵の移動速度を設定する
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy5->pos.x;
		sbz = player.Playerpos.z - enemy5->pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy5->EnemyMoveX = sbx / sb * Speed;
		enemy5->EnemyMoveZ = sbz / sb * Speed;
	}
	else if (enemy5->Enemyflag == false)
	{
		enemy5->EnemyMoveX = 0;
		enemy5->EnemyMoveZ = 0;
	}

	//敵がプレイヤーに当たったらプレイヤー死亡
	if (enemy1->m_colRect.IsCollision(player.m_colrect) == true || enemy2->m_colRect.IsCollision(player.m_colrect) == true || enemy3->m_colRect.IsCollision(player.m_colrect) == true
		|| enemy4->m_colRect.IsCollision(player.m_colrect) == true || enemy5->m_colRect.IsCollision(player.m_colrect) == true)
	{
		player.PlayerDead = true;
	}

}

void Enemy::Draw()
{
	enemy1->Draw();
	enemy2->Draw();
	enemy3->Draw();
	enemy4->Draw();
	enemy5->Draw();
}

void Enemy::End()
{
	enemy1->~EnemyBase();
	enemy2->~EnemyBase();
	enemy3->~EnemyBase();
	enemy4->~EnemyBase();
	enemy5->~EnemyBase();
}
