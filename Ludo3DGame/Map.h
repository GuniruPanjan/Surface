#pragma once
#include "DxLib.h"

class Map
{
public:
	Map();
	virtual ~Map();

	void Init();
	void Update();
	void Draw();

	//モデルハンドルの取得
	int GetModelHandle() { return ModelHandle; }

private:

	//マップのモデルハンドル
	int ModelHandle;

	VECTOR pos, pos2;
	int WhiteColor, BrackColor;
};

