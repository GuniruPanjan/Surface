#pragma once
#include "DxLib.h"

class MapBase
{
public:
	MapBase() 
	{
		for (int i = 0; i < 4; i++)
		{
			MapWallModel[i] = -1;
			MapObjectWallPosX[i] = 0.0f;
			MapObjectWallPosZ[i] = 0.0f;
			MapWallPos[i] = VGet(0.0f, 0.0f, 0.0f);
		}
	}
	virtual ~MapBase() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//マップのモデル読み込み変数
	int GroundMapModel = -1;
	int MapBushModel = -1;
	int MapWallModel[4];
	int MapHouseModel = -1;
	

	//マップのポジション設定
	float MapGroundPosX = 0.0f;
	float MapGroundPosY = 0.0f;
	float MapGroundPosZ = 0.0f;

	float MapObjectBushPosX = 0.0f;
	float MapObjectBushPosY = 0.0f;
	float MapObjectBushPosZ = 0.0f;

	float MapObjectWallPosX[4];
	float MapObjectWallPosY = 0.0f;
	float MapObjectWallPosZ[4];

	float MapHousePosX = 0.0f;
	float MapHousePosY = 0.0f;
	float MapHousePosZ = 0.0f;


	//マップのスケール設定
	float MapSize = 0.0f;
	float MapObjectWallSize = 0.0f;
	float MapHouseSize = 0.0f;

	//マップのポジション設定
	VECTOR MapPos = VGet(MapGroundPosX, MapGroundPosY, MapGroundPosZ);
	VECTOR MapBushPos = VGet(MapObjectBushPosX, MapObjectBushPosY, MapObjectBushPosZ);
	VECTOR MapWallPos[4];
	VECTOR MapHousePos = VGet(MapHousePosX, MapHousePosY, MapHousePosZ);
};


