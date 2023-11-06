#pragma once
class SceneResult
{
public:
	SceneResult();
	~SceneResult();

	void Init();
	void Update();
	void Draw();
	void End();

	bool isSceneEnd() const { return m_isSceneEnd; }

private:
	int m_gameoverHandle;


	bool m_isSceneEnd;
};

