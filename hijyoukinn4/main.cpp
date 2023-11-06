#include "DxLib.h"
#include "Application.h"
#include<Dxlib.h>


//シーン遷移について
//タイトル画面->ゲーム中->ゲームオーバー->最初に
//場面によって表示も入力に対する応答も変わる
//この一つ一つの場面の事を「シーン」といいます
//場面を切り替えられるようにしよう

//使うテクニックとしては「Stateパターン」というのを使う
//ポリモーフィズムをりようして、「現在のシーン」を次から次へ切り替えて遷移する
//今までシーンの切り替えをゲーム管理クラスや関数内のswitch文で切り替えてたかもしれないが
//ここではシーンが次のシーンへの切り替えを制御します

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//auto app = new Application();
	Application& application = Application::GetInstance();
	if (!application.Init())
	{

	}
	application.Run();
	Application& application2 = Application::GetInstance();

	//クラスを作ると
	//①暗黙のコンストラクタ&デストラクタが生成されている
	//②暗黙のコピーコンストラクタも生成されている

	//普通のコンストラクタ
	//クラス名();
	//コピーコンストラクタ
	//クラス名(const クラス名&);

	//演算子オーバーロードとは=+-*/を再定義するものです
	//戻り値 operator演算子(右辺値);

	//今回のように、オブジェクトからオブジェクトへの代入を禁止
	//したいなら、
	//void operator(const クラス名&);
	//をprivateに置くようにします

	//さらに、もっと徹底するなら

	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理


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