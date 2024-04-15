#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "Player/Player.h"
#include<memory>

class BlackHole
{
public:
	BlackHole();
	virtual ~BlackHole();

	void Init();
	void Update(Player& player);
	void Draw();

	//ブラックホールのx座標とy座標
	int BlackHoleX, BlackHoleY;

	//3Dのブラックホールのポジション
	VECTOR pos;

	//ブラックホールの横幅と縦幅
	int BlackHoleWidth, BlackHoleHight;

	//ブラックホールの3Dモデル格納変数
	int BlackHole3D;

	//ブラックホールで死亡した判定の変数
	bool BlackDead;

	static constexpr float Scale = 20.0f; //スケール

	//Rectを管理するポインタ
	//std::shared_ptr<Rect> BlackHoleRect = std::make_shared<Rect>();

	Rect BlackHoleRect;
};



