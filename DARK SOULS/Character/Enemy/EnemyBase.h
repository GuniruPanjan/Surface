#pragma once
#include "Character/CharacterBase.h"
#define ENEMY_NOW 1

class EnemyBase : public CharacterBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtualで継承先を呼び出す
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//モデルハンドルの所得
	
protected:
	bool m_enemySearchFlag;  //敵の索敵フラグ

};

