#include "SceneMgr.h"
#include "DxLib.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneTitle.h"

namespace
{
	static int m_Scene = m_Scene_NUM;
	static int t_Scene = m_Scene_NONE;
}

SceneMgr::SceneMgr()
{
}

SceneMgr::~SceneMgr()
{
}

void SceneMgr::Init()
{
	scene;
}