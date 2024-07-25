#pragma once
#include "EnemyBase.h"
#include "WeakEnemy.h"

/// <summary>
/// �G�̋�����d�l
/// </summary>
class Enemy : public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void Update(Player& player);
	void Draw();
	void End();

	VECTOR GetPos() { return enemy->GetPos(); }
	float GetPosX() { return enemy->GetPosX(); }
	float GetPosY() { return enemy->GetPosY(); }
	float GetPosZ() { return enemy->GetPosZ(); }
	CapsuleCol GetCol() const { return enemy->GetCol(); }
	bool isSphereHit(SphereCol col, float damage) { return enemy->isSphereHit(col, damage); }
	bool isSeachHit(CapsuleCol col) { return enemy->isSeachHit(col); }

private:
	//�G�̍\���̂�z��œǂݍ���
	std::shared_ptr<WeakEnemy> enemy = std::make_shared<WeakEnemy>();
};

