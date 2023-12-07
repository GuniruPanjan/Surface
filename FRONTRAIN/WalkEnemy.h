#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"

class Player;
class Shot;
class Point;
class TimeCount;

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init(WalkEnemy& enemy,TimeCount* time);
	void Update(Player& player, Shot& shot, WalkEnemy& enemy);
	void Draw(int ScrollX, WalkEnemy& enemy, Point& point);

	EnemyBase Base;
	Point point;

	int WalkEnemyGraph;
	//敵の出現スタート時間
	int WalkEnemyTime;
	//敵の出現時間
	int WalkEnemyNowTime;
	//敵の現在地
	float WalkEnemyX, WalkEnemyY;

	//敵の大きさ
	int WalkEnemyWidth, WalkEnemyHeight;

	//エネミーの大きさ取得する変数
	int WalkEnemyW, WalkEnmeyH;

	//エネミーのスピード
	float WalkEnemySpeed;
	//エネミーの死亡判定
	bool WalkEnemyDead = false;
	

	//エネミーが出現するフラグ
	bool WalkEnemyflag = false;
};

