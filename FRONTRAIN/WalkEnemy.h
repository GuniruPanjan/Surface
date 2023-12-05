#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "Player.h"

class Player;
class Shot;
class Point;

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init();
	void Update(Player& player, Shot& shot, WalkEnemy& enemy);
	void Draw(int ScrollX);

	EnemyBase Base;
	Point point;

	int WalkEnemyGraph;

	//敵の現在地
	float WalkEnemyX, WalkEnemyY;

	//敵の大きさ
	int WalkEnemyWidth, WalkEnemyHeight;

	//エネミーの大きさ取得する変数
	int WalkEnemyW, WalkEnmeyH;

	//エネミーのスピード
	float WalkEnemySpeed;
};

