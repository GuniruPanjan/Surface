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
	//敵の現在地
	float SkyEnemyX = 0.0f;
	float SkyEnemyY = 0.0f;
	float SkyEnemyDeadY = 0.0f;
	int SkyHandle[3];

	//アニメーション画像表示の変数
	int S = 0;

	int Time = 0;

	//死亡アニメーション
	int DeadAnimGraph[4];
	int DeadAnimCount;
	int DeadAnimTime;
	//ポイントの画像を入れる変数
	int DeadPoint = 0;

	//敵の大きさ
	int SkyEnemyWidth = 15;
	int SkyEnemyHeight = 10;

	//敵がプレイヤーに向かっていく
	double PX = 0;
	double PY = 0;

	//敵が発生中かどうか
	bool Flag = false;

	//敵の死亡判定
	bool SkyEnemyDead = false;
	//敵が弾で死んだ判定
	bool SkyShotDead = false;
	bool SkyShotDeadPoint = false;
	bool SkyShotDeadSE = false;

	//敵が出現するフラグ
	bool SkyEnemyflag = false;

	//死んだ時のSE用格納変数
	int SESkyEnemyDead;
	int DeadPointSE = 0;

	//SEを一回鳴らす
	bool SE;
};

class SkyEnemy : public EnemyBase
{
public:
	SkyEnemy();
	~SkyEnemy();

	void FinalizeSky(SkyEnemyStruct& enemy);
	void Init(SkyEnemyStruct& enemy, SkyEnemy& Senemy, EnemyLoadDate& date);
	void Update(Player& player, Shot& shot, SkyEnemyStruct enemy[], int SenemySize, float ScrollX, TimeCount* time, SkyEnemy& Senemy, Shield& shield);
	void Draw(float ScrollX, SkyEnemyStruct& enemy, Point& point);

	//敵の出現フラグ
	bool SkyEnemyAppearance = true;

	

	//時間を進める変数
	int T = 0;
	int TUP = 0;
	int TUP2 = 0;
	int TUP3 = 0;
	int TUP4 = 0;
};

