#pragma once
#include "MapBase.h"
class MapGoal : public MapBase
{
public:
	MapGoal();
	virtual ~MapGoal();

	void Init();
	void Update();
	void Draw();
	void End();

private:
	//�n�E�X���f���̃n���h��
	int HouseHandle;
};

