#pragma once
#include "Background.h"
class Player;

class HP
{
public:
	void FinalizeHP();
	void PlayerHPInit();
	//�v���C���[��HP�\������֐�
	void PlayerHP(Player& player, Background& back);

	//HP�o�[�̕ϐ�
	int HPberGraph[10];

	int HPCount;

	//�e�q�̎c��e��
	int MagazineGraph[13];

	//Reload�摜
	int Reload;
	int ReloadGraph[21];

	//�_�ŕϐ�
	int Blinking;
};

