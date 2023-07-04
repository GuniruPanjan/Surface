#include "DxLib.h"
#include <cmath>

//円のデータ
typedef struct CircleData
{
	float x;
	float y;
	float radius;
	unsigned int color;
}CircleData;

//参照型
//プレイヤー操作を関数化
void updatePlayer(CircleData player)
{
	//ゲームの処理
	int mouseX;
	int mouseY;

	//マウスの位置を取得する
	GetMousePoint(&mouseX, &mouseY);
	player.x = (float)mouseX;
	player.y = (float)mouseY;
	
}

//円のデータを２つ渡して当たっているかいないかを判定する関数
bool isCollision(CircleData c0, CircleData c1)
{
	//当たり判定を取る

	float dx = c0.x - c1.x;
	float dy = c1.y - c1.y;
	float dist = sqrtf(dx * dx + dy * dy);
	//2半径の合計と距離を比較して当たりをとる
	if (dist < (c0.radius + c1.radius))
	{
		//当たっている
		return true;
	}
#if true
	    //当たっていない
	    return false;
#else
	//if(true)の場合trueを返す、そうではない場合falseを返す
	return (dist <= (c0.radius + c1.radius));

#endif

}

//円の描画
void drawCircle(CircleData data)
{
	DrawCircle(data.x, data.y, data.radius, data.color);
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

	//円のデータ
	CircleData circle;
	circle.x = 320.0f;
	circle.y = 240.0f;
	circle.radius = 32.0f;
	circle.color = GetColor(255, 255, 255);

	//プレイヤー
	CircleData player;
	player.x = 0.0f;
	player.y = 0.0f;
	player.radius = 16;
	player.color = GetColor(255, 255, 255);

	//ゲームループ
	while (ProcessMessage() != 1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();


		//描画を行う前に画面をクリアする

		ClearDrawScreen();

		//プレイヤーと円の描画
		drawCircle(player);
		drawCircle(circle);

		bool isCol = isCollision(player, circle);
		if (isCol)
		{
			//当たっている場合
			circle.color = GetColor(255, 0, 0);
		}
		else
		{
			//当たっていない場合
			circle.color = GetColor(255, 255, 255);
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