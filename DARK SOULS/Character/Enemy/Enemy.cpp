#include "Enemy.h"

WeakEnemy::WeakEnemy()
{
	for (int i = 0; i < ENEMY_NOW; ++i)
	{
		enemy[i] = ;
	}
}

WeakEnemy::~WeakEnemy()
{
}

void WeakEnemy::Init()
{
	//雑魚エネミーのHPの初期化
	m_hp = 200.0f;

	//敵のスピード初期化
	m_speed = 2.0f;

	//オブジェクトの大きさを変える変数
	m_modelSize = 0.4f;

	//敵の大きさ変更
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));
}

void WeakEnemy::Update()
{
}

void WeakEnemy::Draw()
{
}

void WeakEnemy::End()
{
}
