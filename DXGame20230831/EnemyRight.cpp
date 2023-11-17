#include "EnemyRight.h"
#include "DxLib.h"
#include "Game.h"

namespace
{
	constexpr float kSpeed = 4.0f;
}

EnemyRight::EnemyRight()
	//m_handle(-1),
	//m_isExist(false)
	//m_posは引数なしのコンストラクタが呼ばれる
	//引数無しのコンストラクタを呼ぶ場合が省略できる
{
}

EnemyRight::~EnemyRight()
{
}

//void EnemyRight::Init()
//{
//}

void EnemyRight::Update()
{
	//存在しない敵の処理はしない
	if (!m_isExist) return;

	//m_pos.x -= kSpeed;
	m_pos += m_vec;

	//あたり判定の更新
	UpdateCollision();

	//ベクトルをいじってみる
	//画面中央を超えたら加速する
	if (m_pos.x < Game::kScreenWidth / 2)
	{
		//移動ベクトルを変化させる事で速度を上げる
		//左に移動する量を大きくすることで速く動いているように見せる
		m_vec.x -= 0.5f;
	}

	//画面外に出たら存在をけす
	int width = 0;
	int height = 0;
	GetGraphSize(m_handle, &width, &height);

	if (m_pos.x < 0.0f - width)
	{
		m_isExist = false;
	}
}

//void EnemyRight::Draw() const
//{
//	//存在しない敵は描画しない
//	if (!m_isExist) return;
//
//	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, false);
//}

void EnemyRight::Start()
{
	m_isExist = true;

	int width = 0;
	int height = 0;
	GetGraphSize(m_handle, &width, &height);


	m_pos.x = static_cast<float>(Game::kScreenWidth + width / 2);
	m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - height) + height / 2);

	//1フレームあたりの移動ベクトルを決定する
	m_vec.x = -kSpeed;
	m_vec.y = 0.0f;
}
