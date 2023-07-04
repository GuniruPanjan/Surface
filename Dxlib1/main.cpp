#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//グラフィックデータのメモリに読み込む
	//読み込んだデータを使いたい場合はこの番号を指定してくれ、
	//という数字を返してくれる（ハンドルと呼ばれる）
	//このハンドルを使用して表示するグラフィックを指定する
	int handle = LoadGraph("友達.jpg");

	//読み込んだグラフィックを表示する
	DrawGraph(0, 0, handle, 1);

	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
	DrawLine(0, 120, 640, 120, GetColor(255, 0, 0));
	DrawLine(0, 240, 640, 240, GetColor(0, 255, 0));
	DrawLine(0, 360, 640, 360, GetColor(0, 0, 255));
	DrawLine(0, 0, 640, 120, GetColor(255, 255, 0));
	DrawLine(0, 240, 640, 120, GetColor(255, 0, 255));
	DrawLine(0, 240, 640, 360, GetColor(0, 255, 255));
	WaitKey();				// キー入力待ち

	//メモリ上からグラフィックデータを削除する
	//これ以降使わない、という状態になったら必ず削除する
	DeleteGraph(handle);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}