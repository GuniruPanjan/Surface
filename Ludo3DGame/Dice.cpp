#include "Dice.h"

Dice::Dice():
	DiceModelHandle(0)
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

	//DiceS�T�C�Y��VECTOR
	posS = VGet(0.0f, -100.0f, 0.0f);
	//DiceM�T�C�Y��VECTOR
	posM = VGet(0.0f, 0.0f, 0.0f);

	//���f�����ړ�
	MV1SetPosition(DiceModelHandle, posS);
}

void Dice::Update()
{
}

void Dice::Draw()
{
	//3D���f���̕`��
	MV1DrawModel(DiceModelHandle);
}
