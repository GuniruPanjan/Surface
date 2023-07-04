#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(1);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//表画面ではなく、裏画面に描画する
	SetDrawScreen(DX_SCREEN_BACK);

	//円の表示位置
	int posX = 320;
	//円の移動方向
	int moveX = 5;   //右方向に移動させる

	//グラフィックデータをメモリに読み込む
	//※whileループ内で読み込まないように気をつける
	//whileループ内で読み込んでしまうと1秒間に60回グラフィックを読み込んでしまう
	int playerHandle = LoadGraph("グラフィックデータ/sukaihai.png");     //vcxprojと同じフォルダにある画像を読み込む
	                               //dataフォルダに入れたのでvcxprojからの相対パスを指定する 
	
	//プレイヤーの表示位置を変数で持つ
	int playerX = 320;
	int playerY = 240;

	//プレイヤーの移動量
	int playerMoveY = 4;

	//ゲームを終了しない限り常にゲームの処理は行われる(１秒間に６０回処理が行われる)
	while(ProcessMessage() != -1)   //windowsが画面を閉じろと言わない限り繰り返す
	{

		//描画を行う前に画面をクリアする
		ClearDrawScreen();

		///////////////////////////
		//移動処理
		///////////////////////////

		//円の位置を変更する
		posX += moveX;       //moveXは+4もしくは、-4にしかならない
		//画面端まで行ったら進行方向を変える
		if (posX >= 640)   //円の中心が画面右端よりも右に行った場合
		{
			posX = 640;    //画面外に出ていたら画面内に戻す
			moveX = -5;    //右に移動していたのを左に移動させたいので移動方向を変更
		}
		if (posX < 0)      //画面左端より左にでた場合
		{
			posX = 0;      //画面内に戻す
			moveX = 5;     //右に移動させたい
		}
		//コントローラー（キーボード）でキャラクターを移動させる

		//GetJoypadInputState()を使用して
		//padStateにパッドの押されている状態を取得する
		int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if ((padState & PAD_INPUT_UP) != 0)
		{
			//押されている
			playerY -= 4;
			if (playerY < 0)
			{
				playerY = 0;
			}
		}
		
		if ((padState & PAD_INPUT_DOWN) != 0)
		{
			//押されている
			playerY += 4;
			if (playerY >= 320)
			{
				playerY = 320;
			}
		}
		
		if ((padState & PAD_INPUT_LEFT) != 0)
		{
			playerX -= 4;
			if (playerX < 0)
			{
				playerX = 0;
			}
		}
		
		if ((padState & PAD_INPUT_RIGHT) != 0)
		{
			playerX += 4;
			if (playerX >= 480)
			{
				playerX = 480;
			}
		}
		//Zキー入力
		if ((padState & PAD_INPUT_1) != 0)
		{
			playerY -= 2;
			playerX -= 2;
			if (playerY < 0)
			{
				playerY = 0;
			}
			if (playerX < 0)
			{
				playerX = 0;
			}
			
		}
		//Xキー入力
		if ((padState & PAD_INPUT_2) != 0)
		{
			playerY += 2;
			playerX += 2;
			if (playerY >= 320)
			{
				playerY = 320;
			}
			if (playerX >= 480)
			{
				playerX = 480;
			}
		}
		//Cキー入力
		if ((padState & PAD_INPUT_3) != 0)
		{
			playerY += 2;
			playerX -= 2;
			if (playerY >= 320)
			{
				playerY = 320;
			}
			if (playerX < 0)
			{
				playerX = 0;
			}
		}
		//Aキー入力
		if ((padState & PAD_INPUT_4) != 0)
		{
			playerY -= 2;
			playerX += 2;
			if (playerY < 0)
			{
				playerY = 0;
			}
			if (playerX >= 480)
			{
				playerX = 480;
			}
		}


		

		/*プレイヤーキャラの移動コード
		//プレイヤーの移動処理　上下に移動させる
		playerY += playerMoveY;    //プレイヤーの移動
		if (playerY > 320)         //画面下端よりも下にいった場合の処理
		{
			playerY = 320;
			playerMoveY = -4;
		}
		if (playerY < 0)
		{
			playerY = 0;
			playerMoveY = 4;
		}
		*/
		///////////////////////////
		//描画処理
		///////////////////////////

		//円を右に動かしたい！
		DrawCircle(posX, 240, 40, GetColor(255, 0, 0), 1);

		//読み込んだグラフィックデータを描画する
		DrawGraph(playerX, playerY, playerHandle, 1);

		
		//画面が切り替わるのを待つ
		ScreenFlip();

		//ゲームを終了する、を選択したとき
		if (0) break;
	}
	
	// 読み込んだグラフィックデータをメモリから開放する
	DeleteGraph(playerHandle);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}