#pragma once
#include "DxLib.h"

class MapBase
{
public:
	MapBase() {}
	virtual ~MapBase() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//マップのモデル読み込み変数
	int GroundMapModel = -1;
	int MapBushModel = -1;

	//マップのポジション設定
	float MapPosX = 0.0f;
	float MapPosY = 0.0f;
	float MapPosZ = 0.0f;

	//マップのスケール設定
	float MapSize = 0.0f;

	//マップのポジション設定
	VECTOR MapPos = VGet(MapPosX, MapPosY, MapPosZ);
};


