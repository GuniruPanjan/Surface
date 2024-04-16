#pragma once
#include "SceneBase.h"
class SceneDeadBack : public SceneBase
{
public:
	SceneDeadBack();
	virtual ~SceneDeadBack();

	virtual void Init(); //シーンに入るときの初期化処理
	virtual std::shared_ptr<SceneBase> Update(); //毎フレーム行う更新処理
	virtual void Draw(); //毎フレーム行う描画処理
	virtual void End(); //シーンを抜けるときの終了処理

	//選べるボタンの位置変数
	int SelectX, SelectY;

	//選べるボタンの幅
	int SelectWidth, SelectHight;

	//上キーと下キーの押してる判定
	bool Up, Down;
};

