#include "Player.h"
#include "DxLib.h"

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
	m_move = 0.5f;
	//プレイヤーのグラフを読み込む
	m_playergraph = DrawCircle(320, 50, 5, GetColor(255, 255, 255), true);
}

void Player::Update()
{
	//プレイヤーは落ち続ける
	m_playerY += m_gravity;

	//プレイヤーは落下中移動できる
	//左矢印を押した時
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_playerX -= m_move;
	}
	//右矢印を押した時
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_playerX += m_move;
	}

}

void Player::Draw()
{
	//プレイヤーを描画する
	DrawGraph(static_cast<int>(m_playerX), static_cast<int>(m_playerY), m_playergraph, false);

}

void Player::End()
{
}
