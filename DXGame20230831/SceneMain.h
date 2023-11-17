#pragma once
#include<vector>
#include "Vec2.h"

class Player;
//class EnemyRight;
//class EnemyToPlayer;
//
//class EnemyLeft;

class EnemyBase;
class Bg;
class ShotBase;
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void Init();
	void End();
	void Update();
	void Draw() const;

	//特定の座標から一番近くにいる敵の座標を返す関数
	Vec2 GetNearEnemyPos(Vec2 pos) const;
	//ショットを追加する 登録できなかった場合はfalseを返す
	//登録出来なかった場合は内部でpShot解放する
	bool AddShot(ShotBase* pShot);

//private:
//	static constexpr int kEnemyNum = 16;
private:
	//敵キャラクターの生成
	void CreateEnemyLeft();
	void CreateEnemyRight();
	void CreateEnemyToPlayer();

private:
	//グラフィックハンドル
	int m_playerHandle;
	int m_enemyHandle;
	int m_bgHandle;

	//プレイヤー
	Player* m_pPlayer;

	//敵キャラクター
	//EnemyRight* m_pEnemyRight;
	/*EnemyRight* m_pEnemyRight[kEnemyNum];
	EnemyToPlayer* m_pEnemyToPlayer[kEnemyNum];

	EnemyLeft* m_pEnemyLeft;

	int m_enemyFrameCount;*/

	//背景
	Bg* m_pBg;

	//敵
	std::vector<EnemyBase*>m_pEnemy;   //配列のサイズは実行時に決める（今回はコンストラクタ）
	//EnemyBase* m_pEnemy[16];   //今までの配列

	//ショット
	std::vector<ShotBase*> m_pShot;
	//ShotBase* m_pShot;

	//敵の登場間隔
	int m_enemyInterval;
};

