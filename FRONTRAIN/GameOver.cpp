#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mimageHandle;  //画像ハンドル格納用変数

//初期化
void GameOver_Initialize()
{
	mimageHandle = LoadGraph("date/ゲームオーバー画面.jpg");  //画像のロード
}

//終了処理
void GameOver_Finalize()
{
	DeleteGraph(mimageHandle);   //画像の解放
}

//更新
void GameOver_Update()
{
	//Escキーが押されていたら
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
	{
		SceneMgr_ChageScene(eScene_Menu);//シーンをメニューに変更
	}
}

void GameOver_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);
	DrawString(0, 0, "ゲームオーバー画面です", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります", GetColor(255, 255, 255));
}
