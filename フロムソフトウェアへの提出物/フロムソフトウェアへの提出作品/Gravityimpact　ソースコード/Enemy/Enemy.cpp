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
	enemy2->EnemyY = -3210.0f;
	enemy2->EnemyZ = -600.0f;
	enemy3->EnemyX = -100.0f;
	enemy3->EnemyY = -4810.0f;
	enemy3->EnemyZ = 100.0f;
	enemy4->EnemyX = -100.0f;
	enemy4->EnemyY = -6410.0f;
	enemy4->EnemyZ = 100.0f;
	enemy5->EnemyX = -100.0f;
	enemy5->EnemyY = -6410.0f;
	enemy5->EnemyZ = -150.0f;

	enemy1->EnemyMoveX = 0.0f;
	enemy1->EnemyMoveZ = 0.0f;
	enemy2->EnemyMoveX = 0.0f;
	enemy2->EnemyMoveZ = 0.0f;
	enemy3->EnemyMoveX = 0.0f;
	enemy3->EnemyMoveZ = 0.0f;
	enemy4->EnemyMoveX = 0.0f;
	enemy4->EnemyMoveZ = 0.0f;
	enemy5->EnemyMoveX = 0.0f;
	enemy5->EnemyMoveZ = 0.0f;

	EnemyWidth = 40.0f;

	enemy1->pos = VGet(enemy1->EnemyX, enemy1->EnemyY, enemy1->EnemyZ);
	enemy2->pos = VGet(enemy2->EnemyX, enemy2->EnemyY, enemy2->EnemyZ);
	enemy3->pos = VGet(enemy3->EnemyX, enemy3->EnemyY, enemy3->EnemyZ);
	enemy4->pos = VGet(enemy4->EnemyX, enemy4->EnemyY, enemy4->EnemyZ);
	enemy5->pos = VGet(enemy5->EnemyX, enemy5->EnemyY, enemy5->EnemyZ);
}

void Enemy::Update(Player& player)
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

	//ƒGƒlƒ~[‚ð“®‚©‚·
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

	//“GƒLƒƒƒ‰‚Ìƒ|ƒWƒVƒ‡ƒ“‚©‚çŽ©‹@‚ÉŒü‚©‚¤ƒxƒNƒgƒ‹‚ðŽZo
	enemy1->SubVector = VSub(enemy1->pos, player.Playerpos);
	enemy2->SubVector = VSub(enemy2->pos, player.Playerpos);
	enemy3->SubVector = VSub(enemy3->pos, player.Playerpos);
	enemy4->SubVector = VSub(enemy4->pos, player.Playerpos);
	enemy5->SubVector = VSub(enemy5->pos, player.Playerpos);

	//Šp“x‚ðŽæ“¾
	enemy1->Angle = atan2(enemy1->SubVector.x, enemy1->SubVector.z);
	enemy2->Angle = atan2(enemy2->SubVector.x, enemy2->SubVector.z);
	enemy3->Angle = atan2(enemy3->SubVector.x, enemy3->SubVector.z);
	enemy4->Angle = atan2(enemy4->SubVector.x, enemy4->SubVector.z);
	enemy5->Angle = atan2(enemy5->SubVector.x, enemy5->SubVector.z);

	

	
	//õ“G‘ÎÛ‚ª‹‚½‚ç
	if (enemy1->Enemyflag == true)
	{
		//“G‚ÌˆÚ“®‘¬“x‚ðÝ’è‚·‚é
		double sb, sbx, sbz;

		sbx = player.Playerpos.x - enemy1->pos.x;
		sbz = player.Playerpos.z - enemy1->pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy1->EnemyMoveX = sbx / sb * Speed;
		enemy1->EnemyMoveZ = sbz / sb * Speed;

		MV1SetRotationXYZ(enemy1->EnemyModel, VGet(0.0f, enemy1->Angle + DX_PI_F + DX_PI_F, 0.0f));
		
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

		sbx = player.Playerpos.x - enemy2->pos.x;
		sbz = player.Playerpos.z - enemy2->pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy2->EnemyMoveX = sbx / sb * Speed;
		enemy2->EnemyMoveZ = sbz / sb * Speed;

		MV1SetRotationXYZ(enemy2->EnemyModel, VGet(0.0f, enemy2->Angle + DX_PI_F + DX_PI_F, 0.0f));

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

		sbx = player.Playerpos.x - enemy3->pos.x;
		sbz = player.Playerpos.z - enemy3->pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy3->EnemyMoveX = sbx / sb * Speed;
		enemy3->EnemyMoveZ = sbz / sb * Speed;

		MV1SetRotationXYZ(enemy3->EnemyModel, VGet(0.0f, enemy3->Angle + DX_PI_F + DX_PI_F, 0.0f));

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

		sbx = player.Playerpos.x - enemy4->pos.x;
		sbz = player.Playerpos.z - enemy4->pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy4->EnemyMoveX = sbx / sb * Speed;
		enemy4->EnemyMoveZ = sbz / sb * Speed;

		MV1SetRotationXYZ(enemy4->EnemyModel, VGet(0.0f, enemy4->Angle + DX_PI_F + DX_PI_F, 0.0f));

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

		sbx = player.Playerpos.x - enemy5->pos.x;
		sbz = player.Playerpos.z - enemy5->pos.z;

		sb = sqrt(sbx * sbx + sbz * sbz);

		enemy5->EnemyMoveX = sbx / sb * Speed;
		enemy5->EnemyMoveZ = sbz / sb * Speed;

		MV1SetRotationXYZ(enemy5->EnemyModel, VGet(0.0f, enemy5->Angle + DX_PI_F + DX_PI_F, 0.0f));

	}
	else if (enemy5->Enemyflag == false)
	{
		enemy5->EnemyMoveX = 0;
		enemy5->EnemyMoveZ = 0;
	}

	//“G‚ªƒvƒŒƒCƒ„[‚É“–‚½‚Á‚½‚çƒvƒŒƒCƒ„[Ž€–S
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
