#pragma once
#include "Scene.h"
#include<unordered_map>
class KeyConfigScene:public Scene
{
private:
	int frame_ = 0;

	std::unordered_map<int, std::string> keynameTable_;
	std::unordered_map<int, std::string> padnameTable_;

	std::vector<std::string> menuItems_; //特定の順序にコマンドを並べるための配列
	int currentLineIndex_ = 0; //現在行のインデックス
	bool isEditingNow_ = false; //今編集中なのか
	bool isEditRequestButton_ = false; //今編集中なのか

	Input& input_; //inputクラスの参照
	InputTable_t keyCommandTable_;
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
	void EditUpdate(Input&); //編集状態

	void FadeOutDraw(Input&);//フェードアウト状態

	//描画関数
	void FadeDraw();//拡張縮小描画
	void NormalDraw();//通常描画

	void DrawCommandList();//テキスト描画
	void CommitCurrentKeySetting();


	std::string GetKeyName(int keycode);

public:
	KeyConfigScene(SceneManager& manager,Input& input);
	void Update(Input& input);
	void Draw();
};

