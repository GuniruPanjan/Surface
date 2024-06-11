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

	//�}�b�v�̍��W�ݒ�ƕ`��
	void Mapplace(int handle, float x, float y, float z);

	//�}�b�v�̕ǐ���
	void MapWall(int handle[], float x, float y, float z, float width, float depth);

private:
	//�}�b�v�̃n���h��
	int MapHandle;
	int BushHandle[];
};

