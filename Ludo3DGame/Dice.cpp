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
	posY(0)
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

	posY = -250.0f;

	//DiceS�T�C�Y��VECTOR
	posS = VGet(180.0f, -250.0f, 0.0f);
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

	//���N���b�N�������ŃT�C�R����U���
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		
		//�}�E�X�Ǐ]
		//posS = VGet(MouseX - 300, -250.0f, -MouseZ + 225);

		DiceTurn = true;

	}

	//�T�C�R�����񂷂Əd�͂�^���鏀��������
	if (DiceTurn == true)
	{
		//���N���b�N�������Ă����
		X += GetRand(3);
		Y += GetRand(3);
		Z += GetRand(3);

		MV1SetRotationXYZ(DiceModelHandle, VGet(X, Y, Z));


		//���N���b�N�����Ă��Ȃ��Ƃ�
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)
		{
			posS = VGet(180.0f, posY -= DiceGravity, 0.0f);
		}
	}


}

void Dice::Draw()
{
	//3D���f���̕`��
	MV1DrawModel(DiceModelHandle);
}
