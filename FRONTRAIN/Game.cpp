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

//������
void Game_Initialize()
{
	Back.Init();

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

	for (int i = 0; i < ENEMY_NOW; i++)
	{
		WEnemy.Draw(player.ScrollX, WenemyS[i], point);
	}

	for (int i = 0; i < SHOT; i++)
	{
		map.DrawMap(player.ScrollX, shot[i], player, WenemyS);
	}

	
}
