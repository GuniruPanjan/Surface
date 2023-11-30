#pragma once
#include "Scene.h"
#include "Geometry.h"
#include<list>
/// <summary>
/// タイトルシーンクラス
/// </summary>
class TitleScene : public Scene
{
private:
	struct Bomb
	{
		int handle;
		Position2 pos;
		int frame = 0;
		bool isDead = false;
		Bomb(int h, const Position2& p) :handle(h), pos(p) {};
	};
	int handle_ = 0;
	int frame = 0;
	//更新メンバ関数ポインタ
	void(TitleScene::* updateFunc_)(Input& input);
	//描画メンバ関数ポインタ
	using DrawFunc_t = void(TitleScene::*)();
	DrawFunc_t drawFunc_;

	//更新関数
	void FadeInupdate(Input&); //フェードイン状態
	void NoramalUpdate(Input& input);           //通常状態

	void FadeOutDraw(Input&);//フェードアウト状態

	//描画関数
	void FadeDraw();//フェード中描画
	void NormalDraw();//非フェード描画

public:
	TitleScene(SceneManager& manager);
	~TitleScene();
	void Update(Input& input);
	void Draw();
};

