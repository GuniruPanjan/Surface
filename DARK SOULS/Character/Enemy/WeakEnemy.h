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

	bool isHit(const CapsuleCol& col);
	bool isSphereHit(const SphereCol& col);

	VECTOR GetPos() { return m_pos; }
	float GetPosX() { return m_pos.x; }
	float GetPosY() { return m_pos.y; }
	float GetPosZ() { return m_pos.z; }
	CapsuleCol GetCol() const { return m_capsuleCol; }


private:
	unsigned int m_color = 0xffffff;
};

