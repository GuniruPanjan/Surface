#include "Rect.h"
#include<cassert>

Rect::Rect():
	X(0.0f),
	Y(0.0f),
	Z(0.0f),
	Xwidth(0.0f),
	Yheight(0.0f),
	Zdepth(0.0f)
{

	pos = VGet(0.0f, 0.0f, 0.0f);
	posS = VGet(0.0f, 0.0f, 0.0f);

	P1 = VGet(0.0f, 0.0f, 0.0f);
}

Rect::~Rect()
{
}

void Rect::SetCenter(float x, float y, float z, float width, float height, float depth)
{

	//代入する
	X = x;
	Y = y;
	Z = z;
	Xwidth = width;
	Yheight = height;
	Zdepth = depth;

	pos = VGet(x, y, z);
	posS = VGet(x + width, y + height, z + depth);

	//中心点を求める
	P1 = VGet(posS.x / 2.0f, posS.y / 2.0f, posS.z / 2.0f);
}

bool Rect::IsCollision(const Rect& rect)
{
	//絶対当たらないパターン以外は当たっている
	if (pos.x > rect.posS.x) return false;
	if (pos.y > rect.posS.y) return false;
	if (posS.x < rect.pos.x) return false;
	if (posS.y < rect.pos.y) return false;
	if (pos.z < rect.posS.z) return false;
	if (posS.z > rect.pos.z) return false;


	//当たらないパターン以外は当たっている
	return true;
}


void Rect::Draw(unsigned int color, bool isFill)
{
	//当たり判定描画
	DrawCube3D(posS, pos, color, color, isFill);
}
