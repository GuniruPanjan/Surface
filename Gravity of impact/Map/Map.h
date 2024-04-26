#pragma once
#include "DxLib.h"
class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//マップオブジェクト格納変数
	int MapObject;

	//マップのX,Y,Z座標
	float MapX, MapY, MapZ;

	//マップの大きさ設定
	float MapScale;

	//マップの配置場所
	VECTOR MapPosition;
};

