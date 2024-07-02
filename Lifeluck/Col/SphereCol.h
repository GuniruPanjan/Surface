#pragma once
#include "Col/CapsuleCol.h"
#include "Vec3.h"

class SphereCol
{
public:
	SphereCol();
	virtual ~SphereCol();

	void Init(const Pos3& pos, float radius);
	void Update(const Pos3& pos);

	bool IsHit(const SphereCol& col);
	bool IsHitCapsule(const CapsuleCol& col);

	const Pos3& GetPos() const { return m_pos; }
	float GetRadius() const { return m_radius; }

private:
	Pos3 m_pos;
	float m_radius;
};

