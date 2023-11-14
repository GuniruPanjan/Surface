#include "Player.h"
#include "DxLib.h"

Player::Player():
	HP(100),
	Speed(2),
	PlayerX(640 / 2),
	PlayerY(480 / 2)
{

}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	DrawGraph(PlayerX, PlayerY, playerGraph, true);

	//左キーを押したとき
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PlayerX -= Speed;
	}
	//右キーを押したとき
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		PlayerX += Speed;
	}
}

void Player::Draw()
{
	playerGraph = DrawCircle(PlayerX , PlayerY, 3, GetColor(255, 255, 255), true);
}
