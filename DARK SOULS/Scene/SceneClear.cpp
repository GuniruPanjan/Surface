#include "SceneClear.h"
#include "SceneTitle.h"

SceneClear::SceneClear():
	m_pad(0)
{
}

SceneClear::~SceneClear()
{
}

void SceneClear::Init()
{
}

std::shared_ptr<SceneBase> SceneClear::Update()
{
	//�p�b�h���͏���
	m_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//A�{�^����������
	if (m_pad & PAD_INPUT_1)
	{
		return std::make_shared<SceneTitle>();
	}

	return shared_from_this();  //���g�̃|�C���^��Ԃ�
}

void SceneClear::Draw()
{
	DrawString(240, 300, "Clear", 0xffffff);
}

void SceneClear::End()
{
}
