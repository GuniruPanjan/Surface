#include "Dice.h"

Dice::Dice():
	DiceModelHandle(0)
{
}

Dice::~Dice()
{
	//モデルハンドルの削除
	MV1DeleteModel(DiceModelHandle);
}

void Dice::Init()
{
	//モデルの読み込み
	DiceModelHandle = MV1LoadModel("date/DiceModel/Dice1S.mv1");

	//DiceSサイズのVECTOR
	posS = VGet(0.0f, -100.0f, 0.0f);
	//DiceMサイズのVECTOR
	posM = VGet(0.0f, 0.0f, 0.0f);

	//モデルを移動
	MV1SetPosition(DiceModelHandle, posS);
}

void Dice::Update()
{
}

void Dice::Draw()
{
	//3Dモデルの描画
	MV1DrawModel(DiceModelHandle);
}
