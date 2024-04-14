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
	//”wŒi‰æ‘œ‚ğ“Ç‚İ‚Ş
	ChoiceSceneGraph = LoadGraph("date/‘I‘ğ‰æ‘œ.png");

	//‰Šú‰»ˆ—
	X = 320;
	Y = 240;
}

std::shared_ptr<SceneBase> SceneChoice::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		return std::make_shared<SceneGame>();
	}

	return shared_from_this(); //©g‚Ìshare_ptr‚ğ•Ô‚·
}

void SceneChoice::Draw()
{
	//”wŒi‰æ‘œ•`‰æ
	DrawGraph(0, 0, ChoiceSceneGraph, true);

	DrawCircle(X - 15, Y + 7, 8, GetColor(255, 255, 255), true);

	DrawString(0, 0, "SceneChoice", 0xffffff);

	DrawString(X, Y, "STAGE 1", 0xffffff);
}

void SceneChoice::End()
{
}
