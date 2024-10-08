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
#include "SceneFedo.h"
#include "Save.h"
#include "Explanation.h"
#include "EnemyBase.h"

Player player;
HP hp;
Shot shot[SHOT];
Shield shield;
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
Explanation explanation;

SceneFedo scenefedo;

Save save;

EnemyBase Base;
EnemyLoadDate date;

bool Isflag = false;

int DistanceDown = -1;

//回復の描画処理
int Green = 0;
//Attackの描画処理
int Yello = 0;

//サウンド用格納変数
int SoundGame;

//SE用格納変数
int PlayerSEDead1, PlayerSEDead2;

//SEを一回鳴らす
bool SE;

//初期化
void Game_Initialize()
{
	Base.Init(date);

	Back.Init();


	point.InitPoint();
	hp.PlayerHPInit();
	player.Init(shield, player);

	player.InitShot(shot, player);

	DEnemy.EnemyShotInit(enemyshot, date);

	WEnemy.Init(WenemyS, WEnemy, ENEMY_NOW, date);

	for (int i = 0; i < SKY_ENEMY_NOW; i++)
	{
		SEnemy.Init(SenemyS[i], SEnemy, date);
	}
	for (int i = 0; i < DISTANCE_ENEMY_NOW; i++)
	{
		DEnemy.Init(DenemyS[i], DEnemy, date);
	}
	map.InitMap();

	scenefedo.Init();
	explanation.ExplanationInit();

	save.SaveInit();

	SoundGame = LoadSoundMem("BGM/戦闘bgm.m4a");

	PlayerSEDead1 = LoadSoundMem("SE/狙撃銃発射.mp3");

	PlayerSEDead2 = LoadSoundMem("SE/「ぐっ！」.mp3");

	SE = false;

	Green = 0;
	Yello = 0;
}

//終了処理
void Game_Finalize()
{
	Base.Finalize(date);

	player.FinalizePlayer(player, shot, shield);

	WEnemy.FinalizeWalkEnemy(WenemyS, ENEMY_NOW, date);

	map.FinalizeMap();
	for (int i = 0; i < SKY_ENEMY_NOW; i++)
	{
		SEnemy.FinalizeSky(SenemyS[i]);
	}
	for (int i = 0; i < DISTANCE_ENEMY_NOW; i++)
	{
		DEnemy.FinalizeDistanceEnemy(DenemyS[i]);
	}

	explanation.FinalizeExplanation();

	DeleteSoundMem(SoundGame);

	DeleteSoundMem(PlayerSEDead1);

	DeleteSoundMem(PlayerSEDead2);

	hp.FinalizeHP();

	DEnemy.FinalizeDistanceEnemyShot(enemyshot);

	Back.Finalize();

	save.FinalizeSave();

	scenefedo.FinalizeFedo();

	SetMouseDispFlag(TRUE);
}

//更新処理
void Game_Update()
{
	SetMouseDispFlag(FALSE);

	if (save.Start == false)
	{
		//ここで名前を決めるとゲームを実行
		scenefedo.UpdateIn();

		save.SaveInput();
	}
	else if (save.Start == true)
	{
		PlaySoundMem(SoundGame, DX_PLAYTYPE_LOOP, FALSE);

		if (scenefedo.LetGo == false)
		{
			scenefedo.a = 0;

			timecount.InitTime();

			scenefedo.LetGo = true;
		}
		if (scenefedo.LetGo == true)
		{
			scenefedo.UpdateIn();

			timecount.UpdateTime(point);

			point.UpdatePoint(player, static_cast<int>(player.ScrollX));

			player.Update(player, map, shield, Back);

			for (int i = 0; i < SHOT; i++)
			{
				WEnemy.Update(player, shot[i], WenemyS, ENEMY_NOW, player.ScrollX, &timecount, WEnemy);

				SEnemy.Update(player, shot[i], SenemyS, SKY_ENEMY_NOW, player.ScrollX, &timecount, SEnemy, shield);

				DEnemy.Update(player, shot[i], DenemyS, DISTANCE_ENEMY_NOW, player.ScrollX, &timecount, DEnemy, enemyshot, ENEMY_SHOT, shield);
			}
			for (int j = 0; j < ENEMY_SHOT; j++)
			{
				DEnemy.EnemyShotUpdate(DenemyS, enemyshot[j], DISTANCE_ENEMY_NOW, player, player.ScrollX, shield);
			}

			explanation.ExplanationUpdate();

			player.ShotUpdate(player, shot, SHOT);
			map.UpdateMap(static_cast<int>(player.ScrollX));
		}

	}

}

//描画処理
void Game_Draw()
{

	if (save.Start == true)
	{
		if (scenefedo.LetGo == true)
		{

			Back.Draw();

			timecount.DrawTime();
			point.DrawPoint(player, static_cast<int>(player.ScrollX));

			save.NameOutPut();

			hp.PlayerHP(player, Back, save, point, shot);

			player.Draw(shield, player);

			for (int i = 0; i < SHOT; i++)
			{

				player.DrawShot(shot[i]);

			}

			DEnemy.DrawShot(enemyshot, ENEMY_SHOT, static_cast<int>(player.ScrollX), player, shield);


			WEnemy.Draw(player.ScrollX, WenemyS, point, ENEMY_NOW, player, shot, &timecount);


			for (int i = 0; i < SKY_ENEMY_NOW; i++)
			{
				SEnemy.Draw(player.ScrollX, SenemyS[i], point);
			}
			for (int i = 0; i < DISTANCE_ENEMY_NOW; i++)
			{
				DEnemy.Draw(player.ScrollX, DenemyS[i], point, player, DistanceDown, shot, &timecount);
			}

			for (int i = 0; i < SHOT; i++)
			{
				map.DrawMap(static_cast<int>(player.ScrollX), shot[i], player, WenemyS, SenemyS, DenemyS, enemyshot, ENEMY_SHOT);
			}

			explanation.ExplanationDraw();

			//HPを回復すると描画する
			if (hp.PointHP == true)
			{
				Green = 120;

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Green);
				DrawBox(0, 0, 640, 480, GetColor(0, 255, 0), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, Green);

				hp.PointHP = false;
			}
			if (Green >= 0)
			{
				Green--;
			}
			//Attackを強化すると描画する
			if (hp.PointAttack == true)
			{
				Yello = 120;

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Yello);
				DrawBox(0, 0, 640, 480, GetColor(255, 255, 0), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, Yello);

				hp.PointAttack = false;
				
			}
			if (Yello >= 0)
			{
				Yello--;
			}
			//Yelloが0未満だとクリックできるようにする
			if (Yello <= 0)
			{
				hp.AttackClick = false;
			}

			//プレイヤーが死亡すると
			if (player.HP <= 0)
			{

				scenefedo.DeadAnim();

				scenefedo.WhiteOut();

				if (SE == false)
				{
					PlaySoundMem(PlayerSEDead2, DX_PLAYTYPE_BACK, TRUE);
					PlaySoundMem(PlayerSEDead1, DX_PLAYTYPE_BACK, TRUE);

					SE = true;
				}

				if (save.end == false)
				{
					save.SaveDate(point, timecount);

					save.end = true;
				}

				if (scenefedo.WhiteCount >= 300)
				{
					scenefedo.DeadOut();

					SceneMgr_ChageScene(eScene_GameOver);//シーンをゲームオーバー画面に変更

					DeleteSoundMem(SoundGame);
				}

			}

			//標準の画像描画
			DrawGraph(player.MouseX - 10, player.MouseY - 10, player.Aiming, true);
		}
	}
	
}
