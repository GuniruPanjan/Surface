#pragma once
#include "SceneBase.h"
class SceneChoice : public SceneBase
{
public:
	SceneChoice();
	virtual ~SceneChoice();

	virtual void Init(); //シーンに入るときの初期化処理
	virtual std::shared_ptr<SceneBase> Update(); //毎フレーム行う更新処理
	virtual void Draw(); //毎フレーム行う描画処理
	virtual void End(); //シーンを抜ける時の終了処理

	//ステージの裏か表判定
	bool front, back;

private:

	//文字の位置変数
	int X, Y;

	//時間を計測する変数
	int Time, TimeNow;

	//上キーと下キーの変数
	bool Up, Down;

	//選ぶポイント
	int Select;
};

