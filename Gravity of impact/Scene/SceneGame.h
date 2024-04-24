#pragma once
#include "SceneBase.h"
#include "Camera/Camera.h"
#include "Player/Player.h"


class SceneGame : public SceneBase
{
public:
	SceneGame();
	virtual ~SceneGame();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();
	virtual void End();

	//カメラを管理するポインタ
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();

	//Playerを管理するポインタ
	std::shared_ptr<Player> player = std::make_shared<Player>();
};

