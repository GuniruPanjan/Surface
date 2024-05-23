#pragma once
#include "DxLib.h"
#include "Player/Player.h"
#include "Rect.h"
#include<memory>

class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase();

	//virtualで継承先を呼び出す
	virtual void Update();
	virtual void Draw();

	//モデルハンドルの取得
	int GetModelHandle() { return EnemyModel; }

	//ポジションのgetter/setter
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	//敵のスピード
	float Speed;

	//敵のノックバック威力
	float KnockBack;

	//敵の当たり幅
	float EnemyWidth;

	//敵の移動ベクトル
	float EnemyMoveX, EnemyMoveZ;

	//敵の索敵行動フラグ
	bool Enemyflag;

	//敵の3Dモデル格納用変数
	int EnemyModel;

	//敵の当たり判定矩形
	Rect m_colRect;

	//敵の座標
	float EnemyX, EnemyY, EnemyZ;

	//敵のポジション
	VECTOR pos = VGet(0.0f, 0.0f, 0.0f);

};

