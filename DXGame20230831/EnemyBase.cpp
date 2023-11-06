#include "EnemyBase.h"
#include "DxLib.h"
#include "Game.h"
#include <cassert>

namespace
{
	constexpr float kSpeed = 4.0f;
}

EnemyBase::EnemyBase():
	m_handle(-1),
	m_isExist(false)
	//m_pos�͈����Ȃ��̃R���X�g���N�^���Ă΂��
	//���������̃R���X�g���N�^���Ăԏꍇ���ȗ��ł���
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Init()
{
}

void EnemyBase::Update()
{
	//���݂��Ȃ��G�̏����͂��Ȃ�
	if (!m_isExist) return;

	////m_pos.x -= kSpeed;
	//m_pos += m_vec;

	////�x�N�g�����������Ă݂�
	////��ʒ����𒴂������������
	//if (m_pos.x < Game::kScreenWidth / 2)
	//{
	//	//�ړ��x�N�g����ω������鎖�ő��x���グ��
	//	//���Ɉړ�����ʂ�傫�����邱�Ƃő��������Ă���悤�Ɍ�����
	//	m_vec.x -= 0.5f;
	//}

	////��ʊO�ɏo���瑶�݂�����
	//int width = 0;
	//int height = 0;
	//GetGraphSize(m_handle, &width, &height);

	//if (m_pos.x < 0.0f - width)
	//{
	//	m_isExist = false;
	//}
}

void EnemyBase::Draw() const
{
	float Fnum = 1.2f;    //32Bit
	double Dnum = 1.2;    //64Bit

	//���݂��Ȃ��G�͕`�悵�Ȃ�
	if (!m_isExist) return;
	//�O���t�B�b�N���ݒ肳��Ă��Ȃ���Ύ~�܂�
	assert(m_handle != -1);
	//DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, false);
	DrawRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		1.0, 0.0, m_handle, true, false);
#ifdef _DEBUG
	//�����蔻��̕\��
	//m_colRect.Draw(GetColor(255, 0, 0), false);
#endif
}

void EnemyBase::UpdateCollision()
{
	int width = 0;
	int height = 0;
	GetGraphSize(m_handle, &width, &height);
	//m_colRect.SetLT(m_pos.x - width / 2, m_pos.y - height /2, width, height);
	//m_colRect.Set(m_pos.x, m_pos.y, width, height);
	//���S���W���w�肵�Ă����蔻���Rect�𐶐�����
	m_colRect.SetCenter(m_pos.x, m_pos.y, width, height);
}

//void EnemyBase::Start()
//{
//	m_isExist = false;
//
//	//int width = 0;
//	//int height = 0;
//	//GetGraphSize(m_handle, &width, &height);
//
//
//	//m_pos.x = static_cast<float>(Game::kScreenWidth);
//	//m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - height));
//
//	////1�t���[��������̈ړ��x�N�g�������肷��
//	//m_vec.x = -kSpeed;
//}
