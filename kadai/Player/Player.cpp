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
	//Playerの座標を設定する
	PlayerX = 200.0f;
	PlayerY = 255.0f;
	//Playerのスピードを設定する
	PlayerSpeed = 2.0f;

	//PlayerのScrollを設定する
	PlayerScroll = 0.0f;

	PlayerGraph = LoadGraph("date/Player.png");

	//現在時間を得る
	Time = GetNowCount();
}

void Player::Update()
{
	//経過時間を得る
	PlayerTime = (GetNowCount() - Time) / 1000;

	//左キー
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PlayerX -= PlayerSpeed;

		m_diagonalX = true;
	}
	//右キー
	if (CheckHitKey(KEY_INPUT_RIGHT))
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
	if (CheckHitKey(KEY_INPUT_UP))
	{
		PlayerY -= PlayerSpeed;

		m_diagonalY = true;
	}
	//下キー
	if (CheckHitKey(KEY_INPUT_DOWN))
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
	if (PlayerTime >= 10)
	{
		PlayerScroll -= 1;
	}
	

	//当たり判定更新
	m_colrect.SetCenter(static_cast<float>(PlayerX + PlayerScroll), static_cast<float>(PlayerY), static_cast<float>(PlayerWidth), static_cast<float>(PlayerHeight));

}

void Player::Draw()
{
	//Playerの仮画像
	//DrawCircle(static_cast<int>(PlayerX + PlayerScroll), static_cast<int>(PlayerY), 20, 0xffffff, true);

	DrawGraph(PlayerX + PlayerScroll - 20, PlayerY - 20, PlayerGraph, false);
    
	//あたり判定描画
	m_colrect.Draw(GetColor(255, 0, 0), false);
}

void Player::End()
{
}
