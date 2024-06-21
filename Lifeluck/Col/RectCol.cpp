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
	//���g�̕ӂ̃x�N�g�����쐬
	Vec3 sDirVec = m_pos.GetNormalized() * m_size.width * 0.5f;

	//�Ώۂ̌����Ă�������ɐL�тĂ���x�N�g�����쐬
	Vec3 tDirVec = col.GetVec().GetNormalized() * col.GetLength() * 0.5f;

	//���΃x�N�g��
	Vec3 vec = col.GetPos() - m_pos;

	//�l�̐�Βl��
	vec.x = fabs(vec.x);
	vec.y = fabs(vec.y);
	vec.z = fabs(vec.z);

	//�@���x�N�g��
	Vec3 norm = Cross(sDirVec, tDirVec);

	//���s����
	bool isParallel = norm.SqLength() < 0.001f;

	float s, t;
	//���s�łȂ��ꍇ
	if (!isParallel)
	{
		//�P�ʍs��
		Matrix3 mat;
		mat.Init();

		//�l�̑��
		mat.SetLine(0, sDirVec);
		mat.SetLine(1, tDirVec.Reverse());
		mat.SetLine(2, norm);

		//�t�s��
		mat = mat.GetInverse();

		s = Dot(mat.GetRow(0), vec);
		t = Dot(mat.GetRow(1), vec);
	}
	//���s�łȂ��ꍇ
	else
	{
		s = Dot(sDirVec, vec) / sDirVec.SqLength();
		t = Dot(tDirVec, vec) / tDirVec.SqLength();
	}

	// �͈͂̐���
	if (s < -1.0f) s = -1.0f; // ����
	if (s > 1.0f)  s = 1.0f; // ���
	if (t < -1.0f) t = -1.0f; // ����
	if (t > 1.0f)  t = 1.0f; // ���

	float trw = (col.GetRadius() + m_size.width) * 0.5f;
	float trh = (col.GetRadius() + m_size.height) * 0.5f;
	float trd = (col.GetRadius() + m_size.depth) * 0.5f;


	// ������ł̍ŒZ���W
	Pos3 minPos1 = sDirVec * s + m_pos;
	Pos3 minPos2 = tDirVec * t + col.GetPos();
	// �傫��(2��)
	float sqLen = (minPos1 - minPos2).SqLength();
	// ���ꂼ��̔��a�̍��v��2��
	float ar = (m_size.width * 0.5f) + col.GetRadius();
	ar = ar * ar;
	
	//�e�����̔���
	bool isHitX = vec.x < trw;
	bool isHitY = vec.y < trh;
	bool isHitZ = vec.z < trd;

	//����
	return isHitX && isHitY && isHitZ;

	/*sqLen���������Ă�*/
	//return sqLen < ar;

	return false;
}

bool RectCol::IsHit(const RectCol& rect)
{
	//���΃x�N�g���̍쐬
	auto vec = rect.GetPos() - m_pos;
	//�l�̐�Βl��
	vec.x = fabs(vec.x);
	vec.y = fabs(vec.y);
	vec.z = fabs(vec.z);

	//���ꂼ��̃T�C�Y�̔����̂��̂��쐬
	Size size = (rect.GetSize() + m_size) * 0.5f;

	//�e�����̔���
	bool isHitX = vec.x < size.width;
	bool isHitY = vec.y < size.height;
	bool isHitZ = vec.z < size.depth;

	//����
	return isHitX && isHitY && isHitZ;
}
