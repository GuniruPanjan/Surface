#include "Player.h"
#include "DxLib.h"

Player::Player():
	m_diagonalX(false),
	m_diagonalY(false),
	PlayerDead(false)
{
}

Player::~Player()
{
}

void Player::Init()
{
	//Player�̍��W��ݒ肷��
	PlayerX = 200.0f;
	PlayerY = 255.0f;
	//Player�̃X�s�[�h��ݒ肷��
	PlayerSpeed = 2.0f;

	//Player��Scroll��ݒ肷��
	PlayerScroll = 0.0f;

	PlayerGraph = LoadGraph("date/Player.png");

	//���ݎ��Ԃ𓾂�
	Time = GetNowCount();
}

void Player::Update()
{
	//�o�ߎ��Ԃ𓾂�
	PlayerTime = (GetNowCount() - Time) / 1000;

	//���L�[
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PlayerX -= PlayerSpeed;

		m_diagonalX = true;
	}
	//�E�L�[
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		PlayerX += PlayerSpeed;

		m_diagonalX = true;
	}
	//�E�L�[�ƍ��L�[�������ĂȂ��Ƃ�
	if (CheckHitKey(KEY_INPUT_LEFT) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0)
	{
		m_diagonalX = false;
	}
	//��L�[
	if (CheckHitKey(KEY_INPUT_UP))
	{
		PlayerY -= PlayerSpeed;

		m_diagonalY = true;
	}
	//���L�[
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		PlayerY += PlayerSpeed;

		m_diagonalY = true;
	}
	//��L�[�Ɖ��L�[�������ĂȂ��Ƃ�
	if (CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0)
	{
		m_diagonalY = false;
	}

	//�΂߈ړ��̂Ƃ��X�s�[�h�𗎂Ƃ�
	if (m_diagonalX == true && m_diagonalY == true)
	{
		PlayerSpeed = 1.0f;
	}
	else if (m_diagonalX == false || m_diagonalY == false)
	{
		PlayerSpeed = 2.0f;
	}

	//���Ԃ����ƃX�N���[�����J�n����
	if (PlayerTime >= 10)
	{
		PlayerScroll -= 1;
	}
	

	//�����蔻��X�V
	m_colrect.SetCenter(static_cast<float>(PlayerX + PlayerScroll), static_cast<float>(PlayerY), static_cast<float>(PlayerWidth), static_cast<float>(PlayerHeight));

}

void Player::Draw()
{
	//Player�̉��摜
	//DrawCircle(static_cast<int>(PlayerX + PlayerScroll), static_cast<int>(PlayerY), 20, 0xffffff, true);

	DrawGraph(PlayerX + PlayerScroll - 20, PlayerY - 20, PlayerGraph, false);
    
	//�����蔻��`��
	m_colrect.Draw(GetColor(255, 0, 0), false);
}

void Player::End()
{
}
