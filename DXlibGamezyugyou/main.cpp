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

	//色の宣言
	const unsigned int kchageColor = GetColor(255, 0, 0);
	const unsigned int kdefalutColor = GetColor(200, 200, 200);
}

//プレイヤーと敵が当たっているかを判定する
//クラス、構造体を引数として渡す場合はポインタ、参照渡し推奨
//値渡しだ
bool isCollision(Player player, Enemy enemy)
{
	//判定に必要なプレイヤー情報の取得
	float playerPosX = (float)player.getPosX();
	float playerPosY = (float)player.getPosY();
	float playerRadius = (float)player.getRadius();

	//判定に必要な敵情報の取得
	float enemyPosX = (float)enemy.getPosX();
	float enemyPosY = (float)enemy.getPosY();
	float enemyRadius = (float)enemy.getRadius();

	//X座標
	float dx = playerPosX - enemyPosX;
	//Y座標
	float dy = playerPosY - enemyPosY;
	//三平方の定理を利用して距離を求めた
	float dist = sqrtf(dx * dx + dy * dy);
	if (dist < (playerRadius + enemyRadius))
	{
		//あたった
		return true;
	}
	return false;

}

//プレイヤーを座標を表示する関数
void dispPlayerPos(Player& player)
{
	int x = player.getPosX();
	int y = player.getPosY();
	DrawFormatString(8, 8, GetColor(255, 255, 255), "(%3d,%3d", x, y);
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
			float playerPosX = (float)player.getPosX();
			float playerPosY = (float)player.getPosY();
			float playerRadius = (float)player.getRadius();
		
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			//当たり判定
			float enemyPosX = (float)enemy[i].getPosX();
			float enemyPosY = (float)enemy[i].getPosY();
			float enemyRadius = (float)enemy[i].getRadius();

			float dx = playerPosX - enemyPosX;
			float dy = playerPosY - enemyPosY;
			float dist = sqrtf(dx * dx + dy * dy);

			
			if (dist <= (playerRadius + enemyRadius))
			{
				enemy[i].setColor(kchageColor);
					
			}
			else
			{
				enemy[i].setColor(kdefalutColor);
					
			}
			
			
		}

		//描画
		player.draw();
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			enemy[i].draw();
			
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