#include "Explanation.h"
#include "DxLib.h"

Explanation::Explanation():
	UK(0),
	LK(0),
	RK(0),
	UnderKey(0),
	RightKey(0),
	LeftKey(0),
	LeftClick(0),
	RightClick(0),
	Mouse(0),
	Graph(0)
{
}

Explanation::~Explanation()
{
}

void Explanation::ExplanationInit()
{
	UK = 255;
	LK = 255;
	RK = 255;

	UnderKey = LoadGraph("date/UnderKey.png");
	LeftKey = LoadGraph("date/RightKey.png");
	RightKey = LoadGraph("date/LeftKey.png");

	LeftClick = LoadGraph("date/左クリック.png");
	RightClick = LoadGraph("date/右クリック.png");
	Mouse = LoadGraph("date/マウス.png");

	Graph = -1;

}

void Explanation::ExplanationUpdate()
{
	//下キーを押す
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		UK = 150;
	}
	//下キーを押してないとき
	else if (CheckHitKey(KEY_INPUT_DOWN) == false)
	{
		UK = 255;
	}
	//右キーを押す
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		RK = 150;
	}
	//右キーを押していない時
	else if (CheckHitKey(KEY_INPUT_RIGHT) == false)
	{
		RK = 255;
	}
	//左キーを押す
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		LK = 150;
	}
	//左キーを押していない時
	else if (CheckHitKey(KEY_INPUT_LEFT) == false)
	{
		LK = 255;
	}

	
	
	//左クリックしたとき
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		Graph = LeftClick;
	}
	//右クリックしたとき
	else if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		Graph = RightClick;
	}
	else
	{
		Graph = Mouse;
	}
	

}

void Explanation::ExplanationDraw()
{
	//下キー描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, UK);
	DrawGraph(515, 430, UnderKey, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, UK);

	DrawFormatString(518, 460, GetColor(255, 255, 255), "盾");

	//右キー描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, RK);
	DrawGraph(530, 400, RightKey, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, RK);

	DrawFormatString(560, 400, GetColor(255, 255, 255), "右移動");

	//左キー描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, LK);
	DrawGraph(500, 400, LeftKey, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, LK);

	DrawFormatString(430, 400, GetColor(255, 255, 255), "左移動");

	//マウス描画
	DrawGraph(150, 400, Graph, true);
	DrawFormatString(90, 410, GetColor(255, 255, 255), "ショット");
	DrawFormatString(200, 410, GetColor(255, 255, 255), "リロード");


}
