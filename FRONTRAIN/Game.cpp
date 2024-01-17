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
#include "SkyEnemy.h"
#include "DistanceEnemy.h"

Player player;
HP hp;
Shot shot[SHOT];
EnemyShot enemyshot[ENEMY_SHOT];

WalkEnemy WEnemy;
WalkEnemyStruct WenemyS[ENEMY_NOW];

SkyEnemy SEnemy;
SkyEnemyStruct SenemyS[SKY_ENEMY_NOW];

DistanceEnemy DEnemy;
DistanceEnemyStruct DenemyS[DISTANCE_ENEMY_NOW];

Map map;
Background Back;
TimeCount timecount;
Point point;

bool Isflag = false;

//������
void Game_Initialize()
{
	Back.Init();

	timecount.InitTime();
	point.InitPoint();
	player.Init();

	player.InitShot(shot);

	DEnemy.EnemyShotInit(enemyshot);

	for (int i = 0; i < ENEMY_NOW; i++)
	{
		WEnemy.Init(WenemyS[i], WEnemy);
	}
	for (int i = 0; i < SKY_ENEMY_NOW; i++)
	{
		SEnemy.Init(SenemyS[i], SEnemy);
	}
	for (int i = 0; i < DISTANCE_ENEMY_NOW; i++)
	{
		DEnemy.Init(DenemyS[i], DEnemy);
	}
	map.InitMap();
}

//�I������
void Game_Finalize()
{
}

//�X�V����
void Game_Update()
{
	timecount.UpdateTime(point);

	player.Update(player, map);

	for (int i = 0; i < SHOT; i++)
	{
		WEnemy.Update(player, shot[i], WenemyS, ENEMY_NOW, player.ScrollX, &timecount, WEnemy);

		SEnemy.Update(player, shot[i], SenemyS, SKY_ENEMY_NOW, player.ScrollX, &timecount, SEnemy);

		DEnemy.Update(player, shot[i], DenemyS, DISTANCE_ENEMY_NOW, player.ScrollX, &timecount, DEnemy, enemyshot,ENEMY_SHOT);
	}
	for (int j = 0; j < ENEMY_SHOT; j++)
	{
		DEnemy.EnemyShotUpdate(DenemyS, enemyshot[j], DISTANCE_ENEMY_NOW, player, player.ScrollX);
	}
	
	

	player.ShotUpdate(player, shot, SHOT);
	map.UpdateMap(player.ScrollX);

	//�v���C���[�����S�����
	if (player.HP <= 0)
	{
		SceneMgr_ChageScene(eScene_GameOver);//�V�[�����Q�[���I�[�o�[��ʂɕύX
	}
}

//�`�揈��
void Game_Draw()
{
	Back.Draw();

	timecount.DrawTime();
	point.DrawPoint(player.ScrollX);

	hp.PlayerHP(player);

	player.Draw();
	
	for (int i = 0; i < SHOT; i++)
	{
		player.DrawShot(shot[i]);
	}

	DEnemy.DrawShot(enemyshot,ENEMY_SHOT);

	for (int i = 0; i < ENEMY_NOW; i++)
	{
		WEnemy.Draw(player.ScrollX, WenemyS[i], point);
	}
	for (int i = 0; i < SKY_ENEMY_NOW; i++)
	{
		SEnemy.Draw(player.ScrollX, SenemyS[i], point);
	}
	for (int i = 0; i < DISTANCE_ENEMY_NOW; i++)
	{
		DEnemy.Draw(player.ScrollX, DenemyS[i], point);
	}

	for (int i = 0; i < SHOT; i++)
	{
		map.DrawMap(player.ScrollX, shot[i], player, WenemyS, SenemyS, DenemyS, enemyshot,ENEMY_SHOT);
	}

	
}
