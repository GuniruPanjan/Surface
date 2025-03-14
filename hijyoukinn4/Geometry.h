#pragma once

/// <summary>
/// ベクトルクラス
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
	/// ベクトルの大きさを返す
	/// </summary>
	/// <returns>ベクトルの大きさ</returns>
	float Length()const;
	/// <summary>
	/// ベクトルの大きさの2乗を返す
	/// </summary>
	/// <returns>ベクトルの大きさの2乗</returns>
	float SQLengtah()const;
	/// <summary>
	/// このベクトルを正規化する
	/// </summary>
	void Normalize();
	/// <summary>
	/// このベクトルを正規化したベクトルを返す
	/// </summary>
	/// <returns>正規化済みのベクトル</returns>
	Vector2 Normalized()const;



};
/// <summary>
/// 内積を返すA,B
/// </summary>
/// <param name="lval"></param>
/// <param name="rval"></param>
/// <returns></returns>
float
Dot(const Vector2& lval, const Vector2& rval);

//ベクトルの別名でPosition2(座標)
using Position2 = Vector2;




