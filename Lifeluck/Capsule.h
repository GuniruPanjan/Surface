#pragma once
#include "Vec3.h"
#include "DxLib.h"

class Capsule
{
public:
	Capsule();
	virtual ~Capsule();

	//描画
	void Draw(float r, unsigned int color, bool isFill);

	//カプセルを形成する二点中の座標
	VECTOR Pos1, Pos2;
};

