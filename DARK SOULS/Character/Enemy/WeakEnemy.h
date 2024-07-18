#pragma once
#include "EnemyBase.h"

class WeakEnemy : public EnemyBase
{
public:
	WeakEnemy();
	virtual ~WeakEnemy();

	void Init();
	void Update();
	void Animation(float& time);
	void Draw();
	void End();

	VECTOR GetPos() { return m_pos; }

private:

};

