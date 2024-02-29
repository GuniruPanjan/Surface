#include "Map.h"

Map::Map():
	WhiteColor(0),
	BrackColor(0),
	ModelHandle(0)
{
	pos = VGet(0, 0, 0);
	pos2 = VGet(100, 100, 100);
}

Map::~Map()
{
}

void Map::Init()
{
	ModelHandle = MV1LoadModel("date/MapModel/Map.mb");

	WhiteColor = GetColor(255, 255, 255);
	BrackColor = GetColor(0, 0, 0);
}

void Map::Update()
{
	
}

void Map::Draw()
{
	//ŽŽ‚µ‚ÅCube‚ð•`‰æ
	DrawCube3D(pos, pos2, WhiteColor, WhiteColor, false);

	MV1SetPosition(ModelHandle, pos);
}
