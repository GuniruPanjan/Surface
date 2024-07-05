#pragma once
#include "Vec3.h"
#include "DxLib.h"

class Rect
{
public:
	Rect();
	virtual ~Rect();

	//中心座標と幅高さと奥行を指定
	void SetCenter(float x, float y, float z, float width, float height, float depth);

	//矩形同士の当たり判定
	bool IsCollision(const Rect& rect);

	// 描画
	void Draw(unsigned int color, bool isFill);

	//箱のベクター
	VECTOR pos, posS;

	//中心点
	VECTOR P1;

	//代入するための変数
	float X;
	float Y;
	float Z;
	float Xwidth;
	float Yheight;
	float Zdepth;
};

