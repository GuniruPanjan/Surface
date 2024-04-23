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
};

