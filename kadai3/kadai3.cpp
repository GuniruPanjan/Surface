#include "DxLib.h"
#include "player.h"
#include "Enemy.h"

#if false //ここからコメンゲーム開発

ゲーム開発中はDebug版、
発売されるゲームはRelease版

Debug版ではマクロとして       _DEBUG
Relase版ではマクロとして　　　NDEBUG
がそれぞれ定義されている

#ifdef DEBUG
//デバッグ版でのみ実行される
//座標を表示したり、ワンボタンでクリアしたりする機能を入れる
#else
//リリース版でのみ実行される
//あまりないかな

#endif

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(1);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);


	//プレイヤー関連の情報
	Player player;
	player.handle = LoadGraph("data/sukaihai.png");
	player.x = 320.0f;
	player.y = 240.0f;
	
	//敵関連の情報
	Enemy enemy[ENEMY_NUM];
	int Load = LoadGraph("data/huruhurubebi-.png");
	enemy[ENEMY_NUM].handle;
	enemy[ENEMY_NUM].x;
	enemy[ENEMY_NUM].y;
	enemy[ENEMY_NUM].moveX;
	enemy[ENEMY_NUM].moveY; 

	//敵の初期化
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].handle = Load;
		enemy[i].x = (float)(GetRand(640 - 40));
		enemy[i].y = (float)(GetRand(480 - 40));
		enemy[i].moveX = 2.0f;
		if (GetRand(1))	enemy[i].moveX *= -1.0f;
		enemy[i].moveY = 2.0f;
		if (GetRand(1))	enemy[i].moveY *= -1.0f;
		

	}

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//描画を行う前に画面をクリアする
		ClearDrawScreen();

		//update
		updatePlayer(&player);
		//敵のupdata
		updateAllEnemy(enemy);

		// draw
		drawPlayer(player);
		
		drawAllEnemy(enemy);
		
		//画面内の指定した座標に文字列を表示できる
		//DrawString(0, 0, "テスト", GetColor(255, 128, 0));

		//条件付きコンパイルを利用して
		//Debug版でのみ実行される処理を実装する

		//プレイヤーの座標表示
		DrawFormatString(8,8,GetColor(255,255,255),"Player(%f,%f)",player.x, player.y);
		

		// 画面が切り替わるのを待つ
		ScreenFlip();

	}


	DeleteGraph(player.handle);
	DeleteGraph(Load);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}