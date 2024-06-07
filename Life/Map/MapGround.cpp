#include "MapGround.h"

MapGround::MapGround():
	MapHandle(-1)
{
}

MapGround::~MapGround()
{
}

void MapGround::Init()
{
	//3Dモデル読み込み
	MapModel = MV1LoadModel("MapData/Ground.mv1");

	//マップの大きさ設定
	MapSize = 5.0f;

	MapPosX = 0.0f;
	MapPosY = -8.0f;
	MapPosZ = 0.0f;

	//マップのスケール設定
	MV1SetScale(MapModel, VGet(MapSize, MapSize, MapSize));

	//ハンドルに渡す
	MapHandle = MapModel;
}

void MapGround::Update()
{
}

void MapGround::Draw()
{
	Mapplace(MapHandle, MapPosX, MapPosY, MapPosZ);

}

void MapGround::End()
{
	MV1DeleteModel(MapModel);
}

void MapGround::Mapplace(int handle, float x, float y, float z)
{
	//3Dモデルポジション設定
	MV1SetPosition(handle, VGet(x, y, z));
	
	//3Dモデル描画
	MV1DrawModel(handle);
}
