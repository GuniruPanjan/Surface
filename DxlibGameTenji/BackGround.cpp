#include "BackGround.h"
#include "DxLib.h"

BackGround::BackGround():
	Easy(0),
	Normal(0),
	Difficolt(0)
{
}

BackGround::~BackGround()
{
}

void BackGround::Init()
{
}

void BackGround::Update()
{
}

void BackGround::Draw()
{
	if (Easy == 1)
	{
		LoadGraph("date/�C�[�W�[.jpeg");
	}
	else if (Normal == 1)
	{
		LoadGraph("date/�m�[�}��.jpeg");
	}
	else if (Difficolt == 1)
	{
		LoadGraph("date/���.jpg");
	}
}
