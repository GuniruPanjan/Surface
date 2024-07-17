#include "EnemyBase.h"

EnemyBase::EnemyBase():
	m_enemySearchFlag(false)
{
	//敵のアニメーション読み込み


	//敵のモデル読み込み
	m_handle = MV1LoadModel("Data/Enemy/EnemyModel.mv1");
}

EnemyBase::~EnemyBase()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
}

void EnemyBase::Init()
{
}

void EnemyBase::Update()
{

}

void EnemyBase::Draw()
{
	//3Dモデルポジション設定
	MV1SetPosition(m_handle, m_pos);

	//3Dモデル描画
	MV1DrawModel(m_handle);
}

void EnemyBase::End()
{
	//メモリ解放
	MV1DeleteModel(m_handle);
}
