#pragma once
class Player;

class HP
{
public:
	void PlayerHPInit();
	//�v���C���[��HP�\������֐�
	void PlayerHP(Player& player);

	//HP�o�[�̕ϐ�
	int HPberGraph[10];

	int HPCount;

	//�e�q�̎c��e��
	int MagazineGraph[13];

	//Reload�摜
	int Reload;

	//�_�ŕϐ�
	int Blinking;
};

