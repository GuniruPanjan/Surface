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
	//�u�b�V���̃n���h��
	int MapBushHandle;
};

