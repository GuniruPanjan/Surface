#pragma once
#include "Camera/Camera.h"
#include "Character/Player/Player.h"
#include "SceneBase.h"
class SceneGame : public SceneBase
{
public:
	SceneGame();
	virtual ~SceneGame();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();
	virtual void End();

private:
	//ƒ|ƒCƒ“ƒ^‚ÅŠÇ—
	std::shared_ptr<Player> player = std::make_shared<Player>();
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
};

