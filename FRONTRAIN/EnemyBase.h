#pragma once
#include "Rect.h"
class EnemyBase
{
public:
	EnemyBase();
	~EnemyBase();

	int HP;
	int Speed;
	int Attack;
	int EnemyW;
	int EnemyH;

	//�����蔻��̋�`
	Rect m_colRect;
};

