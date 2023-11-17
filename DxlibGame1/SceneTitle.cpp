#include "SceneTitle.h"
#include "DxLib.h"
#include "Game.h"
#include "SceneManager.h"

SceneTitle::SceneTitle():
	m_isSceneEnd(false),
	m_isScene(-1),
	m_fadeAlpha(255)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	//BGMの読み込み
	m_bgmHndle = LoadSoundMem("data/Sound/30m.rarara.mp3");

	//BGMの再生
	PlaySoundMem(m_bgmHndle, DX_PLAYTYPE_LOOP);
	//フェードインさせるため音量0から始める
	ChangeVolumeSoundMem(0, m_bgmHndle);

	m_isSceneEnd = false;
	//m_isScene = LoadGraph("data/neonn.png");
}

void SceneTitle::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_1)   //パッドの１ボタン　or　キーボードのZキー
	{
		//タイトル画面を終了してSceneMainに移動する処理を書きたい!
		m_isSceneEnd = true;

	}

	if (m_isSceneEnd)
	{
		m_fadeAlpha += 5;
		if (m_fadeAlpha > 255)
		{
			m_fadeAlpha = 255;
		}
	}
	else
	{
		m_fadeAlpha -= 5;
		if (m_fadeAlpha < 0)
		{
			m_fadeAlpha = 0;
		}
	}

	//画面のフェード値を利用してサウンドの音量を決定する
	int volume = 255 - m_fadeAlpha;
	ChangeVolumeSoundMem(volume, m_bgmHndle);
}

void SceneTitle::Draw()
{
	DrawString(120, 120, "タイトル画面", GetColor(255, 255, 255));
	DrawString(120, 120+16, "１ボタンを押してね★", GetColor(255, 255, 255));

	DrawGraph(0, 0, m_isScene, false);

	//フェードの描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeAlpha);        //半透明で表示開始
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeigth, GetColor(255, 255, 255), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      //不透明にしておく

}

void SceneTitle::End()
{
	//BGMを止める
	StopSoundMem(m_bgmHndle);

	//BGMをメモリから削除
	DeleteSoundMem(m_bgmHndle);
	DeleteGraph(m_isScene);
}

bool SceneTitle::isSceneEnd() const
{
	return m_isSceneEnd && (m_fadeAlpha >= 255);
}
