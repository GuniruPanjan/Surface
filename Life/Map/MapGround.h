#pragma once
#include "MapBase.h"

class MapGround : public MapBase
{
public:
	MapGround();
	virtual ~MapGround();

	void Init();
	void Update();
	void Draw();
	void End();

	//マップの座標設定と描画
	void Mapplace(int handle, float x, float y, float z);

	//マップの壁生成
	void MapWall(int handle[], float x, float y, float z, float width, float depth);

private:
	//マップのハンドル
	int MapHandle;
	int BushHandle[];
};

