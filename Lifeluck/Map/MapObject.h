#pragma once
#include "MapBase.h"

class MapObject : public MapBase
{
public:
	MapObject();
	virtual ~MapObject();

	void Init();
	void Update();
	void Draw();
	void End();
private:
	//ブッシュのハンドル
	int MapBushHandle;
};

