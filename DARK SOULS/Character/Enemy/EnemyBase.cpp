#include "EnemyBase.h"

EnemyBase::EnemyBase():
	m_enemySearchFlag(false)
{
	//敵のモデル読み込み
	m_handle = MV1LoadModel("Data/Enemy/EnemyModel.mv1");

	//敵のアニメーション読み込み
	m_animStand = MV1LoadModel("Data/EnemyAnimation/WeakEnemyAnimation/WeakEnemyStand1.mv1");

	//アニメーションアタッチ
	m_animation[0] = MV1AttachAnim(m_handle, 0, m_animStand, TRUE);

	//アタッチしたアニメーションの総再生時間を取得する
	m_totalAnimTime[0] = MV1GetAttachAnimTotalTime(m_handle, m_animation[0]);

	//敵のサイズ変更
	m_modelSize = 0.4f;
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));
	
}

EnemyBase::~EnemyBase()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);
}

void EnemyBase::End()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
	MV1DeleteModel(m_animStand);

}
