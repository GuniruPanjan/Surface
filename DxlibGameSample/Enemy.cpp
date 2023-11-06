#include "Enemy.h"
#include "DxLib.h"
#include<cassert>   //assert.h

//定数定義
namespace
{
	constexpr int kMoveSpeed = 4;

	//グラフィックのサイズ
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;
}

//コンストラクタ
Enemy::Enemy():
	m_handle(-1),
	m_graphWidth(0),
	m_graphHeight(0),
	m_posX(0),
	m_posY(0),
	m_moveX(kMoveSpeed)
{
	if (GetRand(1))
	{
		m_moveX *= -1;
		
	}
}

//デストラクタ
Enemy::~Enemy()
{
	DeleteGraph(m_handle);
}

void Enemy::Init()
{

}

void Enemy::Update()
{
	m_posX += m_moveX;
	if (m_posX < 0)
	{
		m_posX = 0;
		m_moveX *= -1;   //進行方向の反転
	}
	if (m_posX > 640 - m_graphWidth)
	{
		m_posX = 640 - m_graphWidth;
		m_moveX *= -1;  //進行方向の反転
	}
}

void Enemy::Draw() const
{
	int posX = m_posX;
	int posY = m_posY;

	posX += GetRand(5) - 2;
	posY += GetRand(5) - 2;

	if (m_moveX > 0)
	{
		DrawTurnGraph(posX, posY, m_handle, false);
	}
	else
	{
		DrawGraph(posX, posY, m_handle, false);
	}
	
	
}

void Enemy::SetHandle(int Handle)
{
	m_handle = Handle;

	//使用するグラフィックのサイズを取得する
	GetGraphSize(Handle, &m_graphWidth, &m_graphHeight);
}

void Enemy::SetStartPos()
{

	//グラフィックサイズが決定しいないと
	//画面外に表示されるかも！

	//グラフィックを決定する前に呼ばれていたらそれに気づくようにしたい
	// グラフィックが決まる前にここに来たら止まるようにしたい
	//assert(止まらない条件);
	assert(m_handle != -1);

	m_posX = GetRand(640 - m_graphWidth);
	m_posY = GetRand(480 - m_graphHeight);
}