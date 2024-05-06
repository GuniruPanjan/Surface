#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "Player/Player.h"

class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Init();
	virtual void Update(Player& player);
	virtual void Draw(Player& player);
	virtual void End();

	//マップオブジェクト格納変数
	int MapObject;

	//マップのX,Y,Z座標
	float MapX, MapY, MapZ;

	//マップの大きさ設定
	float MapScale;

	//マップの配置場所
	VECTOR MapPosition;

	Rect m_colrect;
};

