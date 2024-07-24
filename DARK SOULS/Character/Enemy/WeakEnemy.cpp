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

	//当たり判定
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_colDeathPos = Pos3(0.0f, -1000.0f, 0.0f);
	m_vec = Vec3(m_pos.x, m_pos.y + 2.0f, m_pos.z);
	m_deathVec = Vec3(0.0f, 0.0f, 0.0f);
	m_len = 40.0f;
	m_capsuleRadius = 14.0f;
	m_capsuleCol.Init(m_colPos, m_vec, m_len, m_capsuleRadius);
}

void WeakEnemy::Update()
{
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);

	m_playTime += 0.5f;

	Animation(m_playTime);

	//敵が死亡したら
	if (m_hp <= 0.0f)
	{
		DrawFormatString(0, 240, 0xffffff, "敵が死んだ");

		m_capsuleCol.Update(m_colDeathPos, m_deathVec);
	}
	else
	{
		m_capsuleCol.Update(m_colPos, m_vec);
	}
}

void WeakEnemy::Animation(float& time)
{
	//敵が死んだら死ぬアニメーションを入れる
	if (m_hp <= 0.0f)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);

			//アニメーションアタッチ
			m_animation[2] = MV1AttachAnim(m_handle, 0, m_animDeath, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
		}
	}

	//再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (time >= m_totalAnimTime[0] && m_animation[0] != -1)
	{
		time = 0.0f;
	}
	if (time >= m_totalAnimTime[2] && m_animation[2] != -1)
	{
		time = 120.0f;
	}

	//再生時間をセットする
	if (m_animation[0] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[0], time);
	}
	if (m_animation[2] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[2], time);
	}
}

void WeakEnemy::Draw()
{
	//方向ベクトル
	Vec3 vec = m_vec.GetNormalized() * m_len * 0.5f;

	Pos3 pos1 = m_colPos + vec;
	Pos3 pos2 = m_colPos - vec;

	if (m_hp > 0.0f)
	{
		DrawCapsule3D(pos1.GetVector(), pos2.GetVector(), m_capsuleRadius, 16, m_color, 0, false);
	}
	

	//3Dモデルポジション設定
	MV1SetPosition(m_handle, m_pos);

	//3Dモデル描画
	MV1DrawModel(m_handle);

	DrawFormatString(0, 320, 0xffffff, "m_colposX : %f m_colposY : %f m_colposZ : %f", m_colPos.x, m_colPos.y, m_colPos.z);
	DrawFormatString(0, 220, 0xffffff, "m_EnemyHp : %f", m_hp);
}

void WeakEnemy::End()
{
}

bool WeakEnemy::isHit(const CapsuleCol& col)
{
	bool isHit = m_capsuleCol.IsHitCapsule(col);

	if (isHit)
	{
		m_color = 0xffff00;
	}
	else
	{
		m_color = 0xffffff;
	}

	return isHit;
}

bool WeakEnemy::isSphereHit(const SphereCol& col, float damage)
{
	bool isHit = m_capsuleCol.IsHitSphere(col);

	//ダメージを受けた判定
	if (isHit)
	{
		m_color = 0xffff00;

		//ダメージを一回だけ与える
		if (m_damageReceived == false)
		{
			m_hp = m_hp - damage;

			m_damageReceived = true;
		}
		
	}
	else
	{
		m_damageReceived = false;

		m_color = 0xffffff;
	}

	return isHit;
}
