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

private:
	//マップのハンドル
	int MapHandle;
};

