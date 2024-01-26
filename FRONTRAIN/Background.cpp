#include "Background.h"
#include "DxLib.h"

Background::Background():
	BackGroundGraph(-1)
{
}

Background::~Background()
{

}

void Background::Init()
{
	BackGroundGraph = LoadGraph("date/îwåi.png");
}

void Background::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
	DrawGraph(0, 0, BackGroundGraph, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 150);
}
