#pragma once
#include "EnemyBase.h"

class BossEnemy : public EnemyBase
{
public:
	BossEnemy();
	virtual ~BossEnemy();

	void Init();
	void Update(Player& player, Map& map);
	void Action(Player& player);
	void Animation(float& time);
	void Draw();
	void End();

	bool isSphereHit(const SphereCol& col, float damage);
	bool isCapsuleHit(const CapsuleCol& col);

	float GetDamage() { return m_attack; }
	bool GameClear() { return m_gameClear; }

	CapsuleCol GetCol() const { return m_capsuleCol; }
	SphereCol GetAttackCol1() { return m_colBossAttackSphere1; }
	SphereCol GetAttackCol2() { return m_colBossAttackSphere2; }
	SphereCol GetAttackCol3() { return m_colBossAttackSphere3; }


private:
	bool m_gameClear;        //ボスを倒したらゲームクリア
	bool m_bossDistance;     //ボスが離れていたときの判断
	bool m_bossBattle;       //ボスの臨戦態勢判定
	bool m_bossMoveAttack;   //ボスの攻撃行動判定
	int m_bossAttack;     //ボスの攻撃パターン
	unsigned int m_color = 0xffffff;
	unsigned int m_seachColor = 0xffffff;
	unsigned int m_distanceColor = 0xffffff;
	Pos3 m_colBossAttackPos1;     //攻撃の当たり判定1
	Pos3 m_colBossAttackPos2;     //攻撃の当たり判定2
	Pos3 m_colBossAttackPos3;     //攻撃の当たり判定3
	float m_bossAttackRadius1;     //攻撃の当たり判定半径1
	float m_bossAttackRadius2;     //攻撃の当たり判定半径2
	float m_bossAttackRadius3;     //攻撃の当たり判定半径3
	SphereCol m_colBossAttackSphere1;    //攻撃の当たり判定Col1
	SphereCol m_colBossAttackSphere2;    //攻撃の当たり判定Col2  
	SphereCol m_colBossAttackSphere3;    //攻撃の当たり判定Col3  



	std::shared_ptr<Map> map = std::make_shared<Map>();
};

