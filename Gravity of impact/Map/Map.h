#pragma once
#include "DxLib.h"
class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//�}�b�v�I�u�W�F�N�g�i�[�ϐ�
	int MapObject;

	//�}�b�v��X,Y,Z���W
	float MapX, MapY, MapZ;

	//�}�b�v�̑傫���ݒ�
	float MapScale;

	//�}�b�v�̔z�u�ꏊ
	VECTOR MapPosition;
};

