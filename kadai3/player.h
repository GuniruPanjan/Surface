#pragma once
//構造体の宣言
typedef struct Player
{
	int handle;
	float x;
	float y;
}Player;

//プロトタイプ宣言
void updatePlayer(Player* pPlayer);
void drawPlayer(Player player);