#pragma once
#include "DxLib.h"

/// <summary>
/// エネミーの基底クラス
/// </summary>
class EnemyBase
{
public:
	EnemyBase() {}
	virtual ~EnemyBase() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

protected:
	//エネミーのモデル格納変数
	int EnemyModel = -1;
	//エネミーのスピード設定
	float EnemySpeed = 0.0f;

	//エネミーのポジション設定
	float EnemyX = 0.0f;
	float EnemyY = 0.0f;
	float EnemyZ = 0.0f;

	VECTOR EnemyPos = VGet(0.0f, 0.0f, 0.0f);
};


