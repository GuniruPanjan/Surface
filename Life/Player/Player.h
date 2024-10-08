#pragma once
#include "PlayerBase.h"
class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();
	void End();

	void SetCameraAngle(float angle) { cameraAngle = angle; }

	//カメラ情報
	float cameraAngle;
	float angle;
	//Playerのポジション設定
	VECTOR PlayerPos = VGet(0.0f, 0.0f, 0.0f);
	//Playerのアニメーション読み込み
	int PlayerAnimStanding, PlayerAnimRun, PlayerAnimWalking, PlayerAnimDying;
	//Playerのアニメーション格納変数
	int PlayerAnim[4];

	//アニメーションの再生時間
	float PlayTime;

	//アニメーションの総再生時間
	float TotalTime[4];

	//Playerが動いたフラグ
	bool PlayerMove;

	//Pad入力取得
	int Pad;

};

