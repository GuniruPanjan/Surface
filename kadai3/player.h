#pragma once
//�\���̂̐錾
typedef struct Player
{
	int handle;
	float x;
	float y;
}Player;

//�v���g�^�C�v�錾
void updatePlayer(Player* pPlayer);
void drawPlayer(Player player);