#include "MapGround.h"

MapGround::MapGround():
	MapHandle(-1)
{
	for (int i = 0; i <= 50; i++)
	{
		BushHandle[i] = -1;
	}
}

MapGround::~MapGround()
{
}

void MapGround::Init()
{
	//3Dモデル読み込み
	GroundMapModel = MV1LoadModel("MapData/Ground.mv1");
	BushModel = MV1LoadModel("MapData/BushModel.mv1");

	//マップの大きさ設定
	MapSize = 5.0f;
	BushSize = 30.0f;

	MapPosX = 0.0f;
	MapPosY = -8.0f;
	MapPosZ = 0.0f;

	//マップのスケール設定
	MV1SetScale(GroundMapModel, VGet(MapSize, MapSize, MapSize));
	MV1SetScale(BushModel, VGet(BushSize, BushSize, BushSize));

	//ハンドルに渡す
	MapHandle = GroundMapModel;

	for (int i = 0; i <= 50; i++)
	{
		BushHandle[i] = MV1DuplicateModel(BushModel);
	}
}

void MapGround::Update()
{
}

void MapGround::Draw()
{
	Mapplace(MapHandle, MapPosX, MapPosY, MapPosZ);

	MapWall(BushHandle, -1250.0f, 0.0f, 1250.0f, 50.0f, 0.0f);
}

void MapGround::End()
{
	MV1DeleteModel(GroundMapModel);
	MV1DeleteModel(BushModel);
}

void MapGround::Mapplace(int handle, float x, float y, float z)
{
	//3Dモデルポジション設定
	MV1SetPosition(handle, VGet(x, y, z));
	
	//3Dモデル描画
	MV1DrawModel(handle);
}

void MapGround::MapWall(int handle[], float x, float y, float z, float width, float depth)
{

	for (int i = 0; i <= 50; i++)
	{
		//3Dモデルポジション設定
		MV1SetPosition(handle[i], VGet(x + width * i, y, z + depth * i));

		//3Dモデル描画
		MV1DrawModel(handle[i]);
	}
	


}
