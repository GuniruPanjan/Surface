#pragma once
class SceneTitle
{
public:
	SceneTitle();
	~SceneTitle();

	void Init();
	void Update();
	void Draw();
	void End();

private:
	static const int kBgNum = 3;


private:

	int m_bgHandle[kBgNum];  //bg -> background

	int m_bgNo;

	int m_fadeCount;  //�t�F�[�h�x�����@0�F�s�����A�t�F�[�h�C������������ԁi�Q�[����ʂ������Ă���j
	                  //�@�@�@�@�@�@�@�@255�F�s�����A�t�F�[�h�A�E�g����������ԁi�^���Áj
	int m_fadeSpeed;  //�t�F�[�h���x
	int m_waitFrame;  //�t�F�[�h�C������������̑҂�����

};

