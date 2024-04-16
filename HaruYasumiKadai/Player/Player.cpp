#include "Player.h"
#include "DxLib.h"

Player::Player() :
	m_diagonalX(false),
	m_diagonalY(false),
	PlayerDead(false),
	PlayerJump(false),
	PlayerJumpPower(0.0f),
	PlayerGravity(0.0f)
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

	
}

void Player::InitBack()
{
	//Player�̍��W��ݒ肷��
	PlayerX = 200.0f;
	PlayerY = 350.0f;
	//Player�̃X�s�[�h��ݒ肷��
	PlayerSpeed = 2.0f;

	//Player��Scroll��ݒ肷��
	PlayerScroll = 0.0f;

	PlayerGraph = LoadGraph("date/Player.png");


	PlayerJump = false;
	PlayerJumpPower = 0.0f;
	PlayerGravity = 3.0f;
}

void Player::Update()
{

	//���L�[
	if (CheckHitKey(KEY_INPUT_LEFT) && PlayerX >= 0 - PlayerScroll)
	{
		PlayerX -= PlayerSpeed;

		m_diagonalX = true;
	}
	//�E�L�[
	if (CheckHitKey(KEY_INPUT_RIGHT) && PlayerX <= 640 - PlayerScroll)
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
	if (CheckHitKey(KEY_INPUT_UP) && PlayerY >= 0)
	{
		PlayerY -= PlayerSpeed;

		m_diagonalY = true;
	}
	//���L�[
	if (CheckHitKey(KEY_INPUT_DOWN) && PlayerY <= 480)
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
	PlayerScroll -= 1;


	//�����蔻��X�V
	m_colrect.SetCenter(static_cast<float>(PlayerX + PlayerScroll), static_cast<float>(PlayerY), static_cast<float>(PlayerWidth), static_cast<float>(PlayerHeight));

}

void Player::UpdateBack()
{

	//���L�[
	if (CheckHitKey(KEY_INPUT_LEFT) && PlayerX >= 0 - PlayerScroll)
	{
		PlayerX -= PlayerSpeed;

		m_diagonalX = true;
	}
	//�E�L�[
	if (CheckHitKey(KEY_INPUT_RIGHT) && PlayerX <= 640 - PlayerScroll)
	{
		PlayerX += PlayerSpeed;

		m_diagonalX = true;
	}

	if (PlayerJumpPower < 0)
	{
		PlayerJumpPower++;

		if (PlayerJumpPower <= 0)
		{
			PlayerJump = true;
		}
	}

	if (PlayerJump == false)
	{
		//�X�y�[�X�L�[
		if (CheckHitKey(KEY_INPUT_SPACE) && PlayerJumpPower == 0.0f)
		{
			PlayerJumpPower = -15;
		}
	}

	PlayerY += PlayerJumpPower;

	if (PlayerJump == true)
	{
		//�d�͂�^����
		PlayerY += PlayerGravity;
	}
	
	//���Ԃ����ƃX�N���[�����J�n����
	PlayerScroll -= 1;

	//�����蔻��X�V
	m_colrect.SetCenter(static_cast<float>(PlayerX + PlayerScroll), static_cast<float>(PlayerY), static_cast<float>(PlayerWidth), static_cast<float>(PlayerHeight));

}

void Player::Draw()
{

	DrawGraph(PlayerX + PlayerScroll - 20, PlayerY - 20, PlayerGraph, true);

	//�����蔻��`��
	//m_colrect.Draw(GetColor(255, 0, 0), false);
}

void Player::DrawBack()
{
	DrawGraph(PlayerX + PlayerScroll - 20, PlayerY - 20, PlayerGraph, true);
}

void Player::End()
{
}

void Player::EndBack()
{
}

