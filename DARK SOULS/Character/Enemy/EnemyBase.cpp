#include "EnemyBase.h"

EnemyBase::EnemyBase():
	m_enemySearchFlag(false),
	m_searchRadius(0.0f)
{
	//敵のモデル読み込み
	m_handle = MV1LoadModel("Data/Enemy/EnemyModel.mv1");

	//敵のアニメーション読み込み
	m_animStand = MV1LoadModel("Data/EnemyAnimation/WeakEnemyAnimation/WeakEnemyStand1.mv1");
	m_animWalk = MV1LoadModel("Data/EnemyAnimation/WeakEnemyAnimation/WeakEnemyAnimWalking.mv1");
	m_animHit = MV1LoadModel("Data/EnemyAnimation/WeakEnemyAnimation/WeakEnemyAnimHit.mv1");
	m_animDeath = MV1LoadModel("Data/EnemyAnimation/WeakEnemyAnimation/WeakEnemyAnimDeath.mv1");

	//アニメーションアタッチ
	m_animation[0] = MV1AttachAnim(m_handle, 0, m_animStand, TRUE);
	m_animation[1] = MV1AttachAnim(m_handle, 0, m_animHit, TRUE);
	m_animation[2] = MV1AttachAnim(m_handle, 0, m_animDeath, TRUE);
	m_animation[3] = MV1AttachAnim(m_handle, 0, m_animWalk, TRUE);

	//アタッチしたアニメーションの総再生時間を取得する
	m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);
	m_totalAnimTime[1] = MV1GetAttachAnimTotalTime(m_handle, m_animation[1]);
	m_totalAnimTime[2] = MV1GetAttachAnimTotalTime(m_handle, m_animation[2]);
	m_totalAnimTime[3] = MV1GetAttachAnimTotalTime(m_handle, m_animation[3]);

	//一旦待機以外のアニメーションをデタッチする
	MV1DetachAnim(m_handle, m_animation[1]);
	MV1DetachAnim(m_handle, m_animation[2]);
	MV1DetachAnim(m_handle, m_animation[3]);
	m_animation[1] = -1;
	m_animation[2] = -1;
	m_animation[3] = -1;

	//敵のサイズ変更
	m_modelSize = 0.4f;
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));
	
}

EnemyBase::~EnemyBase()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animHit);
	MV1DeleteModel(m_animDeath);
	MV1DeleteModel(m_animWalk);

}

void EnemyBase::End()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
	MV1DeleteModel(m_animHit);
	MV1DeleteModel(m_animDeath);
	MV1DeleteModel(m_animWalk);

}
