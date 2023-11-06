#include "EnemyBase.h"
#include "DxLib.h"
#include "Game.h"
#include <cassert>

namespace
{
	constexpr float kSpeed = 4.0f;
}

EnemyBase::EnemyBase():
	m_handle(-1),
	m_isExist(false)
	//m_posは引数なしのコンストラクタが呼ばれる
	//引数無しのコンストラクタを呼ぶ場合が省略できる
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Init()
{
}

void EnemyBase::Update()
{
	//存在しない敵の処理はしない
	if (!m_isExist) return;

	////m_pos.x -= kSpeed;
	//m_pos += m_vec;

	////ベクトルをいじってみる
	////画面中央を超えたら加速する
	//if (m_pos.x < Game::kScreenWidth / 2)
	//{
	//	//移動ベクトルを変化させる事で速度を上げる
	//	//左に移動する量を大きくすることで速く動いているように見せる
	//	m_vec.x -= 0.5f;
	//}

	////画面外に出たら存在をけす
	//int width = 0;
	//int height = 0;
	//GetGraphSize(m_handle, &width, &height);

	//if (m_pos.x < 0.0f - width)
	//{
	//	m_isExist = false;
	//}
}

void EnemyBase::Draw() const
{
	float Fnum = 1.2f;    //32Bit
	double Dnum = 1.2;    //64Bit

	//存在しない敵は描画しない
	if (!m_isExist) return;
	//グラフィックが設定されていなければ止まる
	assert(m_handle != -1);
	//DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, false);
	DrawRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		1.0, 0.0, m_handle, true, false);
#ifdef _DEBUG
	//あたり判定の表示
	//m_colRect.Draw(GetColor(255, 0, 0), false);
#endif
}

void EnemyBase::UpdateCollision()
{
	int width = 0;
	int height = 0;
	GetGraphSize(m_handle, &width, &height);
	//m_colRect.SetLT(m_pos.x - width / 2, m_pos.y - height /2, width, height);
	//m_colRect.Set(m_pos.x, m_pos.y, width, height);
	//中心座標を指定してあたり判定のRectを生成する
	m_colRect.SetCenter(m_pos.x, m_pos.y, width, height);
}

//void EnemyBase::Start()
//{
//	m_isExist = false;
//
//	//int width = 0;
//	//int height = 0;
//	//GetGraphSize(m_handle, &width, &height);
//
//
//	//m_pos.x = static_cast<float>(Game::kScreenWidth);
//	//m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - height));
//
//	////1フレームあたりの移動ベクトルを決定する
//	//m_vec.x = -kSpeed;
//}
