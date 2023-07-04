#include "DxLib.h"
#include "player.h"


typedef struct Player
{
	int handle;
	float x;
	float y;
	int num;
}Player;


void updatePlayer(Player* pPlayer)
{
	//update
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if ((padState & PAD_INPUT_UP) != 0)
	{
		pPlayer->y -= 2.0f;
		if (pPlayer->y < 0)
		{
			pPlayer->y = 0;
		}
	}
	if ((padState & PAD_INPUT_DOWN) != 0)
	{
		pPlayer->y += 2.0f;
		if (pPlayer->y > 320)
		{
			pPlayer->y = 320;
		}
	}
	if ((padState & PAD_INPUT_LEFT) != 0)
	{
		pPlayer->x -= 2.0f;
		if (pPlayer->x < 0)
		{
			pPlayer->x = 0;
		}
	}
	if ((padState & PAD_INPUT_RIGHT) != 0)
	{
		pPlayer->x += 2.0f;
		if (pPlayer->x > 470)
		{
			pPlayer->x = 470;
		}
	}
}


void drawPlayer(Player player)
{
	DrawGraph((int)player.x, (int)player.y, player.handle, 0);
}