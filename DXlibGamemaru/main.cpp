#include "DxLib.h"
#include "player.h"
#include "enemy.h"
#include<cmath>

#define CIRCLE_NUM 3

namespace
{
	//敵の数

	//敵の位置情報
	constexpr int kEnemyIntervalX = 160;
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

	//プレイヤー
	Player player;
	player.init();

	//敵
	Enemy enemy[CIRCLE_NUM];
	for (int i = 0; i < CIRCLE_NUM; i++)
	{
		enemy[i].init();
		enemy[i].setPosX(kEnemyIntervalX * (i + 1));
	}
	

	
	//ゲームループ
	while (ProcessMessage() != 1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();


		//描画を行う前に画面をクリアする

		ClearDrawScreen();

		//ゲームの処理
		player.update();
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			enemy[i].update();
		}
		
		//当たり判定
		int playerPosX = (float)player.getPosX();
		int playerPosY = (float)player.getPosY();
		int enemyPosX = (float)enemy[0].getPosX();
		int enemyPosY = (float)enemy[0].getPosY();
		
		float playerRadius = (float)player.getRadius();
		float enemyRadius = (float)enemy[0].getRadius();

		float dx = enemyPosX - playerPosX;
		float dy = enemyPosY - playerPosY;
		float dist = sqrtf(dx * dx + dy * dy);

		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			if (dist < (playerRadius + enemyRadius))
			{
				enemy[i].getDraw();
				
			}
			else
			{

				enemy[i].draw();
				
			}

		}

		//描画
		player.draw();
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			enemy[i].draw();
			enemy[i].setPosX(kEnemyIntervalX * (i + 1));
		}
		
		
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