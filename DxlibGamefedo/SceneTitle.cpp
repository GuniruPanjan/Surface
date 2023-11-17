#include "SceneTitle.h"
#include "DxLib.h"

//定数定義
namespace
{
	//フェードの速度
	constexpr int kFadeSpeed = 4;

	//フェードイン後の待ち時間
	constexpr int kWaitFrame = 60;
}

SceneTitle::SceneTitle():
	m_bgNo(0),
	m_fadeCount(0),
	m_fadeSpeed(0),
	m_waitFrame(0)
{
	for (int i = 0; i < kBgNum; i++)
	{
		m_bgHandle[i] = -1;
	}
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	//フェードの初期化
	m_fadeCount = 255;     //完全にフェードしきった状態から
	m_fadeSpeed = -kFadeSpeed;      //フェードインさせる -4:フェードイン +4:フェード 0:待ち時間
	m_waitFrame = 0;

	m_bgHandle[0] = LoadGraph("data/jon.jpg");
	m_bgHandle[1] = LoadGraph("data/oni.jpg");
	m_bgHandle[2] = LoadGraph("data/sauza-.jpg");

	//最初に表示する画像を指定する
	m_bgNo = 0;

}

void SceneTitle::Update()
{
	if (m_fadeSpeed == 0)
	{
		//待ち時間
		m_waitFrame++;
		if(m_waitFrame >= kWaitFrame)
		{
			//フェードアウトに遷移
			m_fadeSpeed = kFadeSpeed;
		}
	}
	else if (m_fadeSpeed < 0)
	{
		//フェードイン中
		m_fadeCount += m_fadeSpeed;
		if (m_fadeCount <= 0)
		{
			m_fadeCount = 0;
			//一定時間待ちに遷移
			m_fadeSpeed = 0;
			m_waitFrame = 0;     //待ち時間初期化
		}
	}
	else     //m_fadeSpeed > 0
	{  
		//フェードアウト中
		m_fadeCount = m_fadeSpeed;
		if (m_fadeCount >= 255)
		{
			//画像を切り替えてフェードインに遷移する
			m_fadeSpeed = -kFadeSpeed;

			//表示する画像を変更
			m_bgNo++;
			if (m_bgNo >= kBgNum)
			{
				m_bgNo = 0;
			}
		}
	}

}

void SceneTitle::Draw()
{
	//指定されている画像を表示する
	DrawGraph(0, 0, m_bgHandle[m_bgNo], false);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeCount);      //ここ以降、指定した透明度で描画する
	DrawBox(0, 0, 640,480, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      //もとの設定に戻す（通常の不透明度）

}

void SceneTitle::End()
{
	for (int i = 0; i < kBgNum; i++)
	{
		DeleteGraph(m_bgHandle[i]);
	}
}
