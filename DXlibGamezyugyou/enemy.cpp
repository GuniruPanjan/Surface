#include "enemy.h"
#include "DxLib.h"

//�萔�錾
namespace
{
	constexpr int kPosX = 320;
	constexpr int kPosY = 240;
	//���a
	constexpr int kRadius = 32;
	//�F
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
	//�s���Ȓl��ݒ肳�ꂽ�ꍇ�A�s������Ȃ��悤�ɂ������ł���

	m_posX = x;

	//��ʊO���ݒ肳�ꂽ�ꍇ�͉�ʓ��Ɏ��܂�悤�ɂ���
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

