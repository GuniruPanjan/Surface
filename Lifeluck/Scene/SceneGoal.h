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
	//Pad“ü—ÍŠ“¾•Ï”
	int m_pad;
};

