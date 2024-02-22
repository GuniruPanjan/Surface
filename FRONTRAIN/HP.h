#pragma once
#include "Background.h"
#include "Save.h"
#include "Rect.h"
#include "Point.h"
class Player;

class HP
{
public:
	void FinalizeHP();
	void PlayerHPInit();
	//�v���C���[��HP�\������֐�
	void PlayerHP(Player& player, Background& back, Save& save, Point& point, Shot shot[]);

	//HP�o�[�̕ϐ�
	int HPberGraph[11];

	int HPCount;

	//�{�^���̕ϐ�
	int Botton;
	//�F�ϐ��錾
	int GreenColor, RedColor, YelloColor;
	int HPColor, AttackColor;

	//�V���b�v�ɕK�v�ȃ|�C���g
	int AttackShop, AttackCount;
	//�������тɃ|�C���g�𑽂����邽�߂̕ϐ�
	int FirstBuy, SecondBuy, ThirdBuy;
	//HP���񕜂��邽�߂̕ϐ�
	int HPBuy;

	//�����蔻��ňÂ�����
	int b, b2;

	//�e�q�̎c��e��
	int MagazineGraph[13];

	//Reload�摜
	int Reload;
	int ReloadGraph[21];

	//�|�C���g�ϊ���
	int PointHPChange, PointAttackChange;
	int PointHPChangeUse, PointAttackChangeUse;

	//�|�C���g��ϊ��������ǂ����̔��f
	bool PointHP = false;
	bool PointAttack = false;

	//�_�ŕϐ�
	int Blinking;

	//�{�^����A���ŃN���b�N���Ȃ��悤�ɂ���ϐ�
	bool AttackClick = false;

	//�}�E�X�̍��W�擾
	int MouseX, MouseY;

	//�}�E�X�̓����蔻��̕�
	int UIMouseDecisionX, UIMouseDecisionY;

	//���F������ϐ�
	int UIWhiteColor;

	//���F������ϐ�
	int UIBlackColor;

	//�{�^�������蔻��
	Rect m_HP;
	Rect m_Attack;

	//�}�E�X�����蔻��
	Rect m_Mouse;
};

