#pragma once
#include "Rect.h"
#define ENEMY_NOW 30
#define SKY_ENEMY_NOW 10
#define DISTANCE_ENEMY_NOW 15

struct EnemyLoadDate
{
	//敵の画像取得変数
	int DistanceEnemyGraph;

	//敵の音取得変数
	int WalkEnemySound, WalkEnmeyDeadSound1, WalkEnmeyDeadSound2;

	int SkyEnemyDead;

	int DistanceEnmeySound, DistanceEnemyDamageSound, DistanceEnemyDeadSound;

	//DistanceエネミーのShot用の格納変数
	int ShotDistance;

	//DistanceエネミーのShotの音格納用変数
	int DistanceEnemyShotSound;

	//エネミーを倒したときのポイント表示
	int WalkPoint, SkyPoint, DistancePoint;

	//エネミーを倒したときのポイント獲得音
	int LoadSEPoint;
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

