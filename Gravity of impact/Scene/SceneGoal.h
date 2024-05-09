#pragma once
#include "SceneBase.h"

class SceneGoal : public SceneBase
{
public:
	SceneGoal();
	virtual ~SceneGoal();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();
	virtual void End();

private:
	//3Dのオブジェクト
	int Map, Player;

	//3Dの座標
	float MapX, MapY, MapZ;
	float PlayerX, PlayerY, PlayerZ;

	//シーン遷移させるためのフラグ
	bool SceneChange;
};

