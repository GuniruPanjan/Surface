#include "SphereCol.h"

SphereCol::SphereCol()
{
}

SphereCol::~SphereCol()
{
}

void SphereCol::Init(const Pos3& pos, float radius)
{
	m_pos = pos;
	m_radius = radius;
}

void SphereCol::Update(const Pos3& pos)
{
	m_pos = pos;
}
