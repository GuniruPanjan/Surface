#include "SceneSave.h"
#include "DxLib.h"
#include "SceneGame.h"

SceneSave::SceneSave():
	m_frameCount(0)
{
}

SceneSave::~SceneSave()
{
}

void SceneSave::Init()
{
}

std::shared_ptr<SceneBase> SceneSave::Update()
{
	m_frameCount++;
	if (m_frameCount >= 60)
	{
		return std::make_shared<SceneGame>();
	}

	return shared_from_this();  //é©êgÇÃshare_ptrÇï‘Ç∑
}

void SceneSave::Draw()
{
	DrawString(0, 0, "SceneSave", 0xffffff);

	DrawFormatString(0, 16, 0xffffff, "Frame%d", m_frameCount);
}

void SceneSave::End()
{
}
