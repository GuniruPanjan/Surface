#include "Capsule.h"

Capsule::Capsule()
{
	Pos1 = VGet(0.0f, 0.0f, 0.0f);
	Pos2 = VGet(0.0f, 0.0f, 0.0f);
}

Capsule::~Capsule()
{
}

void Capsule::Draw(float r, unsigned int color, bool isFill)
{
	//ƒJƒvƒZƒ‹•`‰æ
	DrawCapsule3D(Pos1, Pos2, r, 8, color, color, isFill);
}
