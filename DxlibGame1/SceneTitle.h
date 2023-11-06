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

	bool isSceneEnd() const;

private:
	bool m_isSceneEnd;

	int m_isScene;

	int m_bgmHndle;

	//�t�F�[�h�C���A�A�E�g
	int m_fadeAlpha;
};

