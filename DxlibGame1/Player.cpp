#include "Player.h"
#include "DxLib.h"
#include "Game.h"
#include<cassert>

namespace
{
	constexpr float kSpeed = 10.0f;
}

Player::Player() :
	m_handle(-1),
	m_width(0),
	m_height(0),
	m_posX(Game::kScreenWidth / 2),
	m_posY(624.0f),
	m_isTurn(false)
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_posX = Game::kScreenWidth / 2;
	m_posY = 624.0f;
	m_isTurn = false;
}

void Player::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_LEFT)
	{
		m_posX -= kSpeed;
		m_isTurn = false;
		if (m_posX < 0)
		{
			m_posX = 0;
		}
	}
	
	if (pad & PAD_INPUT_RIGHT)
	{
		m_posX += kSpeed;
		m_isTurn = true;
		if (m_posX > Game::kScreenWidth - m_width)
		{
			m_posX = Game::kScreenWidth - m_width;
		}
	}
	
}

void Player::Draw()
{
	if (m_isTurn)
	{
		DrawTurnGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, true);
	}
	else
	{
		DrawGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, true);
	}
	
}

void Player::SetGraphHandle(int handle)
{
	m_handle = handle;
	//グラフィックの幅と高さを取得する
	GetGraphSize(m_handle, &m_width, &m_height);
}

float Player::GetLeft() const
{
	return m_posX;
}

float Player::GetTop() const
{
	return m_posY;
}

float Player::GetRight() const
{
	return m_posX + m_posY;
}

float Player::GetBottom() const
{
	return m_posY + m_height;
}

