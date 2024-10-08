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
}

std::shared_ptr<SceneBase> SceneTitle::Update()
{
	//入力でシーン遷移
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneChoice>();
	}

	return std::shared_ptr<SceneTitle>();
}



void SceneTitle::Draw()
{
}

void SceneTitle::End()
{
}
