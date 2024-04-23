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
	//“ü—Í‚ÅƒV[ƒ“‘JˆÚ
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneChoice>();
	}

	return std::shared_ptr<SceneBase>();
}



void SceneTitle::Draw()
{
}

void SceneTitle::End()
{
}
