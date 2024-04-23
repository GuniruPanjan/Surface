#include "SceneChoice.h"
#include "SceneGame.h"
#include "DxLib.h"

SceneChoice::SceneChoice():
	m_frame(0)
{
}

SceneChoice::~SceneChoice()
{
}

void SceneChoice::Init()
{
	m_frame = 0.0f;
}

std::shared_ptr<SceneBase> SceneChoice::Update()
{
	m_frame++;

	if (m_frame >= 60)
	{
		return std::make_shared<SceneGame>();
	}


	return std::shared_ptr<SceneChoice>();
}

void SceneChoice::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", m_frame);
}

void SceneChoice::End()
{
}
