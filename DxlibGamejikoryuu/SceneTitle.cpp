#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneMgr.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
}

void SceneTitle::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_PAD1);
	if (pad & PAD_INPUT_1)
	{
		
	}
}

void SceneTitle::Draw()
{
	DrawString(0, 0, "スタート画面です。", GetColor(255, 255, 255));
	DrawString(0, 0, "1キーを押すとゲーム画面に進みます", GetColor(255, 255, 255));
}

void SceneTitle::End()
{
}
