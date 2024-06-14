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

	MapObjectWallPosX[0] = 1323.0f;
	MapObjectWallPosY = -650.0f;
	MapObjectWallPosZ[0] = -140.0f;

	MapObjectWallPosX[1] = 150.0f;
	MapObjectWallPosZ[1] = 1320.0f;

	MapObjectWallPosX[2] = -2415.0f;
	MapObjectWallPosZ[2] = -140.0f;

	MapObjectWallPosX[3] = 150.0f;
	MapObjectWallPosZ[3] = -2410.0f;

	MapObjectWallSize = 35.0f;


	MapBushModel = MV1LoadModel("MapData/BushModel.mv1");
	MapWallModel[0] = MV1LoadModel("MapData/wallstoneModel.mv1");

	MapWallModel[1] = MV1DuplicateModel(MapWallModel[0]);
	MapWallModel[2] = MV1DuplicateModel(MapWallModel[0]);
	MapWallModel[3] = MV1DuplicateModel(MapWallModel[0]);


	MapBushPos = VGet(MapObjectBushPosX, MapObjectBushPosY, MapObjectBushPosZ);
	MapWallPos[0] = VGet(MapObjectWallPosX[0], MapObjectWallPosY, MapObjectWallPosZ[0]);
	MapWallPos[1] = VGet(MapObjectWallPosX[1], MapObjectWallPosY, MapObjectWallPosZ[1]);
	MapWallPos[2] = VGet(MapObjectWallPosX[2], MapObjectWallPosY, MapObjectWallPosZ[2]);
	MapWallPos[3] = VGet(MapObjectWallPosX[3], MapObjectWallPosY, MapObjectWallPosZ[3]);


	//マップの壁のサイズ設定
	MV1SetScale(MapWallModel[0], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));
	MV1SetScale(MapWallModel[1], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));
	MV1SetScale(MapWallModel[2], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));
	MV1SetScale(MapWallModel[3], VGet(MapObjectWallSize, MapObjectWallSize, MapObjectWallSize));

}

void MapObject::Update()
{
}

void MapObject::Draw()
{
	MV1SetPosition(MapBushModel, MapBushPos);
	MV1SetPosition(MapWallModel[0], MapWallPos[0]);
	MV1SetPosition(MapWallModel[1], MapWallPos[1]);
	MV1SetPosition(MapWallModel[2], MapWallPos[2]);
	MV1SetPosition(MapWallModel[3], MapWallPos[3]);

	//3Dモデルの回転値をセットする
	MV1SetRotationXYZ(MapBushModel, VGet(1.57f, 0.0f, 0.0f));
	MV1SetRotationXYZ(MapWallModel[0], VGet(0.0f, 1.57f, 0.0f));
	MV1SetRotationXYZ(MapWallModel[2], VGet(0.0f, 1.57f, 0.0f));

	MV1DrawModel(MapWallModel[0]);
	MV1DrawModel(MapWallModel[1]);
	MV1DrawModel(MapWallModel[2]);
	MV1DrawModel(MapWallModel[3]);
	MV1DrawModel(MapBushModel);
	
}

void MapObject::End()
{
	//メモリ解放
	MV1DeleteModel(MapBushModel);
	MV1DeleteModel(MapWallModel[0]);
	MV1DeleteModel(MapWallModel[1]);
	MV1DeleteModel(MapWallModel[2]);
	MV1DeleteModel(MapWallModel[3]);
}
