#include "Player.h"
#include "DxLib.h"

Player::Player():
	m_playerX(0.0f),
	m_playerY(0.0f)
{
}

Player::~Player()
{
}

void Player::Init()
{
	//�v���C���[�̍��W������
	m_playerX = 320.0f;
	m_playerY = 50.0f;

	//�v���C���[�ɏd�͂�^����
	m_gravity = 0.5f;
	//�v���C���[���ړ��ł���X�s�[�h
	m_move = 0.5f;
	//�v���C���[�̃O���t��ǂݍ���
	m_playergraph = DrawCircle(320, 50, 5, GetColor(255, 255, 255), true);
}

void Player::Update()
{
	//�v���C���[�͗���������
	m_playerY += m_gravity;

	//�v���C���[�͗������ړ��ł���
	//��������������
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_playerX -= m_move;
	}
	//�E������������
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_playerX += m_move;
	}

}

void Player::Draw()
{
	//�v���C���[��`�悷��
	DrawGraph(static_cast<int>(m_playerX), static_cast<int>(m_playerY), m_playergraph, false);

}

void Player::End()
{
}
