#pragma once
#include "DxLib.h"

class Dice
{
public:
	Dice();
	virtual ~Dice();

	void Init();
	void Update();
	void Draw();

	//�T�C�R���ɏd�͂�^����ϐ�
	bool DiceTurn;

private:
	int DiceModelHandle;    //Dice�̃��f���i�[�ϐ�
	VECTOR posM, posS;      //Dice�̃|�W�V����

	//�T�C�R���̃|�W�V����
	float posY,posX;

	//���f������]������ϐ�
	float X, Y, Z;

	//�}�E�X�J�[�\���ʒu�擾�ϐ�
	int MouseX, MouseZ;

	//�T�C�R���̏d��
	int DiceGravity;

};

