#pragma once
#include "DxLib.h"

/// <summary>
/// プレイヤーの基底クラス
/// </summary>
class PlayerBase
{
public:
	PlayerBase() {}
	virtual ~PlayerBase() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//プレイヤーの体力
	int PlayerHp = 0;
	//プレイヤーのモデル格納変数
	int PlayerModel = 0;
	//プレイヤーのスピード設定
	float PlayerSpeed = 0;
	//プレイヤーの死亡フラグ
	bool PlayerDead = false;
	//プレイヤーのマシンに与えるエネルギー量
	float PlayerGiveEnergy = 0.0f;

	//プレイヤーのポジション設定
	float PlayerX = 0.0f;
	float PlayerY = 0.0f;
	float PlayerZ = 0.0f;
};
