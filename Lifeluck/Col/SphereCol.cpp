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

bool SphereCol::IsHit(const SphereCol& col)
{
	//相対ベクトル
	Vec3 vec = col.GetPos() - m_pos;
	//相対ベクトルの距離(2乗)
	float vecSqLen = vec.SqLength();

	//半径の合計の2乗
	float radius = m_radius + col.GetRadius();
	radius = radius * radius;

	//判定
	return vecSqLen < radius;
}
