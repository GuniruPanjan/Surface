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
	void Update();
	void Draw();
	void End();

	VECTOR GetPos() { return enemy->GetPos(); }
	float GetPosX() { return enemy->GetPosX(); }
	float GetPosY() { return enemy->GetPosY(); }
	float GetPosZ() { return enemy->GetPosZ(); }


private:
	//�G�̍\���̂�z��œǂݍ���
	std::shared_ptr<WeakEnemy> enemy = std::make_shared<WeakEnemy>();
};

