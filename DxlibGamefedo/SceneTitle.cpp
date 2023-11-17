#include "SceneTitle.h"
#include "DxLib.h"

//�萔��`
namespace
{
	//�t�F�[�h�̑��x
	constexpr int kFadeSpeed = 4;

	//�t�F�[�h�C����̑҂�����
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
	//�t�F�[�h�̏�����
	m_fadeCount = 255;     //���S�Ƀt�F�[�h����������Ԃ���
	m_fadeSpeed = -kFadeSpeed;      //�t�F�[�h�C�������� -4:�t�F�[�h�C�� +4:�t�F�[�h 0:�҂�����
	m_waitFrame = 0;

	m_bgHandle[0] = LoadGraph("data/jon.jpg");
	m_bgHandle[1] = LoadGraph("data/oni.jpg");
	m_bgHandle[2] = LoadGraph("data/sauza-.jpg");

	//�ŏ��ɕ\������摜���w�肷��
	m_bgNo = 0;

}

void SceneTitle::Update()
{
	if (m_fadeSpeed == 0)
	{
		//�҂�����
		m_waitFrame++;
		if(m_waitFrame >= kWaitFrame)
		{
			//�t�F�[�h�A�E�g�ɑJ��
			m_fadeSpeed = kFadeSpeed;
		}
	}
	else if (m_fadeSpeed < 0)
	{
		//�t�F�[�h�C����
		m_fadeCount += m_fadeSpeed;
		if (m_fadeCount <= 0)
		{
			m_fadeCount = 0;
			//��莞�ԑ҂��ɑJ��
			m_fadeSpeed = 0;
			m_waitFrame = 0;     //�҂����ԏ�����
		}
	}
	else     //m_fadeSpeed > 0
	{  
		//�t�F�[�h�A�E�g��
		m_fadeCount = m_fadeSpeed;
		if (m_fadeCount >= 255)
		{
			//�摜��؂�ւ��ăt�F�[�h�C���ɑJ�ڂ���
			m_fadeSpeed = -kFadeSpeed;

			//�\������摜��ύX
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
	//�w�肳��Ă���摜��\������
	DrawGraph(0, 0, m_bgHandle[m_bgNo], false);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeCount);      //�����ȍ~�A�w�肵�������x�ŕ`�悷��
	DrawBox(0, 0, 640,480, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      //���Ƃ̐ݒ�ɖ߂��i�ʏ�̕s�����x�j

}

void SceneTitle::End()
{
	for (int i = 0; i < kBgNum; i++)
	{
		DeleteGraph(m_bgHandle[i]);
	}
}
