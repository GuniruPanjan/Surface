#pragma once
#include "Vec3.h"


class CapsuleCol
{
public:
	CapsuleCol();
	virtual ~CapsuleCol();

	void Init(const Pos3& pos, const Vec3& vec, float len, float radius);
	void Update(const Pos3& pos, const Vec3 vec);

	bool IsHit(const CapsuleCol& col);

	const Pos3& GetPos() const { return m_pos; }
	const Vec3& GetVec() const { return m_vec; }
	float GetLength() const { return m_len; }
	float GetRadius() const { return m_raidus; }

private:
	Pos3 m_pos;
	Vec3 m_vec;
	float m_len;
	float m_raidus;
};

