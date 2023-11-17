#include "DxLib.h"
#include <cmath>

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

	// ゲームループ
	float angle = 0.0f;

	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();


		// ゲームの処理
		constexpr int kCenterX = 320;
		constexpr int kCenterY = 240;
		constexpr float kBarLen = 100;

		//中心点
		DrawCircle(320, 240, 2, GetColor(255, 255, 255), true);
		//半径kBarLenの円
		DrawCircle(kCenterX, kCenterY, kBarLen, GetColor(255, 255, 255), false);

		angle += 0.01f;

		
		//中心から真上方向に直線を引く
		DrawLine(kCenterX, kCenterY, kCenterX, kCenterY - kBarLen, GetColor(255, 255, 255));

		//Θ度の方向に直線を引くには？
		constexpr float kAngle = 60.0f; //kAngle度の方向に長さkBarLenの直線を引きたい
		//そもそもkAngle度とは何の角度?
		//今回は真右方向を0度とし、反時計周りにkAngleの方向に伸ばしたい

		float offsetX = cosf(angle) * kBarLen;
		float offsetY = sinf(angle) * kBarLen;

		//中心からkAngle度の方向にkBarLen長さの線を引く
		DrawLine(kCenterX, kCenterY, kCenterX + offsetX, kCenterY - offsetY, GetColor(255, 255, 255));


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