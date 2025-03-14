#include "CapsuleCol.h"
#include <cmath>
#include <algorithm>
#include "Matrix3.h"


CapsuleCol::CapsuleCol()
{
}

CapsuleCol::~CapsuleCol()
{
}

void CapsuleCol::Init(const Pos3& pos, const Vec3& vec, float len, float radius)
{
	m_pos = pos;
	m_vec = vec;
	m_len = len;
	m_radius = radius;
}

void CapsuleCol::Update(const Pos3& pos, const Vec3 vec)
{
	m_pos = pos;
	m_vec = vec;
}

bool CapsuleCol::IsHitCapsule(const CapsuleCol& col)
{
	//自身の向いている方向に伸びているベクトルを作成
	Vec3 sDirVec = m_vec.GetNormalized() * m_len * 0.5f;
	//対象の向いている方向に伸びているベクトルを作成
	Vec3 tDirVec = col.GetVec().GetNormalized() * col.GetLength() * 0.5f;

	//相対ベクトル
	Vec3 vec = col.GetPos() - m_pos;

	//法線ベクトル
	Vec3 norm = Cross(sDirVec, tDirVec);

	//平行判定
	bool isParallel = norm.SqLength() < 0.001f;

	float s, t;
	//平行でない場合
	if (!isParallel)
	{
		//単位行列
		Matrix3 mat;
		mat.Init();

		//値の代入
		mat.SetLine(0, sDirVec);
		mat.SetLine(1, tDirVec.Reverse());
		mat.SetLine(2, norm);

		//逆行列
		mat = mat.GetInverse();

		s = Dot(mat.GetRow(0), vec);
		t = Dot(mat.GetRow(1), vec);
	}
	//平行の場合
	else
	{
		s = Dot(sDirVec, vec) / sDirVec.SqLength();
		t = Dot(tDirVec, vec) / tDirVec.SqLength();

	}

	//範囲の制限
	if (s < -1.0f) s = -1.0f; //下限
	if (s > 1.0f)  s =  1.0f; //上限
	if (t < -1.0f) t = -1.0f; //下限
	if (t > 1.0f)  t =  1.0f; //上限

	//線分上での最短距離
	Pos3 minPos1 = sDirVec * s + m_pos;
	Pos3 minPos2 = tDirVec * t + col.GetPos();
	//大きさ(2乗)
	float sqLen = (minPos1 - minPos2).SqLength();
	//それぞれの半径の合計の2乗
	float ar = m_radius + col.GetRadius();

	ar = ar * ar;

	return sqLen < ar;
}

//bool CapsuleCol::IsHitSphere(const SphereCol& col)
//{
//	//自身の向いている方向に伸びているベクトルを作成
//	Vec3 dirVec = m_vec.GetNormalized() * m_len * 0.5f;
//	//相対ベクトル
//	Vec3 vec = col.GetPos() - m_pos;
//
//	//相対ベクトルと正面ベクトルの内積
//	float dot = Dot(vec, dirVec);
//	//方向ベクトルの大きさを取得(2乗)
//	float sqLen = dirVec.SqLength();
//
//	//線分上のどこにあるかを確かめる
//	float t = dot / sqLen;
//	//範囲の制限
//	if (t < -1.0f) t = -1.0f; //下限
//	if (t > 1.0f) t = 1.0f; //上限
//
//	//線分上での点までの最短距離
//	Pos3 minPos = dirVec * t + m_pos;
//
//	//最短座標と円の座標のベクトル大きさ(2乗)を取得
//	sqLen = (minPos - col.GetPos()).SqLength();
//	//半径の合計の2乗
//	float radius = m_radius + col.GetRadius();
//	radius = radius * radius;
//
//	return sqLen < radius;
//}
