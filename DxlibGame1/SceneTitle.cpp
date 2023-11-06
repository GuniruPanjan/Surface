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
	//BGM�̓ǂݍ���
	m_bgmHndle = LoadSoundMem("data/Sound/30m.rarara.mp3");

	//BGM�̍Đ�
	PlaySoundMem(m_bgmHndle, DX_PLAYTYPE_LOOP);
	//�t�F�[�h�C�������邽�߉���0����n�߂�
	ChangeVolumeSoundMem(0, m_bgmHndle);

	m_isSceneEnd = false;
	//m_isScene = LoadGraph("data/neonn.png");
}

void SceneTitle::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_1)   //�p�b�h�̂P�{�^���@or�@�L�[�{�[�h��Z�L�[
	{
		//�^�C�g����ʂ��I������SceneMain�Ɉړ����鏈������������!
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

	//��ʂ̃t�F�[�h�l�𗘗p���ăT�E���h�̉��ʂ����肷��
	int volume = 255 - m_fadeAlpha;
	ChangeVolumeSoundMem(volume, m_bgmHndle);
}

void SceneTitle::Draw()
{
	DrawString(120, 120, "�^�C�g�����", GetColor(255, 255, 255));
	DrawString(120, 120+16, "�P�{�^���������Ăˁ�", GetColor(255, 255, 255));

	DrawGraph(0, 0, m_isScene, false);

	//�t�F�[�h�̕`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeAlpha);        //�������ŕ\���J�n
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeigth, GetColor(255, 255, 255), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      //�s�����ɂ��Ă���

}

void SceneTitle::End()
{
	//BGM���~�߂�
	StopSoundMem(m_bgmHndle);

	//BGM������������폜
	DeleteSoundMem(m_bgmHndle);
	DeleteGraph(m_isScene);
}

bool SceneTitle::isSceneEnd() const
{
	return m_isSceneEnd && (m_fadeAlpha >= 255);
}
