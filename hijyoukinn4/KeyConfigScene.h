#pragma once
#include "Scene.h"
#include<unordered_map>
class KeyConfigScene:public Scene
{
private:
	int frame_ = 0;
	Input& input_; //inputクラスの参照
	InputTable_t keyCommandList_;
	//更新メンバ関数ポインタ
	using UpdateFunc_t = void(KeyConfigScene::*)(Input& input);
	UpdateFunc_t updateFunc_;
	//描画メンバ関数ポインタ
	using DrawFunc_t = void(KeyConfigScene::*)();
	DrawFunc_t drawFunc_;

	//更新関数
	void AppearInupdate(Input&); //フェードイン状態
	void NoramalUpdate(Input& input);           //通常状態
	void DisappearUpdate(Input&);   //退場状態

	void FadeOutDraw(Input&);//フェードアウト状態

	//描画関数
	void FadeDraw();//拡張縮小描画
	void NormalDraw();//通常描画

	void DrawCommandList();//テキスト描画

public:
	KeyConfigScene(SceneManager& manager,Input& input);
	void Update(Input& input);
	void Draw();
};

