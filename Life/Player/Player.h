#pragma once
#include "PlayerBase.h"
class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();
	void End();
};

