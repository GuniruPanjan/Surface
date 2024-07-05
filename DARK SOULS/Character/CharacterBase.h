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
	CharacterBase():
		m_hp(0.0f),
		m_attack(0.0f),
		m_handle(-1),
		m_modelSize(0.0f),
		m_speed(0.0f),
		m_dead(false),
		m_posX(0.0f),
		m_posY(0.0f),
		m_posZ(0.0f),
		m_pos(VGet(m_posX,m_posY,m_posZ))
	{
		for (int i = 0; i < ANIMATION; i++)
		{
			m_animation[i] = -1;
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
	float m_speed;  //キャラのスピード
	bool m_dead;   //キャラの死亡判定
	float m_posX;  //キャラのX座標
	float m_posY;  //キャラのY座標
	float m_posZ;  //キャラのZ座標
	int m_animation[ANIMATION];  //キャラのアニメーション格納変数
	VECTOR m_pos;  //キャラのポジション
};

