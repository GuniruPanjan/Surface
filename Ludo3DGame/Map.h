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

	//���f���n���h���̎擾
	int GetModelHandle() { return ModelHandle; }

private:

	//�}�b�v�̃��f���n���h��
	int ModelHandle;

	VECTOR pos, pos2;
	int WhiteColor, BrackColor;
};

