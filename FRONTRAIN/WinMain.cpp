#include "DxLib.h"
#include "GraphMode.h"
#include "SceneMgr.h"
#include "Font.h"
#include "icon/icon.h"
#include <cmath>
#include <memory>

//フォント変更する
Font font;

// プログラムは WinMain から始まります

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//Windowの名前を変更する
	SetWindowText("FRONT RAIN");
	SetWindowIconID(IDI_ICON1);    //ウィンドウアイコンの設定

	GraphMode graph;

	// 一部の関数はDxLib_Init()の前に実行する必要がある

	ChangeWindowMode(true);

	SetWindowSize(graph.GraphModeWIDTH, graph.GraphModeHEIGHT);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理

	{

		return -1;			// エラーが起きたら直ちに終了

	}

	

	SetDrawScreen(DX_SCREEN_BACK);


	font.FontInit();
	SceneMgr_Initialize();
	// ゲームループ

	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく

		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする

		ClearDrawScreen();

		// ゲームの処理

		SceneMgr_Update();  //更新
		SceneMgr_Draw();  //描画


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

	SceneMgr_Finalize();    //終了処理

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 

}