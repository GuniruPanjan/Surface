#pragma once
#include "DxLib.h"

/// <summary>
/// プレイヤーの基底クラス
/// </summary>
class PlayerBase
{
public:
	PlayerBase(){}
	virtual ~PlayerBase(){}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	int PlayerHp = 0;
	int PlayerModel = 0;
	VECTOR PlayerPos = VGet(0.0f, 0.0f, 0.0f);
};

