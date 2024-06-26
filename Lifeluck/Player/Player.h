#pragma once
#include "PlayerBase.h"
#include "Col/CapsuleCol.h"
#include "Col/SphereCol.h"
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
	bool IsHitSearch(const SphereCol& col);

	void End();

	void SetCameraAngle(float angle) { cameraAngle = angle; }

	//カメラ情報
	float cameraAngle;
	float angle;
	//Playerのポジション設定
	VECTOR PlayerPos = VGet(0.0f, 0.0f, 0.0f);
	//Playerのアニメーション読み込み
	int PlayerAnimRun, PlayerAnimWalking, PlayerAnimDying, PlayerAnimCode;
	//Playerのアニメーション格納変数
	int PlayerAnim[5];

	//アニメーションの再生時間
	float PlayTime;

	//アニメーションの総再生時間
	float TotalTime[5];

	//Playerが動いたフラグ
	bool PlayerMove;

	//Pad入力取得
	int Pad;

	
private:
	//プレイヤーの移動
	VECTOR move;

	//マシンの近くにいるとマシンのエネルギーを補充できる判定
	bool m_playercan;
	//マシンをエネルギー補充している行動
	bool m_playercharging;

	//当たり判定用のメンバ変数
	Pos3 m_pos;
	Vec3 m_vec;
	float m_len;
	float m_radius;
	CapsuleCol m_col;

	unsigned int m_color = 0xffffff;
};

