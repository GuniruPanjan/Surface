#pragma once
#include "Player/Player.h"
#include "Map/BlackHole.h"
#include "Map/Map.h"
#include<memory>

//Player���Ǘ�����|�C���^
//std::shared_ptr<Player> player = std::make_shared<Player>();
Player Play;

//BlackHole���Ǘ�����|�C���^
//std::shared_ptr<BlackHole> blackhole = std::make_shared<BlackHole>();
BlackHole blackhole;

//�}�b�v���Ǘ�����|�C���^
//std::shared_ptr<Map> map = std::make_shared<Map>();
Map map;

class SceneBase;

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	void Init();
	void Update();
	void Draw();
	void End();

private:
	std::shared_ptr<SceneBase> m_pScene;
};

