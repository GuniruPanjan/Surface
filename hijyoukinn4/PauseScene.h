#pragma once
#include "Scene.h"

class Input;
class SceneManager;

class PauseScene :public Scene
{
private:
	int frame_ = 0;
	//更新メンバ関数ポインタ
	using UpdateFunc_t = void(PauseScene::*)(Input& input);
	UpdateFunc_t updateFunc_;
	//描画メンバ関数ポインタ
	using DrawFunc_t = void(PauseScene::*)();
	DrawFunc_t drawFunc_;

	//更新関数
	void AppearInupdate(Input&); //フェードイン状態
	void NoramalUpdate(Input& input);           //通常状態
	void DisappearUpdate(Input&);   //退場状態

	void FadeOutDraw(Input&);//フェードアウト状態

	//描画関数
	void FadeDraw();//拡張縮小描画
	void NormalDraw();//通常描画
public:
	PauseScene(SceneManager& manager);
	void Update(Input& input);
	void Draw();
};

