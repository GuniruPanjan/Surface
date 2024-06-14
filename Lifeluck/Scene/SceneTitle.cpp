#include "SceneTitle.h"
#include "SceneGame.h"

SceneTitle::SceneTitle():
	Pad(0)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
}

std::shared_ptr<SceneBase> SceneTitle::Update()
{

	//パッド入力所得
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//フェード開始
	fedo->Update();

	if (fedo->Start >= 255)
	{
		//Aボタンを押したら
		if (Pad & PAD_INPUT_1)
		{
			return std::make_shared<SceneGame>();
		}
	}

	return shared_from_this();  //自身のポインタを返す
}

void SceneTitle::Draw()
{
	DrawString(240, 300, "Title", 0xffffff);
}

void SceneTitle::End()
{
}
