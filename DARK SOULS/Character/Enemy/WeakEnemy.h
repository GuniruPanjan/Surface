#pragma once
#include "EnemyBase.h"

class WeakEnemy : public EnemyBase
{
public:
	WeakEnemy();
	virtual ~WeakEnemy();

	void Init();
	void Update();
	void Animation(float& time);
	void Draw();
	void End();

	bool isHit(const CapsuleCol& col);

	VECTOR GetPos() { return m_pos; }
	float GetPosX() { return m_pos.x; }
	float GetPosY() { return m_pos.y; }
	float GetPosZ() { return m_pos.z; }
	CapsuleCol GetCol() const { return m_col; }


private:
	unsigned int m_color = 0xffffff;

	//当たり判定用のメンバ変数
	Pos3 m_colPos; //当たり判定用のメンバ変数
	Vec3 m_vec;  //当たり判定用のベクターメンバ変数
	float m_len;  //長さ
	float m_radius;  //半径
	CapsuleCol m_col;  //カプセルの当たり判定
};

