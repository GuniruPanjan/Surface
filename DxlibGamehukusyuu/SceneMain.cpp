#include "SceneMain.h"
#include "DxLib.h"

SceneMain::SceneMain()
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	m_player.Init();
	m_player.SetFill(true);        //�v���C���[�̋�`�͓h��Ԃ�
	m_player.SetMouseTrase(true);  //�v���C���[�̋�`�̓}�E�X�ɒǏ]
	for (int i = 0; i < kRectNum; i++)
	{
		m_rect[i].Init();
		m_rect[i].SetRandom();
	}
}

void SceneMain::Update()
{
	m_player.Update();
	for (int i = 0; i < kRectNum; i++)
	{
		m_rect[i].Update();     //rect�̖��t���[���̍X�V����
		if (m_player.IsCollision(m_rect[i]))
		{
			m_rect[i].SetColor(GetColor(255, 0, 0));
		}
		else
		{
			//�������Ă��Ȃ��ꍇ�̏���
			m_rect[i].SetColor(GetColor(255, 255, 255));
		}
	}
}

void SceneMain::Draw()
{
	m_player.Draw();
	for (int i = 0; i < kRectNum; i++)
	{
		m_rect[i].Draw();       //rect�̕`��
	}
}
