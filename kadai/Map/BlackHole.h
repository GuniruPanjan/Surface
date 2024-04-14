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

	//ブラックホールのx座標とy座標とz座標
	int BlackHoleX, BlackHoleY, BlackHoleZ;

	//ブラックホールの横幅と縦幅
	int BlackHoleWidth, BlackHoleHight;

	//ブラックホールの3Dモデル格納変数
	int BlackHole3D;

	//ブラックホールで死亡した判定の変数
	bool BlackDead;

	//Rectを管理するポインタ
	//std::shared_ptr<Rect> BlackHoleRect = std::make_shared<Rect>();

	Rect BlackHoleRect;
};

