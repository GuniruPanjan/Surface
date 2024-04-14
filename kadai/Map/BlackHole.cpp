#include "BlackHole.h"

BlackHole::BlackHole() :
	BlackHole3D(0),
	BlackHoleX(0),
	BlackHoleY(0),
	BlackHoleZ(0),
	BlackHoleWidth(0),
	BlackHoleHight(0),
	BlackDead(false)
{
}

BlackHole::~BlackHole()
{
}

void BlackHole::Init()
{
	//ブラックホールの初期位置
	BlackHoleX = 0;
	BlackHoleY = 240;

	//ブラックホールの幅
	BlackHoleWidth = 150;
	BlackHoleHight = 480;

	BlackDead = false;

	//3Dモデルを読み込む
}

void BlackHole::Update(Player& player)
{
	//3Dモデルを回転させる

	//当たり判定をつける
	BlackHoleRect.SetCenter(static_cast<float>(BlackHoleX), static_cast<float>(BlackHoleY), static_cast<float>(BlackHoleWidth), static_cast<float>(BlackHoleHight));

	//ブラックホールで死んだ判定
	if (BlackHoleRect.IsCollision(player.m_colrect) == true)
	{
		BlackDead = true;
	}
}

void BlackHole::Draw()
{
	//3Dモデルを描画する

	//当たり判定を描画する
	BlackHoleRect.Draw(GetColor(0, 0, 0), true);

	
}
