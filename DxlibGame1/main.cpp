#include "DxLib.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include<cassert>
#include<cmath>
#include "SceneManager.h" 
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"

namespace
{
	////列挙型でシーンを定義
	//enum SceneKind
	//{
	//	SceneKindTitle,
	//	SceneKindMain,
	//	SceneKindResult,
	//};
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	//画面のサイズ変更
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeigth, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//シーン
	SceneManager scene;
	scene.Init();

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		//描画を行う前に画面をクリアする
		ClearDrawScreen();

		//ゲームシーンの更新
		scene.Updete();
		//ゲームシーンの描画
		scene.Draw();
		

		//画面が切り替わるのを待つ
		ScreenFlip();

		//escキーでゲーム終了
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

	//実行していたシーンの終了
	scene.End();

/*
	SceneMain sceneMain;

	sceneMain.Init();
	
	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		sceneMain.Update();
		sceneMain.Draw();

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

	//メモリからグラフィックを削除する
	//DeleteGraph(sceneMain.);
	sceneMain.End();

	//SceneResultをここから始める
	SceneResult sceneResult;

	sceneResult.Init();

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		sceneResult.Update();
		sceneResult.Draw();

		// 画面が切り替わるのを待つ
		ScreenFlip();

		//シーンの終了
		if (sceneMain.IsSceneEnd())
		{
			break;
		}

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

	//シーンの終了処理
	sceneResult.End();
	*/

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}