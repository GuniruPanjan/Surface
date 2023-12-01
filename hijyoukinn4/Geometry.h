#pragma once

/// <summary>
/// �x�N�g���N���X
/// </summary>
struct Vector2
{
	float x;
	float y;

	Vector2 operator+(const Vector2& val) const;
	Vector2 operator-(const Vector2& val) const;
	Vector2 operator*(float scale) const;
	Vector2 operator/(float div) const;
	void operator+=(const Vector2& val);
	void operator-=(const Vector2& val);
	void operator*(float scale);
	void operator/(float div);

	/// <summary>
	/// �x�N�g���̑傫����Ԃ�
	/// </summary>
	/// <returns>�x�N�g���̑傫��</returns>
	float Length()const;
	/// <summary>
	/// �x�N�g���̑傫����2���Ԃ�
	/// </summary>
	/// <returns>�x�N�g���̑傫����2��</returns>
	float SQLengtah()const;
	/// <summary>
	/// ���̃x�N�g���𐳋K������
	/// </summary>
	void Normalize();
	/// <summary>
	/// ���̃x�N�g���𐳋K�������x�N�g����Ԃ�
	/// </summary>
	/// <returns>���K���ς݂̃x�N�g��</returns>
	Vector2 Normalized()const;



};
/// <summary>
/// ���ς�Ԃ�A,B
/// </summary>
/// <param name="lval"></param>
/// <param name="rval"></param>
/// <returns></returns>
float
Dot(const Vector2& lval, const Vector2& rval);

//�x�N�g���̕ʖ���Position2(���W)
using Position2 = Vector2;




