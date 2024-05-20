#pragma once
#include "EnemyBase.h"
#include "Player/Player.h"

class Enemy : public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void Update(Player& player);
	void Draw();
	void End();

	//“G¶¬
	EnemyBase* enemy1 = new EnemyBase();
	EnemyBase* enemy2 = new EnemyBase();
	EnemyBase* enemy3 = new EnemyBase();
	EnemyBase* enemy4 = new EnemyBase();
	EnemyBase* enemy5 = new EnemyBase();

	//“G‚Ìƒ|ƒWƒVƒ‡ƒ“
	VECTOR enemy1pos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR enemy2pos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR enemy3pos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR enemy4pos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR enemy5pos = VGet(0.0f, 0.0f, 0.0f);

};

