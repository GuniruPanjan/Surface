#include "DxLib.h"

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

	int handle = LoadGraph("日本国旗.jpg");
	int fadeAlpha = 255;  //不透明から始める
	int fadeSpeed = -1;   //透明度を高める

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		fadeAlpha += fadeSpeed;
		//0以下にならないようにする
		if (fadeAlpha < 0)
		{
			//完全にフェードインした
			fadeAlpha = 0;
			//次のフレームからはフェードアウト
			fadeSpeed = 1;
		}
		if (fadeAlpha > 255)
		{
			//完全にフェードアウト
			fadeAlpha = 255;
		}
		
		//DX_BLENDMODE_ALPHA: 半透明で表示したい
		//DX_BLENDMODE_ALPHAを指定している場合、
		//　　　　　　どれくらいの透明度で表示するか、を指定する
		//　　　　　　0:完全に透明   255:不透明
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(290, 240, handle, true);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		//SetDrawBlendModeで半透明にしたいと指定すると、
		//以降すべての物が同じ透明度で表示される
		DrawBox(0, 0, 640, 240, GetColor(255, 255, 0), true); //画面上半分を覆う四角

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
		DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, fadeSpeed);


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

	DeleteGraph(handle);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}