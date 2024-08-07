#include "Background.h"
#include "DxLib.h"

Background::Background():
	BackGroundGraph(-1),
	BackX(0),
	BackY(0),
	RedTitle(0),
	Red(0),
	Darken(0)
{
}

Background::~Background()
{

}

void Background::Finalize()
{
	DeleteGraph(BackGroundGraph);

	DeleteGraph(RedTitle);
}

void Background::Init()
{
	BackGroundGraph = LoadGraph("date/背景.png");

	RedTitle = LoadGraph("date/RedTitle.png");

	Red = 0;

	BackX = 0;

	BackY = 0;

	Darken = 75;

}

void Background::Draw()
{
	//背景を暗く描画する
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Darken);
	DrawGraph(0, 0, BackGroundGraph, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, Darken);
	//背景を動かす
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Darken);
	DrawGraph(BackX, BackY, BackGroundGraph, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, Darken);

	//ダメージを喰らうと背景が赤くなっていく
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Red);
	DrawGraph(0, 0, RedTitle, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, Red);
}
