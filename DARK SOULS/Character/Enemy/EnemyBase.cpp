#include "EnemyBase.h"

EnemyBase::EnemyBase():
	m_enemySearchFlag(false)
{
	//敵のスピード初期化
	m_speed = 2.0f;
	//敵のモデル読み込み
	m_handle = MV1LoadModel("Data/Enemy/EnemyModel.mv1");
	//オブジェクトの大きさを変える変数
	m_modelSize = 0.4f;

	//敵の大きさ変更
	MV1SetScale(m_handle, VGet(m_modelSize, m_modelSize, m_modelSize));

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
	//3Dモデル描画
	MV1DrawModel(m_handle);
}
