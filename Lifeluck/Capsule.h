#pragma once
#include "Vec3.h"
#include "DxLib.h"

class Capsule
{
public:
	Capsule();
	virtual ~Capsule();

	//�`��
	void Draw(float r, unsigned int color, bool isFill);

	//�J�v�Z�����`�������_���̍��W
	VECTOR Pos1, Pos2;
};

