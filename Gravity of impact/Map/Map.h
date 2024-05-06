#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "Player/Player.h"

class Map
{
public:
	Map();
	virtual ~Map();

	virtual void Init();
	virtual void Update(Player& player);
	virtual void Draw(Player& player);
	virtual void End();

	//�}�b�v�I�u�W�F�N�g�i�[�ϐ�
	int MapObject;

	//�}�b�v��X,Y,Z���W
	float MapX, MapY, MapZ;

	//�}�b�v�̑傫���ݒ�
	float MapScale;

	//�}�b�v�̔z�u�ꏊ
	VECTOR MapPosition;

	Rect m_colrect;
};

