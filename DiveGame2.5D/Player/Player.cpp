#include "Player.h"
#include "Rect.h"
#include "DxLib.h"

Rect* rect;

Player::Player():
	m_playerX(0.0f),
	m_playerY(0.0f)
{
}

Player::~Player()
{
}

void Player::Init()
{
	//プレイヤーの座標初期化
	m_playerX = 320.0f;
	m_playerY = 50.0f;

	//プレイヤーに重力を与える
	m_gravity = 0.5f;
	//プレイヤーが移動できるスピード
	m_move = 1.0f;
	//プレイヤーのグラフを読み込む
	
}

void Player::Update()
{
	//プレイヤーは落ち続ける
	m_playerY += m_gravity;

	//プレイヤーは落下中移動できる
	//画面外に行かないように
	if (m_playerX >= 0)
	{
		//左矢印を押した時
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			m_playerX -= m_move;
		}
	}
	//画面外に行かないように
	if (m_playerX <= 640)
	{
		
		//右矢印を押した時
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			m_playerX += m_move;
		}
	}
	

}

void Player::Draw()
{
	//プレイヤーを描画する
	m_playergraph = DrawCircle(m_playerX, m_playerY, 10, GetColor(255, 255, 255), true);
	

}

void Player::End()
{
}
