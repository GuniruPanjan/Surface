#pragma once
#include "EnemyBase.h"
class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init();
	void Update();
	void Draw();
private:
	int WalkEnemyGraph;
};

