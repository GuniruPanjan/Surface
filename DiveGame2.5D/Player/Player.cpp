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
	//キー入力
	int Keyinput = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//プレイヤーは落ち続ける
	m_playerY += m_gravity;

	//プレイヤーは落下中移動できる
	//画面外に行かないように
	if (m_playerX >= 0)
	{
		//左矢印を押した時
		if (Keyinput & PAD_INPUT_LEFT)
		{
			m_playerX -= m_move;
		}
	}
	//画面外に行かないように
	if (m_playerX <= 640)
	{
		
		//右矢印を押した時
		if (Keyinput & PAD_INPUT_RIGHT)
		{
			m_playerX += m_move;
		}
	}
	//キーを押している間落下スピードを上げる
	if (Keyinput & PAD_INPUT_DOWN)
	{
		m_gravity = m_swoop;
	}
	//押してない間は重力を戻す
	else
	{
		m_gravity = 0.8f;
	}
	
	m_colRect.SetCenter(m_playerX, m_playerY, 18, 18);
}

void Player::Draw()
{
	//プレイヤーを描画する
	m_playergraph = DrawCircle(m_playerX, m_playerY, 10, GetColor(255, 255, 255), true);
	
	m_colRect.Draw(GetColor(255, 0, 0), false);
}

void Player::End()
{
}
