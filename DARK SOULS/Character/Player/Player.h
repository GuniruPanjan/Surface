#pragma once
#include "Character/CharacterBase.h"
#include "Character/Enemy/Enemy.h"

class Player : public CharacterBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Action();
	void Animation(int& A, float& time, VECTOR& pos);
	void Draw();
	void End();

	//カプセル同士の当たり判定
	bool IsHit(const CapsuleCol& col);

	void SetCameraAngle(float angle) { m_cameraAngle = angle; }

	VECTOR GetPos() { return m_pos; }
	float GetPosX() { return m_pos.x; }
	float GetPosY() { return m_pos.y; }
	float GetPosZ() { return m_pos.z; }
	CapsuleCol GetCol() { return m_col; }


	bool GetLock() { return m_lockonTarget; }
	

private:
	float m_cameraAngle;  //カメラ情報
	bool m_lockonTarget;  //ターゲットロックオン判定
	int m_moveAnimFrameIndex;  //フレームを検索する
	int m_moveAnimShieldFrameIndex;  //ガードするときのフレーム検索
	int m_a;  //長押し確認変数
	int m_pad;  //パッド入力所得変数
	XINPUT_STATE m_xpad;  //パッド入力
	int m_animRollAttack;  //キャラがローディング後に攻撃するアニメーション
	bool m_avoidance;   //回避入力を判断するための変数
	bool m_nextAttack1;  //次の攻撃判定
	bool m_nextAttack2;  //次の攻撃判定
	VECTOR m_nowPos;   //現在のフレームの座標を取得する

	//当たり判定用のメンバ変数
	Pos3 m_colPos; //当たり判定用のメンバ変数
	Vec3 m_vec;  //当たり判定用のベクターメンバ変数
	float m_len;  //長さ
	float m_radius;  //半径
	CapsuleCol m_col;  //カプセルの当たり判定

	unsigned int m_color = 0xffffff;   //デバッグ用の色変更
};

