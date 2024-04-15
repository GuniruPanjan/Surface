#include "BlackHole.h"

BlackHole::BlackHole() :
	BlackHole3D(0),
	BlackHoleX(0),
	BlackHoleY(0),
	pos(VGet(0,0,0)),
	BlackHoleWidth(0),
	BlackHoleHight(0),
	BlackDead(false)
{
}

BlackHole::~BlackHole()
{
	MV1DeleteModel(BlackHole3D);
}

void BlackHole::Init()
{
	//ブラックホールの初期位置
	BlackHoleX = 0;
	BlackHoleY = 240;

	//3Dのブラックホールの初期位置
	pos = VGet(-420, -290, 0);

	//ブラックホールの幅
	BlackHoleWidth = 150;
	BlackHoleHight = 480;

	BlackDead = false;

	//3Dモデルを読み込む
	BlackHole3D = MV1LoadModel("date/BlackHole.mv1");
}

void BlackHole::Update(Player& player)
{

	//3Dモデルのスケール設定
	MV1SetScale(BlackHole3D, VGet(Scale, Scale, Scale));

	//3Dモデルのポジション設定
	MV1SetPosition(BlackHole3D, pos);

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
	MV1DrawModel(BlackHole3D);
	//当たり判定を描画する
	//BlackHoleRect.Draw(GetColor(0, 0, 0), false);

	
}
