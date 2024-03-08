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

	//サイコロに重力を与える変数
	bool DiceTurn;

private:
	//ダイスの動き
	//ジャンプさせてランダムな方向に跳ねさせる
	//ジャンプさせる
	float DiceRebound;
	//ランダムな方向に跳ねさせる
	bool DiceDirection;

	//ジャンプさせるフラグ
	bool DiceJump;

	//サイコロの動きの終了フラグ
	bool DiceEnd;

	//サイコロのランダム
	int DiceRandom;

	//サイコロの目の保存
	int DiceRoll;

	int DiceModelHandle;    //Diceのモデル格納変数
	VECTOR posM, posS;      //Diceのポジション

	//サイコロのポジション
	float posY,posX,posZ;

	//モデルを回転させる変数
	float X, Y, Z;

	//マウスカーソル位置取得変数
	int MouseX, MouseZ;

	//サイコロの重力
	int DiceGravityY, DiceGravityX;

};

