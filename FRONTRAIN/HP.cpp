#include "HP.h"
#include "Player.h"

void HP::PlayerHPInit()
{
	LoadDivGraph("date/HP�o�[.png", 10, 10, 1, 20, 10, HPberGraph);

	LoadDivGraph("date/�e�q.png", 13, 7, 2, 40, 60, MagazineGraph);

	HPCount = 0;
}

void HP::PlayerHP(Player& player)
{
	if (player.HP == 10)
	{
		HPCount = 9;
	}
	if (player.HP == 9)
	{
		HPCount = 8;
	}
	if (player.HP == 8)
	{
		HPCount = 7;
	}
	if (player.HP == 7)
	{
		HPCount = 6;
	}
	if (player.HP == 6)
	{
		HPCount = 5;
	}
	if (player.HP == 5)
	{
		HPCount = 4;
	}
	if (player.HP == 4)
	{
		HPCount = 3;
	}
	if (player.HP == 3)
	{
		HPCount = 2;
	}
	if (player.HP == 2)
	{
		HPCount = 1;
	}
	if (player.HP == 1)
	{
		HPCount = 0;
	}

	if (player.HP <= 0)
	{
		for (int i = 0; i < 10; i++)
		{
			DeleteGraph(HPberGraph[i]);
		}
		
	}

	//�v���C���[�̐^��ɕ\�������
	DrawGraph(player.PlayerX - 10, player.PlayerY - 30, HPberGraph[HPCount], true);

	//��ʂ̍��[�ɕ`��
	DrawGraph(640 / 12, 410, MagazineGraph[player.Bullet], true);

	//�v���C���[�^���HP���\�������
	//DrawFormatString(player.PlayerX - 8, player.PlayerY - 30, GetColor(0, 255, 0), "%d",player.HP);
}
