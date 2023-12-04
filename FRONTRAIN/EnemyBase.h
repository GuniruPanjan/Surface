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

	//“–‚½‚è”»’è‚Ì‹éŒ`
	Rect m_colRect;
};

