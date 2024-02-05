#include "SceneExplanation.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Rect.h"

SceneFedo Explanationfedo;

Rect m_ERect;
Rect m_EMouse;

static int ExplanationHandle;  //画像ハンドル格納用変数

// マウスの座標を取得するための変数
int EMouseX, EMouseY;

int EColor, EBlack, EYello;

bool EMenu;

//サウンド用格納変数
int SoundExplanation;

//SE用格納変数
int SEClickExplanation;

//初期化
void Explanation_Initialize()
{
	ExplanationHandle = LoadGraph("date/説明書.png"); //画像ロード

	EMouseX = 0;
	EMouseY = 0;

	EColor = 0;
	EBlack = GetColor(0, 0, 0);
	EYello = GetColor(255, 255, 0);

	EMenu = false;

	SoundExplanation = LoadSoundMem("BGM/水面影絵.mp3");

	SEClickExplanation = LoadSoundMem("SE/決定ボタンを押す40.mp3");
}

//終了処理
void Explanation_Finalize()
{
	DeleteGraph(ExplanationHandle);//画像の解放

	DeleteSoundMem(SoundExplanation);

	DeleteSoundMem(SEClickExplanation);

	Explanationfedo.FinalizeFedo();
}

//更新
void Explanation_Update()
{
	Explanationfedo.UpdateInSetting();

	//Zキーが押されていたら
	//if (CheckHitKey(KEY_INPUT_Z) != 0)
	if(EMenu == true)
	{

		SceneMgr_ChageScene(eScene_Menu); //シーンをメニュー画面に変更

	}

	//マウスの座標取得
	GetMousePoint(&EMouseX, &EMouseY);

	if (m_ERect.IsCollision(m_EMouse) == true)
	{
		EColor = EYello;

		//左クリックを押したとき
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			EMenu = true;

			PlaySoundMem(SEClickExplanation, DX_PLAYTYPE_BACK, FALSE);
		}

	}
	else if (m_ERect.IsCollision(m_EMouse) == false)
	{
		EColor = EBlack;
	}

	PlaySoundMem(SoundExplanation, DX_PLAYTYPE_LOOP, FALSE);

}

//描画
void Explanation_Draw()
{
	DrawGraph(0, 0, ExplanationHandle, TRUE);

	m_EMouse.SetCenter(EMouseX, EMouseY + 5, 10, 10);

	m_ERect.SetCenter(200, 410, 150, 30);
	DrawString(130, 400, "メニュー画面", EColor);

	/*m_ERect.Draw(GetColor(255, 0, 0), false);
	m_EMouse.Draw(GetColor(255, 0, 0), false);*/
}
