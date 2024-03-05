#include "Dice.h"

Dice::Dice():
	DiceModelHandle(0),
	X(0),
	Y(0),
	Z(0),
	MouseX(0),
	MouseZ(0),
	DiceTurn(false),
	DiceGravity(0),
	posY(0),
	posX(0)
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
	//サイコロのY座標
	posY = -500.0f;
	//サイコロのX座標
	posX = 300.0f;

	//DiceSサイズのVECTOR
	posS = VGet(300.0f, -500.0f, 0.0f);
	//DiceMサイズのVECTOR
	posM = VGet(0.0f, 0.0f, 0.0f);

	//サイコロの重力
	DiceGravity = 5;
}

void Dice::Update()
{
	//モデルを移動
	MV1SetPosition(DiceModelHandle, posS);

	//マウスカーソル位置取得
	//GetMousePoint(&MouseX, &MouseZ);

	//サイコロを回してないとき
	if (DiceTurn == false)
	{
		X += 0.01f;
		Y += 0.02f;
		Z += 0.03f;

		//左クリックをしていないとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)
		{
			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));
		}
		//左クリック長押しでサイコロを振り回す
		else if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{

			//マウス追従
			//posS = VGet(MouseX - 300, -250.0f, -MouseZ + 225);

			DiceTurn = true;

		}
	}

	//サイコロを回すと重力を与える準備をする
	if (DiceTurn == true && posY >= -1000)
	{
		//左クリックを押している間
		X += GetRand(2);
		Y += GetRand(2);
		Z += GetRand(2);

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));


		//左クリックをしていないとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)
		{
			posS = VGet(posX, posY -= DiceGravity, 0.0f);
		}
	}


}

void Dice::Draw()
{
	//3Dモデルの描画
	MV1DrawModel(DiceModelHandle);
}
