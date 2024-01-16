#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"

class Player;
class Shot;
class Point;
class TimeCount;

struct DistanceEnemyStruct : public EnemyBase
{
	//“G‚ÌŒ»İ’n
	float DistanceEnemyX = 0.0f;
	float DistanceEnemyY = 0.0f;
	int DistanceEnemyGraph = -1;

	//“G‚Ì‘å‚«‚³
	int DistanceEnemyWidth = 20;
	int DistanceEnemyHeight = 20;

	//“G‚ÌƒXƒs[ƒh
	float DistanceEnemySpeed = 0.02f;
	//“G‚Ì€–S”»’è
	bool DistanceEnemyDead = false;
	//“G‚ª’e‚Å€‚ñ‚¾”»’è
	bool DistanceShotDead = false;

	//“G‚ªoŒ»‚·‚éƒtƒ‰ƒO
	bool DistanceEnemyflag = false;

};
class DistanceEnemy : public EnemyBase
{
public:
	DistanceEnemy();
	~DistanceEnemy();

	void Init(DistanceEnemyStruct& enemy,DistanceEnemy& Denemy);
	void Update(Player& player,Shot& shot,DistanceEnemyStruct enemy[],int DenemySize,float ScrollX,TimeCount* time,DistanceEnemy& Denemy);
	void Draw(float ScrollX, DistanceEnemyStruct& enemy,Point& point);

	//“G‚ÌoŒ»ƒtƒ‰ƒO
	bool DistanceEnemyAppearance = true;

	//ŠÔ‚ği‚ß‚é•Ï”
	int T = 0;
};

