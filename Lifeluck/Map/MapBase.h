#pragma once
#include "DxLib.h"

class MapBase
{
public:
	MapBase() {}
	virtual ~MapBase() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//�}�b�v�̃��f���ǂݍ��ݕϐ�
	int GroundMapModel = -1;
	int MapBushModel = -1;

	//�}�b�v�̃|�W�V�����ݒ�
	float MapPosX = 0.0f;
	float MapPosY = 0.0f;
	float MapPosZ = 0.0f;

	//�}�b�v�̃X�P�[���ݒ�
	float MapSize = 0.0f;

	//�}�b�v�̃|�W�V�����ݒ�
	VECTOR MapPos = VGet(MapPosX, MapPosY, MapPosZ);
};


