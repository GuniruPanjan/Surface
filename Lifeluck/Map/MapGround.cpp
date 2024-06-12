#include "MapGround.h"

MapGround::MapGround() :
	MapHandle(-1)
{
	
}

MapGround::~MapGround()
{
}

void MapGround::Init()
{
	//3Dモデル読み込み
	GroundMapModel = MV1LoadModel("MapData/Ground.mv1");

	//マップの大きさ設定
	MapSize = 5.0f;

	MapPosX = 0.0f;
	MapPosY = -8.0f;
	MapPosZ = 0.0f;

	//マップのスケール設定
	MV1SetScale(GroundMapModel, VGet(MapSize, MapSize, MapSize));

	MapPos = VGet(MapPosX, MapPosY, MapPosZ);

	//ハンドルに渡す
	MapHandle = GroundMapModel;
}

void MapGround::Update()
{
}

void MapGround::Draw()
{
	//3Dマップのポジション設定
	MV1SetPosition(MapHandle, MapPos);

	//3Dマップの描画
	MV1DrawModel(MapHandle);
	
}

void MapGround::End()
{
	MV1DeleteModel(GroundMapModel);
}

