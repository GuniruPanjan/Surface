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
	//”wŒi‰æ‘œ“Ç‚İ‚İ
	TitleSceneGraph = LoadGraph("date/ƒXƒ^[ƒg‰æ–Ê.png");
}

std::shared_ptr<SceneBase> SceneTitle::Update()
{
	//ƒtƒF[ƒh‚³‚¹‚é
	if (FeadColor >= 255)
	{
		FeadMinus = true;
		FeadPlus = false;
	}
	else if (FeadColor <= 0)
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

	//“ü—Í‚ÅƒV[ƒ“‘JˆÚ
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneChoice>();
	}

	return shared_from_this();
}

void SceneTitle::Draw()
{
	//”wŒi‰æ‘œ•`‰æ
	DrawGraph(0, 0, TitleSceneGraph, true);

	SetFontSize(40);

	DrawString(200, 130, "t‹x‚İ‰Û‘è", GetColor(255, 0, 0));

	SetFontSize(25);

	DrawString(205, 230, "Push Any Button", GetColor(FeadColor, FeadColor, FeadColor));
}

void SceneTitle::End()
{
}