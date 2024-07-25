#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	enemy->Init();
}

void Enemy::Update(Player& player)
{
	enemy->Update(player);
}

void Enemy::Draw()
{
	enemy->Draw();
}

void Enemy::End()
{
	enemy->End();
}
