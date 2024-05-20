#pragma once
#include "Vec3.h"
#include "DxLib.h"

class Rect
{
public:
	Rect();
	virtual ~Rect();

	//���S���W�ƕ������Ɖ��s���w��
	void SetCenter(float x, float y, float z, float width, float height, float depth);

	//��`���m�̓����蔻��
	bool IsCollision(const Rect& rect);

	// �`��
	void Draw(unsigned int color, bool isFill);

	//���̃x�N�^�[
	VECTOR pos, posS;

	//���S�_
	VECTOR P1;

	//������邽�߂̕ϐ�
	float X;
	float Y;
	float Z;
	float Xwidth;
	float Yheight;
	float Zdepth;
};

