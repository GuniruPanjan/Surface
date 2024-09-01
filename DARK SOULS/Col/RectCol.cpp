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

bool RectCol::IsHitCapsule(const CapsuleCol& col)
{

	//���΃x�N�g��
	Vec3 vec = col.GetPos() - m_pos;

	//�l�̐�Βl��
	vec.x = fabs(vec.x);
	vec.y = fabs(vec.y);
	vec.z = fabs(vec.z);

	float trw = col.GetRadius() + (m_size.width * 0.5f);
	float trh = col.GetRadius() + (m_size.height * 0.5f);
	float trd = col.GetRadius() + (m_size.depth * 0.5f);

	//�e�����̔���
	bool isHitX = vec.x < trw;
	bool isHitY = vec.y < trh;
	bool isHitZ = vec.z < trd;

	//����
	return isHitX && isHitY && isHitZ;
}

bool RectCol::IsHItRect(const RectCol& rect)
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
