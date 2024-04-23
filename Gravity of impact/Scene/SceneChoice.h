#pragma once
#include "SceneBase.h"
class SceneChoice : public SceneBase
{
public:
	SceneChoice();
	virtual ~SceneChoice();

	virtual void Init();
	virtual std::shared_ptr<SceneBase>Update();
	virtual void Draw();
	virtual void End();

private:
	//�t���[���J�E���g
	int m_frameCount;
};

