#pragma once
#include "PlayerBase.h"
#include "Rect.h"

class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	virtual void Init();  //最初に初期化処理
	virtual void Update(); //毎フレーム行う更新処理
	virtual void Draw();  //毎フレーム描画処理
	virtual void End();  //終了処理

	//当たり判定の矩形
	Rect m_colRect;

private:
	//プレイヤーの座標
	float m_playerX, m_playerY;
};

