#pragma once
#include "EnemyBase.h"
#include "WeakEnemy.h"

/// <summary>
/// 敵の挙動や仕様
/// </summary>
class Enemy : public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void Update();
	void Draw();
	void End();

	VECTOR GetPos() { return enemy->GetPos(); }
	float GetPosX() { return enemy->GetPosX(); }
	float GetPosY() { return enemy->GetPosY(); }
	float GetPosZ() { return enemy->GetPosZ(); }


private:
	//敵の構造体を配列で読み込み
	std::shared_ptr<WeakEnemy> enemy = std::make_shared<WeakEnemy>();
};

