#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "Player/Player.h"
#include "Map.h"
#include<memory>

struct BlackHoleAttak
{
public:
	//攻撃の画像格納用変数
	int AttakGraph;

	//攻撃の位置
	int AttakX, AttakY;

	//攻撃スピード
	int AttakSpeed;

	//攻撃の存在フラグ
	bool Existence;

	Rect AttakRect;
};

class BlackHole
{
public:
	BlackHole();
	virtual ~BlackHole();

	void Init();
	void InitBack(BlackHoleAttak attak[], int Size);
	void Update(Player& player);
	void Draw();
	void DrawBack(BlackHoleAttak attak[], int Size);
	void Attak(Player& player,BlackHoleAttak attak[], int Size);

	//ブラックホールのx座標とy座標
	int BlackHoleX, BlackHoleY;

	//3Dのブラックホールのポジション
	VECTOR pos;

	//現在時間を得る
	int TimeNow;

	//攻撃までの時間
	int Time;

	//斬撃の画像格納変数
	int Graph;

	//攻撃のランダムとフラグ
	int AttakRandom;
	bool AttakFlag;

	//攻撃間隔
	int Attakinterval;

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



