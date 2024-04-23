#pragma once
#include "PlayerBase.h"
class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();
};

