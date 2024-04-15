#pragma once
#include "PlayerBase.h"

class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	virtual void Init();  //初期化処理
	virtual void InitBack();  //裏の初期化処理
	virtual void Update();  //更新処理を行う
	virtual void UpdateBack();  //裏の更新処理
	virtual void Draw();  //描画処理を行う
	virtual void DrawBack();  //裏の描画処理を行う
	virtual void End();  //終了処理を行う
	virtual void EndBack();  //裏の終了処理を行う

	//Playerの死亡判定
	bool PlayerDead;

	//Playerのジャンプ力
	float PlayerJumpPower;

	//Playerのジャンプフラグ
	bool PlayerJump;

	//Playerの重力
	float PlayerGravity;

private:
	//Playerの斜め移動の時の速度を落とす変数
	bool m_diagonalX, m_diagonalY;
};

