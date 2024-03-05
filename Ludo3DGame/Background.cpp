#include "Background.h"
#include "DxLib.h"

Background::Background()
{
	BackGroundHandle = LoadGraph("date/DeskModel/wood.png");
}

Background::~Background()
{
	DeleteGraph(BackGroundHandle);
}

void Background::Draw()
{
	//�w�i��`��
	DrawGraph(0, 0, BackGroundHandle, true);
}
