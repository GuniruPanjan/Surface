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
	//���͂ŃV�[���J��
	if (CheckHitKeyAll())
	{
		return std::make_shared<SceneChoice>();
	}

	return shared_from_this();  //���g�̃|�C���^��Ԃ�
}

void SceneTitle::Draw()
{
	DrawString(200, 130, "Title", GetColor(255, 255, 255));

	DrawString(205, 230, "Push Any Button", GetColor(255, 255, 255));
}

void SceneTitle::End()
{
}
