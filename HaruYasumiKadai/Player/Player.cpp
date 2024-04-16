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
	//Playerの座標を設定する
	PlayerX = 200.0f;
	PlayerY = 255.0f;
	//Playerのスピードを設定する
	PlayerSpeed = 2.0f;

	//PlayerのScrollを設定する
	PlayerScroll = 0.0f;

	PlayerGraph = LoadGraph("date/Player.png");

	
}

void Player::InitBack()
{
	//Playerの座標を設定する
	PlayerX = 200.0f;
	PlayerY = 350.0f;
	//Playerのスピードを設定する
	PlayerSpeed = 2.0f;

	//PlayerのScrollを設定する
	PlayerScroll = 0.0f;

	PlayerGraph = LoadGraph("date/Player.png");


	PlayerJump = false;
	PlayerJumpPower = 0.0f;
	PlayerGravity = 3.0f;
}

void Player::Update()
{

	//左キー
	if (CheckHitKey(KEY_INPUT_LEFT) && PlayerX >= 0 - PlayerScroll)
	{
		PlayerX -= PlayerSpeed;

		m_diagonalX = true;
	}
	//右キー
	if (CheckHitKey(KEY_INPUT_RIGHT) && PlayerX <= 640 - PlayerScroll)
	{
		PlayerX += PlayerSpeed;

		m_diagonalX = true;
	}
	//右キーと左キーを押してないとき
	if (CheckHitKey(KEY_INPUT_LEFT) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0)
	{
		m_diagonalX = false;
	}
	//上キー
	if (CheckHitKey(KEY_INPUT_UP) && PlayerY >= 0)
	{
		PlayerY -= PlayerSpeed;

		m_diagonalY = true;
	}
	//下キー
	if (CheckHitKey(KEY_INPUT_DOWN) && PlayerY <= 480)
	{
		PlayerY += PlayerSpeed;

		m_diagonalY = true;
	}
	//上キーと下キーを押してないとき
	if (CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0)
	{
		m_diagonalY = false;
	}

	//斜め移動のときスピードを落とす
	if (m_diagonalX == true && m_diagonalY == true)
	{
		PlayerSpeed = 1.0f;
	}
	else if (m_diagonalX == false || m_diagonalY == false)
	{
		PlayerSpeed = 2.0f;
	}

	//時間が立つとスクロールを開始する
	PlayerScroll -= 1;


	//当たり判定更新
	m_colrect.SetCenter(static_cast<float>(PlayerX + PlayerScroll), static_cast<float>(PlayerY), static_cast<float>(PlayerWidth), static_cast<float>(PlayerHeight));

}

void Player::UpdateBack()
{

	//左キー
	if (CheckHitKey(KEY_INPUT_LEFT) && PlayerX >= 0 - PlayerScroll)
	{
		PlayerX -= PlayerSpeed;

		m_diagonalX = true;
	}
	//右キー
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
		//スペースキー
		if (CheckHitKey(KEY_INPUT_SPACE) && PlayerJumpPower == 0.0f)
		{
			PlayerJumpPower = -15;
		}
	}

	PlayerY += PlayerJumpPower;

	if (PlayerJump == true)
	{
		//重力を与える
		PlayerY += PlayerGravity;
	}
	
	//時間が立つとスクロールを開始する
	PlayerScroll -= 1;

	//当たり判定更新
	m_colrect.SetCenter(static_cast<float>(PlayerX + PlayerScroll), static_cast<float>(PlayerY), static_cast<float>(PlayerWidth), static_cast<float>(PlayerHeight));

}

void Player::Draw()
{

	DrawGraph(PlayerX + PlayerScroll - 20, PlayerY - 20, PlayerGraph, true);

	//あたり判定描画
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

