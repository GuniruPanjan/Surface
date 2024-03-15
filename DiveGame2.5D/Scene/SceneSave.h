#pragma once
#include "SceneBase.h"
class SceneSave : public SceneBase
{
public:
	SceneSave();
	virtual ~SceneSave();

	virtual void Init();  //シーンに入るときの初期化処理
	virtual std::shared_ptr<SceneBase> Update(); //毎フレーム行う更新処理
	virtual void Draw();  //毎フレーム行う描画処理
	virtual void End();  //シーンを抜ける時の終了処理
private:
	int m_frameCount;
};

