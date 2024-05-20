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

	EnemyWidth = 40.0f;

	enemy1pos = VGet(enemy1->EnemyX, enemy1->EnemyY, enemy1->EnemyZ);
}

void Enemy::Update(Player& player)
{

	enemy1->SetPos(enemy1pos);
	enemy1->Update();
	enemy1->m_colRect.SetCenter(enemy1->EnemyX - 20.0f, enemy1->EnemyY + 5.0f, enemy1->EnemyZ + -20.0f, EnemyWidth, EnemyWidth, EnemyWidth);

	//���G�Ώۂ�������
	if (enemy1->Enemyflag == true)
	{
		//�G�̈ړ����x��ݒ肷��
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy1pos.x;
		sbz = player.Playerpos.z - enemy1pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy1->EnemyMoveX = sbx / sb * Speed;
		enemy1->EnemyMoveZ = sbz / sb * Speed;
		
	}
	//���G�Ώۂ����Ȃ�������
	else if (enemy1->Enemyflag == false)
	{
		enemy1->EnemyMoveX = 0;
		enemy1->EnemyMoveZ = 0;
	}

	enemy1pos.x += enemy1->EnemyMoveX;
	enemy1pos.z += enemy1->EnemyMoveZ;

}

void Enemy::Draw()
{
	enemy1->Draw();
}

void Enemy::End()
{
	enemy1->~EnemyBase();
}
