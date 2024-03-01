#include "Map.h"

Map::Map():
	WhiteColor(0),
	BrackColor(0),
	ModelHandle(0)
{
	pos = VGet(-100, -300, 0);
	pos2 = VGet(100, 100, 100);
}

Map::~Map()
{
	//モデルハンドルの削除
	MV1DeleteModel(ModelHandle);
}

void Map::Init()
{
	ModelHandle = MV1LoadModel("date/MapModel/Map.mv1");

	WhiteColor = GetColor(255, 255, 255);
	BrackColor = GetColor(0, 0, 0);

	//モデルを移動
	MV1SetPosition(ModelHandle, pos);
}

void Map::Update()
{
	
}

void Map::Draw()
{
	//試しでCubeを描画
	//DrawCube3D(VGet(0,0,0), pos2, WhiteColor, WhiteColor, false);

	//3Dモデルの描画
	MV1DrawModel(ModelHandle);


}
