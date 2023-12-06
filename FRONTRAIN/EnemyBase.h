#pragma once
#include "Rect.h"
#define ENEMY_NOW 30

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

