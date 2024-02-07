#pragma once
#include "Rect.h"
#define ENEMY_NOW 20
#define SKY_ENEMY_NOW 20
#define DISTANCE_ENEMY_NOW 15

struct EnemyLoadDate
{
	//敵の画像取得変数
	int WalkEnemyGraph[12], SkyEnemyGraph[3], DistanceEnemyGraph;

	//敵の音取得変数
	int WalkEnemySound, WalkEnmeyDeadSound1, WalkEnmeyDeadSound2;

	int SkyEnemyDead;

	int DistanceEnmeySound, DistanceEnemyDamageSound, DistanceEnemyDeadSound;

	//敵が死んだ時のアニメーション取得変数
	int WalkEnemyDeadAnim[14],SkyEnemyDeadAnim[4],DistanceEnemyDeadAnim[14];

	//DistanceエネミーのShot用の格納変数
	int ShotDistance;

	int ShotHitGraphRight[2];
	int ShotHitGraphLeft[2];

	int ShotSparkGraphRight[2];
	int ShotSparkGraphLeft[2];

	//DistanceエネミーのShotの音格納用変数
	int DistanceEnemyShotSound;

	//エネミーを倒したときのポイント表示
	int WalkPoint, SkyPoint, DistancePoint;
};

class EnemyBase
{
public:
	EnemyBase();
	~EnemyBase();

	void Finalize(EnemyLoadDate& date);
	void Init(EnemyLoadDate& date);

	int HP;
	int Speed;
	int Attack;
	int EnemyW;
	int EnemyH;

	//当たり判定の矩形
	Rect m_colRect;
};

