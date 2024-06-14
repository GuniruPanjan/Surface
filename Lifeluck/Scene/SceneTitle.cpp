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

	//�p�b�h���͏���
	Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�t�F�[�h�J�n
	fedo->Update();

	if (fedo->Start >= 255)
	{
		//A�{�^������������
		if (Pad & PAD_INPUT_1)
		{
			return std::make_shared<SceneGame>();
		}
	}

	return shared_from_this();  //���g�̃|�C���^��Ԃ�
}

void SceneTitle::Draw()
{
	DrawString(240, 300, "Title", 0xffffff);
}

void SceneTitle::End()
{
}
