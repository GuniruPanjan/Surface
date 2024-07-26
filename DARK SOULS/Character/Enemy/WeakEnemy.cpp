#include "Character/Player/Player.h"
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
	m_speed = 0.01f;

	m_posX = 0.0f;
	m_posY = 0.0f;
	m_posZ = 0.0f;

	m_pos = VGet(m_posX, m_posY, m_posZ);

	//当たり判定
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_colDeathPos = Pos3(0.0f, -1000.0f, 0.0f);
	m_colSearchPos = Pos3(0.0f, m_pos.y + 35.0f, 0.0f);
	m_colDistancePos = Pos3(m_pos.x, m_pos.y + 35.0f, m_pos.z);
	m_vec = Vec3(m_pos.x, m_pos.y + 2.0f, m_pos.z);
	m_deathVec = Vec3(0.0f, 0.0f, 0.0f);
	m_len = 40.0f;
	m_capsuleRadius = 14.0f;
	m_searchRadius = 120.0f;
	m_distanceRadius = 80.0f;
	m_capsuleCol.Init(m_colPos, m_vec, m_len, m_capsuleRadius);
	m_colSearch.Init(m_colSearchPos, m_searchRadius);
	m_colDistance.Init(m_colDistancePos, m_distanceRadius);
}

void WeakEnemy::Update(Player& player)
{
	m_colPos = Pos3(m_pos.x - 2.0f, m_pos.y + 35.0f, m_pos.z);
	m_colDistancePos = Pos3(m_pos.x, m_pos.y + 35.0f, m_pos.z);

	m_playTime += 0.5f;

	//索敵で発見された処理
	if (m_enemySearchFlag == true)
	{
		float X = m_pos.x - player.GetPosX();
		float Z = m_pos.z - player.GetPosZ();

		//プレイヤーの方を向く
		m_angle = atan2f(X, Z);

		//法線ベクトル
		m_moveTurning = atan2f(-X, Z);
		m_moveReverseTurning = atan2f(X, -Z);
	}

	Action(player);

	//敵が移動する
	m_pos = VAdd(m_pos, m_move);

	Animation(m_playTime);

	//敵が死亡したら
	if (m_hp <= 0.0f)
	{
		DrawFormatString(0, 240, 0xffffff, "敵が死んだ");

		m_capsuleCol.Update(m_colDeathPos, m_deathVec);

		m_colSearch.Update(m_colDeathPos);
	}
	else
	{
		m_capsuleCol.Update(m_colPos, m_vec);

		//とりあえず置いとく
		m_colSearch.Update(m_colSearchPos);
		m_colDistance.Update(m_colDistancePos);
	}

	//索敵の当たり判定を正面に持ってくる
	m_colSearchPos.x = m_pos.x + sinf(m_angle) * -80.0f;
	m_colSearchPos.z = m_pos.z - cosf(m_angle) * 80.0f;
	
}

/// <summary>
/// プレイヤーへの攻撃や間合いの取り方などをまとめる関数
/// </summary>
/// <param name="player"></param>
void WeakEnemy::Action(Player& player)
{
	//敵に発見された場合
	if (m_enemySearchFlag == true)
	{
		//プレイヤーと敵の相対距離を算出
		VECTOR tracking = VSub(player.GetPos(), m_pos);

		//角度を出しプレイヤーの周りを旋回運動させる
		MATRIX mtx = MGetRotY(D2R(m_moveTurning) + DX_PI_F / 2);
		MATRIX mtxR = MGetRotY(D2R(m_moveReverseTurning) - DX_PI_F / 2);

		if (m_enemyWait == false)
		{
			m_speed = 0.01f;

			m_move = VScale(tracking, m_speed);
		}
		else
		{
			m_move = VNorm(tracking);

			m_speed = 0.3f;

			m_move = VScale(m_move, m_speed);

			m_move = VTransform(m_move, mtxR);
		}
		
	}
	//敵に発見されてないとき
	else
	{
		//敵が動かないようにする
		m_move = VGet(0.0f, 0.0f, 0.0f);
	}
	
}

void WeakEnemy::Animation(float& time)
{
	//敵がプレイヤーを見つけてないとき
	if (m_enemySearchFlag == false)
	{
		if (m_animation[3] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[3]);

			//アニメーションアタッチ
			m_animation[0] = MV1AttachAnim(m_handle, 0, m_animStand, TRUE);

			time = 0.0f;

			m_animation[3] = -1;
		}
	}
	//敵がプレイヤーを見つけた時(臨戦態勢)
	if (m_enemySearchFlag == true)
	{
		if (m_animation[0] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);

			//アニメーションアタッチ
			m_animation[3] = MV1AttachAnim(m_handle, 0, m_animWalk, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
		}
	}

	//敵が死んだら死ぬアニメーションを入れる
	if (m_hp <= 0.0f)
	{
		if (m_animation[0] != -1 || m_animation[1] != -1 || m_animation[3] != -1)
		{
			//アニメーションデタッチ
			MV1DetachAnim(m_handle, m_animation[0]);
			MV1DetachAnim(m_handle, m_animation[1]);
			MV1DetachAnim(m_handle, m_animation[3]);


			//アニメーションアタッチ
			m_animation[2] = MV1AttachAnim(m_handle, 0, m_animDeath, TRUE);

			time = 0.0f;

			m_animation[0] = -1;
			m_animation[1] = -1;
			m_animation[3] = -1;

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
	if (time >= m_totalAnimTime[3] && m_animation[3] != -1)
	{
		time = 0.0f;
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
	if (m_animation[3] != -1)
	{
		MV1SetAttachAnimTime(m_handle, m_animation[3], time);
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

		//索敵範囲円の3D描画
		DrawSphere3D(m_colSearchPos.GetVector(), m_searchRadius, 16, m_seachColor, m_seachColor, false);

		//一定距離の範囲描画
		DrawSphere3D(m_colDistancePos.GetVector(), m_distanceRadius, 16, m_distanceColor, m_distanceColor, false);

	}

	//3Dモデルポジション設定
	MV1SetPosition(m_handle, m_pos);

	//3Dモデル描画
	MV1DrawModel(m_handle);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(m_handle, VGet(0.0f, m_angle, 0.0f));

	DrawFormatString(0, 320, 0xffffff, "m_colposX : %f m_colposY : %f m_colposZ : %f", m_colPos.x, m_colPos.y, m_colPos.z);
	DrawFormatString(0, 220, 0xffffff, "m_EnemyHp : %f", m_hp);

	if (m_enemySearchFlag == true)
	{
		DrawFormatString(0, 250, 0xffffff, "発見された");
	}
}

void WeakEnemy::End()
{
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

bool WeakEnemy::isSeachHit(const CapsuleCol& col)
{
	bool isHit = m_colSearch.IsHitCapsule(col);

	//プレイヤーを見つけた判定
	if (isHit)
	{
		m_seachColor = 0xffff00;

		m_enemySearchFlag = true;
	}
	else
	{
		m_seachColor = 0xffffff;

		m_enemySearchFlag = false;
	}

	return isHit;
}

bool WeakEnemy::isDistanceHit(const CapsuleCol& col)
{
	bool isHit = m_colDistance.IsHitCapsule(col);

	//一定範囲内にプレイヤーが入った時
	if (isHit)
	{
		m_distanceColor = 0xffff00;

		m_enemyWait = true;
	}
	else
	{
		m_distanceColor = 0xffffff;

		m_enemyWait = false; 
	}

	return isHit;
}
