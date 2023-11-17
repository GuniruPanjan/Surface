#include "player.h"
#include "DxLib.h"

//’è”éŒ¾
namespace
{
	constexpr int kRadius = 16;
}

//ŠÖ”‚ÌŽÀ‘•
Player::Player() :
	m_posX(0),
	m_posY(0)
{

}

Player::~Player()
{

}

void Player::init()
{

}

void Player::update()
{
	GetMousePoint(&m_posX, &m_posY);
}

void Player::draw()
{
	DrawCircle(m_posX, m_posY, 16, GetColor(255, 255, 255), true);
}

int Player::getRadius()
{
	return kRadius;
}