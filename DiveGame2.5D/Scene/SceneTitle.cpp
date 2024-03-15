#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneSave.h"

SceneTitle::SceneTitle()
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
	//左クリックでシーン遷移
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		return std::make_shared<SceneSave>();
	}

	return shared_from_this();  //自身のshared_ptrを返す
}

void SceneTitle::Draw()
{
	DrawString(0, 0, "SceneTitle", 0xffffff);

	DrawFormatString(0, 16, 0xffffff,"左クリックだとSceneSave");

}

void SceneTitle::End()
{
}
