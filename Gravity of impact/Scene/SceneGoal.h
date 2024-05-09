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
	//3D�̃I�u�W�F�N�g
	int Map, Player;

	//3D�̍��W
	float MapX, MapY, MapZ;
	float PlayerX, PlayerY, PlayerZ;

	//�V�[���J�ڂ����邽�߂̃t���O
	bool SceneChange;
};

