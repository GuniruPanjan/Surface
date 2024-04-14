#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneChoice.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	//背景画像読み込み
	TitleSceneGraph = LoadGraph("date/スタート画面.png");
}

std::shared_ptr<SceneBase> SceneTitle::Update()
{
	//フェードさせる
	if (FeadColor >= 255)
	{
		FeadMinus = true;
		FeadPlus = false;
	}
	else if(FeadColor <= 0)
	{
		FeadPlus = true;
		FeadMinus = false;
	}

	if (FeadPlus == true)
	{
		FeadColor++;
	}
	else if (FeadMinus == true)
	{
		FeadColor--;
	}

	//入力でシーン遷移
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneChoice>();
	}

	return shared_from_this();
}

void SceneTitle::Draw()
{
	//背景画像描画
	DrawGraph(0, 0, TitleSceneGraph, true);

	DrawString(245, 230, "Push Any Button", GetColor(FeadColor, FeadColor, FeadColor));
}

void SceneTitle::End()
{
}
