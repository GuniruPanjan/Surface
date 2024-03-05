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
	//���f���n���h���̍폜
	MV1DeleteModel(DiceModelHandle);
}

void Dice::Init()
{
	//���f���̓ǂݍ���
	DiceModelHandle = MV1LoadModel("date/DiceModel/Dice1S.mv1");
	//�T�C�R����Y���W
	posY = -500.0f;
	//�T�C�R����X���W
	posX = 300.0f;

	//DiceS�T�C�Y��VECTOR
	posS = VGet(300.0f, -500.0f, 0.0f);
	//DiceM�T�C�Y��VECTOR
	posM = VGet(0.0f, 0.0f, 0.0f);

	//�T�C�R���̏d��
	DiceGravity = 5;
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
	if (DiceTurn == true && posY >= -1000)
	{
		//���N���b�N�������Ă����
		X += GetRand(2);
		Y += GetRand(2);
		Z += GetRand(2);

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));


		//���N���b�N�����Ă��Ȃ��Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)
		{
			posS = VGet(posX, posY -= DiceGravity, 0.0f);
		}
	}


}

void Dice::Draw()
{
	//3D���f���̕`��
	MV1DrawModel(DiceModelHandle);
}
