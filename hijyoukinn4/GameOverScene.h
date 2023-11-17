#pragma once
#include "Scene.h"
class GameOverScene : public Scene
{
private:
	int handle_;
	int frame_;
	using UpdateFunc_t = void(GameOverScene::*)(Input&);
	using DrawFunc_t = void(GameOverScene::*)();

	UpdateFunc_t updateFunc_ = nullptr;
	DrawFunc_t drawFunc_ = nullptr;

	//çXêVä÷êî
	void FadeInUpdate(Input& input);
	void NormalUpdate(Input& input);
	void FadeOutUpdate(Input& input);

	void FadeDraw();
	void NormalDraw();
public:
	GameOverScene(SceneManager& mgr);
	void Update(Input& input);
	void Draw();
};

