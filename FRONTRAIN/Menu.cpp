#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Game.h"

static int mimageHandle;  //画像ハンドル格納用変数

bool ContinueInit; //コンテニューしたときに初期化する

//初期化
void Menu_Initialize()
{
	mimageHandle = LoadGraph("date/ホーム画面.jpg");    //画像ロード

	ContinueInit = true;
}

//終了処理
void Menu_Finalize()
{
	DeleteGraph(mimageHandle); //画像の解放
}

//更新
void Menu_Update()
{
	//ContinueInitがtrueなら1回実行する
	if (ContinueInit == true)
	{
		//ゲームシーンを初期化する
		Game_Initialize();
	}
	ContinueInit = false;
	

	//Aキーが押されていたら
	if (CheckHitKey(KEY_INPUT_A) != 0)
	{
		SceneMgr_ChageScene(eScene_Game);//シーンをゲーム画面に変更

		ContinueInit = true;
	}
	//Cキーが押されていたら
	if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		SceneMgr_ChageScene(eScene_Config);//シーンを設定画面に変更
	}
}

//描画
void Menu_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);
	DrawString(0, 0, "メニュー画面です", GetColor(255, 255, 255));
	DrawString(0, 20, "Aキーを押すとゲーム画面に進みます", GetColor(255, 255, 255));
	DrawString(0, 40, "Cキーを押すと設定画面に進みます", GetColor(255, 255, 255));

}
