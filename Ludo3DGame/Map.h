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

	VECTOR pos, pos2;

private:

	//�}�b�v�̃��f���n���h��
	int ModelHandle;
	
	int WhiteColor, BrackColor;
};

