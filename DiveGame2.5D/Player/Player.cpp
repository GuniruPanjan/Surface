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
	//�L�[����
	int Keyinput = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�v���C���[�͗���������
	m_playerY += m_gravity;

	//�v���C���[�͗������ړ��ł���
	//��ʊO�ɍs���Ȃ��悤��
	if (m_playerX >= 0)
	{
		//��������������
		if (Keyinput & PAD_INPUT_LEFT)
		{
			m_playerX -= m_move;
		}
	}
	//��ʊO�ɍs���Ȃ��悤��
	if (m_playerX <= 640)
	{
		
		//�E������������
		if (Keyinput & PAD_INPUT_RIGHT)
		{
			m_playerX += m_move;
		}
	}
	//�L�[�������Ă���ԗ����X�s�[�h���グ��
	if (Keyinput & PAD_INPUT_DOWN)
	{
		m_gravity = m_swoop;
	}
	//�����ĂȂ��Ԃ͏d�͂�߂�
	else
	{
		m_gravity = 0.8f;
	}
	
	m_colRect.SetCenter(m_playerX, m_playerY, 18, 18);
}

void Player::Draw()
{
	//�v���C���[��`�悷��
	m_playergraph = DrawCircle(m_playerX, m_playerY, 10, GetColor(255, 255, 255), true);
	
	m_colRect.Draw(GetColor(255, 0, 0), false);
}

void Player::End()
{
}
