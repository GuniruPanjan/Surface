#include "Player.h"
#include "Rect.h"
#include "DxLib.h"

Rect* rect;

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
	m_move = 1.0f;
	//�v���C���[�̃O���t��ǂݍ���
	
}

void Player::Update()
{
	//�v���C���[�͗���������
	m_playerY += m_gravity;

	//�v���C���[�͗������ړ��ł���
	//��ʊO�ɍs���Ȃ��悤��
	if (m_playerX >= 0)
	{
		//��������������
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			m_playerX -= m_move;
		}
	}
	//��ʊO�ɍs���Ȃ��悤��
	if (m_playerX <= 640)
	{
		
		//�E������������
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			m_playerX += m_move;
		}
	}
	

}

void Player::Draw()
{
	//�v���C���[��`�悷��
	m_playergraph = DrawCircle(m_playerX, m_playerY, 10, GetColor(255, 255, 255), true);
	

}

void Player::End()
{
}
