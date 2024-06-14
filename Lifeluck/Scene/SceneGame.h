#pragma once
#include "SceneBase.h"
#include "Player/Player.h"
#include "Camera/Camera.h"
#include "Enemy/Enemy.h"
#include "Machine/Machine.h"
#include "Map/MapGround.h"
#include "Map/MapObject.h"
#include<memory>

class SceneGame :  public SceneBase
{
public:
	SceneGame();
	virtual ~SceneGame();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();
	virtual void End();

	//ƒ|ƒCƒ“ƒ^‚ÅŠÇ—
	std::shared_ptr<Player> player = std::make_shared<Player>();
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
	std::shared_ptr<Machine> machine = std::make_shared<Machine>();
	std::shared_ptr<MapGround> ground = std::make_shared<MapGround>();
	std::shared_ptr<MapObject> obj = std::make_shared<MapObject>();

};

