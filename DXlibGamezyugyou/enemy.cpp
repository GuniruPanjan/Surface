#include "enemy.h"
#include "DxLib.h"

//定数宣言
namespace
{
	constexpr int kPosX = 320;
	constexpr int kPosY = 240;
	//半径
	constexpr int kRadius = 32;
	//色
	const unsigned int kColor = GetColor(200, 200, 200);
}


Enemy::Enemy() :
	m_posX(kPosX),
	m_posY(kPosY),
	Color(kColor)
{

}

Enemy::~Enemy()
{
	
}

void Enemy::init()
{

}

void Enemy::update()
{

}

void Enemy::draw()
{
	DrawCircle(m_posX, m_posY, kRadius, Color, true);
}

void Enemy::setPosX(int x)
{
	//不正な値を設定された場合、不正じゃないようにしたいできる

	m_posX = x;

	//画面外が設定された場合は画面内に収まるようにする
	if (m_posX < 0)
	{
		m_posX = 0;
	}
	if (m_posX > 640)
	{
		m_posX = 640;
	}
}

int Enemy::getPosX()
{
	return m_posX;
}

int Enemy::getPosY()
{
	return m_posY;
}

int Enemy::getRadius()
{
	return kRadius;
}

void Enemy::setColor(unsigned int x)
{
	Color = x;
}

