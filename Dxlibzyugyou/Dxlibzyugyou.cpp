#include "DxLib.h"
#include <cmath>

//当たり判定を取る円の数
#define CIRCLE_NUM 3
//円のデータを構造体にまとめる
typedef struct CircleData
{
	//メンバをここに書く
	float x;//X座標
	float y;//Y座標
	float radius;//半径
	unsigned int color;//色
}CircleData;

//円のデータを2つ渡して当たっているか当たっていないかを判定する関数
bool isCollision(CircleData c0, CircleData c1)
{
	//当たり判定をとる

		//1.判定を取りたい各円の中心の距離を求める
		//x座標の距離 (c0.x - c1.x)      2乗するので絶対値はとらなくてもいい
		//y座標の距離 (c0.y - c1.y)
	float dx = c0.x - c1.x;
	float dy = c0.y - c1.y;
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
	//であればそのままif文の条件文の中身を返せば良いのでは
	return (dist <= (c0.radius + c1.radius));

#endif
	
}

//円の描画
void drawCircle(CircleData data)
{
	DrawCircle(data.x, data.y, data.radius, data.color);
}

//参照型の復習
//プレイヤーを動かすのを関数化
//関数内でマウスカーソルの位置を取り、引数として渡されたCircleDataの座標に設定する
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
	CircleData circle[CIRCLE_NUM]; //配列に
	//円のデータの初期化
	for (int i = 0; i < CIRCLE_NUM; i++)
	{

	circle[i].x = 160.0f * (i+1);
	circle[i].y = 240.0f;
	circle[i].radius = 32.0f;
	circle[i].color = GetColor(255, 255, 255);

	}

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

		

		



		//DrawCircle(mouseX, mouseY, 8, GetColor(255, 255, 255), true);

		drawCircle(player);
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
			drawCircle(circle[i]);
		}

		//DrawCircle(320, 240, 32, GetColor(255, 255, 0),true);

		for (int i = 0; i < CIRCLE_NUM; i++)
		{


			bool isCol = isCollision(player, circle[i]);

			if (isCol)
			{
				//当たっている場合
				circle[i].color = GetColor(255, 0, 0);
			}
			else
			{
				//当たっていない場合
				circle[i].color = GetColor(255, 255, 255);
			}
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