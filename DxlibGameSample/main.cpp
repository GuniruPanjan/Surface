#include "DxLib.h"
#include "Enemy.h"
#include<cassert>

//定数定義
namespace
{
	//敵の数
	constexpr int kEnemyNum = 5;
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//グラフィックリソースのロード
	int enemyHandle = LoadGraph("data/ゲームキャラ２.png");
	assert(enemyHandle != -1);   //ファイルのロードに失敗すると止まる


	Enemy enemy[kEnemyNum]; //enemy[0] ~ enemy[kEnemyNum-1]が準備される

	for (int i = 0; i < kEnemyNum; i++)
	{
		enemy[i].Init();
		enemy[i].SetHandle(enemyHandle);
		enemy[i].SetStartPos();
	}
	
	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		for (int i = 0; i < kEnemyNum; i++)
		{
			enemy[i].Update();
			
		}

		for (int i = 0; i < kEnemyNum; i++)
		{
			enemy[i].Draw();
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

	//グラフィックリソースをメモリから解放
	DeleteGraph(enemyHandle);


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}