#pragma once
#include "EnemyBase.h"
#include "Point.h"
#include "TimeCount.h"
#include "Player.h"

class Player;
class Shot;
class Point;
class TimeCount;
class Shield;

struct SkyEnemyStruct : public EnemyBase
{
	//“G‚ÌŒ»İ’n
	float SkyEnemyX = 0.0f;
	float SkyEnemyY = 0.0f;
	int SkyEnemyGraph = -1;

	//“G‚Ì‘å‚«‚³
	int SkyEnemyWidth = 10;
	int SkyEnemyHeight = 10;

	//“G‚ªƒvƒŒƒCƒ„[‚ÉŒü‚©‚Á‚Ä‚¢‚­
	double PX = 0;
	double PY = 0;

	//“G‚ª”­¶’†‚©‚Ç‚¤‚©
	bool Flag = false;

	//“G‚Ì€–S”»’è
	bool SkyEnemyDead = false;
	//“G‚ª’e‚Å€‚ñ‚¾”»’è
	bool SkyShotDead = false;

	//“G‚ªoŒ»‚·‚éƒtƒ‰ƒO
	bool SkyEnemyflag = false;
};

class SkyEnemy : public EnemyBase
{
public:
	SkyEnemy();
	~SkyEnemy();

	void Init(SkyEnemyStruct& enemy, SkyEnemy& Senemy);
	void Update(Player& player, Shot& shot, SkyEnemyStruct enemy[], int SenemySize, float ScrollX, TimeCount* time, SkyEnemy& Senemy, Shield& shield);
	void Draw(float ScrollX, SkyEnemyStruct& enemy, Point& point);

	//“G‚ÌoŒ»ƒtƒ‰ƒO
	bool SkyEnemyAppearance = true;

	//ŠÔ‚ği‚ß‚é•Ï”
	int T = 0;
};

