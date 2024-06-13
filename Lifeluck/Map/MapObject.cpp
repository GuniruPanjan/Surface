#include "MapObject.h"

MapObject::MapObject()
{
	for (int i = 0; i < 4; i++)
	{
		MapWallModel[i] = -1;
	}
}

MapObject::~MapObject()
{
}

void MapObject::Init()
{
	/*マップの壁が異常に重い*/

	MapObjectBushPosX = 1250.0f;
	MapObjectBushPosY = -100.0f;
	MapObjectBushPosZ = -850.0f;

	MapObjectWallPosX = 1323.0f;
	MapObjectWallPosY = -650.0f;
	MapObjectWallPosZ = -140.0f;

	MapObjectWallSize = 35.0f;


	MapBushModel = MV1LoadModel("MapData/BushModel.mv1");
	MapWallModel[0] = MV1LoadModel("MapData/wallstoneModel.mv1");

	MapBushPos = VGet(MapObjectBushPosX, MapObjectBushPosY, MapObjectBushPosZ);
	MapWallPos = VGet(MapObjectWallPosX, MapObjectWallPosY, MapObjectWallPosZ);

	MV1SetScale(MapWallModel[0], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));
}

void MapObject::Update()
{
}

void MapObject::Draw()
{
	MV1SetPosition(MapBushModel, MapBushPos);
	MV1SetPosition(MapWallModel[0], MapWallPos);

	//3Dモデルの回転地をセットする
	MV1SetRotationXYZ(MapBushModel, VGet(1.57f, 0.0f, 0.0f));
	MV1SetRotationXYZ(MapWallModel[0], VGet(0.0f, 1.57f, 0.0f));

	MV1DrawModel(MapWallModel[0]);
	MV1DrawModel(MapBushModel);
	
}

void MapObject::End()
{
	//メモリ解放
	MV1DeleteModel(MapBushModel);
	MV1DeleteModel(MapWallModel[0]);
}
