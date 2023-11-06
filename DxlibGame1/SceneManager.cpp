#include "SceneManager.h"

SceneManager::SceneManager():
	m_runScene(kSceneKindMain),
	m_title(),    //クラスの初期化時は（）の中にコンストラクタの引数を書く
	m_main(),     //今回はどのシーンもコンストラクタで引数を要求しないので
	m_result()    //m_title()のような書き方でもOK
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	//初期化処理
	//実行したいシーンの初期化を行う
	switch (m_runScene)
	{
	case kSceneKindTitle:
	    m_title.Init();
		break;
	case kSceneKindMain:
		m_main.Init();
		break;
	case kSceneKindResult:
		m_result.Init();
		break;
	default:
		break;
	}
}

void SceneManager::Updete()
{
	//各シーンの更新を行う
	switch (m_runScene)
	{
	case kSceneKindTitle:
		m_title.Update();
		break;
	case kSceneKindMain:
		m_main.Update();
		break;
	case kSceneKindResult:
		m_result.Update();
		break;
	default:
		break;
	}
}

void SceneManager::Draw()
{
	switch (m_runScene)
	{
	case kSceneKindTitle:
		m_title.Draw();
		break;
	case kSceneKindMain:
		m_main.Draw();
		break;
	case kSceneKindResult:
		m_result.Draw();
		break;
	default:
		break;
	}
}

void SceneManager::End()
{
	switch (m_runScene)
	{
	case kSceneKindTitle:
		if (m_title.isSceneEnd())
		{
			m_title.End();

			m_runScene = kSceneKindMain;
			m_main.Init();
		}
		
		break;
	case kSceneKindMain:
		if (m_main.IsSceneEnd())
		{
			m_main.End();

			m_runScene = kSceneKindResult;
			m_result.Init();
		}
		
		break;
	case kSceneKindResult:
		if (m_result.isSceneEnd())
		{
			m_result.End();

			m_runScene = kSceneKindTitle;
			m_title.Init();
		}
		
		break;
	default:
		break;
	}
}
