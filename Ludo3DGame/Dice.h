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

	//モデルを回転させる変数
	float X, Y, Z;

	//マウスカーソル位置取得変数
	int MouseX, MouseZ;

};

