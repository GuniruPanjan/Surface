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

private:
	int DiceModelHandle;    //Dice�̃��f���i�[�ϐ�
	VECTOR posM, posS;      //Dice�̃|�W�V����

};

