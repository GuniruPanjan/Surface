#include "SphereCol.h"
#include "CapsuleCol.h"

SphereCol::SphereCol()
{
}

SphereCol::~SphereCol()
{
}

void SphereCol::Init(const Pos3& pos, float radius)
{
	m_pos = pos;
	m_radius = radius;
}

void SphereCol::Update(const Pos3& pos)
{
	m_pos = pos;
}

bool SphereCol::IsHitCapsule(const CapsuleCol& col)
{
	//�����Ă�������ɐL�тĂ���x�N�g�����쐬
	Vec3 dirVec = col.GetVec().GetNormalized() * col.GetLength() * 0.5f;

	//���΃x�N�g��
	Vec3 vec = col.GetPos() - m_pos;

	//���΃x�N�g���Ɛ��ʃx�N�g���̓���
	float dot = Dot(vec, dirVec);
	//�����x�N�g���̑傫�����擾(2��)
	float sqLen = dirVec.SqLength();

	//������̂ǂ��ɂ��邩���m���߂�
	float t = dot / sqLen;
	//�͈͂̐���
	if (t < -1.0f) t = -1.0f;  //����
	if (t > 1.0f) t = 1.0f;  //���

	//������ł̓_�܂ł̍ŒZ����
	Pos3 minPos = dirVec * t + m_pos;

	//�ŒZ�����Ɖ~�̍��W�̃x�N�g���傫��(2��)���擾
	sqLen = (minPos - col.GetPos()).SqLength();
	//���a�̍��v��2��
	float radius = m_radius + col.GetRadius();
	radius = radius * radius;

	return sqLen < radius;
}