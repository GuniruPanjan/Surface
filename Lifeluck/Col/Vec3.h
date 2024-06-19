#pragma once
#include "DxLib.h"

/// <summary>
/// �T�C�Y�\����
/// </summary>
struct Size
{
	//��
	float width = 0.0f;
	//����
	float height = 0.0f;
	//���s
	float depth = 0.0f;

	Size() :
		width(0.0f),
		height(0.0f),
		depth(0.0f)
	{
	}
	Size(float inwidth, float inheight, float indepth) :
		width(inwidth),
		height(inheight),
		depth(indepth)
	{

	}
	//�����Z
	Size operator+(const Size& size) const;
	//�|���Z
	Size operator*(float scale) const;
};

/// <summary>
/// �x�N�^�[�\����
/// </summary>
struct Vec3
{
	float x, y, z;

	Vec3();
	Vec3(float X, float Y, float Z);

	//�P�����Z�q
	Vec3 Reverse();
	//�����Z
	Vec3 operator+(const Vec3& vec) const;
	//Vec3 += Vec3
	void operator+=(const Vec3& vec);
	//�����Z
	Vec3 operator-(const Vec3& vec) const;
	//Vec3 -= Vec3
	void operator-=(const Vec3& vec);
	//�|���Z
	Vec3 operator*(float scale) const;
	//Vec3 *= scale
	void operator*=(float scale);
	//����Z
	Vec3 operator/(float scale) const;
	//Vec3 /= scale
	void operator/=(float scale);
	//Vec3 == Vec3�������ꍇ
	bool operator==(const Vec3& vec) const;
	//Vec3 != Vec3�������ꍇ
	bool operator!=(const Vec3& vec) const;

	//Dxlib�̊֐����g���ۂɁAVECTOR�^�ɕϊ�����֐�
	VECTOR GetVector() const { return VGet(x, y, z); }

	//�������擾
	float Length() const;

	//������2����擾
	float SqLength() const;

	//���g�̐��K��
	void Normalize();

	//���K���������ʂ��擾
	Vec3 GetNormalized() const;
};
/// <summary>
/// ���`���
/// </summary>
/// <param name="start">�X�^�[�g</param>
/// <param name="end">�I��</param>
/// <param name="t">����</param>
/// <returns>��Ԍ�</returns>
Vec3 Lerp(const Vec3& start, const Vec3& end, float t);

/// <summary>
/// ����
/// </summary>
/// <param name="vec1">�x�N�g��1</param>
/// <param name="vec2">�x�N�g��2</param>
/// <returns></returns>
float Dot(const Vec3& vec1, const Vec3& vec2);

/// <summary>
/// �O��
/// </summary>
/// <param name="vec1">�x�N�g��1</param>
/// <param name="vec2">�x�N�g��2</param>
/// <returns></returns>
Vec3 Cross(const Vec3& vec1, const Vec3& vec2);

using Pos3 = Vec3;