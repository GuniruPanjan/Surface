#pragma once
#include "Vec3.h"

class CapsuleCol;

class RectCol
{
public:
	RectCol();
	virtual ~RectCol();

	void Init(const Pos3& pos, const Size& size);
	void Update(const Pos3& pos);

	bool IsHit(const CapsuleCol& col);
	bool IsHit(const RectCol& rect);

	const Pos3& GetPos() const { return m_pos; }
	const Size& GetSize() const { return m_size; }

private:
	Pos3 m_pos;
	Size m_size;
};

