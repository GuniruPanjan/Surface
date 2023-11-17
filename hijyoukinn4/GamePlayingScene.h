#pragma once
#include "Scene.h"
class GamePlayingScene : public Scene
{
private:
	float fps_ = 0.0f;
	int handle_ = 0;
	int frame_ = 0;
	using UpdateFunc_t = void(GamePlayingScene::*)(Input&);
	using DrawFunc_t = void(GamePlayingScene::*)();

	UpdateFunc_t updateFunc_ = nullptr;
	DrawFunc_t drawFunc_ = nullptr;

	//çXêVä÷êî
	void FadeInUpdate(Input& input);
	void NormalUpdate(Input& input);
	void FadeOutUpdate(Input& input);

	void FadeDraw();
	void NormalDraw();
public:
	GamePlayingScene(SceneManager& mgr);
	void Update(Input& input);
	void Draw();
};

