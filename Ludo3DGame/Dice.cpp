#include "Dice.h"

Dice::Dice():
	DiceModelHandle(0),
	X(0),
	Y(0),
	Z(0),
	MouseX(0),
	MouseZ(0)
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
	posS = VGet(180.0f, -250.0f, 0.0f);
	//DiceMサイズのVECTOR
	posM = VGet(0.0f, 0.0f, 0.0f);
}

void Dice::Update()
{
	//モデルを移動
	MV1SetPosition(DiceModelHandle, posS);

	//マウスカーソル位置取得
	GetMousePoint(&MouseX, &MouseZ);

	//左クリック長押しでサイコロを振り回す
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		//押している間
		X += GetRand(3);
		Y += GetRand(3);
		Z += GetRand(3);

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		posS = VGet(MouseX - 300, -250.0f, -MouseZ + 225);

	}


}

void Dice::Draw()
{
	//3Dモデルの描画
	MV1DrawModel(DiceModelHandle);
}
