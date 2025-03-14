#include "SceneChoice.h"
#include "DxLib.h"
#include "SceneGame.h"

SceneChoice::SceneChoice():
	X(0),
	Y(0)
{
}

SceneChoice::~SceneChoice()
{
}

void SceneChoice::Init()
{
	//wiζπΗέή
	ChoiceSceneGraph = LoadGraph("date/Iπζ.png");

	//ϊ»
	X = 320;
	Y = 240;
}

std::shared_ptr<SceneBase> SceneChoice::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		return std::make_shared<SceneGame>();
	}

	return shared_from_this(); //©gΜshare_ptrπΤ·
}

void SceneChoice::Draw()
{
	//wiζ`ζ
	DrawGraph(0, 0, ChoiceSceneGraph, true);

	DrawCircle(X - 15, Y + 7, 8, GetColor(255, 255, 255), true);

	DrawString(0, 0, "SceneChoice", 0xffffff);

	DrawString(X, Y, "STAGE 1", 0xffffff);
}

void SceneChoice::End()
{
}
