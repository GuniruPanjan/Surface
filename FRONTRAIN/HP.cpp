#include "HP.h"
#include "Player.h"

void HP::FinalizeHP()
{
	for (int i = 0; i < 10; i++)
	{
		DeleteGraph(HPberGraph[i]);
	}

	for (int i = 0; i < 13; i++)
	{
		DeleteGraph(MagazineGraph[i]);
	}

	for (int i = 0; i < 21; i++)
	{
		DeleteGraph(ReloadGraph[i]);
	}

	DeleteGraph(Reload);
}

void HP::PlayerHPInit()
{
	LoadDivGraph("date/HPバー.png", 10, 10, 1, 20, 10, HPberGraph);

	LoadDivGraph("date/弾倉.png", 13, 7, 2, 40, 60, MagazineGraph);

	LoadDivGraph("date/ReloadGraph.png", 21, 7, 3, 20, 60, ReloadGraph);

	Reload = LoadGraph("date/Reload.png");

	Blinking = 0;

	HPCount = 0;
}

void HP::PlayerHP(Player& player, Background& back)
{
	if (player.HP == 10)
	{
		back.Red = 0;

		HPCount = 9;
	}
	if (player.HP == 9)
	{
		back.Red = 10;

		HPCount = 8;
	}
	if (player.HP == 8)
	{
		back.Red = 20;

		HPCount = 7;
	}
	if (player.HP == 7)
	{
		back.Red = 30;

		HPCount = 6;
	}
	if (player.HP == 6)
	{
		back.Red = 40;

		HPCount = 5;
	}
	if (player.HP == 5)
	{
		back.Red = 50;

		HPCount = 4;
	}
	if (player.HP == 4)
	{
		back.Red = 60;

		HPCount = 3;
	}
	if (player.HP == 3)
	{
		back.Red = 70;

		HPCount = 2;
	}
	if (player.HP == 2)
	{
		back.Red = 80;

		HPCount = 1;
	}
	if (player.HP == 1)
	{
		back.Red = 90;

		HPCount = 0;
	}

	if (player.HP <= 0)
	{
		back.Red = 100;

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
