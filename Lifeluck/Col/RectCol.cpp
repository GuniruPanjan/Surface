#include "RectCol.h"
#include<cmath>
#include "CapsuleCol.h"
#include "Matrix3.h"


RectCol::RectCol()
{
}

RectCol::~RectCol()
{
}

void RectCol::Init(const Pos3& pos, const Size& size)
{
	m_pos = pos;
	m_size = size;
}

void RectCol::Update(const Pos3& pos)
{
	m_pos = pos;
}

bool RectCol::IsHit(const CapsuleCol& col)
{
	//自身の辺のベクトルを作成
	Vec3 sDirVec = m_pos.GetNormalized() * m_size.width * 0.5f;

	//対象の向いている方向に伸びているベクトルを作成
	Vec3 tDirVec = col.GetVec().GetNormalized() * col.GetLength() * 0.5f;

	//相対ベクトル
	Vec3 vec = col.GetPos() - m_pos;

	//値の絶対値化
	vec.x = fabs(vec.x);
	vec.y = fabs(vec.y);
	vec.z = fabs(vec.z);

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
	//平行でない場合
	else
	{
		s = Dot(sDirVec, vec) / sDirVec.SqLength();
		t = Dot(tDirVec, vec) / tDirVec.SqLength();
	}

	// 範囲の制限
	if (s < -1.0f) s = -1.0f; // 下限
	if (s > 1.0f)  s = 1.0f; // 上限
	if (t < -1.0f) t = -1.0f; // 下限
	if (t > 1.0f)  t = 1.0f; // 上限

	float trw = (col.GetRadius() + m_size.width) * 0.5f;
	float trh = (col.GetRadius() + m_size.height) * 0.5f;
	float trd = (col.GetRadius() + m_size.depth) * 0.5f;


	// 線分上での最短座標
	Pos3 minPos1 = sDirVec * s + m_pos;
	Pos3 minPos2 = tDirVec * t + col.GetPos();
	// 大きさ(2乗)
	float sqLen = (minPos1 - minPos2).SqLength();
	// それぞれの半径の合計の2乗
	float ar = (m_size.width * 0.5f) + col.GetRadius();
	ar = ar * ar;
	
	//各成分の判定
	bool isHitX = vec.x < trw;
	bool isHitY = vec.y < trh;
	bool isHitZ = vec.z < trd;

	//判定
	return isHitX && isHitY && isHitZ;

	/*sqLenが悪さしてる*/
	//return sqLen < ar;

	return false;
}

bool RectCol::IsHit(const RectCol& rect)
{
	//相対ベクトルの作成
	auto vec = rect.GetPos() - m_pos;
	//値の絶対値化
	vec.x = fabs(vec.x);
	vec.y = fabs(vec.y);
	vec.z = fabs(vec.z);

	//それぞれのサイズの半分のものを作成
	Size size = (rect.GetSize() + m_size) * 0.5f;

	//各成分の判定
	bool isHitX = vec.x < size.width;
	bool isHitY = vec.y < size.height;
	bool isHitZ = vec.z < size.depth;

	//判定
	return isHitX && isHitY && isHitZ;
}
