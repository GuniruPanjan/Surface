#pragma once
#include "EnemyBase.h"
#include "Col/CapsuleCol.h"
#include "Col/RectCol.h"

class Enemy : public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy();

	void Init();
	void Update();
	void Draw();

	CapsuleCol GetCol() const { return m_col; }
	bool IsHit(const CapsuleCol& col);

	void End();

private:
	//エネミーのモーション格納変数
	int EnemyAnim[3];
	//モーションのトータル時間
	float TotalTime[3];

	//エネミーのモーション読み込み変数
	int EnemyWark;

	//再生時間
	float PlayTime;

	//当たり判定用メンバ変数
	Pos3 m_pos;
	Vec3 m_vec;
	Size m_size;
	float m_len;
	float m_radius;
	RectCol m_rect;
	CapsuleCol m_col;

	unsigned int m_color = 0xffffff;
};

