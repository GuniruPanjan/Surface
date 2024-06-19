#pragma once
#include "PlayerBase.h"
#include "Col/CapsuleCol.h"
#include<memory>

class Player : public PlayerBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();

	CapsuleCol GetCol() const { return m_col; }
	bool IsHit(const CapsuleCol& col);

	void End();

	void SetCameraAngle(float angle) { cameraAngle = angle; }

	//カメラ情報
	float cameraAngle;
	float angle;
	//Playerのポジション設定
	VECTOR PlayerPos = VGet(0.0f, 0.0f, 0.0f);
	//Playerのアニメーション読み込み
	int PlayerAnimRun, PlayerAnimWalking, PlayerAnimDying;
	//Playerのアニメーション格納変数
	int PlayerAnim[4];

	//アニメーションの再生時間
	float PlayTime;

	//アニメーションの総再生時間
	float TotalTime[4];

	//Playerが動いたフラグ
	bool PlayerMove;

	//Playerのカプセル型の当たり判定
	int HitCapsule;

	//Pad入力取得
	int Pad;
private:
	Pos3 m_pos;
	Vec3 m_vec;
	float m_len;
	float m_radius;
	CapsuleCol m_col;

	unsigned int m_color = 0xffffff;
};

