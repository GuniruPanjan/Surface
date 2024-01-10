#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mimageHandle;   //画像ハンドル格納用変数

//初期化
void Config_Initialize()
{
	mimageHandle = LoadGraph("date/メニュー画面.jpg");//画像のロード
}

//終了処理
void Config_Finalize()
{
	DeleteGraph(mimageHandle);//画像の解放
}

//更新
void Config_Update()
{
	//SPACEキーが押されていたら
	if (CheckHitKey(KEY_INPUT_SPACE) != 0)
	{
		SceneMgr_ChageScene(eScene_Menu);//シーンをメニューに変更
	}
}

//描画
void Config_Draw()
{
	DrawGraph(0, 0, mimageHandle, false);
	DrawString(0, 0, "設定画面です", GetColor(255, 255, 255));
	DrawString(0, 20, "SPACEキーを押すとメニュー画面に戻ります", GetColor(255, 255, 255));
}
