#include "DxLib.h"
#include <cmath>
#include "Scene/SceneManager.h"
#include<memory>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// windowモード設定
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	//シーンを管理するポインタ
	std::shared_ptr<SceneManager> pScene = std::make_shared<SceneManager>();

	pScene->Init();

	while (ProcessMessage() != -1)
	{
		LONGLONG  time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();

		//ゲームの処理
		pScene->Update();

		//ゲームの描画
		pScene->Draw();

		//裏画面を表画面を入れ替える
		ScreenFlip();

		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}
	pScene->End();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}