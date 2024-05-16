#pragma once
#include "DxLib.h"
#include "Rect.h"
#include<memory>

class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtualで継承先を呼び出す
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void End();

	//モデルハンドルの取得
	int GetModelHandle() { return EnemyModel; }

	//ポジションのgetter/setter
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	//敵のスピード
	float Speed;

	//敵のノックバック威力
	float KnockBack;

	//敵の3Dモデル格納用変数
	int EnemyModel;

	//敵の座標
	float EnemyX, EnemyY, EnemyZ;

	//敵の当たり判定矩形
	Rect m_colRect;

	//敵のポジション
	VECTOR pos = VGet(0.0f, 0.0f, 0.0f);

};

