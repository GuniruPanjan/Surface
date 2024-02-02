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
	float WalkEnemyX = 0.0f; 
    float WalkEnemyY = 0.0f;
	int WalkEnemyGraph[12];

	//敵の大きさ
	int WalkEnemyWidth = 20;
	int WalkEnemyHeight = 20;

	//エネミーのスピード
	float WalkEnemySpeed = 0.04f;
	//エネミーの死亡判定
	bool WalkEnemyDead = false;
	//敵が弾で死んだ判定
	bool WalkShotDead = false;

	//アニメーションタイム
	int AnimTime = 0;

	int RightAnim = 0;
	int LeftAnim = 0;

	//死んだアニメーション
	int Handle[14];

	//アニメーションタイム
	int AnimCount = 0;
	int AnimTimeDead = 0;

	//エネミーが出現するフラグ
	bool WalkEnemyflag = false;

	//SE用格納変数
	int SEWalkEnemy;

	int SEWalkEnemyDead1, SEWalkEnemyDead2;

	//SEを一回だけ鳴らす
	bool SE1,SE2;
	
};

class WalkEnemy : public EnemyBase
{
public:
	WalkEnemy();
	~WalkEnemy();

	void Init(WalkEnemyStruct enemy[], WalkEnemy& Wenemy, int WenemySize);
	void Update(Player& player, Shot& shot, WalkEnemyStruct enemy[],int WenemySize,float ScrollX,TimeCount* time,WalkEnemy& Wenemy);
	void Draw(float ScrollX, WalkEnemyStruct enemy[], Point& point, int WenemySize, Player& player, Shot shot[]);

	EnemyBase Base;
	WalkEnemyStruct WenemyS[ENEMY_NOW];

	//敵の出現フラグ
	bool WalkEnemyAppearance = true;
	
	//時間を進める変数
	int T = 0;
	int TUP = 0;
};

