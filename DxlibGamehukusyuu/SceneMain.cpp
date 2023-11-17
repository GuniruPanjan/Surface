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
	m_player.SetFill(true);        //プレイヤーの矩形は塗りつぶす
	m_player.SetMouseTrase(true);  //プレイヤーの矩形はマウスに追従
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
		m_rect[i].Update();     //rectの毎フレームの更新処理
		if (m_player.IsCollision(m_rect[i]))
		{
			m_rect[i].SetColor(GetColor(255, 0, 0));
		}
		else
		{
			//当たっていない場合の処理
			m_rect[i].SetColor(GetColor(255, 255, 255));
		}
	}
}

void SceneMain::Draw()
{
	m_player.Draw();
	for (int i = 0; i < kRectNum; i++)
	{
		m_rect[i].Draw();       //rectの描画
	}
}
