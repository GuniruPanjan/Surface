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
	//���f���̓ǂݍ���
	DiceModelHandle = MV1LoadModel("date/DiceModel/Dice1S.mv1");
}

Dice::~Dice()
{
	//���f���n���h���̍폜
	MV1DeleteModel(DiceModelHandle);
}

void Dice::Init()
{
	
	//�T�C�R����Y���W
	posY = -500.0f;
	//�T�C�R����X���W
	posX = 300.0f;
	//�T�C�R����Z���W
	posZ = 0.0f;

	//DiceS�T�C�Y��VECTOR
	posS = VGet(300.0f, -500.0f, 0.0f);
	//DiceM�T�C�Y��VECTOR
	posM = VGet(0.0f, 0.0f, 0.0f);

	//�T�C�R���̏d��
	DiceGravityY = 15;
	DiceGravityX = 10;

	//�_�C�X�̃��o�E���h
	DiceRebound = 20;

	//�T�C�R���̖�
	DiceRoll = 0;
}

void Dice::Update()
{
	//���f�����ړ�
	MV1SetPosition(DiceModelHandle, posS);

	//�}�E�X�J�[�\���ʒu�擾
	//GetMousePoint(&MouseX, &MouseZ);

	//�T�C�R�����񂵂ĂȂ��Ƃ�
	if (DiceTurn == false)
	{
		X += 0.01f;
		Y += 0.02f;
		Z += 0.03f;

		//���N���b�N�����Ă��Ȃ��Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)
		{
			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));
		}
		//���N���b�N�������ŃT�C�R����U���
		else if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{

			//�}�E�X�Ǐ]
			//posS = VGet(MouseX - 300, -250.0f, -MouseZ + 225);

			DiceTurn = true;

		}
	}

	//�T�C�R�����񂷂Əd�͂�^���鏀��������
	if (DiceTurn == true && posY >= -1000 && DiceJump == false && DiceEnd == false)
	{
		//���N���b�N�������Ă����
		X += GetRand(1);
		Y += GetRand(1);
		Z += GetRand(1);

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		//���N���b�N�����Ă��Ȃ��Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)
		{
			DiceGravityY++;

			posS = VGet(posX += DiceGravityX, posY -= DiceGravityY, posZ);
		}


	}
	else if (posY <= -1000 && DiceEnd == false)
	{
		//�_�C�X���W�����v������
		DiceJump = true;

		//�_�C�X���]������������߂�
		DiceDirection = true;
	}

	if (DiceJump == true && posY <= -850)
	{
		posS = VGet(posX -= DiceGravityX, posY += DiceRebound, 0.0f);

		//Dice��Rebound����
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
		//Dice��Rebound����
		X += 0.08f;
		Y += 0.09f;
		Z += 0.1f;

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		posS = VGet(posX += DiceGravityX, posY -= DiceGravityY, posZ);
	}
	else if (posY <= -1000 && DiceEnd == true)
	{
		//�T�C�R���̖ڂ�1�������ꍇ
		if (DiceRandom == 0)
		{
			DiceRoll = 1;

			X = 21;
			Y = 20.5f;
			Z = 19.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//�T�C�R���̖ڂ�2�������ꍇ
		if (DiceRandom == 1)
		{
			DiceRoll = 2;

			X = 18.8f;
			Y = 18.9f;
			Z = 17.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//�T�C�R���̖ڂ�3�������ꍇ
		if (DiceRandom == 2)
		{
			DiceRoll = 3;

			X = 22.5f;
			Y = 20.5f;
			Z = 19.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//�T�C�R���̖ڂ�4�������ꍇ
		if (DiceRandom == 3)
		{
			DiceRoll = 4;

			X = 25.8f;
			Y = 20.5f;
			Z = 19.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//�T�C�R���̖ڂ�5�������ꍇ
		if (DiceRandom == 4)
		{
			DiceRoll = 5;

			X = 23;
			Y = 25.1f;
			Z = 21;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
		//�T�C�R���̖ڂ�6�̏ꍇ
		if (DiceRandom == 5)
		{
			DiceRoll = 6;

			X = 24;
			Y = 20.5f;
			Z = 19.8f;

			MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));

		}
	}

	//�T�C�R���̓]�������
	if (DiceDirection == true)
	{

	}

	
	//�T�C�R���̖ڂ�\��������
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�T�C�R��:%d", DiceRoll);

}

void Dice::Draw()
{
	//3D���f���̕`��
	MV1DrawModel(DiceModelHandle);
}
