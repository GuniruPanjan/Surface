#pragma once
#include "EnemyBase.h"
#include "Player.h"
class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init();
	void Update();
	void Draw();

	Shot shot[SHOT];
	EnemyBase Base;

	int WalkEnemyGraph;

	//敵の現在地
	int WalkEnemyX, WalkEnemyY;

	//エネミーの大きさ取得する変数
	int WalkEnemyW, WalkEnmeyH;
};

