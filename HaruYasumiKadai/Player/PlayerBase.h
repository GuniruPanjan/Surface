#pragma once
#include "Rect.h"
#include<memory>



class PlayerBase
{
public:
	PlayerBase();
	virtual ~PlayerBase() {}

	//virtualで継承先を呼び出す

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	//Playerのスピード
	float PlayerSpeed;
	//Playerの画像保存
	int PlayerGraph;
	//PlayerのX,Y座標
	float PlayerX, PlayerY;
	//Playerのスクロール
	float PlayerScroll;

	//Playerの当たり判定幅
	int PlayerWidth, PlayerHeight;

	//Rectを管理するポインタ
	Rect m_colrect;
};

