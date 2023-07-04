#include "DxLib.h"
#include "Circle.h"

namespace
{
	//クリックする〇の数
	constexpr int kCircleNum = 20;

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

	//ゲームのフレーム数計測
	int frameCount = 0;

	//〇をクリックした回数
	int clickCount = 0;

	Circle circle;
	circle.init();

	
	//ゲームループ
	while (ProcessMessage() != 1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();


		//描画を行う前に画面をクリアする

		ClearDrawScreen();

		//ゲームの処理
		if (clickCount < kCircleNum)    //ゲームが終わったら計測を止める
		{
			frameCount++;
		}

		
		circle.update();
		if (!circle.isExist())
		{
			//〇がクリックされて消えた回数
			clickCount++;
			if (clickCount >= kCircleNum)
			{
				//ゲーム終了
			}
			else
			{
				//〇がクリックされて消えていた場合の処理
				circle.init();
			}
			
		}

		//描画
		circle.draw();
		if (clickCount >= kCircleNum)
		{
			DrawString(320, 240, "ゲームクリア！", GetColor(255, 255, 0));
		}
		
		//プレイ時間表示
		//frameCountを時間に変換したい
		//秒に変換frameCount / 60
		//1/100秒単位に変換  frameCount / 60 * 100      
		int tempCount = frameCount * 100 / 60;   //1秒の場合100,2.5秒の場合250
		DrawFormatString(320, 480 - 16, GetColor(255, 255, 255)," %d.%02d",tempCount /100,tempCount % 100);


		//画面が切り替わるのを待つ
		ScreenFlip();

		//escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66ミリ秒経過するまで待つ
			
		}
	}

	DxLib_End();            //DXライブラリ使用
	

	return 0;				// ソフトの終了 
}