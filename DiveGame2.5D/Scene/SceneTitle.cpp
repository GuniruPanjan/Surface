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
	//���N���b�N�ŃV�[���J��
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		return std::make_shared<SceneSave>();
	}

	return shared_from_this();  //���g��shared_ptr��Ԃ�
}

void SceneTitle::Draw()
{
	DrawString(0, 0, "SceneTitle", 0xffffff);

	DrawFormatString(0, 16, 0xffffff,"���N���b�N����SceneSave");

}

void SceneTitle::End()
{
}
