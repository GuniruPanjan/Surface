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

	//�T�C�R���ɏd�͂�^����ϐ�
	bool DiceTurn;

private:
	//�_�C�X�̓���
	//�W�����v�����ă����_���ȕ����ɒ��˂�����
	//�W�����v������
	float DiceRebound;
	//�����_���ȕ����ɒ��˂�����
	bool DiceDirection;

	//�W�����v������t���O
	bool DiceJump;

	//�T�C�R���̓����̏I���t���O
	bool DiceEnd;

	//�T�C�R���̃����_��
	int DiceRandom;

	//�T�C�R���̖ڂ̕ۑ�
	int DiceRoll;

	int DiceModelHandle;    //Dice�̃��f���i�[�ϐ�
	VECTOR posM, posS;      //Dice�̃|�W�V����

	//�T�C�R���̃|�W�V����
	float posY,posX,posZ;

	//���f������]������ϐ�
	float X, Y, Z;

	//�}�E�X�J�[�\���ʒu�擾�ϐ�
	int MouseX, MouseZ;

	//�T�C�R���̏d��
	int DiceGravityY, DiceGravityX;

};

