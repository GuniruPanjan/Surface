#include "SceneGoal.h"
#include "DxLib.h"
#include "SceneChoice.h"

SceneGoal::SceneGoal()
{
}

SceneGoal::~SceneGoal()
{
}

void SceneGoal::Init()
{
	GoalSceneGraph = LoadGraph("date/クリア画面.png");
}

std::shared_ptr<SceneBase> SceneGoal::Update()
{

	//エンタキー入力でシーン遷移
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		return std::make_shared<SceneChoice>();
	}

	return shared_from_this();
}

void SceneGoal::Draw()
{
	//背景画面を描画する
	DrawGraph(0, 0, GoalSceneGraph, true);

	DrawString(245, 230, "選択画面に戻る", GetColor(0, 0, 0));
}

void SceneGoal::End()
{
	DeleteGraph(GoalSceneGraph);
}
