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

	//����̍��W
	VECTOR pos1;
	//�����̍��W
	VECTOR pos2;
	//�E��̍��W
	VECTOR pos3;
	//�E���̍��W
	VECTOR pos4;
	//���̍���
	VECTOR pos5;
	//���̍���
	VECTOR pos6;
	//���̉E��
	VECTOR pos7;
	//���̉E��
	VECTOR pos8;

private:

	float m_left;  //�����X���W

	float m_top;  //�����Y���W

	float m_right;   //�E����X���W

	float m_bottom;   //�E����Y���W

	float m_tableZ;   //�\��Z���W

	float m_backZ;    //����Z���W

	//������邽�߂̕ϐ�
	float X;
	float Y;
	float Z;
	float Xwidth;
	float Yheight;
	float Zdepth;
};
