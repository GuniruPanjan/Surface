#include "Dice.h"

Dice::Dice():
	DiceModelHandle(0),
	X(0),
	Y(0),
	Z(0),
	MouseX(0),
	MouseZ(0),
	DiceTurn(false),
	DiceGravityY(0),
	DiceGravityX(0),
	posY(0),
	posX(0),
	posZ(0),
	DiceRoll(0),
	DiceRebound(0),
	DiceJump(false),
	DiceEnd(false),
	DiceRandom(0),
	DiceDirection(false)
{
	//モデルの読み込み
	DiceModelHandle = MV1LoadModel("date/DiceModel/Dice1S.mv1");
}

Dice::~Dice()
{
	//モデルハンドルの削除
	MV1DeleteModel(DiceModelHandle);
}

void Dice::Init()
{
	
	//サイコロのY座標
	posY = -500.0f;
	//サイコロのX座標
	posX = 300.0f;
	//サイコロのZ座標
	posZ = 0.0f;

	//DiceSサイズのVECTOR
	posS = VGet(300.0f, -500.0f, 0.0f);
	//DiceMサイズのVECTOR
	posM = VGet(0.0f, 0.0f, 0.0f);

	//サイコロの重力
	DiceGravityY = 15;
	DiceGravityX = 10;

	//ダイスのリバウンド
	DiceRebound = 20;

	//サイコロの目
	DiceRoll = 0;
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
	if (DiceTurn == true && posY >= -1000 && DiceJump == false && DiceEnd == false)
	{
		//左クリックを押している間
		X += GetRand(1);
		Y += GetRand(1);
		Z += GetRand(1);

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		//左クリックをしていないとき
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)
		{
			DiceGravityY++;

			posS = VGet(posX += DiceGravityX, posY -= DiceGravityY, posZ);
		}


	}
	else if (posY <= -1000 && DiceEnd == false)
	{
		//ダイスをジャンプさせる
		DiceJump = true;

		//ダイスが転がる方向を決める
		DiceDirection = true;
	}

	if (DiceJump == true && posY <= -850)
	{
		posS = VGet(posX -= DiceGravityX, posY += DiceRebound, 0.0f);

		//DiceをRebound中回す
		X += 0.1f;
		Y += 0.2f;
		Z += 0.3f;

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		if (posY >= -850)
		{
			DiceJump = false;

			DiceEnd = true;

			DiceRandom = GetRand(5);
		}

	}
	else if (DiceJump == false && posY >= -1000 && DiceEnd == true)
	{
		//DiceをRebound中回す
		X += 0.08f;
		Y += 0.09f;
		Z += 0.1f;

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		posS = VGet(posX += DiceGravityX, posY -= DiceGravityY, posZ);
	}
	else if (posY <= -1000 && DiceEnd == true)
	{
		//サイコロの目が1だった場合
		if (DiceRandom == 0)
		{
			DiceRoll = 1;

			X = 21;
			Y = 20.5f;
			Z = 19.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//サイコロの目が2だった場合
		if (DiceRandom == 1)
		{
			DiceRoll = 2;

			X = 18.8f;
			Y = 18.9f;
			Z = 17.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//サイコロの目が3だった場合
		if (DiceRandom == 2)
		{
			DiceRoll = 3;

			X = 22.5f;
			Y = 20.5f;
			Z = 19.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//サイコロの目が4だった場合
		if (DiceRandom == 3)
		{
			DiceRoll = 4;

			X = 25.8f;
			Y = 20.5f;
			Z = 19.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//サイコロの目が5だった場合
		if (DiceRandom == 4)
		{
			DiceRoll = 5;

			X = 23;
			Y = 25.1f;
			Z = 21;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//サイコロの目が6の場合
		if (DiceRandom == 5)
		{
			DiceRoll = 6;

			X = 24;
			Y = 20.5f;
			Z = 19.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
	}

	//サイコロの転がる方向
	if (DiceDirection == true)
	{

	}

	
	//サイコロの目を表示させる
	DrawFormatString(0, 0, GetColor(255, 255, 255), "サイコロ:%d", DiceRoll);

}

void Dice::Draw()
{
	//3Dモデルの描画
	MV1DrawModel(DiceModelHandle);
}
