#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "Player/Player.h"
#include<memory>

class BlackHole
{
public:
	BlackHole();
	virtual ~BlackHole();

	void Init();
	void Update(Player& player);
	void Draw();

	//�u���b�N�z�[����x���W��y���W��z���W
	int BlackHoleX, BlackHoleY, BlackHoleZ;

	//�u���b�N�z�[���̉����Əc��
	int BlackHoleWidth, BlackHoleHight;

	//�u���b�N�z�[����3D���f���i�[�ϐ�
	int BlackHole3D;

	//�u���b�N�z�[���Ŏ��S��������̕ϐ�
	bool BlackDead;

	//Rect���Ǘ�����|�C���^
	//std::shared_ptr<Rect> BlackHoleRect = std::make_shared<Rect>();

	Rect BlackHoleRect;
};

