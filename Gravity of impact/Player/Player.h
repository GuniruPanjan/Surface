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

	//Playerのポジション
	VECTOR Playerpos = VGet(0.0f, 10.0f, 0.0f);

	//Playerのアングル
	VECTOR PlayerAngle;
};

