#pragma once
#include "DxLib.h"
#include<memory>
//だいたいのアニメーション
#define  ANIMATION   30

/// <summary>
/// キャラクターの基底クラス
/// </summary>
class CharacterBase
{
public:
	CharacterBase() :
		m_hp(0.0f),
		m_attack(0.0f),
		m_handle(-1),
		m_modelSize(0.0f),
		m_angle(0.0f),
		m_speed(0.0f),
		m_dead(false),
		m_posX(0.0f),
		m_posY(0.0f),
		m_posZ(0.0f),
		m_moveflag(false),
		m_moveAttack(false),
		m_moveAttackEnd(true),
		m_attackNumber(0),
		m_playerTime(0.0f),
		m_animStand(-1),
		m_animWalk(-1),
		m_animRun(-1),
		m_animRoll(-1),
		m_animAttack1(-1),
		m_animAttack2(-1),
		m_animAttack3(-1),
		m_move(VGet(0.0f, 0.0f, 0.0f)),
		m_pos(VGet(m_posX, m_posY, m_posZ)),
		m_drawPos(VGet(0.0f, 0.0f, 0.0f)),
		m_prevPos(VGet(0.0f, 0.0f, 0.0f)),
		m_nowPos(VGet(0.0f, 0.0f, 0.0f)),
		m_moveVector(VGet(0.0f, 0.0f, 0.0f))
	{
		for (int i = 0; i < ANIMATION; i++)
		{
			m_animation[i] = -1;
			m_totalAnimTime[i] = 0.0f;
		}
	
	}

	virtual ~CharacterBase(){}

	//virtualで継承先を呼び出す

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

protected:
	float m_hp;  //キャラのHP
	float m_attack;  //キャラの攻撃力
	int m_handle;  //キャラのモデルハンドル
	float m_modelSize;  //キャラのモデルサイズ
	float m_angle;  //キャラのアングル
	float m_speed;  //キャラのスピード
	bool m_dead;   //キャラの死亡判定
	float m_posX;  //キャラのX座標
	float m_posY;  //キャラのY座標
	float m_posZ;  //キャラのZ座標
	bool m_moveflag;  //キャラが動いたか判断するフラグ
	bool m_moveAttack;  //キャラが攻撃したかどうか判断するフラグ
	bool m_moveAttackEnd;  //キャラの攻撃が終了したかどうか判断するフラグ
	int m_attackNumber;   //キャラの攻撃が何段階目か判断する変数
	float m_playerTime;  //キャラのアニメーションを進める時間
	int m_animStand;  //キャラの経っているアニメーション格納変数
	int m_animWalk;   //キャラの歩くアニメーション格納変数
	int m_animRun;    //キャラの走るアニメーション格納変数
	int m_animRoll;   //キャラのローディングアニメーション格納変数
	int m_animAttack1;   //キャラの攻撃アニメーション格納変数
	int m_animAttack2;   //キャラの攻撃アニメーション格納変数
	int m_animAttack3;   //キャラの攻撃アニメーション格納変数
	int m_animation[ANIMATION];  //キャラのアニメーション格納変数
	float m_totalAnimTime[ANIMATION];  //キャラのアニメーション再生時間
	VECTOR m_move;  //キャラの移動
	VECTOR m_pos;  //キャラのポジション
	VECTOR m_drawPos;   //キャラのモデルを描画するポジション
	VECTOR m_prevPos;  //キャラのアニメーションで移動しているフレームの座標取得
	VECTOR m_nowPos;  //キャラのアニメーション後の座標を取得する
	VECTOR m_moveVector;  //キャラのアニメーションでの座標移動値を入れる
};

