#include "EnemyRight.h"
#include "DxLib.h"
#include "Game.h"

namespace
{
	constexpr float kSpeed = 4.0f;
}

EnemyRight::EnemyRight()
	//m_handle(-1),
	//m_isExist(false)
	//m_pos�͈����Ȃ��̃R���X�g���N�^���Ă΂��
	//���������̃R���X�g���N�^���Ăԏꍇ���ȗ��ł���
{
}

EnemyRight::~EnemyRight()
{
}

//void EnemyRight::Init()
//{
//}

void EnemyRight::Update()
{
	//���݂��Ȃ��G�̏����͂��Ȃ�
	if (!m_isExist) return;

	//m_pos.x -= kSpeed;
	m_pos += m_vec;

	//�����蔻��̍X�V
	UpdateCollision();

	//�x�N�g�����������Ă݂�
	//��ʒ����𒴂������������
	if (m_pos.x < Game::kScreenWidth / 2)
	{
		//�ړ��x�N�g����ω������鎖�ő��x���グ��
		//���Ɉړ�����ʂ�傫�����邱�Ƃő��������Ă���悤�Ɍ�����
		m_vec.x -= 0.5f;
	}

	//��ʊO�ɏo���瑶�݂�����
	int width = 0;
	int height = 0;
	GetGraphSize(m_handle, &width, &height);

	if (m_pos.x < 0.0f - width)
	{
		m_isExist = false;
	}
}

//void EnemyRight::Draw() const
//{
//	//���݂��Ȃ��G�͕`�悵�Ȃ�
//	if (!m_isExist) return;
//
//	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, false);
//}

void EnemyRight::Start()
{
	m_isExist = true;

	int width = 0;
	int height = 0;
	GetGraphSize(m_handle, &width, &height);


	m_pos.x = static_cast<float>(Game::kScreenWidth + width / 2);
	m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - height) + height / 2);

	//1�t���[��������̈ړ��x�N�g�������肷��
	m_vec.x = -kSpeed;
	m_vec.y = 0.0f;
}
