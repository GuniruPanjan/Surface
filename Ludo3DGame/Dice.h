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
	int DiceModelHandle;    //Diceのモデル格納変数
	VECTOR posM, posS;      //Diceのポジション

};

