#pragma once
#include "Character/CharacterBase.h"
#define ENEMY_NOW 1  //敵の配列で出す数

class Player;

class EnemyBase : public CharacterBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtualで継承先を呼び出す
	void Init() {};
	void Update() {};
	void Draw() {};
	virtual void End();
	
protected:
	bool m_enemySearchFlag;  //敵の索敵フラグ
	bool m_enemyWait;    //敵が一定距離を保つフラグ
	int m_enemyWaitseeRandom;   //エネミーの様子見行動のランダム化
	float m_searchRadius;  //円の当たり判定
	float m_distanceRadius;  //円の半径
	float m_moveTurning;   //時計回りに旋回するための法線ベクトル
	float m_moveReverseTurning;  //反時計周りに旋回するための法線ベクトル
	Pos3 m_colSearchPos;  //索敵範囲の当たり判定
	Pos3 m_colDistancePos;   //一定距離を保つための判定
	SphereCol m_colSearch;  //スフィア型の当たり判定
	SphereCol m_colDistance;  //一定距離を保つスフィア型の当たり判定
};

