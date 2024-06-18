#include "MapGoal.h"

MapGoal::MapGoal():
	HouseHandle(-1)
{
}

MapGoal::~MapGoal()
{
}

void MapGoal::Init()
{
	//3Dモデルの読み込み
	MapHouseModel = MV1LoadModel("MapData/HouseModel.mv1");

	MapHousePosX = 0.0f;
	MapHousePosY = -25.0f;
	MapHousePosZ = -1150.0f;

	MapHouseSize = 250.0f;

	//マップのスケール設定
	MV1SetScale(MapHouseModel, VGet(MapHouseSize, MapHouseSize, MapHouseSize));

	MapHousePos = VGet(MapHousePosX, MapHousePosY, MapHousePosZ);

	HouseHandle = MapHouseModel;
}

void MapGoal::Update()
{

}

void MapGoal::Draw()
{
	//3Dモデルポジション設定
	MV1SetPosition(HouseHandle, MapHousePos);

	//3Dモデルの回転値をセットする
	MV1SetRotationXYZ(HouseHandle, VGet(0.0f, 3.14f, 0.0f));

	//3Dモデル描画
	MV1DrawModel(HouseHandle);
}

void MapGoal::End()
{
	//メモリ解放
	MV1DeleteModel(MapHouseModel);
}
