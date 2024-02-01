#include "HP.h"
#include "Player.h"

void HP::PlayerHPInit()
{
	LoadDivGraph("date/HPバー.png", 10, 10, 1, 20, 10, HPberGraph);

	LoadDivGraph("date/弾倉.png", 13, 7, 2, 40, 60, MagazineGraph);

	LoadDivGraph("date/ReloadGraph.png", 21, 7, 3, 20, 60, ReloadGraph);

	Reload = LoadGraph("date/Reload.png");

	Blinking = 0;

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

	//プレイヤーの真上に表示される
	DrawGraph(player.PlayerX - 10, player.PlayerY - 30, HPberGraph[HPCount], true);

	//画面の左端に描く
	DrawGraph(30, 410, MagazineGraph[player.Bullet], true);
	DrawFormatString(38, 432, GetColor(0, 0, 0), "%d", player.Bullet);
	DrawFormatString(36, 430, GetColor(255, 255, 255), "%d", player.Bullet);

	//Reloadタイムを描画する
	DrawGraph(70, 410, ReloadGraph[player.BulletTime / 2], true);

	//プレイヤーの弾が切れたら描画する
	if (player.Bullet == 0)
	{
		Blinking++;

		if (Blinking >= 5)
		{
			DrawGraph(25, 430, Reload, true);

			if (Blinking >= 20)
			{
				Blinking = 0;
			}
		}

		
	}
	
}
