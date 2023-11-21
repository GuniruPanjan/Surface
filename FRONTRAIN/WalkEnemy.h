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

	int WalkEnemyGraph;

	//エネミーの大きさ取得する変数
	int WalkEnemyW, WalkEnmeyH;
};

