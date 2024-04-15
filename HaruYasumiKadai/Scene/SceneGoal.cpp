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
	GoalSceneGraph = LoadGraph("date/�N���A���.png");
}

std::shared_ptr<SceneBase> SceneGoal::Update()
{

	//�G���^�L�[���͂ŃV�[���J��
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		return std::make_shared<SceneChoice>();
	}

	return shared_from_this();
}

void SceneGoal::Draw()
{
	//�w�i��ʂ�`�悷��
	DrawGraph(0, 0, GoalSceneGraph, true);

	DrawString(245, 230, "�I����ʂɖ߂�", GetColor(0, 0, 0));
}

void SceneGoal::End()
{
	DeleteGraph(GoalSceneGraph);
}
