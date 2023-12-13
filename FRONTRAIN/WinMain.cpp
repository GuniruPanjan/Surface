#include "Player.h"
#include "WalkEnemy.h"
#include "Background.h"
#include "DxLib.h"
#include "Map.h"
#include "GraphMode.h"
#include "TimeCount.h"
#include "Point.h"

// プログラムは WinMain から始まります

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{
	GraphMode graph;

	// 一部の関数はDxLib_Init()の前に実行する必要がある

	ChangeWindowMode(true);

	SetWindowSize(graph.GraphModeWIDTH, graph.GraphModeHEIGHT);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理

	{

		return -1;			// エラーが起きたら直ちに終了

	}

	

	SetDrawScreen(DX_SCREEN_BACK);

	Player player;
	Shot shot[SHOT];
	WalkEnemy WEnemy;
	WalkEnemyStruct WenemyS[ENEMY_NOW];
	Map map;
	Background Back;
	TimeCount timecount;
	Point point;

	int shotGraph = LoadGraph("date/銃弾.png");
	bool Isflag = false;

	

	timecount.InitTime();
	point.InitPoint();
	player.Init();
	for (int i = 0; i < SHOT; i++)
	{
		player.InitShot(shot[i],shotGraph);
	}

	for (int i = 0; i < ENEMY_NOW; i++)
	{
		WEnemy.Init(WenemyS[i], WEnemy);
	}

	
	

	map.InitMap();
	// ゲームループ

	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく

		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする

		ClearDrawScreen();

		// ゲームの処理

		Back.Draw();

		timecount.UpdateTime(point);

		player.Update(player, map);

		for (int i = 0; i < SHOT; i++)
		{
			WEnemy.Update(player, shot[i], WenemyS, ENEMY_NOW,player.ScrollX,&timecount,WEnemy);
		}

		player.ShotUpdate(player, shot, SHOT);
		map.UpdateMap(player.ScrollX);
		
		timecount.DrawTime();
		point.DrawPoint();
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
		

		

		// 画面が切り替わるのを待つ

		ScreenFlip();

		// escキーでゲーム終了

		if (CheckHitKey(KEY_INPUT_ESCAPE))

		{

			break;

		}

		// FPS60に固定する

		while (GetNowHiPerformanceCount() - start < 16667)

		{

			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ

		}

	}

	

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 

}