#pragma once
#include "SceneBase.h"
#include "Camera/Camera.h"
#include "Map/Map.h"
#include "Enemy/Enemy.h"
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

	//�J�������Ǘ�����|�C���^
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();

	//Player���Ǘ�����|�C���^
	std::shared_ptr<Player> player = std::make_shared<Player>();

	//Enemy���Ǘ�����|�C���^
	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();

	//Map���Ǘ�����|�C���^
	std::shared_ptr<Map> map = std::make_shared<Map>();
};

