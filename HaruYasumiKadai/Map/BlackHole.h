#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "Player/Player.h"
#include "Map.h"
#include<memory>

struct BlackHoleAttak
{
public:
	//�U���̉摜�i�[�p�ϐ�
	int AttakGraph;

	//�U���̈ʒu
	int AttakX, AttakY;

	//�U���X�s�[�h
	int AttakSpeed;

	//�U���̑��݃t���O
	bool Existence;

	Rect AttakRect;
};

class BlackHole
{
public:
	BlackHole();
	virtual ~BlackHole();

	void Init();
	void InitBack(BlackHoleAttak attak[], int Size);
	void Update(Player& player);
	void Draw();
	void DrawBack(BlackHoleAttak attak[], int Size);
	void Attak(Player& player,BlackHoleAttak attak[], int Size);

	//�u���b�N�z�[����x���W��y���W
	int BlackHoleX, BlackHoleY;

	//3D�̃u���b�N�z�[���̃|�W�V����
	VECTOR pos;

	//���ݎ��Ԃ𓾂�
	int TimeNow;

	//�U���܂ł̎���
	int Time;

	//�a���̉摜�i�[�ϐ�
	int Graph;

	//�U���̃����_���ƃt���O
	int AttakRandom;
	bool AttakFlag;

	//�U���Ԋu
	int Attakinterval;

	//�u���b�N�z�[���̉����Əc��
	int BlackHoleWidth, BlackHoleHight;

	//�u���b�N�z�[����3D���f���i�[�ϐ�
	int BlackHole3D;

	//�u���b�N�z�[���Ŏ��S��������̕ϐ�
	bool BlackDead;

	static constexpr float Scale = 20.0f; //�X�P�[��

	//Rect���Ǘ�����|�C���^
	//std::shared_ptr<Rect> BlackHoleRect = std::make_shared<Rect>();

	Rect BlackHoleRect;

	
};



