#include "SceneManager.h"

SceneManager::SceneManager():
	m_runScene(kSceneKindMain),
	m_title(),    //�N���X�̏��������́i�j�̒��ɃR���X�g���N�^�̈���������
	m_main(),     //����͂ǂ̃V�[�����R���X�g���N�^�ň�����v�����Ȃ��̂�
	m_result()    //m_title()�̂悤�ȏ������ł�OK
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	//����������
	//���s�������V�[���̏��������s��
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
	//�e�V�[���̍X�V���s��
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
