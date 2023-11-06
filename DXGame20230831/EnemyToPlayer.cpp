#include "EnemyToPlayer.h"
#include "DxLib.h"
#include "Game.h"
#include "Player.h"
#include<cassert>

namespace
{
	constexpr float kSpeed = 3.0f;
}

EnemyToPlayer::EnemyToPlayer():
	/*m_handle(-1),
	m_isExist(false),*/
	m_pPlayer(nullptr)
	//m_pos�͈����Ȃ��̃R���X�g���N�^���Ă΂��
	//���������̃R���X�g���N�^���Ăԏꍇ���ȗ��ł���
{
	//m_pPlayer�ɂ�SceneMain�ł��łɃ��������m�ۂ���Player��
	//�ǂ��ɒu����Ă���̂��A�̏������Ă��������̂ł����ł̓������m�ۂ��Ȃ�
}

EnemyToPlayer::~EnemyToPlayer()
{
	//m_pPlayer�̊m�ۉ����SceneMain���Ǘ�����̂�
	//���l�ɉ�����s��Ȃ�
}

//void EnemyToPlayer::Init()
//{
//}

void EnemyToPlayer::Update()
{
	//���݂��Ȃ��G�̏����͂��Ȃ�
	if (!m_isExist) return;

	//m_pos.x -= kSpeed;
	m_pos += m_vec;

	//�����蔻��̍X�V
	UpdateCollision();

	//�x�N�g�����������Ă݂�
	//��ʒ����𒴂������������
	//if (m_pos.x < Game::kScreenWidth / 2)
	//{
		//�ړ��x�N�g����ω������鎖�ő��x���グ��
		//���Ɉړ�����ʂ�傫�����邱�Ƃő��������Ă���悤�Ɍ�����
		//m_vec.x -= 0.5f;
	//}

	//��ʊO�ɏo���瑶�݂�����
	int width = 0;
	int height = 0;
	GetGraphSize(m_handle, &width, &height);

	//�E����o�Ă��č��ɏ�����G�O��ł̎�����S���Ă���
	/*if (m_pos.x < 0.0f - width)
	{
		m_isExist = false;
	}*/

	//���Ɉړ����Ă���G��"��ʍ����犮�S�ɏo�������G������
	if ((m_vec.x < 0.0f) &&   //���Ɉړ����Ă���G
		(m_pos.x < 0.0f - width / 2))   //�������ʊO�ɏo��
	{
		m_isExist = false;
	}
	//�E�Ɉړ����Ă���G��"��ʉE���犮�S�ɏo�������G������
	if ((m_vec.x > 0.0f) &&   //�E�Ɉړ����Ă���G
	   (m_pos.x > Game::kScreenWidth + width / 2))   //�E�����ʊO�ɏo��
	{
		m_isExist = false;
	}
	//��Ɉړ����Ă���G��"��ʏォ�犮�S�ɏo�������G������
	if ((m_vec.y < 0.0f) &&   //��Ɉړ����Ă���G
	   (m_pos.y < 0.0f - height / 2))   //�ォ���ʊO�ɏo��
	{
		m_isExist = false;
	}
	//���Ɉړ����Ă���G��"��ʉ����犮�S�ɏo�������G������
	if ((m_vec.y > 0.0f) &&   //���Ɉړ����Ă���G
		(m_pos.y > Game::kScreenHeight + height / 2))   //�������ʊO�ɏo��
	{
		m_isExist = false;
	}

}

//void EnemyToPlayer::Draw() const
//{
//	//���݂��Ȃ��G�͕`�悵�Ȃ�
//	if (!m_isExist) return;
//
//	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle, false);
//}

void EnemyToPlayer::Start()
{
	m_isExist = true;

	int width = 0;
	int height = 0;
	GetGraphSize(m_handle, &width, &height);

	//��ʂ̏㉺���E�����ꂩ����o�ꂷ��
	//�ǂ�����o�Ă��邩�͕�����Ȃ��i�����_���j

	//rand()�֐����g�p���ă����_���Ȑ����𐶐�����
	//rand()�֐��@�����_���Ȑ����𐶐�����@�͈͂�0~RAND_MAX
	//rand()�̖߂�l���g���ƂƂĂ��������ł����\��������
	//int num = rand() % 4;
	//�����Ƃ��������̃����_�����g�����ߍ����DxLib��GetRand()�֐����g�p����
	int num = GetRand(3);

	switch (num)
	{
	case 0://�ォ��
		m_pos.x = static_cast<float>(GetRand(Game::kScreenWidth - width) + width /2);  //���ʒu�̓����_��
		m_pos.y = static_cast<float>( - height / 2);   //��ʏォ������Ă���
		break;
	case 1://������
		m_pos.x = static_cast<float>( - width / 2);
		m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - height) + height / 2);
		break;
	case 2://������
		m_pos.x = static_cast<float>(GetRand(Game::kScreenWidth - width) + width / 2);
		m_pos.y = static_cast<float>(Game::kScreenHeight + height /2);
		break;
	case 3://�E����
		m_pos.x = static_cast<float>(Game::kScreenWidth + width / 2);
		m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - height) + height / 2);
		break;

	default:
		assert(false);
		break;
	}


	/*m_pos.x = static_cast<float>(Game::kScreenWidth);
	m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - height));*/

	//1�t���[��������̈ړ��x�N�g�������肷��
	//m_vec.x = -kSpeed;
	//m_vec.y = 0.0f;

	//��ʒ������o�R���ĉ�ʊO�܂ň�葬�x�ňړ�����

	//�R���X�g���N�^��nullptr���ݒ肳��āA����ȍ~�ύX����Ă��Ȃ���Ύ~�܂�
	assert(m_pPlayer);

	//�^�[�Q�b�g�ʒu�@�@�@�I�_�̍��W - �n�_�̍��W
	//const Vec2 target = Vec2{ Game::kScreenWidth / 2, Game::kScreenHeight / 2 };
	const Vec2 target = m_pPlayer->GetPos();

	//�G�̏����ʒu����^�[�Q�b�g�ʒu�Ɍ������x�N�g���𐶐�����
	Vec2 toTarget = target - m_pos;

	//�x�N�g���̒�����kSpeed�ɂ��Ă��

	//�x�N�g���̐��K�� ������1�ɂ���
	toTarget.normalize();
	//kSpeed�ł�����
	m_vec = toTarget * kSpeed;
}
