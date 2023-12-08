#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"

class Player;
class Shot;
class Point;
class TimeCount;

struct WalkEnemyStruct : public EnemyBase
{
	//敵の現在地
	float WalkEnemyX; 
	float WalkEnemyY;
	int WalkEnemyGraph;

	//敵の大きさ
	int WalkEnemyWidth = 20;
	int WalkEnemyHeight = 20;
	//エネミーの大きさ取得する変数
	int WalkEnemyW, WalkEnmeyH;

	//エネミーのスピード
	float WalkEnemySpeed = 0.03f;
	//エネミーの死亡判定
	bool WalkEnemyDead = false;

	//エネミーが出現するフラグ
	bool WalkEnemyflag = false;

	
};

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init(WalkEnemyStruct enemy,WalkEnemy& Wenemy);
	void Update(Player& player, Shot& shot, WalkEnemyStruct enemy[],int WenemySize,int ScrollX,TimeCount* time,WalkEnemy& Wenemy);
	void Draw(int ScrollX, WalkEnemyStruct& enemy, Point& point);

	EnemyBase Base;
	Point point;
	WalkEnemyStruct WenemyS[ENEMY_NOW];

	//敵の出現フラグ
	bool WalkEnemyAppearance = true;
	
	//時間を進める変数
	int T;
};

