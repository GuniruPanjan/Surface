#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
	
	for (int i = 1; i <= 10; i++)
	{
		DrawLine(64 * i, 0, 640, 48 * i, GetColor(255, 0, 0));
		
		DrawLine(0, 48 * 1, 640 - (64 * 1), 480, GetColor(255, 0, 0));
	}
	

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}