#include "DxLib.h"
#include "Map.h"
#include "Camera.h"
#include "Dice.h"
#include "Background.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウのサイズ変更
	int WindowSizeX, WindowSizeY;
	WindowSizeX = 1280;
	WindowSizeY = 960;

	SetWindowSize(WindowSizeX, WindowSizeY);

	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//マップを生成
	Map* map = new Map;

	//カメラを生成
	Camera* camera = new Camera;

	//ダイスを生成
	Dice* dice = new Dice;

	//背景を生成
	Background* Back = new Background;


	map->Init();
	camera->Init();
	dice->Init();


	SetDrawScreen(DX_SCREEN_BACK);

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		Back->Draw();

		//map->Draw();

		camera->Update();

		dice->Update();
		dice->Draw();
		

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