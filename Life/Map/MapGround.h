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

	void Mapplace(int handle, float x, float y, float z);

private:
	//マップのハンドル
	int MapHandle;
};

