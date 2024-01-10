#include "Game.h"
#include "Player.h"
#include "WalkEnemy.h"
#include "Background.h"
#include "DxLib.h"
#include "Map.h"
#include "GraphMode.h"
#include "TimeCount.h"
#include "Point.h"
#include "SceneMgr.h"
#include "HP.h"

Player player;
HP hp;
Shot shot[SHOT];
WalkEnemy WEnemy;
WalkEnemyStruct WenemyS[ENEMY_NOW];
Map map;
Background Back;
TimeCount timecount;
Point point;

bool Isflag = false;

//èâä˙âª
void Game_Initialize()
{
	timecount.InitTime();
	point.InitPoint();
	player.Init();
	for (int i = 0; i < SHOT; i++)
	{
		player.InitShot(shot[i]);
	}
	for (int i = 0; i < ENEMY_NOW; i++)
	{
		WEnemy.Init(WenemyS[i], WEnemy);
	}
	map.InitMap();
}

//èIóπèàóù
void Game_Finalize()
{
}

//çXêVèàóù
void Game_Update()
{
	timecount.UpdateTime(point);

	player.Update(player, map);

	for (int i = 0; i < SHOT; i++)
	{
		WEnemy.Update(player, shot[i], WenemyS, ENEMY_NOW, player.ScrollX, &timecount, WEnemy);
	}

	player.ShotUpdate(player, shot, SHOT);
	map.UpdateMap(player.ScrollX);
}

//ï`âÊèàóù
void Game_Draw()
{
	Back.Draw();

	timecount.DrawTime();
	point.DrawPoint();

	hp.PlayerHP(player);

	player.Draw();
	
	for (int i = 0; i < SHOT; i++)
	{
		player.DrawShot(shot[i]);
	}

	for (int i = 0; i < ENEMY_NOW; i++)
	{
		WEnemy.Draw(player.ScrollX, WenemyS[i], point);
	}

	for (int i = 0; i < SHOT; i++)
	{
		map.DrawMap(player.ScrollX, shot[i], player, WenemyS);
	}

	
}
