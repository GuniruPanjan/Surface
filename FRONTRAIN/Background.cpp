#include "Background.h"
#include "DxLib.h"

Background::Background():
	BackGroundGraph(-1),
	BackX(0),
	BackY(0),
	RedTitle(0),
	Red(0),
	WaveCount(1)
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
	BackGroundGraph = LoadGraph("date/îwåi.png");

	RedTitle = LoadGraph("date/RedTitle.png");

	Red = 0;

	BackX = 0;

	BackY = 0;

	WaveCount = 1;
}

void Background::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 75);
	DrawGraph(0, 0, BackGroundGraph, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 75);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 75);
	DrawGraph(BackX, BackY, BackGroundGraph, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 75);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Red);
	DrawGraph(0, 0, RedTitle, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, Red);

	/*DrawString(250, 60, "WAVE:", GetColor(255, 255, 255));

	DrawFormatString(300,60,GetColor)*/
}
