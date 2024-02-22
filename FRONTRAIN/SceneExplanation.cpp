#include "SceneExplanation.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneFedo.h"
#include "Rect.h"

SceneFedo Explanationfedo;

Rect m_ERect;
Rect m_EMouse;

static int ExplanationHandle;  //画像ハンドル格納用変数

static int Botton;    //ボタン画像格納用変数

static int b;    //画像透過用変数

// マウスの座標を取得するための変数
int EMouseX, EMouseY;

//マウスの当たり判定の幅
int ExplanationMouseDecisionX, ExplanationMouseDecisionY;

int EColor, EBlack, EYello;

bool EMenu;

//サウンド用格納変数
int SoundExplanation;

//SE用格納変数
int SEClickExplanation;

//画像を暗くする変数
int ExplanationDarken;

//元の画像の明るさ変数
int ExplanationFormer;

//初期化
void Explanation_Initialize()
{
	ExplanationHandle = LoadGraph("date/ゲーム画面.png"); //画像ロード

	EMouseX = 0;
	EMouseY = 0;

	Botton = LoadGraph("date/ボタン.png");

	b = 255;

	EColor = 0;
	EBlack = GetColor(0, 0, 0);
	EYello = GetColor(255, 255, 0);

	EMenu = false;

	SoundExplanation = LoadSoundMem("BGM/水面影絵.mp3");

	SEClickExplanation = LoadSoundMem("SE/決定ボタンを押す40.mp3");

	ExplanationMouseDecisionX = 10;
	ExplanationMouseDecisionY = 10;

	ExplanationDarken = 120;
	ExplanationFormer = 255;
}

//終了処理
void Explanation_Finalize()
{
	DeleteGraph(ExplanationHandle);//画像の解放

	DeleteSoundMem(SoundExplanation);

	DeleteSoundMem(SEClickExplanation);

	DeleteGraph(Botton);

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

		b = ExplanationDarken;

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

		b = ExplanationFormer;
	}

	PlaySoundMem(SoundExplanation, DX_PLAYTYPE_LOOP, FALSE);

}

//描画
void Explanation_Draw()
{
	DrawGraph(-93, 0, ExplanationHandle, TRUE);

	m_EMouse.SetCenter(static_cast<float>(EMouseX), static_cast<float>(EMouseY + 5), static_cast<float>(ExplanationMouseDecisionX), static_cast<float>(ExplanationMouseDecisionY));

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, b);
	DrawGraph(120, 395, Botton, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	m_ERect.SetCenter(180, 410, 120, 30);
	DrawString(135, 397, "タイトル", EColor);
}
