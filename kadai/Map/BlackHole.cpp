#include "BlackHole.h"

BlackHole::BlackHole() :
	BlackHole3D(0),
	BlackHoleX(0),
	BlackHoleY(0),
	BlackHoleZ(0),
	BlackHoleWidth(0),
	BlackHoleHight(0),
	BlackDead(false)
{
}

BlackHole::~BlackHole()
{
}

void BlackHole::Init()
{
	//�u���b�N�z�[���̏����ʒu
	BlackHoleX = 0;
	BlackHoleY = 240;

	//�u���b�N�z�[���̕�
	BlackHoleWidth = 150;
	BlackHoleHight = 480;

	BlackDead = false;

	//3D���f����ǂݍ���
}

void BlackHole::Update(Player& player)
{
	//3D���f������]������

	//�����蔻�������
	BlackHoleRect.SetCenter(static_cast<float>(BlackHoleX), static_cast<float>(BlackHoleY), static_cast<float>(BlackHoleWidth), static_cast<float>(BlackHoleHight));

	//�u���b�N�z�[���Ŏ��񂾔���
	if (BlackHoleRect.IsCollision(player.m_colrect) == true)
	{
		BlackDead = true;
	}
}

void BlackHole::Draw()
{
	//3D���f����`�悷��

	//�����蔻���`�悷��
	BlackHoleRect.Draw(GetColor(0, 0, 0), true);

	
}
