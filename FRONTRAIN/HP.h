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

	//�����蔻��ňÂ�����
	int b, b2;

	//�e�q�̎c��e��
	int MagazineGraph[13];

	//Reload�摜
	int Reload;
	int ReloadGraph[21];

	//�_�ŕϐ�
	int Blinking;

	//�}�E�X�̍��W�擾
	int MouseX, MouseY;

	//�{�^�������蔻��
	Rect m_HP;
	Rect m_Attack;

	//�}�E�X�����蔻��
	Rect m_Mouse;
};

