#include "WeakEnemy.h"

WeakEnemy::WeakEnemy()
{
}

WeakEnemy::~WeakEnemy()
{
}

void WeakEnemy::Init()
{
	//敵のHP初期化
	m_hp = 200.0f;

	//敵のスピード初期化
	m_speed = 2.0f;

	m_posX = 0.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;

	m_pos = VGet(m_posX, m_posY, m_posZ);
}

void WeakEnemy::Update()
{
	m_playTime += 0.5f;

	Animation(m_playTime);
}

void WeakEnemy::Animation(float& time)
{
	//再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (time >= m_totalAnimTime[0] && m_animation[0] != -1)
	{
		time = 0.0f;
	}

	//再生時間をセットする
	if (m_animation[0] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[0], time);
	}
}

void WeakEnemy::Draw()
{
	//3Dモデルポジション設定
	MV1SetPosition(m_handle, m_pos);

	//3Dモデル描画
	MV1DrawModel(m_handle);
}

void WeakEnemy::End()
{
}
