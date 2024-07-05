#pragma once
#include "EnemyBase.h"

class Enemy : public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void Update(Player& player);
	void Draw();
	void End();

	//ìGê∂ê¨
	EnemyBase* enemy1 = new EnemyBase();
	EnemyBase* enemy2 = new EnemyBase();
	EnemyBase* enemy3 = new EnemyBase();
	EnemyBase* enemy4 = new EnemyBase();
	EnemyBase* enemy5 = new EnemyBase();

};

